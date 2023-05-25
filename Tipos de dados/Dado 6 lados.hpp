// composto por int face;
#ifndef dado_hpp
#define dado_hpp

#include <thread>
#include <chrono>
#include <time.h>
#include <windows.h>
// #include <unistd.h>
#include <iostream>

using namespace std;

class Dado
{
private:
public:
    Dado();
    int rolarDado(int TIME);
};

#endif // dado_hpp
