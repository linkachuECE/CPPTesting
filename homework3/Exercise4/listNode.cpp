#include "listNode.h"
#include <string>
#include <iostream>

void ListNode::addNode(std::string word){
    if(m_nextNode)
        m_nextNode->addNode(word);
    else
        m_nextNode = new ListNode(word, this);
}

bool ListNode::search(std::string word){
    if(word == m_word) return true;
    else if (m_nextNode) 
        return m_nextNode->search(word);
    else
        return false;
}