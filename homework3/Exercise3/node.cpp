#include "node.h"
#include <iostream>
#include <algorithm>

void Node::wordInsert(std::string data){
    if(lower(data) < lower(m_data)){
        if (m_leftChild)
            m_leftChild->wordInsert(data);
        else{
            m_leftChild = new Node(data, this);
            m_leftChild->isLeftChild = true;
        }
    } else {
        if (m_rightChild)
            m_rightChild->wordInsert(data);
        else{
            m_rightChild = new Node(data, this);
            m_rightChild->isRightChild = true;
        }
    }
}

bool Node::depthFirstSearch(std::string searchWord){
    if(lower(searchWord) == lower(m_data))
        return true;
    else if(lower(searchWord) < lower(m_data) && m_leftChild)
        return m_leftChild->depthFirstSearch(searchWord);
    else if(lower(searchWord) > lower(m_data) && m_rightChild)
        return m_rightChild->depthFirstSearch(searchWord);
    else
        return false;
}

void Node::lexographicalPrint(){
    if(m_leftChild)
        m_leftChild->lexographicalPrint();
    else{
        Node* currNode = this;
        while(currNode){
            std::cout << currNode->m_data << " ";
            currNode = currNode->findSuccessor();
        }
        std::cout << std::endl;
    }
}

Node* Node::findSuccessor(){
    Node *currNode{};

    if(isRootNode){
        currNode = m_rightChild;
        while(currNode->m_leftChild)
            currNode = currNode->m_leftChild;
        m_successor = currNode;
    }
    else if(isLeftChild){
        if(m_rightChild){
            currNode = m_rightChild;
            while(currNode->m_leftChild)
                currNode = currNode->m_leftChild;
            m_successor = currNode;
        } else
            m_successor = m_parent;
    } else if (isRightChild){
        if(m_rightChild){
            currNode = m_rightChild;
            while(currNode->m_leftChild)
                currNode = currNode->m_leftChild;
            m_successor = currNode;
        } else {
            currNode = m_parent;
            while(currNode->isRightChild)
                currNode = currNode->m_parent;
            if(currNode->isLeftChild)
                m_successor = currNode->m_parent;
        }
    }

    return m_successor;
}

Node::~Node(){
    if(m_rightChild)
        delete m_rightChild;
    if(m_leftChild)
        delete m_leftChild;
}

std::string Node::lower(std::string s){
    std::transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });

    return s;
}