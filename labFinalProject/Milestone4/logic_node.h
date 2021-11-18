#ifndef LOGIC_NODE_H
#define LOGIC_NODE_H
#include <functional>
#include <string>

class Logic_Node{
private:
    Logic_Node *m_input1{}, *m_input2{}, *m_input3{};
    bool m_isInput{}, m_isOutput{}, isNotGate{}, m_displayedOutput{};
    int m_output = -1;
    std::string m_gateName{};
    static int inputNo, notGateNo, xorGateNo, andGateNo, orGateNo;
    std::function<bool(bool, bool)> m_2logicFunction{};
    std::function<bool(bool, bool, bool)> m_3logicFunction{};
public:
    Logic_Node(const char logicFunction,
                Logic_Node* input1 = nullptr, 
                Logic_Node* input2 = nullptr,
                Logic_Node* input3 = nullptr);
    
    void determineLogicFunction(const char logicFunction);
    int getInput();
    std::string getGateName() const{return m_gateName;}

    bool getInputStatus() const{return m_isInput;}
};

#endif