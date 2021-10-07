#ifndef NODOSUCURSAL_H
#define NODOSUCURSAL_H

#include "Sucursal.h"

class NodoSucursal {
public:
    NodoSucursal(Sucursal*);
    virtual ~NodoSucursal();

    void setSig(NodoSucursal *);
    void setDato(Sucursal *);

    NodoSucursal * getSig();
    Sucursal * getDato();
private:
    NodoSucursal *sig;
    Sucursal *dato;
};

#endif /* NODOSUCURSAL_H */

