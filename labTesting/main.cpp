#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <limits>

void GetNumOfNonWSCharacters(const std::string& userText) {
	int total{};
	for (char c : userText)
		if (!isspace(c))
			total++;

	std::cout << "Number of non-whitespace characters: " << total << std::endl;
}

void GetNumOfWords(const std::string& userText) {
	int wordCount{};
	enum state {
		IN,
		OUT
	} currentState{ OUT };

	for (char c : userText) {
		if (isspace(c) && currentState == IN) {
			currentState = OUT;
		}
		else if (!isspace(c) && currentState == OUT) {
			currentState = IN;
			wordCount++;
		}
	}

	std::cout << "Number of words: " << wordCount << std::endl;
}

void FindText(const std::string& userText) {
	std::string input;
	std::cout << "Enter a word or phrase to be found:" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);

	size_t start{};
	int count{};

	while (true) {
		start = userText.find(input, start);

		if (start == std::string::npos)
			break;
		else {
			start++;
			count++;
		}
	}

	std::cout << "\"" << input << "\" instances: " << count << std::endl;
}

void ReplaceExclamation(std::string& userText) {
	std::replace(userText.begin(), userText.end(), '!', '.');
}

void ShortenSpace(std::string& userText) {
	enum state {
		wasSpace,
		wasChar
	} currentState{ wasChar };

	for (unsigned long i = 0; i < userText.size(); i++) {
		if (isspace(userText.at(i))) {
			if (currentState == wasSpace) {
				userText.erase(i--, 1);
			}
			currentState = wasSpace;
		}
		else {
			currentState = wasChar;
		}
	}
}

void PrintMenu() {
	std::cout << "MENU" << std::endl;
	std::cout << "c - Number of non-whitespace characters" << std::endl;
	std::cout << "w - Number of words" << std::endl;
	std::cout << "f - Find text" << std::endl;
	std::cout << "r - Replace all !'s" << std::endl;
	std::cout << "s - Shorten spaces" << std::endl;
	std::cout << "q - Quit" << std::endl;
	std::cout << std::endl;
	std::cout << "Choose an option:" << std::endl;
}

void ExecuteMenu(std::string& userText, char optionSelect) {
	bool invalidInput{ true };
   
   while(invalidInput){
      invalidInput = false;
      switch (optionSelect) {
      case 'c':
      case 'C':
         GetNumOfNonWSCharacters(userText);
         break;

      case 'w':
      case 'W':
         GetNumOfWords(userText);
         break;

      case 'f':
      case 'F':
         FindText(userText);
         break;

      case 'r':
      case 'R':
         ReplaceExclamation(userText);
         std::cout << "Edited text: " << userText << std::endl;
         break;

      case 's':
      case 'S':
         ShortenSpace(userText);
         std::cout << "Edited text: " << userText;
         break;

      case 'q':
      case 'Q':
         exit(0);
         break;

      default:
         invalidInput = true;
         break;
      }
   }
}

int main() {
	std::string userText{};
	char charInput{};
	std::cout << "Enter a sample text:" << std::endl;
	std::getline(std::cin, userText);
	std::cout << std::endl;

	std::cout << "You entered: " << userText << std::endl;

	while (true) {
		std::cout << std::endl;
		PrintMenu();
		std::cin >> charInput;
		ExecuteMenu(userText, charInput);
	}

	return 0;
}