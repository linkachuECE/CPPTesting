#include "node.h"
#include "iostream"
#include <sstream>
#include <vector>

Node* createTree(std::vector<int>& data){
    Node* root = new Node(data.front());
    for(auto dataPoint = data.begin() + 1; dataPoint != data.end(); dataPoint++)
        root->addNode(*dataPoint);
    return root;
}

Node* getUserInput(){
    int num{};
    std::string input{};
    std::vector<int> data{};

    std::cout << "Enter a string of space-separated numbers: ";
    getline(std::cin, input);
    std::istringstream ss(input);

    while(ss >> num)
        data.push_back(num);
    
    return createTree(data);
}

int main(){
    Node* root = getUserInput();

    std::cout << "Depth-first search: ";
    root->depthFirstPrint();
    std::cout << std::endl;

    std::cout << "Breadth-first search: ";
    root->breadthFirstPrint();
    std::cout << std::endl;

    return 0;
}