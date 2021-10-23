#include "gates.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <functional>

std::vector<std::pair<std::function<bool(bool, bool)>, std::string>> gateList = {
	{And,"AND"},
	{Nand,"NAND"},
	{Or,"OR"},
	{Nor,"NOR"},
	{Xor,"XOR"},
	{Xnor,"XNOR"}
};

int printMenu() {
	char input{};
	std::cout << "Welcome to the simulator!" << std::endl;
	std::cout << "Choose an option:\n" << std::endl;

	for (int i = 0; i < gateList.size(); i++)
		std::cout << i + 1 << ". " << gateList.at(i).second << std::endl;
	std::cout << "7. NOT" << std::endl;
	std::cout << "(Press Q to quit)" << std::endl;
	std::cin >> input;

	return input;
}

void printTruthTable(char selection) {
	std::cout << "Truth table for a " << gateList.at(selection - '0' - 1).second << " gate:" << std::endl;
	std::cout << "input 1 | input 2 | output" << std::endl;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			std::cout << "   " << i << "    |    " << j << "    |   " << gateList.at(selection - '0' - 1).first(i, j) << std::endl;
	std::cout << std::endl;
}

void printNotGateTruthTable(){
	std::cout << "Truth table for a NOT gate:" << std::endl;
	std::cout << "input 1 | output" << std::endl;
	std::cout << "   1    |    0  " << std::endl;
	std::cout << "   0    |    1  " << std::endl;
	std::cout << std::endl;

}

void notGate() {
	int input{};
	std::cout << "NOT GATE" << std::endl;
	std::cout << "Give an input of 1 or 0: ";
	std::cin >> input;
	std::cout << std::endl << "Output is: " << Not(input) << std::endl << std::endl;
}

void twoInputGate(int selection) {
	int input1{}, input2{};
	std::cout << gateList.at(selection - '0' - 1).second << " GATE" << std::endl;
	std::cout << "Type input 1 (1 or 0): ";
	std::cin >> input1;
	std::cout << "Type input 2 (1 or 0): ";
	std::cin >> input2;
	std::cout <<  std::endl << "Output is: " << gateList.at(selection - '0' - 1).first(input1, input2) << std::endl << std::endl;
}

int main() {
	while(true){
		char selection = printMenu();
		int output{};
		if (selection == '7'){
			notGate();
			printNotGateTruthTable();
		}
		else if (selection == 'Q' || selection == 'q')
			return false;
		else{
			twoInputGate(selection);
			printTruthTable(selection);
		}
	}

	return 0;
}