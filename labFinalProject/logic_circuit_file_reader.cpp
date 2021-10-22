#include <iostream>
#include <fstream>
#include "gates.h"
#include "logic_node.h"
#include "logic_circuit.h"

int main(){
    LogicCircuit myCircuit{};
    myCircuit.addNode('I');
    myCircuit.addNode('I');
    myCircuit.addNode('N', 2);
    myCircuit.addNode('A', 1, 3);
    myCircuit.addNode('O', 1, 4);
    myCircuit.addNode('X', 5, 3);
    myCircuit.addNode('Q', 6);

    std::cout << myCircuit.getOutput() << std::endl;
}