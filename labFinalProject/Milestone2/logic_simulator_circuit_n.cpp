#include "gates.h"
#include <iostream>
#include <random>

bool* circuit1(bool* signalA, bool* signalB, int length){
    bool* output = new bool[length/2];
    bool* signalAFirst = signalA;
    bool* signalALast = signalA + (length/2);
    bool* signalBFirst = signalB;
    bool* signalBLast = signalB + (length/2);

    output = gate::Not_N((gate::Xnor_N(gate::And_N(signalAFirst, signalBFirst, length / 2), gate::Or_N(signalALast, signalBLast, length / 2), length / 2)),(length / 2));
    return output;
}
int main(){
    int iInput{};
    char cInput{};
    bool userInput{};
    std::cout << "Which circuit would you like to simulate? (Enter a number)" << std::endl;
    std::cout << "Circuit 1" << std::endl;
    std::cout << "Circuit 2" << std::endl;
    std::cin >> iInput;

    int arrLength = (iInput == 1) ? 8 : 16;
    bool signalA[arrLength];
    bool signalB[arrLength];

    std::cout << "Would you like to enter the values yourself? (y/n)" << std::endl;
    std::cin >> cInput;

    if(cInput == 'y' || cInput == 'Y') userInput = true;
    else userInput = false;

    if (userInput){
        std::cout << "Enter all " << arrLength << " inputs for signal A, separated by spaces, then press enter:" << std::endl;
        for(int i = 0; i < arrLength; i++)
            std::cin >> signalA[i];
        
        std::cout << "Enter all " << arrLength << " inputs for signal B, separated by spaces, then press enter:" << std::endl;
        for(int i = 0; i < arrLength; i++)
            std::cin >> signalB[i];
    } else {
        srand(time(0));
        for(int i = 0; i < arrLength; i++){
            signalA[i] = rand() % 2;
            signalB[i] = rand() % 2;
        }
    }

    bool* output = circuit1(signalA, signalB, arrLength);

    std::cout << "Output of the circuit: " << std::endl;
    for(int i = 0; i < arrLength / 2; i++){
        std::cout << output[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}