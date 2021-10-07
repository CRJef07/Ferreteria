#include "NodoSucursal.h"

NodoSucursal::NodoSucursal(Sucursal* dato) : dato(dato), sig(nullptr) {
}

NodoSucursal::~NodoSucursal() {
}

void NodoSucursal::setSig(NodoSucursal * sig) {
    this->sig = sig;
}

void NodoSucursal::setDato(Sucursal * dato) {
    this->dato = dato;
}

NodoSucursal * NodoSucursal::getSig() {
    return sig;
}

Sucursal * NodoSucursal::getDato() {
    return dato;
}
