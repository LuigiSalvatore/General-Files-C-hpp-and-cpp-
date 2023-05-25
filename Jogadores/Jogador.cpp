#include "Jogador.hpp"

Jogador::Jogador(bool bot, string n)
{
    numBolas = 15;
    name = n;
    isBot = bot;
    srand(time(NULL));
}

void Jogador::setBalls(int balls2Set) { numBolas = balls2Set; }
void Jogador::removeBall() { numBolas--; }
void Jogador::addBall() { numBolas++; }
void Jogador::setNameJogador(string n) { name = n; }
bool Jogador::isPlayerBot() { return isBot; }
int Jogador::getNumBallsOfJogador() { return numBolas; }
string Jogador::getName() { return name; }
int Jogador::quantasVezesJogar()
{
    int aux;
    if (isBot)
    {
        aux = (rand() % numBolas) + 1;
        cout << "|" << name << "|, com sua sabedoria incomparavel decidiu jogar o dado " << aux << " vezes!" << endl;
        cout << endl;
        return aux;
    }
    cout << "Quantas vezes voce quer jogar o dado? (de 1 a " << numBolas << ")" << endl;
    cin >> aux;
    while (aux > numBolas || aux <= 0)
    {
        cout << "Por favor informe um valor de 1 a " << numBolas << ")" << endl;
        cin >> aux;
    }
    return aux;
}