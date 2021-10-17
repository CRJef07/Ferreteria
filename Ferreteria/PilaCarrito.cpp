#include "PilaCarrito.h"

PilaCarrito::PilaCarrito() : pila(stack <string>()) {

}

void PilaCarrito::agregar(string p) {
    pila.push(p);
}

string PilaCarrito::eliminarTop() {
    string eliminado = "";
    if (!pila.empty()) {
        eliminado = pila.top();
        pila.pop();
    }
    return eliminado;
}

string PilaCarrito::toString() {
    stack<string> pila2; //se crea una copia de las pilas para que se elimine la copia y no los objetos(las otras pilas)
    pila2 = pila;
    int tam = pila2.size();
    stringstream x;
    if (pila2.empty()) {
        x << "El carrito esta vacio\n";
    } else {
        for (int i = 0; i < tam; i += 1) {
            x << pila2.top() << "\n";
            pila2.pop();
        }

    }
    return x.str();
}

string PilaCarrito::getTop() {
    return pila.top();
}

int PilaCarrito::getTam() {
    return pila.size();
}

PilaCarrito::~PilaCarrito() {
}

bool PilaCarrito::pilaVacia() {
    return pila.empty();
}

void PilaCarrito::pop() {
    if (!pila.empty()) {
        pila.pop();
    }
}
