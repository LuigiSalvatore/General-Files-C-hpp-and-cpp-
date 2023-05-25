/*
-Luigi Salvatore Bos-mikich
-Programação orientada a objetos - 18/05/2023
*/
#include <string>
#include "Equipe.hpp"

Equipe::Equipe(string a, string n, string nc, string c, string e) : Clube(a, n, nc, c, e)
{
    numPontos = 0;
    numJogos = 0;
    numVitorias = 0;
    numEmpates = 0;
    numDerrotas = 0;
    numGolTomados = 0;
    numGolFeitos = 0;

#ifdef DEBUG
    cout << "|+|   |Classe Equipe Criada|" << endl;
#endif
}
Equipe::~Equipe()
{
#ifdef DEBUG
    cout << "|-|   |Classe Clube Destruida|" << endl;
#endif
}

int Equipe::obtemPontos() { return numPontos; }
int Equipe::obtemJogos() { return numJogos; }
int Equipe::obtemVitorias() { return numVitorias; }
int Equipe::obtemEmpates() { return numEmpates; }
int Equipe::obtemDerrotas() { return numDerrotas; }
int Equipe::obtemGolsTomados() { return numGolTomados; }
int Equipe::obtemGolsFeitos() { return numGolFeitos; }

void Equipe::definePontos(int p) { numPontos = p; }
void Equipe::defineNumJogos(int j) { numJogos = j; }
void Equipe::defineNumVitorias(int v) { numVitorias = v; }
void Equipe::defineNumEmpates(int e) { numEmpates = e; }
void Equipe::defineNumDerrotas(int d) { numDerrotas = d; }
void Equipe::defineGolsTomados(int gt) { numGolTomados = gt; }
void Equipe::defineGolsFeitos(int gf) { numGolFeitos = gf; }
bool Equipe::ganhou(int golsFeitos, int golsTomados)
{
    if (golsFeitos > golsTomados)
        return true;
    else
        return false;
}
bool Equipe::perdeu(int golsFeitos, int golsTomados)
{
    if (golsFeitos < golsTomados)
        return true;
    else
        return false;
}
bool Equipe::empatou(int golsFeitos, int golsTomados)
{
    if (golsFeitos = golsTomados)
        return true;
    else
        return false;
}

void Equipe::registraJogo(int golsFeitos, int golsTomados)
{
    numJogos++;
    numGolTomados += golsTomados;
    numGolFeitos += golsFeitos;
    if (ganhou(golsFeitos, golsTomados))
    {
        numPontos += 3; // para cada vitoria, adiciona 3 pontos
        numVitorias++;  // adiciona mais uma vitoria
    }
    else if (perdeu(golsFeitos, golsTomados))
    {
        numDerrotas++; // adiciona mais uma derrota
    }
    else if (empatou(golsFeitos, golsTomados))
    {
        numPontos += 1; // para cada empate, adiciona 1 ponto
        numEmpates++;   // adiciona mais um empate
    }
}