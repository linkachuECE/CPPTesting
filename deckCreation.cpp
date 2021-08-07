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