#include <string>

class SortedListNode{
private:
    std::string m_word{};
    SortedListNode *m_previousNode{}, *m_nextNode{};
public:
    SortedListNode(std::string word, SortedListNode* previousNode = 0): m_word{word}, m_previousNode{previousNode}{}
    
    SortedListNode addNode(std::string word);
    bool search(std::string word);

    SortedListNode getRoot();
};