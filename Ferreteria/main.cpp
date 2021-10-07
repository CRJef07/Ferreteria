#include "Controladora.h"

int main() {
    ListaSucursal *sucursales = new ListaSucursal();
    Sucursal *Alajuela = new Sucursal("1","Alajuela",new PilaCajero(), new ColaCliente,new list<Seccion>);
    sucursales->agregar(Alajuela);
    
    Controladora *control = new Controladora(sucursales, new PilaCarrito);
    control->menuPrincipal();
    
    delete control;
    control = nullptr;
    return 0;
}

