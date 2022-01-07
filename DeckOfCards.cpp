#include "DeckOfCards.h"

void DeckOfCards::inital()
{
	this->currentCard = 51;
	deck.clear();

	for (int i = 0; i < 13 * 4; i++) {
		deck.push_back(Card(i % 13, i % 4));
	}
}

DeckOfCards::DeckOfCards()
{
	this->currentCard = 51;
	deck.clear();
	
	for (int i = 0; i < 13*4 ;i++) {
		deck.push_back(Card(i % 13, i % 4));
	}

}

void DeckOfCards::shuffle()
{
	srand(time(NULL));
	int counter = 0;
	while (counter < 200) {
		swap(deck[rand() % 52], deck[rand() % 52]);
		counter++;
	}
	//
}

Card& DeckOfCards::dealCard()
{
	Card* temp = new Card(deck[currentCard].get_face(), deck[currentCard].get_suit());
	deck.pop_back();
	currentCard--;
	return *temp;
}

bool DeckOfCards::moreCards()
{
	return deck.size()==0;
}
