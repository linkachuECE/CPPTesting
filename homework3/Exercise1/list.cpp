#include "list.h"
#include <iostream>
List::List(int length, int height, int* matrix){
    m_head = new HeadNode(length, height);

    for(int i = 0; i < length; i++)
        for(int j = 0; j< height; j++)
            if(*((matrix+i*height) + j))
                addNode(i, j, *((matrix+i*height) + j));
}

void List::addNode(int x, int y, int data){
    m_head->createNextNode(x, y, data);
}

void List::printList() const{
    DataNode* currNode = m_head->getNext();
    std::cout << "Dimensions of matrix: " << m_head->getLength() << "x" << m_head->getHeight() << std::endl;
    std::cout << std::endl;

    std::cout << "Points of interest:" << std::endl;
    while(currNode){
        std::cout << *currNode << std::endl;
        currNode = currNode->getNext();
    }
}