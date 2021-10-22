#include "gates.h"
#include <iostream>
#include <fstream>
#include "logic_node.h"

int main(){
    Logic_Node input1{'I'};
    Logic_Node input2{'I'};
    Logic_Node andGate{'A'};
    Logic_Node notGate{'N'};

    andGate.tieInput(input1);
    andGate.tieInput(input2);

    notGate.tieInput(andGate);

    std::cout << notGate.getInput() << std::endl;
}