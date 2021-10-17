#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include "ListaSucursal.h"

class Controladora {
public:
    Controladora(ListaSucursal *, PilaCarrito *);
    virtual ~Controladora();

    void setSucursales(ListaSucursal*);
    void setCarritoCliente(PilaCarrito*);

    ListaSucursal *getSucursales();
    PilaCarrito *getCarritoCliente();

    string toString();
    
    void agregarSucursales(string, string);

    void menuPrincipal();
    //-------------------------ADMI-----------------------------
    void menuAdministrador();

    void editarSucursal(string);

    void editarCajeroSucursal(PilaCajero *);

    void editarColaClientes(ColaCliente*);

    void agregarCliente(ColaCliente*);

    void editarListaSecciones(NodoSucursal*);

    void agregarSeccion(int, string, list<Seccion> *);

    //-------------------------CLIENTE-----------------------------

    Seccion seccionEspecifica(list<Seccion>, int);

    void menuCliente();

    void subMenu(NodoSucursal *);

    void menuProductos(Seccion);

    void productoEspecifico(string, ListaProducto*, int);

    void pagar(NodoSucursal*);

    void pagarColaClientes(PilaCajero*, Cliente, int);

    void pagarUsuario(PilaCajero*);

    void limpiarCajero(PilaCajero*);

private:
    ListaSucursal *sucursales;
    PilaCarrito *carritoCliente;
};
#endif /* CONTROLADORA_H */