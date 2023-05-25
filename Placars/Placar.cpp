// Placar feito com ajuda de Bruno Becker Silva

#include "placar.hpp"
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// #define DEBUG

#define TAM 10000

Placar::Placar()
{
  jogador1 = 0;
}

Placar::~Placar() {}

void Placar::addJ1() { jogador1++; }

string Placar::obtemPlacar(Jogador *j1, Tabuleiro *t)
{
  stringstream ss;
  string sAux = j1->getName();
  int iAux = t->getRodadasPercorridas();
  ss << "\n|---VENCEDOR---|" << endl;

  ss << sAux << " venceu em " << iAux << " rodadas!!!" << endl;
  if (!(j1->getName() == "Roland, o deus de Speculate"))
  {
    escreveArq(sAux, iAux);
  }
  ss << "|---VENCEDOR---|" << endl;
  ss << endl;
  ss << "Obrigado por jogar!" << endl;

  return ss.str();
}

struct Player
{
  string name;
  int score;
};

bool comparePlayers(Player p1, Player p2)
{
  return p1.score < p2.score;
}

void Placar::obtemPlacarSalvo()
{
  const int MAX_PLAYERS = 10;
  vector<Player> players;
  string filename = "ranking.txt", sAux = "";
  ifstream file(filename);
  int iAux = 0, i = 1;

  if (file.is_open())
  {
    while (!file.eof() && players.size() < MAX_PLAYERS)
    {
      Player player;
      file >> sAux >> iAux;
      cout << "rank " << i << " --> " << sAux << " Ganhou em " << iAux << " rodadas!" << endl;
      players.push_back(player);
      i++;
      // ss << "rank " << i << " --> " << sAux << " Ganhou em " << iAux << " rodadas!" << endl;
    }
    file.close();
  }
}

void Placar::escreveArq(string playerName, int playerScore)
{
  const int MAX_PLAYERS = 10;
  vector<Player> players;
  string filename = "ranking.txt";

  // Ler os jogadores do arquivo
  ifstream file(filename);
  if (file.is_open())
  {
    while (!file.eof() && players.size() < MAX_PLAYERS)
    {
      Player player;
      file >> player.name >> player.score;
      players.push_back(player);
    }
    file.close();
  }

  // Ordenar os jogadores pelo score
  sort(players.begin(), players.end(), comparePlayers);

  // Adicionar um novo jogador
  Player newPlayer;
  newPlayer.name = playerName;
  newPlayer.score = playerScore;

  if (newPlayer.score < players.back().score)
  {
    players.push_back(newPlayer);
    sort(players.begin(), players.end(), comparePlayers);
    players.pop_back(); // remover o último jogador (o pior do ranking)
    cout << "Adicionado ao ranking, está entre os Top 10!" << endl;
  }
  else
  {
    cout << "O novo jogador não está entre os Top 10." << endl;
  }

  // Escrever a lista atualizada no arquivo
  ofstream outfile(filename);
  if (outfile.is_open())
  {
    for (auto player : players)
    {
      outfile << player.name << " " << player.score << endl;
    }
    outfile.close();
#ifdef DEBUG
    cout << "Arquivo fechado" << endl;
    cout << "A lista tem " << players.size() << " elementos" << endl;
#endif
  }
}