#include "ListaSucursal.h"

ListaSucursal::ListaSucursal() : cabeza(nullptr) {
}

ListaSucursal::~ListaSucursal() {
    NodoSucursal * nodoBorrar = nullptr;

    while (cabeza != nullptr) {
        nodoBorrar = cabeza;
        cabeza = cabeza->getSig();
        nodoBorrar->setSig(nullptr);
        delete nodoBorrar;
        nodoBorrar = nullptr;
    }
}

NodoSucursal *ListaSucursal::getCabeza() {
    return cabeza;
}

void ListaSucursal::agregar(Sucursal* dato) {
    NodoSucursal *nuevoNodo = new NodoSucursal(dato);

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        nuevoNodo->setSig(cabeza);
        cabeza = nuevoNodo;
    }
}

bool ListaSucursal::eliminar(string id) {
    NodoSucursal * borrar = cabeza;
    NodoSucursal * anterior = nullptr;
    bool tempBorrado = false;

    if (borrar == nullptr) {
        return tempBorrado;
    }
    if (borrar->getDato()->getId() == id) {
        cabeza = borrar->getSig();
        delete borrar;
        borrar = nullptr;
        tempBorrado = true;
    } else {
        while ((borrar != nullptr) && (borrar->getDato()->getId() != id)) {
            anterior = borrar;
            borrar = borrar->getSig();
        }
        if (borrar == nullptr) {
            tempBorrado = false;
        } else {
            anterior->setSig(borrar->getSig());
            delete borrar;
            borrar = nullptr;
            tempBorrado = true;
        }
    }
    return tempBorrado;
}

string ListaSucursal::toString() {
    stringstream x;

    NodoSucursal *tempAux = cabeza;

    if (tempAux == nullptr) {
        x << "\t\tNo hay ninguna sucursal registrada\n";
        return x.str();
    }

    while (tempAux != nullptr) {
        x << tempAux->getDato()->toString() << "\n";
        tempAux = tempAux->getSig();
    }

    return x.str();
}

NodoSucursal *ListaSucursal::getSucursalEspecifica(string id) {
    NodoSucursal *aux = cabeza;

    while (aux != nullptr) {

        if (aux->getDato()->getId() == id) {
            return aux;
        }
        aux = aux->getSig();
    }
    return nullptr;
}

string ListaSucursal::toStringCliente() {
    stringstream x;

    NodoSucursal *tempAux = cabeza;

    if (tempAux == nullptr) {
        x << "\t\tNo hay ninguna sucursal registrada\n";
        return x.str();
    }

    x << "\t\tSucursales: \n";

    while (tempAux != nullptr) {
        x << tempAux->getDato()->toStringCliente() << "\n";
        tempAux = tempAux->getSig();
    }

    return x.str();
}