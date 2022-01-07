#ifndef POKER_H
#define POKER_H
using namespace std;

#include "Games.h"
#include "DeckOfCards.h"
#include<vector>
#include<string>
#include<algorithm>



class Poker:public Games {
	/*
	* 要实现的内容 
	1、发牌
	2、比较大小
	* 
	*/
private:
	ofstream fout;
	vector<Card>player;
	vector<Card>computer;
	double player_score;
	double computer_score;
	DeckOfCards deck_cards;
	void sendCards();			//发牌 player 和 computer 各发5张牌
	double map_face_to_score(int);
	double judger(vector<int> obj[13]);
	void inital();
public:
	Poker();
	~Poker();
	void play();
	// 通过 Games 继承
	virtual void judge_and_play() override;
	virtual void prnt() override;

};





#endif // !POKER_H



