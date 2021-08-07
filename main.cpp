#include "headers.h"
#include "deckCreation.cpp"

#define MAX_SCORE 21
#define DEALER_LIMIT 17

unsigned int second = 1000000;

struct member {
	int total{};
	std::array<Card, 10> hand{};
	int cardCount{};
	int lastCountedCard{};
};

void PressEnterToContinue(){
	std::cout << "Press the Enter key to play: ";
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}

// Returns a card from the given deck and erases it 
Card pullCard(deck& thisDeck){
	static int i{0};
	return thisDeck[i++];
}

// Adds the value of of the most recently added cards to the member's total
void updateTotal(member& thisMember){
	for(int i = thisMember.lastCountedCard; i < thisMember.cardCount; i++){
		thisMember.total += getCardValue(thisMember.hand[i],thisMember.total);
		thisMember.lastCountedCard++;
	}
}

// Add to both the hand of the member, and to their total score
void addToHandAndTotal(member& thisMember, deck playDeck){
	thisMember.hand[thisMember.cardCount++] = pullCard(playDeck);
	updateTotal(thisMember);
}

// Displays all the cards of the called-upon member
void displayHand(member& thisMember){
	for(int i = 0; i < thisMember.cardCount; i++){
			printCard(thisMember.hand[i]);
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Display the cards and score total of the player
void displayPlayerStatus(member& player){
	std::cout << "Your current cards are:" << std::endl;
	displayHand(player);
	std::cout << "Your current total is: " << player.total << std::endl;
}

// Displays all the cards and score total of the called-upon member
void displayDealerStatus(member& dealer){
	std::cout << "The dealer's current cards are:" << std::endl;
	displayHand(dealer);
	std::cout << "The dealer's current total is: " << dealer.total << std::endl;
}

// Ask whther the player wants to hit or stand
bool askToHitOrStand(){
	char input{};
	while(true){
			std:: cout << "Would you like to hit (h) or stand (s)? ";
			std::cin >> input;
			if(input == 's' || input == 'S')
				return false;
			else if (input == 'H' || input == 'h')
				return true;
			else
				std::cout << "Invalid input" << std::endl;
	}
}

// Asks whether te user would like to play again
bool askToPlayAgain(){
	char input{};
	while(true){
			std:: cout << "Would you like to play again? (Y/N)";
			std::cin >> input;
			if(input == 'n' || input == 'N')
				return false;
			else if (input == 'y' || input == 'Y')
				return true;
			else
				std::cout << "Invalid input" << std::endl;
	}
}

bool playBlackJack(){
	system("clear");
	deck playDeck{};
	playDeck.resize(52);
	createDeck(playDeck);
	shuffleDeck(playDeck);

	static bool has_played{false};

	std::cout << "Welcome to Black Jack!" << std::endl;
	if (!has_played) { PressEnterToContinue();}
	std::cout << std::endl;

	has_played = true;

	// Create the player with a single card that is pulled from the deck and erased
	member player{0, {pullCard(playDeck), pullCard(playDeck)}, 2};
	// Update the player's total with the first and second card they got
	updateTotal(player);

	bool hitAgain{true}, playerBust{false};

	do{
		displayPlayerStatus(player);

		char input{};

		hitAgain = askToHitOrStand();

		if(hitAgain){
			system("clear");
			addToHandAndTotal(player, playDeck);
			if(player.total > MAX_SCORE){
				displayPlayerStatus(player);
				std::cout << "You bust!" << std::endl;
				playerBust = true;
				hitAgain = false;
			}
		}

	} while(hitAgain);

	if(!playerBust){
		system("clear");

		bool dealerBust{};
		std::cout << "Dealer's turn: " << std::endl;

		member dealer{0, {pullCard(playDeck), pullCard(playDeck)}, 1};
		updateTotal(dealer);
		displayDealerStatus(dealer);

		while(dealer.total < 17){
			system("clear");
			addToHandAndTotal(dealer, playDeck);
			displayDealerStatus(dealer);
			usleep(3 * second);
			if(dealer.total > 21){
				std::cout << "Dealer Bust! You win." << std::endl;
				dealerBust = true;
			}
		}

		if(!dealerBust){
			system("clear");
			std::cout << "The dealer has a total of " << dealer.total << 
			", and you had a total of " << player.total << std::endl;

			if(dealer.total > player.total)
				std::cout << "You lost!" << std::endl;
			else if(dealer.total == player.total)
				std::cout << "It's a tie!" << std::endl;
			else
				std::cout << "You won!";
		}
	}
	std::cout << std::endl;
	return askToPlayAgain();

}

int main(){
	bool keepPlaying;
	do{ 
		keepPlaying = playBlackJack();
	} while(keepPlaying);

	system("clear");
	return 0;
}