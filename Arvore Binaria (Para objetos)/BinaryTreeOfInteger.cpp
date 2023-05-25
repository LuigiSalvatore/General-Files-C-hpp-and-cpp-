#include <iostream>
#include <cstdlib>
using namespace std;

#include "BinaryTreeOfInteger.hpp"

BinaryTreeOfInteger::BinaryTreeOfInteger()
{
    root = NULL;
    count = 0;
#ifdef DEBUG
    cout << "|+|  |BinaryTree Criada|"
#endif
}
BinaryTreeOfInteger::~BinaryTreeOfInteger(){
#ifdef DEBUG
    cout << "|-|  |BinaryTree Destruida|"
#endif
}

// Metodo que procura por element a partir de n
// e retorna a referencia para o nodo no qual elem esta
// armazenado.
NodoAB *BinaryTreeOfInteger::searchNodoRef(int elem, NodoAB *n)
{
    if (n == NULL)
        return NULL;

    // Visita a raiz
    if (elem == n->element)
        return n;

    // Visita a subarvore da esquerda
    NodoAB *aux = searchNodoRef(elem, n->left);

    // Se nao encontrou, visita a subarvore da direita
    if (aux == NULL)
        aux = searchNodoRef(elem, n->right);

    return aux;
}

// Metodo que calcula a altura da arvore
int BinaryTreeOfInteger::height()
{
    if (root == NULL)
        return 0;
    return height(root);
}

// Metodo que calcula a altura da subarvore
// que comeca no nodo 'n'
int BinaryTreeOfInteger::height(NodoAB *n)
{
    if (n->left == NULL && n->right == NULL)
        return 0;
    int h = 0;
    if (n->left != NULL)
    { // verifica altura da subarvore da esquerda
        int alt = height(n->left);
        if (alt > h)
            h = alt;
    }
    if (n->right != NULL)
    { // verifica altura da subarvore da direita
        int alt = height(n->right);
        if (alt > h)
            h = alt;
    }
    return 1 + h;
}

// Conta o numero de nodos a partir de "n"
int BinaryTreeOfInteger::countNodos(NodoAB *n)
{
    if (n == NULL)
        return 0;
    else
        return 1 + countNodos(n->left) + countNodos(n->right);
}

// Verifica se a arvore esta vazia ou nao.
bool BinaryTreeOfInteger::isEmpty()
{
    return (root == NULL);
}

// Retorna o elemento armazenado na raiz da arvore
int BinaryTreeOfInteger::getRoot()
{
    if (isEmpty())
    {
        throw 0;
    }
    return root->element;
}

// Retorna quem e o elemento pai do elemento passado por parametro.
int BinaryTreeOfInteger::getParent(int element)
{
    NodoAB *aux = searchNodoRef(element, root);

    if (aux == NULL) // Se nao achou element
        throw 0;

    if (aux == root) // se element estiver na raiz
        throw 0;

    return aux->father->element;
}

// Altera o elemento da raiz da arvore.
void BinaryTreeOfInteger::setRoot(int element)
{
    if (root != NULL)
        root->element = element;
}

// Insere o elemento como raiz da arvore, se a arvore estiver vazia
// retorna true em caso de sucesso
bool BinaryTreeOfInteger::addRoot(int element)
{
    if (root != NULL) // se a arvore nao estiver vazia
        return false;
    root = new NodoAB(element);
    count++;
    return true;
}

// Insere element a esquerda de elemFather (retorna true).
// Se nao encontrar father,
// ou se father ja tiver um filho a esquerda, element nao e
// inserido (retorna false)
bool BinaryTreeOfInteger::addLeft(int element, int elemFather)
{
    NodoAB *aux = searchNodoRef(elemFather, root);

    if (aux == NULL) // Se nao encontrou elemFather
        return false;

    if (aux->left != NULL) // Se elemFather ja tem filho a esquerda
        return false;

    // Se tudo "ok", insere o elemento
    NodoAB *n = new NodoAB(element);
    n->father = aux;
    aux->left = n;
    count++;
    return true;
}

// Insere element a direita de elemFather (retorna true).
// Se nao encontrar father,
// ou se father ja tiver um filho a direita, element nao e
// inserido (retorna false)
bool BinaryTreeOfInteger::addRight(int element, int elemFather)
{
    /* COMPLETE */
    return false;
}

// Troca um elemento da arvore pelo elemento passado por parametro.
// retorna true se fez a troca, false caso contrario
bool BinaryTreeOfInteger::set(int old, int element)
{
    /* COMPLETE */
    return false;
}

// Verifica se element esta ou nao armazenado na arvore
bool BinaryTreeOfInteger::contains(int elem)
{
    NodoAB *nAux = searchNodoRef(elem, root);
    return (nAux != NULL);
}

// Retorna true se element esta armazenado em um nodo externo.
// retorna true se element esta em um nodo externo.
bool BinaryTreeOfInteger::isExternal(int element)
{
    /* COMPLETE */
    return 0;
}

// Retorna true se element esta armazenado em um nodo interno.
// retorna true se element esta em um nodo interno.
bool BinaryTreeOfInteger::isInternal(int element)
{
    /* COMPLETE */
    return 0;
}

// Retorna true se element tem um filho a esquerda.
// retorna true se element tem um filho a esquerda, false caso contrario.
bool BinaryTreeOfInteger::hasLeft(int element)
{
    /* COMPLETE */
    return 0;
}

// Retorna true se element tem um filho a direita.
// retorna true se element tem um filho a direita, false caso contrario.
bool BinaryTreeOfInteger::hasRight(int element)
{
    /* COMPLETE */
    return 0;
}

// Retorna o filho a esquerda de element.
// retorna o filho a esquerda, ou null se nao tiver filho a esquerda.
int BinaryTreeOfInteger::getLeft(int element)
{
    /* COMPLETE */
    return 0;
}

// Retorna o filho a direita de element.
// retorna o filho a direita, ou null se nao tiver filho a direita.
int BinaryTreeOfInteger::getRight(int element)
{
    /* COMPLETE */
    return 0;
}

// Retorna o total de elementos da arvore.
int BinaryTreeOfInteger::size()
{
    return count;
}

// retorna o nível que um elemento se encontra
int BinaryTreeOfInteger::level(int element)
{
    /* COMPLETE */
    return 0;
}

// Remove um galho da arvore a partir do elemento recebido por parametro.
void BinaryTreeOfInteger::removeBranch(NodoAB *n)
{
    // Remove a subarvore da esquerda
    if (n->left != NULL)
        removeBranch(n->left);

    // Remove a subarvore da direita
    if (n->right != NULL)
        removeBranch(n->right);
    // Neste ponto 'n' não tem mais filhos, por isto pode ser removido

    delete n; // Apaga o nodo da memória
}

// Remove um galho da arvore a partir do elemento recebido por parametro.
bool BinaryTreeOfInteger::removeBranch(int element)
{
    if (root == NULL) // se a arvore estiver vazia
        return false;

    // Verifica se element esta na raiz
    if (root->element == element)
    {
        // PINHO
        removeBranch(root);
        count = 0;
        root = NULL;
        return true;
    }

    NodoAB *aux = searchNodoRef(element, root);

    // Se nao encontrou element
    if (aux == NULL)
        return false;

    // Se encontrou, faz a remocao do galho
    count = count - countNodos(aux); // atualizar o count
    NodoAB *father = aux->father;    // referencia para o pai
    if (aux == father->left)         // se for para remover subarvore da esquerda
        father->left = NULL;
    else
        father->right = NULL;
    // PINHO
    removeBranch(aux);
    return true;
}
