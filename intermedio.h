#ifndef INTERMEDIO_H
#define INTERMEDIO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Instruccion {
    std::string op, arg1, arg2, resultado;
};

std::vector<Instruccion> codigo_intermedio;
int contador_temp = 0;

std::string nuevo_temp() {
    return "t" + std::to_string(contador_temp++);
}

int nuevo_label_num = 0;
std::string nuevo_label() {
    return "L" + std::to_string(nuevo_label_num++);
}

void emitir(const std::string &op, const std::string &arg1,
            const std::string &arg2, const std::string &res) {
    codigo_intermedio.push_back({op, arg1, arg2, res});
}

void imprimir_intermedio() {
    std::cout << "\033[1;35m  CODIGO INTERMEDIO (3 direcciones)\033[0m\n";
    for (size_t i = 0; i < codigo_intermedio.size(); i++) {
        auto &ins = codigo_intermedio[i];
        if (ins.op == "LABEL") {
            std::cout << ins.resultado << ":\n";
        } else if (ins.op == "GOTO") {
            std::cout << "  GOTO " << ins.resultado << "\n";
        } else if (ins.op == "IF_FALSE") {
            std::cout << "  IF_FALSE " << ins.arg1 << " GOTO " << ins.resultado << "\n";
        } else if (ins.op == "PARAM") {
            std::cout << "  PARAM " << ins.arg1 << "\n";
        } else if (ins.op == "CALL") {
            std::cout << "  " << ins.resultado << " = CALL " << ins.arg1
                      << " " << ins.arg2 << "\n";
        } else if (ins.op == "RETURN") {
            std::cout << "  RETURN " << ins.arg1 << "\n";
        } else if (ins.op == "PRINT") {
            std::cout << "  PRINT " << ins.arg1 << "\n";
        } else if (ins.op == "READ") {
            std::cout << "  READ " << ins.resultado << "\n";
        } else if (ins.arg2.empty()) {
            std::cout << "  " << ins.resultado << " = "
                      << ins.op << " " << ins.arg1 << "\n";
        } else {
            std::cout << "  " << ins.resultado << " = "
                      << ins.arg1 << " " << ins.op << " " << ins.arg2 << "\n";
        }
    }
}

void guardar_intermedio() {
    std::ofstream f("codigo_intermedio.txt");
    for (auto &ins : codigo_intermedio) {
        if (ins.op == "LABEL")
            f << ins.resultado << ":\n";
        else if (ins.op == "GOTO")
            f << "  GOTO " << ins.resultado << "\n";
        else if (ins.op == "IF_FALSE")
            f << "  IF_FALSE " << ins.arg1 << " GOTO " << ins.resultado << "\n";
        else if (ins.op == "PRINT")
            f << "  PRINT " << ins.arg1 << "\n";
        else if (ins.op == "READ")
            f << "  READ " << ins.resultado << "\n";
        else if (ins.arg2.empty())
            f << "  " << ins.resultado << " = " << ins.op << " " << ins.arg1 << "\n";
        else
            f << "  " << ins.resultado << " = "
              << ins.arg1 << " " << ins.op << " " << ins.arg2 << "\n";
    }
}

#endif
