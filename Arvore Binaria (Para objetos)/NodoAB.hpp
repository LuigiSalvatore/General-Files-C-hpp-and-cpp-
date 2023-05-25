#ifndef _NodoAB
#define _NodoAB
#include "Object.hpp" //object class

class NodoAB
{
public:
  Object obj; // object object
  NodoAB *father;
  NodoAB *left;
  NodoAB *right;

  NodoAB(Object obj); // construtor
  ~NodoAB();          // destructor

  void print();
};
#endif
