#ifndef Jogador_hpp
#define Jogador_hpp

#include <string>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Jogador
{

private:
    int numBolas;
    string name;
    bool isBot;

public:
    Jogador(bool bot, string n = "Roland, o deus de Speculate");

    void setBalls(int balls2Set);
    void removeBall();
    void addBall();
    void setNameJogador(string n);

    bool isPlayerBot();
    int getNumBallsOfJogador();
    string getName();
    int quantasVezesJogar();
};
#endif // Jogador_hpp