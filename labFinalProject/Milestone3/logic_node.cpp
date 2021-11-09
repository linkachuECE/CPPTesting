#include "logic_node.h"
#include "gates.h"
#include <iostream>

int Logic_Node::inputNo = 1;
int Logic_Node::notGateNo = 1;
int Logic_Node::xorGateNo = 1;
int Logic_Node::andGateNo = 1;
int Logic_Node::orGateNo = 1;

Logic_Node::Logic_Node(const char logicFunction,
                Logic_Node* input1, 
                Logic_Node* input2): 
                m_input1{input1}, 
                m_input2{input2}{
                    determineLogicFunction(logicFunction);
                }

void Logic_Node::determineLogicFunction(const char c){
    switch (c){
        case 'I':
        case 'i':
            m_logicFunction = nullptr;
            m_isInput = true;
            m_gateName = "Input " + std::to_string(inputNo++);
            break;
        
        case 'Q':
        case 'q':
            m_logicFunction = nullptr;
            m_isOutput = true;
            m_gateName = "Output";
            break;
        
        case 'N':
        case 'n':
            m_logicFunction = nullptr;
            isNotGate = true;
            m_gateName = "NOT gate " + std::to_string(notGateNo++);
            break;
        
        case 'A':
        case 'a':
            m_logicFunction = gate::And;
            m_gateName = "AND gate " + std::to_string(andGateNo++);
            break;
        
        case 'O':
        case 'o':
            m_logicFunction = gate::Or;
            m_gateName = "OR gate " + std::to_string(orGateNo++);
            break;
        
        case 'X':
        case 'x':
            m_logicFunction = gate::Xor;
            m_gateName = "XOR gate " + std::to_string(xorGateNo++);
            break;
    }
}

void Logic_Node::tieInput(Logic_Node& input){
    if(!m_input1){
        m_input1 = &input;
    }
    else if (!m_input2 && !isNotGate){
        m_input2 = &input;
    }
}

int Logic_Node::getInput(){
    if(m_output == -1){
        if(!m_isInput){
            if(isNotGate)
                m_output = gate::Not(m_input1->getInput());
            else if(m_isOutput)
                m_output = m_input1->getInput();
            else
                m_output = m_logicFunction(m_input2->getInput(), m_input1->getInput());
        } else {
            std::cout << "Enter a value for " << m_gateName << " (1 or 0): ";
            std::cin >> m_output;
        }
    }
    if(!m_displayedOutput && !m_isInput){
        std::cout << "Output from " << m_gateName << " is " << m_output << std::endl;
        m_displayedOutput = true;
    }
    return m_output;
}
