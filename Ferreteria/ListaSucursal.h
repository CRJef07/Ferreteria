#ifndef LISTASUCURSAL_H
#define LISTASUCURSAL_H

#include "NodoSucursal.h"

class ListaSucursal {
public:
    ListaSucursal();

    virtual ~ListaSucursal();

    NodoSucursal *getCabeza();

    void agregar(Sucursal*);

    bool eliminar(string);

    string toString();
    string toStringCliente();
    NodoSucursal *getSucursalEspecifica(string);

private:
    NodoSucursal *cabeza;
};

#endif /* LISTASUCURSAL_H */
