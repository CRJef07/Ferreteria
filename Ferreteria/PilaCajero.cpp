#include "PilaCajero.h"

PilaCajero::PilaCajero() : pila(stack <string>()) {

}

void PilaCajero::agregar(string p) {
    pila.push(p);
}

string PilaCajero::eliminarTop() {
    string eliminado = "";
    if (!pila.empty()) {
        eliminado = pila.top();
        pila.pop();
    }
    return eliminado;
}

string PilaCajero::toString() {
    stack<string> pila2; //se crea una copia de las pilas para que se elimine la copia y no los objetos(las otras pilas)
    pila2 = pila;
    int tam = pila2.size();
    stringstream x;
    if (pila2.empty()) {
        x << " la pila esta vacia\n";
    } else {
        for (int i = 0; i < tam; i += 1) {
            x << pila2.top() << "\n";
            pila2.pop();
        }

    }
    return x.str();
}

int PilaCajero::getTam() {
    return pila.size();
}

string PilaCajero::getTop() {
    return pila.top();
}

PilaCajero::~PilaCajero() {
}

