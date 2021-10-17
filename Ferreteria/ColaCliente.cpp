#include <valarray>

#include "ColaCliente.h"

ColaCliente::ColaCliente() : cola(queue<Cliente>()) {
}

ColaCliente::~ColaCliente() {
}

void ColaCliente::agregar(Cliente* cliente) {
    cola.push(*cliente);
}

Cliente * ColaCliente::eliminarTop() {
    Cliente *aux;
    if (!cola.empty()) {
        *aux = cola.front();
        cola.pop();
    } else {
        return nullptr;
    }
    return aux;
}

int ColaCliente::getTam() {
    return cola.size();
}

Cliente ColaCliente::getTop() {
    return cola.front();
}

string ColaCliente::toString() {
    queue<Cliente> colaAux = cola;
    Cliente clienteAux(new PilaCarrito());

    stringstream x;

    if (cola.empty()) {
        x << "No hay clientes\n";
    }

    while (!colaAux.empty()) {
        clienteAux = colaAux.front();
        x << clienteAux.toString();
        colaAux.pop();
    }

    return x.str();
}

void ColaCliente::pop() {
    cola.pop();
}

bool ColaCliente::colaVacia() {
    return cola.empty();
}