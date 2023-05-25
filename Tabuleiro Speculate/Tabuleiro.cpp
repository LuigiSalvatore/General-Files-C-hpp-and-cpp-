#include "Tabuleiro.hpp"

using namespace std;

Tabuleiro::Tabuleiro(bool Am_I_Bot)
{
    dado = new Dado();
    usuario = new Jogador(Am_I_Bot, getAName());
    computador = new Jogador(true);
    rodadasPercorridas = 0;
    casa[0] = true;
    casa[1] = false;
    casa[2] = true;
    casa[3] = false;
    casa[4] = true;
    centro = 0;
    ganhador = nullptr;
}
Tabuleiro::~Tabuleiro()
{
    delete dado;
    delete usuario;
    delete computador;
}

// Dado Tabuleiro::getDado() { return dado; }
Jogador *Tabuleiro::getUsuario() { return usuario; }
Jogador *Tabuleiro::getComputador() { return computador; }
Jogador *Tabuleiro ::getGanhador() { return ganhador; }
void Tabuleiro::setGanhadorUsuario() { ganhador = usuario; }
void Tabuleiro::setGanhadorComputador() { ganhador = computador; }
void Tabuleiro::removeBallFromPlayer(Jogador *j) { j->removeBall(); }
void Tabuleiro::addRodadasPercorridas() { rodadasPercorridas++; }
void Tabuleiro::addBallToCenter() { centro++; }
void Tabuleiro::addBallToPlayer(Jogador *j) { j->addBall(); }
void Tabuleiro::ForcePositionTrue(int pos) { casa[pos] = true; }
void Tabuleiro::ForcePositionFalse(int pos) { casa[pos] = false; }
int Tabuleiro::getCentro() { return centro; }
int Tabuleiro::getRodadasPercorridas() { return rodadasPercorridas; }
int Tabuleiro::rollDie(int TIME) { return dado->rolarDado(TIME) - 1; }
string Tabuleiro::getJogadorName(Jogador *j) { return j->getName(); }
string Tabuleiro::getAName()
{
    string aux;
    cout << "Por favor digite um nome: " << endl;
    // getline(cin, aux);
    cin >> aux;
    return aux;
}
bool Tabuleiro::checkForBallInPos(int pos) // true = there is a ball
{
    if (pos != 5)
    {
        return casa[pos];
    }
    return false;
}
void Tabuleiro::manipBall(Jogador *j, int pos)
{
    if (pos == 5)
    {
        addBallToCenter();
        j->removeBall(); // removes ball from player
        cout << "Que sorte! a bola de |" << j->getName() << "| foi para o centro! Bolas no centro: " << getCentro() << endl;
        cout << endl;
    }
    if (pos <= 4)
    {
        switch (checkForBallInPos(pos))
        {
        case true:
            j->addBall();            // adds ball to player
            ForcePositionFalse(pos); // removes ball from position
            cout << "Que azar! a bola de |" << j->getName() << "| caiu na posicao " << pos + 1 << " que ja tinha uma bola! \nAgora esse jogador tem " << j->getNumBallsOfJogador() << " bolas!" << endl;
            cout << endl;
            break;
        case false:
            j->removeBall();        // removes ball from player
            ForcePositionTrue(pos); // add ball to position
            cout << "Que sorte! a bola de |" << j->getName() << "| caiu na posicao " << pos + 1 << " que estava vazia! \nAgora esse jogador tem " << j->getNumBallsOfJogador() << " bolas!" << endl;
            cout << endl;
            break;
        }
    }
}
