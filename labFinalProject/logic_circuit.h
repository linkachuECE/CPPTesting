#ifndef LOGIC_CIRCUIT_H
#define LOGIC_CIRCUIT_H
#include <vector>
#include <iostream>
#include "gates.h"
#include "logic_node.h"

class LogicCircuit{
private:
    std::vector<Logic_Node> m_NodeList{};
public:
    LogicCircuit(){}
    void addNode(const char logicFunction, int input1 = 0, int input2 = 0);
    int getOutput();
};

#endif