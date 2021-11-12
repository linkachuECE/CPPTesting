#include "node.h"
#include "iostream"

int main(){
    Node* root = new Node(2);
    root->addNode(1);
    root->addNode(3);

    root->depthFirstPrint();
    std::cout << std::endl;

    return 0;
}