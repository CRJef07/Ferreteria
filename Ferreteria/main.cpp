#include "Controladora.h"

int main() {
    ListaSucursal *sucursales = new ListaSucursal();
    PilaCarrito *carrito = new PilaCarrito();



    list<Seccion> *secciones = new list<Seccion>;
    ListaProducto *lista = new ListaProducto();
    PilaProducto * pila = new PilaProducto();
    PilaProducto * pila2 = new PilaProducto();
    for (auto i = 0; i < 5; i++) {
        pila->agregar("Martillo");
    }

    for (auto i = 0; i < 5; i++) {
        pila2->agregar("Clavos");
    }

    lista->insertarPrimero(pila);
    lista->insertarPrimero(pila2);
    Seccion sec(1, "Herramientas", lista);
    secciones->push_front(sec);



    Sucursal *Alajuela = new Sucursal("1", "Alajuela", new PilaCajero(), new ColaCliente, secciones);
    sucursales->agregar(Alajuela);

    Controladora control(sucursales, carrito);
    control.menuPrincipal();

    return 0;
}

