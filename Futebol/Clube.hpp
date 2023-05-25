/*
-Luigi Salvatore Bos-mikich
-Programação orientada a objetos - 18/05/2023
*/

#ifndef CLUBE
#define CLUBE
#include <string>
#include <iostream>

using namespace std;

class Clube // base class
{
protected:
    string abreviatura;
    string nome;
    string nomeCompleto;
    string cidade;
    string estado;

public:
    Clube(string a = "", string n = "", string nc = "", string c = "", string e = "");
    ~Clube();

    string obtemAbreviatura();
    string obtemNome();
    string obtemNomeCompleto();
    string obtemCidade();
    string obtemEstado();

    void defineAbreviatura(string a);
    void defineNome(string n);
    void defineNomeCompleto(string nc);
    void defineCidade(string c);
    void defineEstado(string e);
};
#endif // CLUBE