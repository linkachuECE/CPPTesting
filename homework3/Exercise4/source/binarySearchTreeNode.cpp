#include "../include/binarySearchTreeNode.h"
#include "../include/lower.h"

void BSTNode::wordInsert(std::string data){
    if(lower(data) < lower(m_data)){
        if (m_leftChild)
            m_leftChild->wordInsert(data);
        else{
            m_leftChild = new BSTNode(data, this);
            m_leftChild->isLeftChild = true;
        }
    } else {
        if (m_rightChild)
            m_rightChild->wordInsert(data);
        else{
            m_rightChild = new BSTNode(data, this);
            m_rightChild->isRightChild = true;
        }
    }
}

bool BSTNode::depthFirstSearch(std::string searchWord){
    if(searchWord == m_data)
        return true;
    else if(searchWord < m_data && m_leftChild)
        return m_leftChild->depthFirstSearch(searchWord);
    else if(searchWord > m_data && m_rightChild)
        return m_rightChild->depthFirstSearch(searchWord);
    else
        return false;
}

BSTNode::~BSTNode(){
    if(m_rightChild)
        delete m_rightChild;
    if(m_leftChild)
        delete m_leftChild;
}