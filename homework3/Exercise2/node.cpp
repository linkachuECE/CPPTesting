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
    if(isRootNode) setDistances();

    for(int i = 0; i <= m_maxHeight; i++)
        printLevel(i);
}

int Node::setDistances(int parentDistance){
    if(!isRootNode)
        m_distance = parentDistance + 1;

    if(!m_leftChild && !m_rightChild)
        m_maxHeight = 0;
    else if(!m_leftChild && m_rightChild)
        m_maxHeight = m_rightChild->setDistances(m_distance) + 1;
    else if(m_leftChild && !m_rightChild)
        m_maxHeight = m_leftChild->setDistances(m_distance) + 1;
    else{
        int leftMax = m_leftChild->setDistances(m_distance);
        int rightMax = m_rightChild->setDistances(m_distance);
        m_maxHeight = ((leftMax > rightMax) ? leftMax : rightMax) + 1;
    }

    return m_maxHeight;
}

void Node::printLevel(int level){
    if (m_distance == level)
        std::cout << m_data << ", ";
    else{
        if(m_leftChild)
            m_leftChild->printLevel(level);
        if(m_rightChild)
            m_rightChild->printLevel(level);
    }
}

Node::~Node(){
    if(m_rightChild)
        delete m_rightChild;
    if(m_leftChild)
        delete m_leftChild;
}