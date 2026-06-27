#ifndef SEMANTICA_H
#define SEMANTICA_H
#include <iostream>
#include <string>
#include <vector>
#include <map>

extern int num_linea;
extern int total_errores_logicos;

enum TipoDato { TIPO_ENTERO, TIPO_DECIMAL, TIPO_TEXTO, TIPO_BOOL, TIPO_VOID, TIPO_ARRAY, TIPO_DESCONOCIDO };

inline std::string nombreTipo(TipoDato t) {
    switch(t) {
        case TIPO_ENTERO:  return "entero";
        case TIPO_DECIMAL: return "decimal";
        case TIPO_TEXTO:   return "texto";
        case TIPO_BOOL:    return "booleano";
        case TIPO_VOID:    return "vacio";
        case TIPO_ARRAY:   return "arreglo";
        default:           return "desconocido";
    }
}

struct SimboloVar {
    std::string nombre;
    TipoDato    tipo;
    double      valor;
    bool        esArray;
    int         tamano;
    std::vector<double> elementos;
};

struct SimboloFun {
    std::string nombre;
    TipoDato    retorno;
    std::vector<TipoDato> params;
};

struct Alcance {
    std::string nombre;
    std::map<std::string, SimboloVar> variables;
};

// Se marcan como inline o extern para evitar problemas de duplicados al enlazar
inline std::vector<Alcance>   pila_alcances;
inline std::vector<SimboloFun> tabla_funciones;

inline void entrar_alcance(const std::string &nombre) {
    pila_alcances.push_back({nombre, {}});
}

inline void salir_alcance() {
    if (!pila_alcances.empty())
        pila_alcances.pop_back();
}

inline bool existe_var(const std::string &nombre) {
    for (int i = (int)pila_alcances.size()-1; i >= 0; i--)
        if (pila_alcances[i].variables.count(nombre)) return true;
    return false;
}

inline SimboloVar* buscar_var(const std::string &nombre) {
    for (int i = (int)pila_alcances.size()-1; i >= 0; i--)
        if (pila_alcances[i].variables.count(nombre))
            return &pila_alcances[i].variables[nombre];
    return nullptr;
}

inline void declarar_var(const std::string &nombre, TipoDato tipo, bool esArray=false, int tam=0) {
    if (pila_alcances.empty()) {
        std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                  << ": no hay alcance activo.\033[0m\n\n";
        total_errores_logicos++;
        return;
    }
    auto &alcance = pila_alcances.back();
    if (alcance.variables.count(nombre)) {
        std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                  << ": variable '" << nombre << "' ya declarada en este alcance.\033[0m\n"
                  << "  Solucion: elimina la declaracion duplicada.\n\n";
        total_errores_logicos++;
        return;
    }
    SimboloVar sv;
    sv.nombre = nombre; sv.tipo = tipo;
    sv.valor = 0; sv.esArray = esArray; sv.tamano = tam;
    if (esArray) sv.elementos.resize(tam, 0);
    alcance.variables[nombre] = sv;
}

inline void asignar_var(const std::string &nombre, double valor, TipoDato tipoValor=TIPO_DECIMAL) {
    SimboloVar *sv = buscar_var(nombre);
    if (!sv) {
        std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                  << ": variable '" << nombre << "' no declarada.\033[0m\n"
                  << "  Solucion: declara 'entero " << nombre << ";' antes de usarla.\n\n";
        total_errores_logicos++;
        return;
    }
    if (sv->tipo == TIPO_ENTERO && tipoValor == TIPO_TEXTO) {
        std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                  << ": tipo incompatible. No puedes asignar texto a entero '" << nombre << "'.\033[0m\n\n";
        total_errores_logicos++;
        return;
    }
    sv->valor = valor;
}

inline double obtener_var(const std::string &nombre) {
    SimboloVar *sv = buscar_var(nombre);
    if (!sv) {
        std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                  << ": variable '" << nombre << "' no identificada en este alcance.\033[0m\n"
                  << "  Solucion: declara la variable antes de usarla.\n\n";
        total_errores_logicos++;
        return 0;
    }
    return sv->valor;
}

inline void declarar_funcion(const std::string &nombre, TipoDato retorno, std::vector<TipoDato> params) {
    for (auto &f : tabla_funciones) {
        if (f.nombre == nombre) {
            std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                      << ": funcion '" << nombre << "' ya declarada.\033[0m\n\n";
            total_errores_logicos++;
            return;
        }
    }
    tabla_funciones.push_back({nombre, retorno, params});
}

inline bool existe_funcion(const std::string &nombre) {
    for (auto &f : tabla_funciones)
        if (f.nombre == nombre) return true;
    return false;
}

inline void imprimir_tabla_simbolos() {
    std::cout << "\033[1;33m  TABLA DE SIMBOLOS\033[0m\n";
    std::cout << "\033[1;33m................................\033[0m\n";
    for (auto &alcance : pila_alcances) {
        std::cout << "\nAlcance: " << alcance.nombre << "\n";
        for (auto &par : alcance.variables) {
            auto &v = par.second;
            std::cout << "  " << nombreTipo(v.tipo) << " " << v.nombre;
            if (v.esArray) std::cout << "[" << v.tamano << "]";
            std::cout << " = " << v.valor << "\n";
        }
    }
    if (!tabla_funciones.empty()) {
        std::cout << "\nFunciones declaradas:\n";
        for (auto &f : tabla_funciones)
            std::cout << "  " << nombreTipo(f.retorno) << " " << f.nombre << "()\n";
    }
}

#endif
