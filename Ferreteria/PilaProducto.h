#ifndef PILAPRODUCTO_H
#define PILAPRODUCTO_H
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class PilaProducto {
public:
    PilaProducto();
    virtual ~PilaProducto();
    void agregar(string);
    string eliminarTop();
    void Pop();
    int getTam();
    string getTop();
    string toString();
    bool pilaVacia();
private:
    stack<string> pila;
};
#endif /* PILAPRODUCTO_H */

