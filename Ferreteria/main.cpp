#include "Controladora.h"

int main() {
    ListaSucursal *sucursales = new ListaSucursal();
    PilaCarrito *carrito = new PilaCarrito();
    
    Sucursal *Alajuela = new Sucursal("1","Alajuela",new PilaCajero(), new ColaCliente,new list<Seccion>);
    sucursales->agregar(Alajuela);
    
    Controladora control(sucursales, carrito);
    control.menuPrincipal();

    return 0;
}

