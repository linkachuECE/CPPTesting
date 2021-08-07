#include "headers.h"

enum class suit{
	hearts,
	spades,
	clubs,
	diamonds,

	max_suits
};

enum class rank{
	r2,
	r3,
	r4,
	r5,
	r6,
	r7,
	r8,
	r9,
	r10,
	Jack,
	Queen,
	King,
	Ace,

	max_ranks
};


struct Card{
	suit thisSuit{};
	rank thisRank{};
};

using deck = std::vector<Card>;

void createDeck(deck& newDeck){
	for (int s = 0; s < 4; s++){
		for (int r = 0; r < 13; r++){
			Card currentCard{static_cast<suit>(s), static_cast<rank>(r)};
			newDeck.at( (s * 13) + r ) = currentCard;
		}
	}
}

void printCard(const Card& thisCard){

	std::string s{}, r{};

	switch(thisCard.thisSuit){
		case suit::hearts:
			s = "Hearts";
			break;
		case suit::clubs:
			s = "Clubs";
			break;
		case suit::diamonds:
			s = "Diamonds";
			break;
		case suit::spades:
			s = "Spades";
			break;
	};

	switch(thisCard.thisRank){
		case rank::r2:
			r = "2";
			break;
		case rank::r3:
			r = "3";
			break;
		case rank::r4:
			r = "4";
			break;
		case rank::r5:
			r = "5";
			break;
		case rank::r6:
			r = "6";
			break;
		case rank::r7:
			r = "7";
			break;
		case rank::r8:
			r = "8";
			break;
		case rank::r9:
			r = "9";
			break;
		case rank::r10:
			r = "10";
			break;
		case rank::Jack:
			r = "Jack";
			break;
		case rank::Queen:
			r = "Queen";
			break;
		case rank::King:
			r = "King";
			break;
		case rank::Ace:
			r = "Ace";
			break;
	};

	std::cout << r << " of " << s;
}

void printDeck(const deck& thisDeck){
	for (Card thisCard : thisDeck)
		printCard(thisCard);
}

void shuffleDeck(deck& thisDeck){
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(thisDeck.begin(), thisDeck.end(), mt);
}

int getCardValue(Card& thisCard, int total){
	switch (thisCard.thisRank){
		case rank::r2:
		case rank::r3:
		case rank::r4:
		case rank::r5:
		case rank::r6:
		case rank::r7:
		case rank::r8:
		case rank::r9:
		case rank::r10:
			return (static_cast<int>(thisCard.thisRank) + 2);
			break;

		case rank::Jack:
		case rank::Queen:
		case rank::King:
			return 10;
			break;
		
		case rank::Ace:
            return (total > 10) ? 1 : 11;
			break;
		default:
			return 0;
	}
}


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