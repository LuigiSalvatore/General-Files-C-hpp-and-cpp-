// composto de dado e de jogadores.
#ifndef Tabuleiro_hpp
#define Tabuleiro_hpp

#include "Dado.hpp"
#include "Jogador.hpp"

using namespace std;

class Tabuleiro
{
private:
    Dado *dado;
    int rodadasPercorridas;
    bool casa[5];
    int centro;

public:
    Jogador *usuario;    // sem encapsulamento
    Jogador *computador; // sem encapsulamento
    Jogador *ganhador;   // sem encapsulamento

    Tabuleiro(bool Am_I_Bot);              // constructor
    ~Tabuleiro();                          // destructor
    string getJogadorName(Jogador *j);     // returns name of Jogador as string
    string getAName();                     // asks user for a name and resturns it as a string
    Jogador *getUsuario();                 // returns pointer to usuario object
    Jogador *getComputador();              // returns pointer to computador object
    Jogador *getGanhador();                // returns pointer to ganhador object
    void addRodadasPercorridas();          // adds to RodadsPercorridas
    void setGanhadorUsuario();             // define usuario como ganhador
    void setGanhadorComputador();          // define computador como ganhador
    void addBallToCenter();                // adds balls to center
    void addBallToPlayer(Jogador *j);      // adds balls to player
    void ForcePositionTrue(int pos);       // sets position to true
    void ForcePositionFalse(int pos);      // sets position to false
    void removeBallFromPlayer(Jogador *j); // removes balls from player
    int rollDie(int TIME);                 // rolls the die
    int getRodadasPercorridas();           // returns rodadasPercorridas object
    int getCentro();                       // returns centro object
    bool checkForBallInPos(int pos);       // checks if there is a ball in the position
    void manipBall(Jogador *j, int pos);   // manipulates the ball
};
#endif // Tabuleiro_hpp