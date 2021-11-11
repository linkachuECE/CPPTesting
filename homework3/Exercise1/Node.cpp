#include "Node.h"
#include "dataNode.h"
#include "headNode.h"

void Node::createNextNode(int x, int y, int data){
    if(m_nextNode)
        m_nextNode->createNextNode(x, y, data);
    else{
        m_nextNode = new DataNode(x, y, data);
    }
}