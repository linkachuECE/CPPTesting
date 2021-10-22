#include "gates.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <functional>

std::vector<std::pair<std::function<bool(bool, bool)>, std::string>> gateList = {
	{gate::And,"AND"},
	{gate::Nand,"NAND"},
	{gate::Or,"OR"},
	{gate::Nor,"NOR"},
	{gate::Xor,"XOR"},
	{gate::Xnor,"XNOR"}
};

int printMenu() {
	int input{};
	std::cout << "Welcome to the simulator!" << std::endl;
	std::cout << "Choose an option:\n" << std::endl;

	for (int i = 0; i < gateList.size(); i++)
		std::cout << i + 1 << ". " << gateList.at(i).second << std::endl;
	std::cout << "7. NOT" << std::endl;
	std::cin >> input;

	return input;
}

void printTruthTable(int selection) {
	std::cout << "Truth table for a " << gateList.at(selection - 1).second << " gate:" << std::endl;
	std::cout << "input 1 | input 2 | output" << std::endl;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			std::cout << "   " << i << "    |    " << j << "    |   " << gateList.at(selection - 1).first(i, j) << std::endl;
}

void notGate() {
	int input{};
	std::cout << "NOT GATE" << std::endl;
	std::cout << "Give an input of 1 or 0";
	std::cin >> input;
	std::cout << "Output is: " << gate::Not(input) << std::endl;
}

void twoInputGate(int selection) {
	int input1{}, input2{};
	std::cout << gateList.at(selection - 1).second << " GATE" << std::endl;
	std::cout << "Type input 1 (1 or 0): ";
	std::cin >> input1;
	std::cout << "Type input 2 (1 or 0): ";
	std::cin >> input2;
	std::cout << "Output is: " << gateList.at(selection - 1).first(input1, input2) << std::endl;
}

int main() {
	while(true){
		int selection = printMenu();
		int output{};
		if (selection == 7)
			notGate();
		else if (selection == 'Q' || selection == 'q')
			break;
		else
			twoInputGate(selection);

		printTruthTable(selection);
	}

	return 0;
}