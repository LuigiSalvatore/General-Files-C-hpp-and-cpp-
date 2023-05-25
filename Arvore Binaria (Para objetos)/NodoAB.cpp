#include <iostream>
using namespace std;

#include "NodoAB.hpp"

NodoAB::NodoAB(Object object)
{
  left = nullptr;
  right = nullptr;
  father = nullptr;
  obj = object;
#ifdef DEBUG
  cout << "|+|  |NodoAB Criado|"
#endif
}
NodoAB::~NodoAB()
{
#ifdef DEBUG
  cout << "|-|  |NodoAB Destruido|"
#endif
}

void NodoAB::print()
{
  cout << "Nodo: " << obj << endl;
  cout << "\tEsq: ";
  if (left != nullptr)
    cout << left->obj;
  else
    cout << "NULL";
  cout << endl;

  cout << "\tDir: ";
  if (right != nullptr)
    cout << right->obj;
  else
    cout << "NULL";
  cout << endl;
}