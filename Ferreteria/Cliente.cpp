#include "Cliente.h"

Cliente::Cliente(PilaCarrito *carrito) : carrito(carrito) {
}

void Cliente::setCarrito(PilaCarrito* carrito) {
    this->carrito = carrito;
}

PilaCarrito * Cliente::getCarrito() {
    return carrito;
}

string Cliente::toString() {
    PilaCarrito *aux = carrito;
    int tam = aux->getTam();

    stringstream x;

    x << aux->toString();
    return x.str();
}

Cliente::~Cliente() {
}

