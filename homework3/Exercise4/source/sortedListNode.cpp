#include "../include/sortedListNode.h"
#include "../include/lower.h"
#include <string>
#include <iostream>

SortedListNode SortedListNode::addNode(std::string word){

    std::string l1{lower(word)};
    std::string l2{lower(m_word)};
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;

    if(l1 < l2){
        if(m_previousNode){
            m_previousNode->m_nextNode = new SortedListNode{word, m_previousNode};
            m_previousNode = m_previousNode->m_nextNode;
        } else {
            m_previousNode = new SortedListNode{word};
        }
        m_previousNode->m_nextNode = this;
    } else {
        if(m_nextNode)
            m_nextNode->addNode(word);
        else
            m_nextNode = new SortedListNode{word, this};
    }

    return getRoot();
}

bool SortedListNode::search(std::string word){
    if(word > m_word)
        return false;
    else if(lower(word) == lower(m_word)) 
        return true;
    else if (m_nextNode) 
        return m_nextNode->search(word);
    else
        return false;
}

SortedListNode SortedListNode::getRoot(){
    if(m_previousNode)
        return m_previousNode->getRoot();
    else
        return *this;
}