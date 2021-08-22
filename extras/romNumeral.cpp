#include <string>
#include <map>
#include <iostream>
#include <sstream>

std::string solution(int number){

	std::string romString{};

	std::map<int, const char> numAssign{
		std::pair<int, char>(1, 'I'),
		std::pair<int, char>(5, 'V'),
		std::pair<int, char>(10, 'X'),
		std::pair<int, char>(50, 'L'),
		std::pair<int, char>(100, 'C'),
		std::pair<int, char>(500, 'D'),
		std::pair<int, char>(1000, 'M')
	};

	std::reverse_iterator<std::_Rb_tree_iterator<std::pair<const int, const char>>> doublePrev;

	for (auto it = numAssign.rbegin(), prev = numAssign.rend(); it != numAssign.rend(); prev = it++){
		int revs{};
		while (number >= it->first){
			romString += it->second;
			number -= it->first;
			
			if (++revs == 4 && it != numAssign.rbegin()){
				for(int i = 0; i < 4; i++)
					romString.pop_back();
				
				if(romString.back() == prev->second){
					romString.pop_back();
					romString += it->second;
					romString += doublePrev->second;
				} else {
					romString += it->second;
					romString += prev->second;
				}

			}
		}
		doublePrev = prev;
	}
	return romString;
}

int main(int argc, char* argv[]){

	if (argc == 1){
		std::cerr << "No argument provided" << std::endl;
		return 0;
	}

	for(int i = 0; argv[1][i] != '\0'; i++)
		if (!isdigit(argv[1][i])){
			std::cerr << "Invalid input" << std::endl;
			return 0;
		}

	std::stringstream stream;
	int input{};

	stream << argv[1];
	stream >> input;

	std::cout << solution(input) << std::endl;

	return 0;
}