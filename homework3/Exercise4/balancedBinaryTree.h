#ifndef BALANCEDBINARYTREE_H
#define BALANCEDBINARYTREE_H
#include <string>

class BBTNode {
private:
    std::string m_data{};
    BBTNode *m_rightChild{}, *m_leftChild{}, *m_parent{};
    int height{};
public:
    BBTNode(std::string data, BBTNode* parent = 0): m_data{data}, m_parent{parent}{}

    bool addNode(std::string data);
};

#endif