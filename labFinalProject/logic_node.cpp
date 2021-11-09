#include "logic_node.h"
#include "gates.h"
#include <iostream>

int Logic_Node::inputNo = 1;

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
            m_gateName = "Not gate";
            break;
        
        case 'A':
        case 'a':
            m_logicFunction = gate::And;
            m_gateName = "And gate";
            break;
        
        case 'O':
        case 'o':
            m_logicFunction = gate::Or;
            m_gateName = "Or gate";
            break;
        
        case 'X':
        case 'x':
            m_logicFunction = gate::Xor;
            m_gateName = "Xor gate";
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
    if(!m_isInput){
        std::cout << "Feeding input to " << m_gateName << std::endl;
        if(isNotGate)
            return gate::Not(m_input1->getInput());
        else if(m_isOutput)
            return m_input1->getInput();
        else
            return m_logicFunction(m_input1->getInput(), m_input2->getInput());
    } else {
        if(output == NULL){
            std::cout << "Enter a value for " << m_gateName << ": ";
            std::cin >> output;
        }
        return output;
    }
}