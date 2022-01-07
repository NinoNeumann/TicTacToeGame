#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include<vector>

class DeckOfCards {
private:
	vector<Card> deck;
	int currentCard;
	
public:
	DeckOfCards();
	void shuffle();
	Card& dealCard();
	void inital();
	bool moreCards();
};

#endif // !DECKOFCARDS_H
