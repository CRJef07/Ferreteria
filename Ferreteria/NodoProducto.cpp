#include "NodoProducto.h"

NodoProducto::NodoProducto(NodoProducto* ant, PilaProducto* dato, NodoProducto* sig) : ant(ant), dato(dato), sig(sig) {
}

NodoProducto::~NodoProducto() {
}

void NodoProducto::setSig(NodoProducto * sig) {
    this->sig = sig;
}

NodoProducto * NodoProducto::getSig() {
    return sig;
}

void NodoProducto::setAnt(NodoProducto* ant) {
    this->ant = ant;
}

NodoProducto * NodoProducto::getAnt() {
    return ant;
}

void NodoProducto::setDato(PilaProducto* dato) {
    this->dato = dato;
}

PilaProducto * NodoProducto::getDato() {
    return dato;
}