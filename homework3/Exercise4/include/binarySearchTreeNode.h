#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H
#include <string>

class BSTNode{
private:
    std::string m_data{};
    BSTNode *m_rightChild{}, * m_leftChild{}, *m_parent{};
    bool isRootNode{}, isRightChild{}, isLeftChild{};

public:
    BSTNode(std::string data, BSTNode* parent = 0): m_data{data}, m_parent{parent}{isRootNode = !parent;}
    ~BSTNode();

    BSTNode* getRightChild() const{return m_rightChild;}
    BSTNode* getLeftChild() const{return m_leftChild;}
    BSTNode* getParent() const{return m_parent;}
    std::string getData() const{return m_data;}

    void wordInsert(std::string data);

    bool depthFirstSearch(std::string searchWord);
};

#endif