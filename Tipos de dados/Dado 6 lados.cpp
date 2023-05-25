#include "Dado 6 lados.hpp"
#define MENSAGEM

Dado::Dado()
{
    srand(time(NULL));
}
int Dado::rolarDado(int TIME)
{
#ifdef MENSAGEM
    cout << "O dado foi jogado e caiu em: ";
#endif
    int v = 0;
    // this_thread::sleep_for(std::chrono::seconds(TIME));
    Sleep(TIME);
    v = (rand() % 6) + 1;
#ifdef MENSAGEM
    cout << v << endl;
#endif

    // this_thread::sleep_for(std::chrono::seconds(TIME));
    Sleep(TIME);
    cout << endl;
    return v;
}