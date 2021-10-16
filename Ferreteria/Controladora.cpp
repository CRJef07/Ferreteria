#include "Controladora.h"

Controladora::Controladora(ListaSucursal * sucursales, PilaCarrito * carritoCliente) : sucursales(sucursales), carritoCliente(carritoCliente) {
}

Controladora::~Controladora() {
}

void Controladora::setSucursales(ListaSucursal* sucursales) {
    this->sucursales = sucursales;
}

void Controladora::setCarritoCliente(PilaCarrito* carritoCliente) {
    this->carritoCliente = carritoCliente;
}

ListaSucursal *Controladora::getSucursales() {
    return sucursales;
}

PilaCarrito *Controladora::getCarritoCliente() {
    return carritoCliente;
}

string Controladora::toString() {
    stringstream x;

    if (sucursales != nullptr) {
        x << "\tSucursal: \n" << sucursales->toString() << "\n";
    }

    x << carritoCliente->toString();

    return x.str();
}

//INTERFAZ

void Controladora::menuPrincipal() {
    string opc = "";

    do {
        fflush(stdin);
        system("clear");

        cout << "\t\tBienvenido a la Ferreteria Martillo Feliz\n\n";
        cout << "1 - MENU ADMINISTRADOR\n";
        cout << "2 - MENU CLIENTE\n";
        cout << "77 - SALIR\n";
        cout << "Opcion digitada:   ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "77") {
                throw opc;
            }

            switch (stoi(opc)) {
                case 1:
                    menuAdministrador();
                    break;

                case 2:
                    menuCliente();
                    break;

                case 77:
                    delete sucursales;
                    sucursales = nullptr;
                    delete carritoCliente;
                    carritoCliente = nullptr;
                    exit(0);
            }
        } catch (...) {
        }

    } while (true);
}

void Controladora::menuAdministrador() {
    string opc = "";
    string idSucursal = "";
    string ubicacionSucursal = "";

    PilaCajero *cajero = new PilaCajero();
    ColaCliente *colaClientes = new ColaCliente();
    list<Seccion> *listaSecciones = new list<Seccion>;
    NodoSucursal *aux;
    do {
        fflush(stdin); //LIMPIAR BUFFER 
        system("clear");

        cout << "\t\t\tMenu del administrador\n";
        cout << "Digite la opcion que desee ejecutar\n";
        cout << " 1 - Insertar una nueva sucursal\n";
        cout << " 2 - Editar sucursal\n";
        cout << " 3 - Ver Sucursal Especifica\n";
        cout << " 4 - Ver Todas las Sucursales\n";
        cout << " 5 - Eliminar sucursal especifica\n";
        cout << "77 - SALIR \n";
        cout << "Opcion:  ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "3" && opc != "4" && opc != "5" && opc != "77") {
                throw opc;
            }
            switch (stoi(opc)) {
                case 1:

                    cout << "Digite el id de la sucursal:   ";
                    getline(cin, idSucursal);

                    cout << "Ahora digite la ubicacion de la sucursal:   ";
                    getline(cin, ubicacionSucursal);
                    sucursales->agregar(new Sucursal(idSucursal, ubicacionSucursal, cajero, colaClientes, listaSecciones));
                    break;

                case 2:
                    cout << "Digite el id de la sucursal que desea editar:   ";
                    getline(cin, idSucursal);
                    editarSucursal(idSucursal);
                    break;

                case 3:
                    cout << "Digite el numero de la sucursal\n";
                    getline(cin, idSucursal);
                    aux = sucursales->getSucursalEspecifica(idSucursal);
                    if (aux == nullptr) {
                        cout << "No se encontro la sucursal\n";
                    } else {
                        cout << aux->getDato()->toString();
                    }
                    cin.get();
                    break;

                case 4:
                    system("CLEAR");
                    cout << "\t\tSucursales\n" << sucursales->toString();
                    cin.get();
                    break;

                case 5:
                    cout << "Digite el numero de la sucursal a eliminar\n";
                    getline(cin, idSucursal);
                    if (sucursales->eliminar(idSucursal) == true) {
                        cout << "Se borro correctamente\n";
                    } else {
                        cout << "No se encontro\n";
                    }
                    cin.get();
                    break;
            }
        } catch (...) {
        }
    } while (opc != "77");
}

void Controladora::editarSucursal(string id) {
    NodoSucursal *aux = sucursales->getSucursalEspecifica(id);

    if (aux == nullptr) {
        cout << "No se encuentra esa sucursal\n";
        cin.get();
    } else {
        string opc = "";
        string id = "";
        string ubicacion = "";
        do {
            fflush(stdin); //LIMPIAR BUFFER 
            system("clear");

            cout << "\t\t\tMenu editar Sucursal\n";
            cout << "Digite la opcion que desee ejecutar\n";
            cout << " 1 - Editar ID\n";
            cout << " 2 - Editar Ubicacion\n";
            cout << " 3 - Editar Cajero\n";
            cout << " 4 - Editar ColaClientes\n";
            cout << " 5 - Editar Lista de Secciones\n";
            cout << "77 - SALIR \n";
            cout << "Opcion:  ";
            getline(cin, opc);

            try {
                if (opc != "1" && opc != "2" && opc != "3" && opc != "4" && opc != "5" && opc != "77") {
                    throw opc;
                }
                switch (stoi(opc)) {
                    case 1:
                        cout << "Digite el nuevo ID de la sucursal:   ";
                        getline(cin, id);
                        aux->getDato()->setId(id);
                        break;

                    case 2:
                        cout << "Digite la nueva ubicacion de la sucursal:   ";
                        getline(cin, ubicacion);
                        aux->getDato()->setUbicacion(ubicacion);
                        break;

                    case 3:
                        editarCajeroSucursal(aux->getDato()->getCajero());
                        break;

                    case 4:
                        editarColaClientes(aux->getDato()->getClientes());
                        break;

                    case 5:
                        editarListaSecciones(aux);
                        break;
                }
            } catch (...) {
            }
        } while (opc != "77");
    }
}

void Controladora::editarCajeroSucursal(PilaCajero * cajero) {
    string opc = "";
    string producto = "";
    do {
        fflush(stdin); //LIMPIAR BUFFER 
        system("clear");

        cout << "\t\t\tMenu editar cajero\n";
        cout << "Digite la opcion que desee ejecutar\n";
        cout << " 1 - Agregar un producto\n";
        cout << " 2 - Eliminar un producto\n";
        cout << "77 - SALIR \n";
        cout << "Opcion:  ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "77") {
                throw opc;
            }
            switch (stoi(opc)) {
                case 1:
                    cout << "Digite el producto que desea agregar al cajero:   ";
                    getline(cin, producto);
                    cajero->agregar(producto);
                    break;

                case 2:fflush(stdin); //LIMPIAR BUFFER 
                    system("clear");
                    cout << "Eliminando: " << cajero->eliminarTop();
                    cin.get();
                    break;
            }
        } catch (...) {
        }
    } while (opc != "77");
}

void Controladora::editarColaClientes(ColaCliente* cola) {
    string opc = "";
    PilaCarrito *carrito = new PilaCarrito;
    Cliente *nuevoCliente = new Cliente(carrito);

    do {
        fflush(stdin); //LIMPIAR BUFFER 
        system("clear");

        cout << "\t\t\tMenu editar cola de clientes\n";
        cout << "Digite la opcion que desee ejecutar\n";
        cout << " 1 - Agregar un cliente a la cola\n";
        cout << " 2 - Eliminar un cliente de la cola\n";
        cout << " 3 - Ver los carritos de los clientes\n";
        cout << "77 - SALIR \n";
        cout << "Opcion:  ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "3" && opc != "77") {
                throw opc;
            }
            switch (stoi(opc)) {
                case 1:
                    agregarCliente(cola);
                    break;

                case 2:
                    system("CLEAR");
                    if (cola->colaVacia()) {
                        cout << "No hay cliente" << endl;
                    } else {
                        //cout << cola->eliminarTop();
                        cout << cola->getTop().toString();
                        cola->pop();
                    }
                    cin.get();
                    break;

                case 3:
                    system("CLEAR");
                    cout << cola->toString();
                    cin.get();
                    break;
            }
        } catch (...) {
        }
    } while (opc != "77");
}

void Controladora::agregarCliente(ColaCliente* cola) {
    string opc = "";
    string producto = "";
    int cantidad = 0;
    PilaCarrito *carrito = new PilaCarrito();
    Cliente *nuevo = new Cliente(carrito);
    do {
        fflush(stdin); //LIMPIAR BUFFER 
        system("clear");

        cout << "\t\t\tMenu editar cliente\n";
        cout << "Digite la opcion que desee ejecutar\n";
        cout << " 1 - Agregar un producto al carrito\n";
        cout << " 2 - Ver carrito\n";
        cout << " 3 - Eliminar un producto del carrito\n";
        cout << "77 - SALIR \n";
        cout << "Opcion:  ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "3" && opc != "77") {
                throw opc;
            }
            switch (stoi(opc)) {
                case 1:
                    cout << "Digite el producto que desea agregar:   ";
                    getline(cin, producto);

                    cout << "Digite la cantidad que desea agregar:   ";
                    cin >> cantidad;
                    cin.ignore();

                    for (int i = 0; i < cantidad; i++) {
                        nuevo->getCarrito()->agregar(producto);
                    }
                    break;

                case 2:
                    system("CLEAR");
                    cout << nuevo->getCarrito()->toString();
                    cin.get();
                    break;

                case 3:
                    system("CLEAR");
                    cout << "Eliminando: " << nuevo->getCarrito()->eliminarTop();
                    cin.get();
                    break;

                case 77:
                    cola->agregar(nuevo); //AGREGAR EL CLIENTE CON LOS PRODUCTOS
                    break;
            }
        } catch (...) {
        }
    } while (opc != "77");

}

void Controladora::editarListaSecciones(NodoSucursal * aux) {
    string opc = "";

    list<Seccion> *secciones = aux->getDato()->getSecciones();

    do {
        int numero = 0;
        string nombre = "";
        fflush(stdin); //LIMPIAR BUFFER 
        system("clear");

        cout << "\t\t\tMenu editar Lista de Secciones\n";
        cout << "Digite la opcion que desee ejecutar\n";
        cout << " 1 - Agregar una Seccion\n";
        cout << " 2 - Eliminar un Seccion\n";
        cout << " 3 - Ver los secciones\n";
        cout << "77 - SALIR \n";
        cout << "Opcion:  ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "3" && opc != "77") {
                throw opc;
            }
            switch (stoi(opc)) {
                case 1:
                    cout << "Digite el numero de la seccion:   ";
                    cin>>numero;
                    cin.ignore();

                    cout << "Digite el nombre de la seccion:   ";
                    getline(cin, nombre);

                    agregarSeccion(numero, nombre, secciones);
                    break;

                case 2:
                    cout << secciones->front().toString();
                    secciones->pop_front();
                    cin.get();
                    break;

                case 3:
                    cout << aux->getDato()->toStringSecciones(*secciones);
                    cin.get();
                    break;
            }
        } catch (...) {
        }
    } while (opc != "77");
}

void Controladora::agregarSeccion(int numero, string nombre, list<Seccion> *secciones) {
    string opc = "";
    ListaProducto *listaP = new ListaProducto();

    do {
        Seccion nuevaSeccion(numero, nombre, listaP);
        PilaProducto *pilaProductos = new PilaProducto();
        string producto = "";
        int cantidad = 0;
        fflush(stdin); //LIMPIAR BUFFER 
        system("clear");

        cout << "\t\t\tMenu editar Lista de Productos\n";
        cout << "Digite la opcion que desee ejecutar\n";
        cout << " 1 - Agregar una producto a la pila\n";
        cout << " 2 - Eliminar un producto a la pila\n";
        cout << " 3 - Ver los productos de la pila\n";
        cout << "77 - SALIR \n";
        cout << "Opcion:  ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "3" && opc != "77") {
                throw opc;
            }
            switch (stoi(opc)) {
                case 1:
                    cout << "Digite el producto que desea agregar:   ";
                    getline(cin, producto);

                    cout << "Digite la cantidad que desea agregar:   ";
                    cin >> cantidad;
                    cin.ignore();

                    for (int i = 0; i < cantidad; i++) {
                        pilaProductos->agregar(producto);
                    }

                    listaP->insertarPrimero(pilaProductos);

                    break;

                case 2:
                    cout << "Digite el producto que desea eliminar de la lista de productos\n";
                    getline(cin, producto);
                    if (listaP->eliminarTop(producto)) {
                        cout << "Eliminado correctamente\n";
                    } else {
                        cout << "No se encuentra ese producto\n";
                    }
                    cin.get();
                    break;

                case 3:
                    cout << listaP->toString();
                    cin.get();
                    break;

                case 77:
                    secciones->push_front(nuevaSeccion);
                    break;
            }
        } catch (...) {
        }
    } while (opc != "77");
}

//-----------------------------CLIENTE---------------------------------------------

void Controladora::menuCliente() {
    string opc = "";
    string id = "";
    do {
        fflush(stdin);
        system("clear");

        cout << "\t\tBienvenido a menu cliente\n\n";
        cout << "1 - Seleccione la sucursal\n";
        cout << "77 - SALIR\n";
        cout << "Opcion digitada:   ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "77") {
                throw opc;
            }

            switch (stoi(opc)) {
                case 1:
                    cout << sucursales->toStringCliente();

                    if (sucursales->getCabeza() == nullptr) {
                        cin.get();
                    }

                    if (sucursales->getCabeza() != nullptr) {
                        cout << "Digite el numero de la sucursal:   ";
                        getline(cin, id);

                        NodoSucursal *aux = sucursales->getSucursalEspecifica(id);

                        if (aux != nullptr) {
                            subMenu(aux);
                        }
                    }
                    break;
            }
        } catch (...) {
        }

    } while (opc != "77");
}

void Controladora::subMenu(NodoSucursal *aux) {
    string opc = "";
    int numero = 0;

    do {
        fflush(stdin);
        system("clear");

        cout << "\t\tMenu de secciones\n\n";
        cout << "1 - Seleccione la seccion\n";
        cout << "77 - SALIR\n";
        cout << "Opcion digitada:   ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "77") {
                throw opc;
            }

            switch (stoi(opc)) {
                case 1:
                    cout << aux->getDato()->toStringSeccionesCliente(*aux->getDato()->getSecciones()) << "\n";

                    if (!aux->getDato()->getSecciones()->empty()) {
                        cout << "Digite el numero de la seccion:   ";
                        cin>>numero;
                        cin.ignore();

                        ListaProducto *listaP = new ListaProducto();
                        Seccion auxS(0, "", listaP);
                        auxS = seccionEspecifica(*aux->getDato()->getSecciones(), numero);

                        if (auxS.getNumero() != -1) {
                            menuProductos(auxS);
                            cin.get();
                        } else {
                            cout << "La seccion no se encuentra en esta sucursal\n";
                        }

                    }
                    cin.get();
                    break;
            }
        } catch (...) {
        }

    } while (opc != "77");
}

Seccion Controladora::seccionEspecifica(list<Seccion> lista, int numero) {
    ListaProducto *listaP = new ListaProducto();
    Seccion auxS(-1, "", listaP);

    while (!lista.empty()) {

        if (lista.front().getNumero() == numero) {
            auxS = lista.front();
            return auxS;
        }
        lista.pop_front();
    }
    return auxS;
}

void Controladora::menuProductos(Seccion secciones) {
    string opc = "";
    string producto = "";
    int cantProductos = 0;
    ListaProducto *lista = secciones.getProductos();
    NodoProducto *auxNodo = lista->getCabeza();

    do {
        fflush(stdin);
        system("clear");

        cout << "\t\tMenu de seccion especifica\n\n";
        cout << "1 - Seleccione el producto\n";
        cout << "77 - SALIR\n";
        cout << "Opcion digitada:   ";
        getline(cin, opc);

        try {
            if (opc != "1" && opc != "2" && opc != "77") {
                throw opc;
            }

            switch (stoi(opc)) {
                case 1:
                    cout << lista->toString();

                    if (lista->getCabeza()->getDato()->getTop() != "") {
                        cout << "Digite el producto que desee agregar al carrito" << endl;
                        getline(cin, producto);
                        cout << "Digite la cantidad de productos" << endl;
                        cin>>cantProductos;
                        productoEspecifico(producto, lista, cantProductos);
                    } else {
                        cout << "\tLa pila esta vacia\n";
                    }
                    cin.get();
                    break;

                case 2:
                    cout << "\t\tCARRITO CLIENTE: \n" << carritoCliente->toString();
                    cin.get();
                    break;
            }
        } catch (...) {
        }

    } while (opc != "77");
}

void Controladora::productoEspecifico(string producto, ListaProducto *lista, int cantProducto) {
    NodoProducto *cabeza = lista->getCabeza();
    string productoCarrito = "";
    int contador = 0;
    while (cabeza != nullptr) {

        if (cabeza->getDato()->getTop() == producto) {
            for (int i = 0; i < cantProducto; i++) {
                if (cabeza->getDato()->pilaVacia() == false) {
                    //productoCarrito = cabeza->getDato()->eliminarTop();
                    productoCarrito = cabeza->getDato()->getTop();
                    cabeza->getDato()->Pop();
                    carritoCliente->agregar(productoCarrito);
                    contador++;
                }
            }
            cout << productoCarrito << " se agrego al carrito " << contador << " veces" << endl;
        }
        cabeza = cabeza->getSig();
    }
}