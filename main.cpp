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

using deck = std::array<Card, 52>;

void createDeck(deck& newDeck){
	for (int s = 0; s < 4; s++){
		for (int r = 0; r < 13; r++){
			Card currentCard{static_cast<suit>(s), static_cast<rank>(r)};
			newDeck.at( (s * 13) + r ) = currentCard;
		}
	}
}

void printCard(const Card& thisCard){

	char s{}, r{};

	switch(thisCard.thisSuit){
		case suit::hearts:
			r = 'H';
			break;
		case suit::clubs:
			r = 'C';
			break;
		case suit::diamonds:
			r = 'D';
			break;
		case suit::spades:
			r = 'S';
			break;
	};

	switch(thisCard.thisRank){
		case rank::r2:
			s = '2';
			break;
		case rank::r3:
			s = '3';
			break;
		case rank::r4:
			s = '4';
			break;
		case rank::r5:
			s = '5';
			break;
		case rank::r6:
			s = '6';
			break;
		case rank::r7:
			s = '7';
			break;
		case rank::r8:
			s = '8';
			break;
		case rank::r9:
			s = '9';
			break;
		case rank::r10:
			s = 'X';
			break;
		case rank::Jack:
			s = 'J';
			break;
		case rank::Queen:
			s = 'Q';
			break;
		case rank::King:
			s = 'K';
			break;
		case rank::Ace:
			s = 'A';
			break;
	};

	std::cout << r << s << std::endl;
}

void printDeck(const deck& thisDeck){
	for (Card thisCard : thisDeck)
		printCard(thisCard);
}

void shuffleDeck(deck& thisDeck){
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(thisDeck.begin(), thisDeck.end(), mt);
}

int getCardValue(Card& thisCard){
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
			return 11;
			break;
		default:
			return 0;
	}
}

int main(){
	
	deck newDeck{};
	createDeck(newDeck);
	printDeck(newDeck);
	shuffleDeck(newDeck);

	std::cout << "shuffled deck: " << std::endl;
	printDeck(newDeck);

	std::cout << "The first card in the deck is: ";
	printCard(newDeck[0]);
	std::cout << "And its value is: " << getCardValue(newDeck[0]) << std::endl;

	return 0;
}