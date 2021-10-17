#include "Sucursal.h"

Sucursal::Sucursal(string id, string ubicacion, PilaCajero* cajero, ColaCliente * clientes, list<Seccion> *secciones) : id(id), ubicacion(ubicacion), cajero(cajero), clientes(clientes), secciones(secciones) {
}

Sucursal::~Sucursal() {
}

void Sucursal::setId(string id) {
    this->id = id;
}

void Sucursal::setUbicacion(string) {
    this->ubicacion = ubicacion;
}

string Sucursal::getId() {
    return id;
}

string Sucursal::getUbicacion() {
    return ubicacion;
}

void Sucursal::setCajero(PilaCajero* cajero) {
    this->cajero = cajero;
}

void Sucursal::setClientes(ColaCliente* clientes) {
    this->clientes = clientes;
}

void Sucursal::setSecciones(list<Seccion> *secciones) {
    this->secciones = secciones;
}

list<Seccion> *Sucursal::getSecciones() {
    return secciones;
}

PilaCajero * Sucursal::getCajero() {
    return cajero;
}

ColaCliente * Sucursal::getClientes() {
    return clientes;
}

string Sucursal::toStringSecciones(list<Seccion> lista) {
    stringstream x;

    if (lista.empty()) {
        x << "Lista vacia";
        return x.str();
    }

    while (!lista.empty()) {
        x << lista.front().toString();
        lista.pop_front();
    }

    return x.str();
}

string Sucursal::toString() {
    stringstream x;

    x << "El ID es: " << id << "\n";

    x << "La ubicacion es: " << ubicacion << "\n";

    if (cajero == nullptr) {
        x << "No hay cajero \n";
    } else {
        x << "Cajero: " << cajero->toString();
    }

    if (clientes == nullptr) {
        x << "No hay clientes \n";
    } else {
        x << "Clientes: " << clientes->toString();
    }

    if (secciones->empty()) {
        x << "No hay secciones \n";
    } else {
        x << toStringSecciones(*secciones);
    }

    return x.str();
}

string Sucursal::toStringCliente() {
    stringstream x;

    x << "El ID es: " << id << "\n";

    x << "La ubicacion es: " << ubicacion << "\n";
    return x.str();
}

string Sucursal::toStringSeccionesCliente(list<Seccion> lista) {
    stringstream x;

    if (lista.empty()) {
        x << "Lista vacia";
        return x.str();
    }

    while (!lista.empty()) {
        x << lista.front().toStringCliente();
        lista.pop_front();
    }

    return x.str();
}