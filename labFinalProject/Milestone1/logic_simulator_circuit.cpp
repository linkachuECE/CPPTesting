#include <iostream>
#include "gates.h"

int circuit1(int a, int b){
    return Or(And(a, b), And(Not(a), Not(b)));
}

int circuit2(int a, int b){
    return Or(And(Not(a), b), And(a, Not(b)));
}

int main(){
    int a, b;
    std::cout << "Enter a value for the first input: ";
    std::cin >> a;
    std::cout << "Enter a value for the second input: ";
    std::cin >> b;

    std::cout << "Output of circuit 1 is: " << circuit1(a, b) << std::endl;
    std::cout << "Output of circuit 2 is: " << circuit2(a, b) << std::endl;

    return 0;
}