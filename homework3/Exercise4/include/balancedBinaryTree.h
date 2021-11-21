#ifndef BALANCEDBINARYTREE_H
#define BALANCEDBINARYTREE_H
#include <string>

class BBTNode {
private:
    std::string m_data{};
    BBTNode *m_rightChild{}, *m_leftChild{}, *m_parent{};
    int m_height{}, m_balanceFactor{};
    bool isRootNode{};
public:
    BBTNode(const std::string data, BBTNode* parent = 0): m_data{data}, m_parent{parent}{
        if(!m_parent)
            isRootNode = true;
    }

    void addNode(const std::string data);

    int retrieveHeight();
    void retrieveBalanceFactor();

    bool search(const std::string word);
};

#endif