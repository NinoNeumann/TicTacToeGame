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
	* Ҫʵ�ֵ����� 
	1������
	2���Ƚϴ�С
	* 
	*/
private:
	ofstream fout;
	vector<Card>player;
	vector<Card>computer;
	double player_score;
	double computer_score;
	DeckOfCards deck_cards;
	void sendCards();			//���� player �� computer ����5����
	double map_face_to_score(int);
	double judger(vector<int> obj[13]);
	void inital();
public:
	Poker();
	~Poker();
	void play();
	// ͨ�� Games �̳�
	virtual void judge_and_play() override;
	virtual void prnt() override;

};





#endif // !POKER_H



