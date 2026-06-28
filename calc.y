%{
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "nodo.h"
#include "ast.h"
#include "cst.h"
#include "semantica.h"
#include "intermedio.h"

extern int yylex();
extern int num_linea;
void yyerror(const char *s);

int total_errores_lexicos     = 0;
int total_errores_sintacticos = 0;
int total_errores_logicos     = 0;

void yyerror(const char *s) {
    std::cerr << "\n\033[1;31m[ERROR SINTACTICO] Linea " << num_linea
              << ": estructura invalida.\033[0m\n"
              << "  Posibles causas:\n"
              << "  - Falta ';' al final\n"
              << "  - Parentesis o llave sin cerrar\n"
              << "  - Instruccion incompleta\n\n";
    total_errores_sintacticos++;
}
%}

%union {
    double num;
    char  *str;
    struct Nodo *nodo;
}

%token <num> NUM VERDADERO FALSO
%token <str> ID TEXTO_VAL
%token SI SINO MIENTRAS PARA FUNCION RETORNAR
%token MOSTRAR DATOINGRESADO SALIDA ENTRADA
%token TENTERO TDECIMAL TTEXTO
%token LE GE EQ NE LT GT AND OR NOT

%type <nodo> expr instruccion cond params_lista args_lista

%left OR
%left AND
%right NOT
%left '+' '-'
%left '*' '/' '%'
%right UMENOS

%%

programa:
    { entrar_alcance("global"); }
    instrucciones
    { }
;

instrucciones:
    | instrucciones instruccion
        {
            if ($2) {
                std::cout << "\n\033[1;33m--- AST ---\033[0m\n";
                imprimirAST($2);
                std::cout << "\n\033[1;36m--- CST ---\033[0m\n";
                imprimirCST($2);
                std::ofstream fa("ast_salida.txt", std::ios::app);
                guardarAST($2, fa); fa << "\n";
                std::ofstream fc("cst_salida.txt", std::ios::app);
                guardarCST($2, fc); fc << "\n";
            }
        }
;
;
bloque: 
    '{' instrucciones '}'  { }
;


instruccion:
    TENTERO ID ';'
        {
            declarar_var($2, TIPO_ENTERO);
            emitir("DECL", "entero", "", $2);
            $$ = new Nodo("declaracion entero: " + std::string($2),
                          nullptr, nullptr, new Nodo("token: ';'"));
        }
    | TDECIMAL ID ';'
        {
            declarar_var($2, TIPO_DECIMAL);
            emitir("DECL", "decimal", "", $2);
            $$ = new Nodo("declaracion decimal: " + std::string($2),
                          nullptr, nullptr, new Nodo("token: ';'"));
        }
    | TTEXTO ID ';'
        {
            declarar_var($2, TIPO_TEXTO);
            emitir("DECL", "texto", "", $2);
            $$ = new Nodo("declaracion texto: " + std::string($2),
                          nullptr, nullptr, new Nodo("token: ';'"));
        }
    | TENTERO ID '[' NUM ']' ';'
        {
            declarar_var($2, TIPO_ENTERO, true, (int)$4);
            char buf[64]; snprintf(buf,63,"%d",(int)$4);
            emitir("DECL_ARRAY", "entero", buf, $2);
            $$ = new Nodo("declaracion arreglo entero: " + std::string($2) +
                          "[" + std::to_string((int)$4) + "]");
        }
    | TENTERO ID '=' expr ';'
        {
            declarar_var($2, TIPO_ENTERO);
            asignar_var($2, atof($4->etiqueta.c_str()));
            emitir("=", $4->etiqueta, "", $2);
            $$ = new Nodo("decl+asig: " + std::string($2),
                          new Nodo("variable: " + std::string($2)), $4,
                          new Nodo("token: '='"));
        }
    | TDECIMAL ID '=' expr ';'
        {
            declarar_var($2, TIPO_DECIMAL);
            asignar_var($2, atof($4->etiqueta.c_str()));
            emitir("=", $4->etiqueta, "", $2);
            $$ = new Nodo("decl+asig: " + std::string($2),
                          new Nodo("variable: " + std::string($2)), $4,
                          new Nodo("token: '='"));
        }
    | ID '=' expr ';'
        {
            asignar_var($1, atof($3->etiqueta.c_str()));
            printf("  %s = %.6g\n", $1, atof($3->etiqueta.c_str()));
            emitir("=", $3->etiqueta, "", $1);
            $$ = new Nodo("asignacion: " + std::string($1) + " =",
                          new Nodo("variable: " + std::string($1)), $3,
                          new Nodo("token: '='"));
        }
    | ID '[' expr ']' '=' expr ';'
        {
            std::string etiq = std::string($1) + "[" + $3->etiqueta + "]";
            emitir("ARRAY_SET", $6->etiqueta, $3->etiqueta, $1);
            $$ = new Nodo("asignacion arreglo: " + etiq,
                          $3, $6, nullptr);
        }
    | MOSTRAR SALIDA expr ';'
        {
            printf("%.6g\n", atof($3->etiqueta.c_str()));
            emitir("PRINT", $3->etiqueta, "", "");
            $$ = new Nodo("mostrar <<", $3, nullptr, new Nodo("token: '<<'"));
        }
    | MOSTRAR SALIDA TEXTO_VAL ';'
        {
            char *s = $3; if (s[0]=='"') s++;
            char buf[256]; strncpy(buf,s,255);
            int len=strlen(buf);
            if(buf[len-1]=='"') buf[len-1]='\0';
            printf("%s\n", buf);
            emitir("PRINT", "\""+std::string(buf)+"\"", "", "");
            $$ = new Nodo("mostrar << \"" + std::string(buf) + "\"");
        }
    | MOSTRAR SALIDA ID ';'
        {
            printf("%.6g\n", obtener_var($3));
            emitir("PRINT", $3, "", "");
            $$ = new Nodo("mostrar << var(" + std::string($3) + ")");
        }
    | DATOINGRESADO ENTRADA ID ';'
        {
            if (!existe_var($3))
                std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                          << ": variable '" << $3 << "' no declarada.\033[0m\n\n";
            double val;
            printf("Ingresa valor para %s: ", $3);
            fflush(stdout);
            fscanf(stdin, "%lf", &val);
            asignar_var($3, val);
            emitir("READ", "", "", $3);
            $$ = new Nodo("datoingresado >> " + std::string($3));
        }
    | SI '(' cond ')' bloque
        {
            std::string Lfalso = nuevo_label();
            std::string Lfin   = nuevo_label();
            emitir("IF_FALSE", $3->etiqueta, "", Lfalso);
            emitir("LABEL",    "", "", Lfalso);
            emitir("LABEL",    "", "", Lfin);
            $$ = new Nodo("si ( condicion )", $3, nullptr);
        }
    | SI '(' cond ')' bloque SINO bloque
        {
            std::string Lfalso = nuevo_label();
            std::string Lfin   = nuevo_label();
            emitir("IF_FALSE", $3->etiqueta, "", Lfalso);
            emitir("GOTO",     "", "", Lfin);
            emitir("LABEL",    "", "", Lfalso);
            emitir("LABEL",    "", "", Lfin);
            $$ = new Nodo("si-sino", $3, nullptr);
        }
    | MIENTRAS '(' cond ')' bloque
        {
            std::string Linicio = nuevo_label();
            std::string Lfin    = nuevo_label();
            emitir("LABEL",    "", "", Linicio);
            emitir("IF_FALSE", $3->etiqueta, "", Lfin);
            emitir("GOTO",     "", "", Linicio);
            emitir("LABEL",    "", "", Lfin);
            $$ = new Nodo("mientras ( condicion )", $3, nullptr);
        }
    | PARA '(' instruccion cond ';' instruccion ')' bloque
        {
            std::string Linicio = nuevo_label();
            std::string Lfin    = nuevo_label();
            emitir("LABEL",    "", "", Linicio);
            emitir("IF_FALSE", $4->etiqueta, "", Lfin);
            emitir("GOTO",     "", "", Linicio);
            emitir("LABEL",    "", "", Lfin);
            $$ = new Nodo("para ( init ; cond ; paso )", $3, $4);
        }
    | FUNCION ID '(' params_lista ')' bloque
        {
            declarar_funcion($2, TIPO_VOID, {});
            salir_alcance();
            emitir("LABEL", "", "", std::string($2) + "_inicio");
            emitir("RETURN","0","","");
            $$ = new Nodo("funcion: " + std::string($2), $4, nullptr);
        }
    | FUNCION TENTERO ID '(' params_lista ')' bloque
        {
            declarar_funcion($3, TIPO_ENTERO, {});
            salir_alcance();
            emitir("LABEL", "", "", std::string($3) + "_inicio");
            $$ = new Nodo("funcion entero: " + std::string($3), $5, nullptr);
        }
    | RETORNAR expr ';'
        {
            emitir("RETURN", $2->etiqueta, "", "");
            $$ = new Nodo("retornar", $2);
        }
    | ID '(' args_lista ')' ';'
        {
            if (!existe_funcion($1))
                std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                          << ": funcion '" << $1 << "' no declarada.\033[0m\n\n";
            std::string tmp = nuevo_temp();
            emitir("CALL", $1, "0", tmp);
            $$ = new Nodo("llamada funcion: " + std::string($1), $3);
        }
    | expr ';'
        {
            printf("= %s\n", $1->etiqueta.c_str());
            emitir("EXPR", $1->etiqueta, "", nuevo_temp());
            $$ = new Nodo("expresion", $1, nullptr, new Nodo("token: ';'"));
        }

params_lista:
    { $$ = new Nodo("params: vacio"); }
    | TENTERO ID
        {
            entrar_alcance("funcion");
            declarar_var($2, TIPO_ENTERO);
            $$ = new Nodo("param entero: " + std::string($2));
        }
    | params_lista ',' TENTERO ID
        {
            declarar_var($4, TIPO_ENTERO);
            $$ = new Nodo("params", $1,
                          new Nodo("param entero: " + std::string($4)));
        }
;

args_lista:
    { $$ = new Nodo("args: vacio"); }
    | expr
        {
            emitir("PARAM", $1->etiqueta, "", "");
            $$ = new Nodo("arg", $1);
        }
    | args_lista ',' expr
        {
            emitir("PARAM", $3->etiqueta, "", "");
            $$ = new Nodo("args", $1, $3);
        }
;

cond:
    expr LE expr  { $$ = new Nodo("condicion: <=", $1, $3); }
    | expr GE expr  { $$ = new Nodo("condicion: >=", $1, $3); }
    | expr EQ expr  { $$ = new Nodo("condicion: ==", $1, $3); }
    | expr NE expr  { $$ = new Nodo("condicion: !=", $1, $3); }
    | expr LT expr  { $$ = new Nodo("condicion: <",  $1, $3); }
    | expr GT expr  { $$ = new Nodo("condicion: >",  $1, $3); }
    | cond AND cond { $$ = new Nodo("condicion: &&", $1, $3); }
    | cond OR  cond { $$ = new Nodo("condicion: ||", $1, $3); }
    | NOT cond      { $$ = new Nodo("condicion: !",  $2, nullptr); }
;

expr:
    NUM
        {
            char buf[64]; snprintf(buf,63,"%g",$1);
            $$ = new Nodo(std::string(buf));
        }
    | VERDADERO   { $$ = new Nodo("verdadero"); }
    | FALSO       { $$ = new Nodo("falso"); }
    | TEXTO_VAL   { $$ = new Nodo(std::string($1)); }
    | ID
        {
            double v = obtener_var($1);
            char buf[64]; snprintf(buf,63,"var(%s)=%g",$1,v);
            $$ = new Nodo(std::string(buf));
        }
    | ID '[' expr ']'
        {
            std::string etiq = std::string($1) + "[" + $3->etiqueta + "]";
            $$ = new Nodo("acceso arreglo: " + etiq, $3);
        }
    | ID '(' args_lista ')'
        {
            if (!existe_funcion($1))
                std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                          << ": funcion '" << $1 << "' no declarada.\033[0m\n\n";
            std::string tmp = nuevo_temp();
            emitir("CALL", $1, "0", tmp);
            $$ = new Nodo("llamada: " + std::string($1) + "()", $3);
        }
    | expr '+' expr
        {
            std::string tmp = nuevo_temp();
            emitir("+", $1->etiqueta, $3->etiqueta, tmp);
            $$ = new Nodo("expr: +", $1, $3, new Nodo("token: '+'"));
        }
    | expr '-' expr
        {
            std::string tmp = nuevo_temp();
            emitir("-", $1->etiqueta, $3->etiqueta, tmp);
            $$ = new Nodo("expr: -", $1, $3, new Nodo("token: '-'"));
        }
    | expr '*' expr
        {
            std::string tmp = nuevo_temp();
            emitir("*", $1->etiqueta, $3->etiqueta, tmp);
            $$ = new Nodo("expr: *", $1, $3, new Nodo("token: '*'"));
        }
    | expr '/' expr
    {
        bool div_cero = false;
        std::string etiq_der = $3->etiqueta;

        if (etiq_der == "0" || etiq_der == "0.0") {
            div_cero = true;
        }
        else if (etiq_der.find("var(") == 0) {
            size_t pos_igual = etiq_der.find("=");
            if (pos_igual != std::string::npos) {
                std::string val_str = etiq_der.substr(pos_igual + 1);
                if (val_str == "0" || val_str == "0.0" || atof(val_str.c_str()) == 0.0) {
                    div_cero = true;
                }
            }
        }

        if (div_cero) {
            std::cerr << "\n\033[1;31m[ERROR SEMANTICO] Linea " << num_linea
                      << ": division por cero detectada.\033[0m\n"
                      << "  Causa: el divisor vale 0. Operacion invalida.\n"
                      << "  Tipo: ERROR SEMANTICO (el codigo es sintacticamente correcto\n"
                      << "        pero tiene un significado invalido en tiempo de ejecucion)\n\n";
            total_errores_logicos++;
        }

        std::string tmp = nuevo_temp();
        emitir("/", $1->etiqueta, $3->etiqueta, tmp);
        $$ = new Nodo("expr: /", $1, $3, new Nodo("token: '/'"));
    }
    | expr '%' expr
        {
            std::string tmp = nuevo_temp();
            emitir("%", $1->etiqueta, $3->etiqueta, tmp);
            $$ = new Nodo("expr: %", $1, $3, new Nodo("token: '%'"));
        }
    | '-' expr %prec UMENOS
        {
            std::string tmp = nuevo_temp();
            emitir("NEG", $2->etiqueta, "", tmp);
            $$ = new Nodo("negativo", $2);
        }
    | '(' expr ')'
        {
            $$ = new Nodo("agrupacion",
                          new Nodo("token: '('"), $2,
                          new Nodo("token: ')'"));
        }
;

%%

int main() {
    std::cout << "=== COMPILADOR v2 — Con bucles, funciones y semantica ===\n";
    std::cout << "Escribe tu codigo y presiona Ctrl+D al finalizar:\n\n";
    yyparse();
    imprimir_tabla_simbolos();
    imprimir_intermedio();
    guardar_intermedio();
    std::cout << "\033[1;33m  RESUMEN DE ERRORES\033[0m\n";
    std::cout << "\033[1;33m----------------------------\033[0m\n";
    if (!total_errores_lexicos && !total_errores_sintacticos && !total_errores_logicos)
        std::cout << "\033[1;32m  Sin errores. Codigo valido.\033[0m\n\n";
    else {
        if (total_errores_lexicos)
            std::cout << "\033[1;31m  Errores lexicos:     " << total_errores_lexicos     << "\033[0m\n";
        if (total_errores_sintacticos)
            std::cout << "\033[1;31m  Errores sintacticos: " << total_errores_sintacticos << "\033[0m\n";
        if (total_errores_logicos)
            std::cout << "\033[1;31m  Errores logicos:     " << total_errores_logicos     << "\033[0m\n";
        std::cout << "\n";
    }
    return 0;
}