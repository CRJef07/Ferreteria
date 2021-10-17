#include "Controladora.h"

int main() {
    ListaSucursal *sucursales = new ListaSucursal();
    PilaCarrito *carrito = new PilaCarrito();

    Controladora control(sucursales, carrito);
    control.menuPrincipal();

//    delete sucursales;
//    sucursales = nullptr;
//    delete carrito;
//    carrito = nullptr;

    return 0;
}

