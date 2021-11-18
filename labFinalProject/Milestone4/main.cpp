#include <iostream>
#include <fstream>
#include "gates.h"
#include "logic_node.h"
#include "logic_circuit.h"

LogicCircuit* fileReader(char* fileName){
    LogicCircuit* thisCircuit = new LogicCircuit{};
    std::ifstream fReader;
    int iInput{}, index{}, input1{}, input2{}, input3{};
    char cInput{}, lFunction{};

    fReader.open(fileName);

    fReader >> iInput;

    while(!fReader.eof()){
        fReader >> index >> cInput >> lFunction;

        if(toupper(lFunction) != 'I'){
            if(toupper(lFunction) == 'N' || toupper(lFunction) == 'Q')
                fReader >> input1;
            else if(toupper(lFunction) == 'A' || toupper(lFunction) == 'O' || toupper(lFunction) == 'X'){
                fReader >> input1 >> input2;
                if(fReader.peek() != '\n')
                    fReader >> input3;
            }
        }

        if(!input1)
            thisCircuit->addNode(lFunction);
        else if (!input2)
            thisCircuit->addNode(lFunction, input1);
        else if (!input3)
            thisCircuit->addNode(lFunction, input1, input2);
        else
            thisCircuit->addNode(lFunction, input1, input2, input3);
    }

    return thisCircuit;
}

int main(){
    
    LogicCircuit* myCircuit = fileReader("test.txt");

    myCircuit->GetInputs();

    std::cout << std::endl;

    int output = myCircuit->getOutput();

    std::cout << std::endl << "The output of the circuit is: " << output << std::endl;

    return 0;
    
}