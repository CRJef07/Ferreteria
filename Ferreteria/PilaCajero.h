#ifndef PILACAJERO_H
#define PILACAJERO_H
#include <iostream>
#include <sstream>
#include <stack>
#include <windows.h>
using namespace std;

class PilaCajero {
public:
    PilaCajero();
    virtual ~PilaCajero();
    void agregar(string);
    string eliminarTop();
    int getTam();
    string getTop();
    string toString();
    void pop();
    bool pilaVacia();
private:
    stack<string> pila;
};
#endif /* PILACAJERO_H */
