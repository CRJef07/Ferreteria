#ifndef PILACARRITO_H
#define PILACARRITO_H
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class PilaCarrito {
public:
    PilaCarrito();
    virtual ~PilaCarrito();
    void agregar(string);
    string eliminarTop();
    int getTam();
    string getTop();
    string toString();
private:
    stack<string> pila;
};
#endif /* PILACARRITO_H */

