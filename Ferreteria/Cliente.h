#ifndef CLIENTE_H
#define CLIENTE_H

#include "PilaCarrito.h"

class Cliente {
public:
    Cliente(PilaCarrito*);

    void setCarrito(PilaCarrito*);
    PilaCarrito * getCarrito();

    string toString();

    virtual ~Cliente();
private:
    PilaCarrito *carrito;
};

#endif /* CLIENTE_H */

