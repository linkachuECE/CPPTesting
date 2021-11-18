#include "gates.h"
#include "logic_node.h"
#include "logic_circuit.h"

void LogicCircuit::addNode(const char logicFunction, int input1, int input2, int input3){
    if(!input1)
        m_NodeList.push_back(new Logic_Node(logicFunction));
    else if(!input2)
        m_NodeList.push_back(new Logic_Node(logicFunction, m_NodeList.at(input1 - 1)));
    else if(!input3)
        m_NodeList.push_back(new Logic_Node(logicFunction, m_NodeList.at(input1 - 1), m_NodeList.at(input2 - 1)));
    else
        m_NodeList.push_back(new Logic_Node(logicFunction, m_NodeList.at(input1 - 1), m_NodeList.at(input2 - 1), m_NodeList.at(input3 - 1)));
}

int LogicCircuit::getOutput(){
    return m_NodeList.back()->getInput();
}

void LogicCircuit::GetInputs(){
    for(auto node : m_NodeList)
        if(node->getInputStatus())
            node->getInput();
}