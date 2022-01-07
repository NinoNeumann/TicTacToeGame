#include "Card.h"


bool Card::operator<(Card obj2)
{
	return face<obj2.get_face();
}



Card::Card(int face,int suit)
{
	this->face = face;
	this->suit = suit;
}

string* Card::getFace_S()
{
	return face_s;
}

string Card::toString()
{
	string res;
	res = face_s[face] +" OF "+ suit_s[suit];
	return res;
}

string* Card::getSuit_S()
{
	return suit_s;
	// TODO: 在此处插入 return 语句
}

int Card::get_face()
{
	return face;
}

int Card::get_suit()
{
	return suit;
}

string Card::face_s[13] = { "Ace ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Night ","Ten ","Jack ","Queen ","King " };
string Card::suit_s[4] = { "Hearts","Diamonds","Clubs","Spades" };