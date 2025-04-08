#include "pch.h"
#include "Unitest.h"
#include <cassert>

int abs(int x){
    if(x >= 0) return x;
    else return -x;
}

int main () {
    assert( abs(5) == 5 );
    assert( abs(-5) == 5 );
}