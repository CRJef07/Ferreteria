#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H

#include "NodoProducto.h"

class ListaProducto {
public:
    ListaProducto();
    virtual ~ListaProducto();

    NodoProducto * getCabeza();

    NodoProducto * getUltimo();

    bool eliminarTop(string);

    void insertarPrimero(PilaProducto*);

    void insertarUltimo(PilaProducto*);

    bool borrarPrimero();

    string toString();

    int getTam();

    int cantPilasVacias();

private:
    NodoProducto *cabeza;

    NodoProducto *actual;
};

#endif /* LISTAPRODUCTO_H */

