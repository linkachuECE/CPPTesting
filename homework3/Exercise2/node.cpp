#include "node.h"
#include <iostream>

void Node::addNode(int data){
    if(data < m_data){
        if (m_leftChild)
            m_leftChild->addNode(data);
        else
            m_leftChild = new Node(data, this);
    } else {
        if (m_rightChild)
            m_rightChild->addNode(data);
        else
            m_rightChild = new Node(data, this);
    }
}

void Node::depthFirstPrint(){
    std::cout << m_data << ", ";
    if(m_leftChild)
        m_leftChild->depthFirstPrint();
    if(m_rightChild)
        m_rightChild->depthFirstPrint();
}

void Node::breadthFirstPrint(){
    if(isRootNode) retrieveHeight();

    for(int i = m_height; i >= 0; i--)
        printLevel(i);
}

int Node::retrieveHeight(){
    if(!m_leftChild && !m_rightChild)
        m_height = 0;
    else if(m_leftChild && !m_rightChild)
        m_height = m_leftChild->retrieveHeight() + 1;
    else if(!m_leftChild && m_rightChild)
        m_height = m_rightChild->retrieveHeight() + 1;
    else{
        int rightHeight = m_rightChild->retrieveHeight();
        int leftHeight = m_leftChild->retrieveHeight();

        m_height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    }
    return m_height;
}

void Node::printLevel(int level){
    if (m_height == level)
        std::cout << m_data << ", ";
    else{
        if(m_leftChild)
            m_leftChild->printLevel(level);
        if(m_rightChild)
            m_rightChild->printLevel(level);
    }
}