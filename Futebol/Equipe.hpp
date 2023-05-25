/*
-Luigi Salvatore Bos-mikich
-Programação orientada a objetos - 18/05/2023
*/
#ifndef EQUIPE
#define EQUIPE
#include <string>
#include <iostream>
#include "Clube.hpp"

using namespace std;

class Equipe : public Clube // sub class
{
private:
    int numPontos;
    int numJogos;
    int numVitorias;
    int numEmpates;
    int numDerrotas;
    int numGolTomados;
    int numGolFeitos;

public:
    Equipe(string a = "", string n = "", string nc = "", string c = "", string e = "");
    ~Equipe();

    int obtemPontos();
    int obtemJogos();
    int obtemVitorias();
    int obtemEmpates();
    int obtemDerrotas();
    int obtemGolsTomados();
    int obtemGolsFeitos();

    void definePontos(int p);
    void defineNumJogos(int j);
    void defineNumVitorias(int v);
    void defineNumEmpates(int e);
    void defineNumDerrotas(int d);
    void defineGolsTomados(int gt);
    void defineGolsFeitos(int gf);

    void registraJogo(int golsFeitos, int golsTomados); // registra um jogo de acordo com quantidade de gols
    bool ganhou(int golsFeitos, int golsTomados);
    bool perdeu(int golsFeitos, int golsTomados);
    bool empatou(int golsFeitos, int golsTomados);
};
#endif // EQUIPE