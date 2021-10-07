#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

#include "PilaProducto.h"

class NodoProducto {
public:
    NodoProducto(NodoProducto*, PilaProducto*, NodoProducto*);
    virtual ~NodoProducto();

    void setSig(NodoProducto *);
    NodoProducto * getSig();

    void setAnt(NodoProducto*);
    NodoProducto * getAnt();

    void setDato(PilaProducto*);
    PilaProducto * getDato();

private:
    NodoProducto *sig;
    NodoProducto *ant;
    PilaProducto *dato;
};

#endif /* NODOPRODUCTO_H */

