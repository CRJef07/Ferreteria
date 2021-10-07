#ifndef COLACLIENTE_H
#define COLACLIENTE_H

#include <queue>
#include "Cliente.h"

class ColaCliente {
public:
    ColaCliente();
    virtual ~ColaCliente();
    void agregar(Cliente*);
    Cliente * eliminarTop();
    int getTam();
    Cliente getTop();
    void pop();
    bool colaVacia();
    string toString();
private:
    queue<Cliente> cola;
};

#endif /* COLACLIENTE_H */

