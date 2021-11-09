#include <iostream>
#include <fstream>
#include "gates.h"
#include "logic_node.h"
#include "logic_circuit.h"

int main(){
    LogicCircuit myCircuit{};
    myCircuit.addNode('I');
    myCircuit.addNode('I');
    myCircuit.addNode('A', 1, 2);
    myCircuit.addNode('N', 3);
    myCircuit.addNode('Q', 4);

    std::cout << myCircuit.getOutput() << std::endl;
}