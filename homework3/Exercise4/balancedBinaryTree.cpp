#include "balancedBinaryTree.h"

bool BBTNode::addNode(std::string data){
    if(isRootNode)
        m_height = retrieveHeight();
        
    if(!m_leftChild)
        m_leftChild = new BBTNode(data, this);
    else if (!m_rightChild)
        m_rightChild = new BBTNode(data, this);
}

int BBTNode::retrieveHeight(){
    if(!m_leftChild && !m_rightChild)
        m_height = 0;
    else if(m_leftChild && !m_rightChild)
        m_height = m_leftChild->retrieveHeight() + 1;
    else if(!m_leftChild && m_rightChild)
        m_height = m_rightChild->retrieveHeight() + 1;
    else if(m_leftChild && m_rightChild){
        int leftHeight = m_leftChild->retrieveHeight();
        int rightHeight = m_rightChild->retrieveHeight();
        m_height = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    }
    return m_height;
}