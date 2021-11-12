#include "node.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

void printFile(std::string filename){
    std::ifstream fReader{};
    fReader.open(filename);

    if(fReader.is_open())
        std::cout << fReader.rdbuf();
    
    std::cout << std::endl;
}

Node* fileReader(const std::string filename){
    std::ifstream fReader{};
    fReader.open(filename);

    std::string currWord{};

    fReader >> currWord;
    Node* root = new Node(currWord);

    while(fReader >> currWord)
        root->wordInsert(currWord);

    return root;
}

std::vector<std::string>* userInput(){
    auto userWords = new std::vector<std::string>{};
    std::string word{};

    std::cout << "Enter three words, separated by spaces: ";
    for(int i = 0; i < 3; i++){
        std::cin >> word;
        userWords->push_back(word);
    }

    return userWords;
}

double searchWords(Node* root, std::vector<std::string>* words){
    int total{};
    for(std::string word : *words)
        total += root->depthFirstSearch(word);

    return total / 3.0;
}

int main(){
    std::string filename{"fairy_tails"};
    std::cout << "Original file:" << std::endl;
    printFile(filename);
    std::cout << std::endl;

    Node* my_words = fileReader("fairy_tails");
    auto user_words = userInput();

    std::cout << std::setprecision(0) << std::fixed << searchWords(my_words, user_words) * 100 << "\% of those words were found" << std::endl << std::endl;

    std::cout << "Words in alphebetical order: " << std::endl;
    my_words->lexographicalPrint();
    return 0;
}