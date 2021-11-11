#ifndef HEADNODE_H
#define HEADNODE_H
#include "dataNode.h"
#include "Node.h"

class HeadNode: public Node {
private:
    int m_length{}, m_height{};

public:
    HeadNode(int length, int height): 
    m_length{length}, 
    m_height{height}{}

    int getLength() const{return m_length;}
    int getHeight() const{return m_height;}
    DataNode* getNext() const{return dynamic_cast<DataNode*>(Node::m_nextNode);}
};

#endif