#include "PilaProducto.h"

PilaProducto::PilaProducto() : pila(stack <string>()) {
}

void PilaProducto::agregar(string p) {
    pila.push(p);

}

void PilaProducto::Pop() {
    if (!pila.empty()) {
        pila.pop();
    }
}

string PilaProducto::eliminarTop() {
    string eliminado = "";
    if (!pila.empty()) {
        eliminado = pila.top();
        pila.pop();
    }
    return eliminado;
}

int PilaProducto::getTam() {
    return pila.size();
}

string PilaProducto::getTop() {
    if (!pila.empty()) {
        return pila.top();
    }
    return "";
}

PilaProducto::~PilaProducto() {
}

string PilaProducto::toString() {
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

bool PilaProducto::pilaVacia() {
    if(pila.empty() == true){
        return true;
    }
    return false;
}
