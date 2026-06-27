#ifndef AST_H
#define AST_H
#include "nodo.h"
#include <iostream>
#include <fstream>
#include <string>

void imprimirAST(Nodo *n, std::string prefijo="", bool esUltimo=true) {
    if (!n) return;
    std::cout << prefijo << (esUltimo ? "└── " : "├── ") << n->etiqueta << "\n";
    std::string np = prefijo + (esUltimo ? "    " : "│   ");
    int h = (n->izq?1:0)+(n->der?1:0)+(n->tercero?1:0);
    int i = 0;
    if (n->izq)     { i++; imprimirAST(n->izq,     np, i==h); }
    if (n->der)     { i++; imprimirAST(n->der,     np, i==h); }
    if (n->tercero) { i++; imprimirAST(n->tercero, np, i==h); }
}

void guardarAST(Nodo *n, std::ofstream &f, std::string prefijo="", bool esUltimo=true) {
    if (!n) return;
    f << prefijo << (esUltimo ? "└── " : "├── ") << n->etiqueta << "\n";
    std::string np = prefijo + (esUltimo ? "    " : "│   ");
    int h = (n->izq?1:0)+(n->der?1:0)+(n->tercero?1:0);
    int i = 0;
    if (n->izq)     { i++; guardarAST(n->izq,     f, np, i==h); }
    if (n->der)     { i++; guardarAST(n->der,     f, np, i==h); }
    if (n->tercero) { i++; guardarAST(n->tercero, f, np, i==h); }
}

#endif
