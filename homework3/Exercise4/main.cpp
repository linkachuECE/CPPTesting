#include "include/balancedBinaryTree.h"
#include "include/binarySearchTreeNode.h"
#include "include/listNode.h"
#include "include/sortedListNode.h"
#include "include/lower.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

bool sortedListNodeSearch(SortedListNode& root, const std::string searchWord){
    return root.search(searchWord);
}

bool listNodeSearch(ListNode& root, const std::string searchWord){
    return root.search(searchWord);
} 

bool BSTSearch(BSTNode& root, const std::string searchWord){
    return root.depthFirstSearch(searchWord);
}

bool BBTSearch(BBTNode& root, const std::string searchWord){
    return root.search(searchWord);
}

SortedListNode& sortedListNodeInsertion(SortedListNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root = root.addNode(*i);

    return root;
}

void listNodeInsertion(ListNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root.addNode(*i);
} 

void BSTInsertion(BSTNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root.wordInsert(*i);
}

void BBTInsertion(BBTNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root.addNode(*i);
}

std::vector<std::string>* fReader(const std::string filename){
    std::ifstream reader{};
    reader.open(filename);

    std::string currWord{};
    int num{};

    reader >> num >> currWord;
    std::vector<std::string>* list = new std::vector{currWord};

    while(reader >> num >> currWord)
        list->push_back(currWord);

    return list;
}

int main(){
    std::vector<std::string>* list = fReader("test.txt");

    BBTNode bbt{list->at(0)};
    BSTNode bst{list->at(0)};
    ListNode listNode{list->at(0)};
    SortedListNode sortedListNode{list->at(0)};

    BBTInsertion(bbt, list);
    BSTInsertion(bst, list);
    listNodeInsertion(listNode, list);
    sortedListNode = sortedListNodeInsertion(sortedListNode, list);

    return 0;
}