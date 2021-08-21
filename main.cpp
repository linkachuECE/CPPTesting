#include <fstream>
#include <iostream>

int main(){
	std::ofstream outputFile{};
	outputFile.open("test.txt", std::ios::app);

	if(!outputFile){
		std::cerr << "File doesn't work" << std::endl;
		return 0;
	}

	outputFile << "Testing the initial file write here" << std::endl;
	std::cout << "Wrote to file" << std::endl;

	std::ifstream inputFile{"test.txt"};
	std::string inputString;

	while (inputFile){
		std::getline(inputFile, inputString);
		std::cout << inputString << '\n';
	}

	inputFile.close();
	outputFile.close();

	return 0;
}