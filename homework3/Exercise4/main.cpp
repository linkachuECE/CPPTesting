#include "include/balancedBinaryTree.h"
#include "include/binarySearchTreeNode.h"
#include "include/listNode.h"
#include "include/sortedListNode.h"
#include "include/lower.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

bool listNodeSearch(ListNode& root, const std::string searchWord){
    return root.search(searchWord);
}

bool sortedListNodeSearch(SortedListNode& root, const std::string searchWord){
    return root.search(searchWord);
}

bool BBTSearch(BBTNode& root, const std::string searchWord){
    return root.search(searchWord);
}

bool BSTSearch(BSTNode& root, const std::string searchWord){
    return root.depthFirstSearch(searchWord);
}

void listNodeInsertion(ListNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root.addNode(*i);
} 

SortedListNode& sortedListNodeInsertion(SortedListNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root = root.addNode(*i);

    return root;
}

void BBTInsertion(BBTNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root.addNode(*i);
}

void BSTInsertion(BSTNode& root, std::vector<std::string>* list){
    for(auto i = list->begin() + 1; i < list->end(); i++)
        root.wordInsert(*i);
}

std::vector<std::string>* fReader(const std::string filename){
    std::ifstream reader{};
    reader.open(filename);

    std::string currWord{};
    int num{};

    reader >> currWord;
    std::vector<std::string>* list = new std::vector{currWord};

    while(reader >> currWord)
        list->push_back(currWord);

    return list;
}

int main(){
    std::vector<std::string>* list = fReader("key_file_50MB.txt");

    ListNode lNode{list->at(0)};

    time_t begin = time(NULL);

    listNodeInsertion(lNode, list);

    time_t end = time(NULL);

    printf("Time elapsed is %d seconds\n", (end - begin));

    return 0;
}