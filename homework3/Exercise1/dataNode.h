#ifndef DATANODE_H
#define DATANODE_H
#include <iostream>
#include "Node.h"

class DataNode: public Node{
private:
    int m_x{}, m_y{}, m_data{};

public:
    DataNode(int x, int y, int data): 
    m_x{x}, 
    m_y{y}, 
    m_data{data}{}

    int getX() const{return m_x;}
    int getY() const{return m_y;}
    int getData() const{return m_data;}
    DataNode* getNext() const{return dynamic_cast<DataNode*>(Node::m_nextNode);}
    friend std::ostream& operator<<(std::ostream& out, const DataNode& node);
};

#endif