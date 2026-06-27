#ifndef CST_H
#define CST_H
#include "nodo.h"
#include <iostream>
#include <fstream>
#include <string>

void imprimirCST(Nodo *n, std::string prefijo="", bool esUltimo=true) {
    if (!n) return;
    std::cout << prefijo << (esUltimo ? "└── " : "├── ")
              << "\033[1;36m" << n->etiqueta << "\033[0m\n";
    std::string np = prefijo + (esUltimo ? "    " : "│   ");
    int h = (n->izq?1:0)+(n->der?1:0)+(n->tercero?1:0);
    int i = 0;
    if (n->izq)     { i++; imprimirCST(n->izq,     np, i==h); }
    if (n->der)     { i++; imprimirCST(n->der,     np, i==h); }
    if (n->tercero) { i++; imprimirCST(n->tercero, np, i==h); }
}

void guardarCST(Nodo *n, std::ofstream &f, std::string prefijo="", bool esUltimo=true) {
    if (!n) return;
    f << prefijo << (esUltimo ? "└── " : "├── ") << n->etiqueta << "\n";
    std::string np = prefijo + (esUltimo ? "    " : "│   ");
    int h = (n->izq?1:0)+(n->der?1:0)+(n->tercero?1:0);
    int i = 0;
    if (n->izq)     { i++; guardarCST(n->izq,     f, np, i==h); }
    if (n->der)     { i++; guardarCST(n->der,     f, np, i==h); }
    if (n->tercero) { i++; guardarCST(n->tercero, f, np, i==h); }
}

#endif
