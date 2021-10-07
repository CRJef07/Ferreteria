#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <list>

#include "ColaCliente.h"
#include "PilaCajero.h"
#include "Seccion.h"

class Sucursal {
public:
    Sucursal(string, string, PilaCajero*, ColaCliente*, list<Seccion>*);
    virtual ~Sucursal();

    void setId(string);
    void setUbicacion(string);
    void setCajero(PilaCajero*);
    void setClientes(ColaCliente*);
    void setSecciones(list<Seccion>*);

    string getId();
    string getUbicacion();
    PilaCajero * getCajero();
    ColaCliente * getClientes();
    list<Seccion> *getSecciones();

    string toStringSecciones(list<Seccion>);

    string toString();
    string toStringCliente();
    string toStringSeccionesCliente(list<Seccion>);
private:
    string id;
    string ubicacion;
    PilaCajero *cajero;
    ColaCliente *clientes;
    list<Seccion> *secciones; //ListaSeccion *secciones;
};

#endif /* SUCURSAL_H */

