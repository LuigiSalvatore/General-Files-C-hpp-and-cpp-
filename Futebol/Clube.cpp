/*
-Luigi Salvatore Bos-mikich
-Programação orientada a objetos - 18/05/2023
*/
#include <string>
#include <iostream>
#include "Clube.hpp"

using namespace std;

Clube::Clube(string a, string n, string nc, string c, string e)
{
    abreviatura = a;   // Default = ""
    nome = n;          // Default = ""
    nomeCompleto = nc; // Default = ""
    cidade = c;        // Default = ""
    estado = e;        // Default = ""

#ifdef DEBUG
    cout << "|+|   |Classe Clube Criada|" << endl;
#endif
}
Clube::~Clube()
{
#ifdef DEBUG
    cout << "|-|   |Classe Clube Destruida|" << endl;
#endif
}

string Clube::obtemAbreviatura() { return abreviatura; }
string Clube::obtemNome() { return nome; }
string Clube::obtemNomeCompleto() { return nomeCompleto; }
string Clube::obtemCidade() { return cidade; }
string Clube::obtemEstado() { return estado; }

void Clube::defineAbreviatura(string a) { abreviatura = a; }
void Clube::defineNome(string n) { nome = n; }
void Clube::defineNomeCompleto(string nc) { nomeCompleto = nc; }
void Clube::defineCidade(string c) { cidade = c; }
void Clube::defineEstado(string e) { estado = e; }
