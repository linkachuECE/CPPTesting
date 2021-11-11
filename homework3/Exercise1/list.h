#ifndef LIST_H
#define LIST_H
#include "dataNode.h"
#include "headNode.h"

class List{
private:
    HeadNode* m_head{};
public:
    List(int length, int height, int* matrix);
    ~List(){if(m_head) delete m_head;}
    void addNode(int x, int y, int data);
    void printList() const;
};

#endif