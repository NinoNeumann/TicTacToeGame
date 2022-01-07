#ifndef CARDS_H
#define CAEDS_H
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<random>
using namespace std;
#define FACE_NUM 13
#define SUIT_NUM 4;

class Card {
private:
	int face, suit;
	static string face_s[13];
	static string suit_s[4];
	
public:
	bool operator<(Card obj2);
	Card(int ,int);
	string toString();
	string* getFace_S();
	string* getSuit_S();
	int get_face();
	int get_suit();

};

#endif
