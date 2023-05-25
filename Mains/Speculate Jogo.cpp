#include "Tabuleiro.hpp"
#include "Placar.hpp"
#include <iostream>
using namespace std;

int main()

{
    // start new game
    Placar *placar;
    placar = new Placar;
    Tabuleiro *tabuleiro;
    int escolha, vezesAJogar = 0, counter, TIME = 0;
    string nomeJogador, aux;

    // menu

    cout << "digite sua escolha:" << endl;
    cout << "|1|-> Jogar speculate;" << endl;
    cout << "|2|-> Ver o placar;" << endl;
    cout << "|3|-> Sair do programa;" << endl;
    cout << "|4|-> Testar programa(sem tempo de exec e 2 jogadores bots);" << endl;
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        TIME = 500;
        tabuleiro = new Tabuleiro(false); // is bot?
        break;
    case 2:
        placar->obtemPlacarSalvo();
        delete &placar;
        cin >> aux;
        return 1;
        break;
    case 3:
        cout << "digite alguma coisa para sair do programa" << endl;
        delete &placar;
        cin >> aux;
        return 1;
        break;
    case 4:
        TIME = 0;
        tabuleiro = new Tabuleiro(true); // is bot?
        break;
    default:
        cout << "Escolha invalida, digite alguma coisa para sair do programa" << endl;
        delete &placar;
        cin >> aux;

        return 1;
        break;
    }
    while (tabuleiro->computador->getNumBallsOfJogador() && tabuleiro->usuario->getNumBallsOfJogador() && (escolha == 4 || escolha == 1))
    {
        if (tabuleiro->computador->getNumBallsOfJogador()) // checka a condição de vitoria do computador
        {
            vezesAJogar = tabuleiro->usuario->quantasVezesJogar();
            counter = 1;

            for (vezesAJogar; vezesAJogar > 0; vezesAJogar--, counter++)
            {
#ifdef DEBUG
                cout << counter << "Vez numero-> ";
#endif
                tabuleiro->manipBall(tabuleiro->getUsuario(), tabuleiro->rollDie(TIME));
            }
            if (!tabuleiro->usuario->getNumBallsOfJogador())
            {
                tabuleiro->setGanhadorUsuario();
            }
        }
        if (tabuleiro->usuario->getNumBallsOfJogador()) // checka a condição de vitoria do usuario
        {
            vezesAJogar = tabuleiro->computador->quantasVezesJogar();
            counter = 1;
            for (vezesAJogar; vezesAJogar > 0; vezesAJogar--, counter++)
            {
#ifdef DEBUG
                cout << counter << "Vez numero-> ";
#endif
                tabuleiro->manipBall(tabuleiro->getComputador(), tabuleiro->rollDie(TIME));
            }
            if (!tabuleiro->computador->getNumBallsOfJogador())
            {
                tabuleiro->setGanhadorComputador();
            }
        }
        tabuleiro->addRodadasPercorridas();
    }
    // Mostra quem ganhou
    // cout << "o ganhador foi: " << tabuleiro->getJogadorName(tabuleiro->getGanhador()) << ", que ganhou em " << tabuleiro->getRodadasPercorridas() << " partidas" << endl;

    // PRECISA TA NO FINAL

    cout << placar->obtemPlacar(tabuleiro->getGanhador(), tabuleiro);
    delete &tabuleiro;
    delete &placar;
    cin >> aux;
}
