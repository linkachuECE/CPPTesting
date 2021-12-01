#include "../include/balancedBinaryTree.h"
#include "../include/lower.h"

void BBTNode::addNode(const std::string data){
    retrieveBalanceFactor();

    if(m_balanceFactor <= 0){
        if(!m_leftChild)
            m_leftChild = new BBTNode(data, this);
        else
            m_leftChild->addNode(data);
    } else {
        if(!m_rightChild)
            m_rightChild = new BBTNode(data, this);
        else
            m_rightChild->addNode(data);
    }
}

int BBTNode::retrieveHeight(){
    if(!m_leftChild && !m_rightChild)
        m_height = 1;
    else if(m_leftChild && !m_rightChild)
        m_height = m_leftChild->retrieveHeight() + 1;
    else if(!m_leftChild && m_rightChild)
        m_height = m_rightChild->retrieveHeight() + 1;
    else if(m_leftChild && m_rightChild){
        int leftHeight = m_leftChild->retrieveHeight();
        int rightHeight = m_rightChild->retrieveHeight();
        m_height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    }
    return m_height;
}

void BBTNode::retrieveBalanceFactor(){
    int rightHeight{}, leftHeight{};
    if(isRootNode)
        retrieveHeight();
    
    if(m_rightChild)
        rightHeight = m_rightChild->m_height;
    if(m_leftChild)
        leftHeight = m_leftChild->m_height;

    m_balanceFactor = leftHeight - rightHeight;
}

bool BBTNode::search(const std::string word){
    if(m_leftChild)
        if(m_leftChild->search(word))
            return true;
    if(lower(word) == lower(m_data))
        return true;
    if(m_rightChild)
        if(m_rightChild->search(word))
            return true;
    
    return false;
}