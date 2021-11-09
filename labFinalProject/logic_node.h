#ifndef LOGIC_NODE_H
#define LOGIC_NODE_H
#include <functional>
#include <string>

class Logic_Node{
private:
    Logic_Node *m_input1{}, *m_input2{};
    bool m_isInput{}, m_isOutput{}, isNotGate{};
    int output = NULL;
    std::string m_gateName{};
    static int inputNo;
    std::function<bool(bool, bool)> m_logicFunction{};
public:
    Logic_Node(const char logicFunction,
                Logic_Node* input1 = nullptr, 
                Logic_Node* input2 = nullptr);
    
    void determineLogicFunction(const char logicFunction);
    void tieInput(Logic_Node& input);
    int getInput();
    std::string getGateName(){return m_gateName;}
};

#endif