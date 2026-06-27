#ifndef NODO_H
#define NODO_H
#include <string>

struct Nodo {
    std::string etiqueta;
    Nodo *izq, *der, *tercero;
    Nodo(std::string et, Nodo *i=nullptr, Nodo *d=nullptr, Nodo *t=nullptr)
        : etiqueta(et), izq(i), der(d), tercero(t) {}
};

#endif
