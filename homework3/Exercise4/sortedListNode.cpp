#include "sortedListNode.h"
#include <string>

void SortedListNode::addNode(std::string word){
    if(word > m_word){
        m_previousNode->m_nextNode = new SortedListNode{word, m_previousNode};
        m_previousNode = m_previousNode->m_nextNode;
        m_previousNode->m_nextNode = this;
    } else {
        if(m_nextNode)
            m_nextNode->addNode(word);
        else
            m_nextNode = new SortedListNode{word, this};
    }
}

bool SortedListNode::search(std::string word){
    if(word == m_word) return true;
    else if (m_nextNode) 
        return m_nextNode->search(word);
    else
        return false;
}