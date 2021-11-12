#ifndef NODE_H
#define NODE_H
#include <string>

class Node{
private:
    std::string m_data{};
    Node *m_rightChild{}, * m_leftChild{}, *m_parent{}, *m_successor{};
    bool isRootNode{}, isRightChild{}, isLeftChild{};

public:
    Node(std::string data, Node* parent = 0): m_data{data}, m_parent{parent}{isRootNode = !parent;}
    ~Node();

    Node* getRightChild() const{return m_rightChild;}
    Node* getLeftChild() const{return m_leftChild;}
    Node* getParent() const{return m_parent;}
    std::string getData() const{return m_data;}

    void wordInsert(std::string data);

    bool depthFirstSearch(std::string searchWord);

    void lexographicalPrint();
    Node* findSuccessor();

    std::string lower(std::string);
};

#endif