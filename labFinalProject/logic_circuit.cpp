#include "gates.h"
#include "logic_node.h"
#include "logic_circuit.h"

void LogicCircuit::addNode(const char logicFunction, int input1, int input2){
    if(!input1)
        m_NodeList.push_back(Logic_Node(logicFunction));
    else if(!input2)
        m_NodeList.push_back(Logic_Node(logicFunction, &m_NodeList.at(input1 - 1)));
    else
        m_NodeList.push_back(Logic_Node(logicFunction, &m_NodeList.at(input1 - 1), &m_NodeList.at(input2 - 1)));
}

int LogicCircuit::getOutput(){
    return m_NodeList.back().getInput();
}