#ifndef _ARVBIN
#define _ARVBIN
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

#include "NodoAB.hpp"

class BinaryTreeOfInteger
{
private:
  NodoAB *root;
  int count;

  NodoAB *searchNodoRef(int elem, NodoAB *n);
  int height(NodoAB *n);
  int countNodos(NodoAB *n);
  void removeBranch(NodoAB *n);

public:
  BinaryTreeOfInteger();
  ~BinaryTreeOfInteger();
  bool isEmpty();
  int getRoot();
  int getParent(int element);
  void setRoot(int element);
  bool addRoot(int element);
  bool addLeft(int element, int elemPai);
  bool addRight(int element, int elemPai);
  bool set(int old, int element);
  bool isExternal(int element);
  bool isInternal(int element);
  bool hasLeft(int element);
  bool hasRight(int element);
  int getLeft(int element);
  int getRight(int element);
  int size();
  int height();
  int level(int element);
  bool contains(int elem);
  bool removeBranch(int element);
};
#endif
