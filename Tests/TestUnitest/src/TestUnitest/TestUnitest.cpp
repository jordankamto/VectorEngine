#include <Unitest/Unitest.h>
#include <iostream>
#include <cassert>
#include <Logger/Log.h>

#define logger logger__.Source()
Logger logger__("TestUnitest");

int abs(int x){
    if(x >= 0) return x;
    else return -x;
}

int main () {

    logger.AddTarget(std::make_unique<ConsoleLogger>());
    logger.Assert(abs(-5) == 5, "Erreur critique dans le module {0} : code {1}", "auth", -1);
    assert( abs(-5) == 5 );
}