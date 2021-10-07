#include "Seccion.h"

Seccion::Seccion(int numero, string nombre, ListaProducto* productos) : numero(numero), nombre(nombre), productos(productos) {
}

Seccion::~Seccion() {
}

void Seccion::setNumero(int numero) {
    this->numero = numero;
}

void Seccion::setNombre(string nombre) {
    this->nombre = nombre;
}

void Seccion::setProductos(ListaProducto* productos) {
    this->productos = productos;
}

int Seccion::getNumero() {
    return numero;
}

string Seccion::getNombre() {
    return nombre;
}

ListaProducto * Seccion::getProductos() {
    return productos;
}

string Seccion::toString() {
    stringstream x;

    x << "\tSeccion #" << numero << "\n";
    
    x << "Nombre: " << nombre << "\n";
    
    x <<  productos->toString() ;
    
    return x.str();
}
string Seccion::toStringCliente() {
    stringstream x;

    x << "\tSeccion #" << numero << "\n";
    
    x << "Nombre: " << nombre << "\n";
    
    return x.str();
}
