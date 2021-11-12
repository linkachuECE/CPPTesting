#ifndef NODE_H
#define NODE_H

class Node{
private:
    int m_data{}, m_distance{}, m_maxHeight{};
    Node *m_rightChild{}, * m_leftChild{}, *m_parent{};
    bool isRootNode{};

public:
    Node(int data, Node* parent = 0): m_data{data}, m_parent{parent}{isRootNode = !parent;}
    ~Node();

    Node* getRightChild() const{return m_rightChild;}
    Node* getLeftChild() const{return m_leftChild;}
    Node* getParent() const{return m_parent;}
    int getData() const{return m_data;}

    void addNode(int data);

    void depthFirstPrint();

    void breadthFirstPrint();
    void printLevel(int level);

    int setDistances(int parentDistance = 0);
};

#endif