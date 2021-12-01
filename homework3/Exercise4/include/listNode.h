#ifndef LISTNODE_H
#define LISTNODE_H
#include <string>

class ListNode{
protected:
    std::string m_word{};
    ListNode *m_previousNode{}, *m_nextNode{};
public:
    ListNode(std::string word, ListNode* previousNode = 0): m_word{word}, m_previousNode{previousNode}{}

    void addNode(std::string word);
    bool search(std::string word);
};

#endif