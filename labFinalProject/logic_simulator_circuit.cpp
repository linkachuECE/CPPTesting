#include <iostream>
#include "gates.h"

using namespace gate;

int circuit1(int a, int b){
    return Or(And(a, b), And(Not(a), Not(b)));
}

int circuit2(int a, int b){
    return Or(And(Not(a), b), And(a, Not(b)));
}