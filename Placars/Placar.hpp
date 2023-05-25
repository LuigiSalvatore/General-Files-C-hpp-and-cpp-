// Placar feito com ajuda de Bruno Becker Silva

#ifndef _PLACAR_HPP
#define _PLACAR_HPP

#include "Jogador.hpp"
#include "Tabuleiro.hpp"

class Placar
{
private:
    int jogador1, jogador2;

public:
    Placar();
    ~Placar();
    void addJ1();
    // void atualizaPlacar(int j1, int j2);
    string obtemPlacar(Jogador *j1, Tabuleiro *t);
    void obtemPlacarSalvo();
    void escreveArq(string playerName, int playerScore);
};
#endif // PLACAR_HPP