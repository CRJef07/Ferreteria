#ifndef SECCION_H
#define SECCION_H

#include "ListaProducto.h"

class Seccion {
public:
    Seccion(int, string, ListaProducto*);
    virtual ~Seccion();

    void setNumero(int);
    void setNombre(string);
    void setProductos(ListaProducto*);

    int getNumero();
    string getNombre();
    ListaProducto * getProductos();

    string toString();
    string toStringCliente();
private:
    int numero;
    string nombre;
    ListaProducto *productos;
};

#endif /* SECCION_H */

