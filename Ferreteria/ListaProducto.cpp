#include "ListaProducto.h"

ListaProducto::ListaProducto() : cabeza(nullptr), actual(nullptr) {
}

ListaProducto::~ListaProducto() {
    NodoProducto *borrar = nullptr;

    while (cabeza != nullptr) {
        borrar = cabeza;
        cabeza = cabeza->getSig();
        borrar->setSig(nullptr);
        delete borrar;
    }
}

NodoProducto * ListaProducto::getCabeza() {
    return cabeza;

}

NodoProducto * ListaProducto::getUltimo() {
    actual = cabeza;

    if (actual == nullptr) {
        return nullptr;
    }

    while (actual->getSig() != nullptr) {
        actual = actual->getSig();
    }
    return actual;

}

bool ListaProducto::eliminarTop(string producto) {
    NodoProducto * Borrar = cabeza;
    NodoProducto * Anterior = nullptr;

    bool tempBorrado = false;

    if (Borrar == nullptr) {//PRIMER NODO
        return tempBorrado;
    }

    if (Borrar->getDato()->getTop() == producto) {
        cabeza = Borrar->getSig();
        delete Borrar;
        Borrar = nullptr;
        tempBorrado = true;
    } else {
        while ((Borrar != nullptr) && (Borrar->getDato()->getTop() != producto)) {
            Anterior = Borrar;
            Borrar = Borrar->getSig();
        }
        if (Borrar == nullptr) {
            tempBorrado = false;
        } else {
            Anterior->setSig(Borrar->getSig());
            delete Borrar;
            Borrar = nullptr;
            tempBorrado = true;
        }
    }
    return tempBorrado;
}

void ListaProducto::insertarPrimero(PilaProducto* dato) {
    cabeza = new NodoProducto(nullptr, dato, cabeza);
}

void ListaProducto::insertarUltimo(PilaProducto* dato) {
    actual = cabeza;

    if (cabeza == nullptr) {
        cabeza = new NodoProducto(nullptr, dato, cabeza);
    } else {
        actual = cabeza;
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
        actual->setSig(new NodoProducto(actual, dato, nullptr));
    }
}

/*void ListaProducto::borrarPrimero() {
    actual = cabeza;
    if (cabeza != nullptr) {
        if (cabeza->getSig() == nullptr) {
            delete cabeza;
            cabeza = nullptr;
        } else {
            cabeza = actual->getSig();
            cabeza->setAnt(nullptr);
            delete actual;
        }
        cout << "\t\tSe elimino correctamente\n";
    }
}*/

bool ListaProducto::borrarPrimero() {
    bool eliminado = false;
    actual = cabeza;
    if (cabeza != nullptr) {
        if (cabeza->getSig() == nullptr) {
            delete cabeza;
            cabeza = nullptr;
            eliminado = true;
        } else {
            cabeza = actual->getSig();
            cabeza->setAnt(nullptr);
            delete actual;
            eliminado = true;
        }
    }
    return eliminado;
}

/*string ListaProducto::toString() {
    stringstream x;

    NodoProducto *tempAux = cabeza;

    if (tempAux == nullptr) {
        x << "\t\tNo hay datos registrados\n";
        return x.str();
    }

    while (tempAux != nullptr) {
        x << tempAux->getDato()->toString() << "\n";
        tempAux = tempAux->getSig();
    }
    return x.str();
}*/

string ListaProducto::toString() {
    stringstream x;

    NodoProducto *tempAux = cabeza;

    if (tempAux == nullptr) {
        x << "\t\tNo hay datos registrados\n";
        return x.str();
    }

    while (tempAux != nullptr) {
        x << "Producto: " << tempAux->getDato()->getTop() << " - ";
        x << "Cantidad: " << tempAux->getDato()->getTam() << "\n";
        tempAux = tempAux->getSig();
    }

    return x.str();
}