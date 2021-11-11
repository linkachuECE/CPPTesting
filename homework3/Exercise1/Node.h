#ifndef NODE_H
#define NODE_H

class Node {
protected:
    Node* m_nextNode{};
public:
    ~Node(){if(m_nextNode) delete m_nextNode;}
    virtual void createNextNode(int x, int y, int data);
};

#endif