#include "Poker.h"

void Poker::sendCards()
{
	//shuffle 
	deck_cards.inital();
	deck_cards.shuffle();
	//send cards  发牌
	for (int i = 0; i < 5; ++i) {
		player.push_back(deck_cards.dealCard());
		computer.push_back(deck_cards.dealCard());
	}
}

double Poker::map_face_to_score(int index)
{
	/*
	* 将十三号牌与其score 对应
	*/
	double res = 0;
	res = index - 1;
	res = (res >= 0) ? res * 0.5 : 6;
	return res;
}

double Poker::judger(vector<int> obj[13])
{
	double max_score = 0;
	int max_face = 0;
	for(int i = 0;i<13;++i)
	switch (obj[i].size()) {
	case 0:break;
	case 1: {
		max_face = i;
		double the_score = map_face_to_score(max_face);
		if (max_score < the_score)
			max_score = the_score;
	}break;
	case 2: {
		max_face = i;
		double the_score = 10*map_face_to_score(max_face);
		if (max_score < the_score)
			max_score = the_score;
	}break;
	case 3: {
		max_face = i;
		double the_score = 100*map_face_to_score(max_face);
		if (max_score < the_score)
			max_score = the_score;
	}break;
	case 4: {
		max_face = i;
		double the_score = 1000*map_face_to_score(max_face);
		if (max_score < the_score)
			max_score = the_score;
	}break;
	}
	return max_score;
}

void Poker::inital()
{
	player.clear();
	computer.clear();
}



Poker::Poker():Games("player1")
{
	player.clear();
	computer.clear();
	player_score=0;
	computer_score=0;
	fout.open("score.txt");

}

Poker::~Poker()
{
	fout.close();
}

void Poker::play()
{
	int i = 0;
	while (1) {
		cout << "input 1 start game 0 quit" << endl;
		cin >> i;
		if (i) {
			sendCards();
			judge_and_play();
			inital();
		}
		else if (i == 0) {
			break;
		}
		else {
			cout << "please input a new number!" << endl;
		}
	}
}




void Poker::judge_and_play()
{
	cout << "================" << getTotal() << "=Turns================\n";
	fout << "================" << getTotal() << "=Turns================\n";
	sort(player.begin(), player.end());
	sort(computer.begin(), computer.end());

	vector<int> book1[13];

	vector<int> book2[13];

	for (int i = 0; i < 5; ++i) {
		book1[player[i].get_face()].push_back(player[i].get_suit());
		book2[computer[i].get_face()].push_back(computer[i].get_suit());
	}


	player_score = judger(book1);



	computer_score = judger(book2);

	if (player_score > computer_score) {
		int plw = getPlWin();
		int total = getTotal();
		setTotal(total + 1);
		setPlWin(plw + 1);
		cout << "player Win!!" << endl;
	}
	else if (player_score < computer_score) {
		int pcw = getPcWin();
		int total = getTotal();
		setTotal(total + 1);
		setPcWin(pcw + 1);
		cout << "computer Win!!" << endl;
	}
	else {
		int total = getTotal();
		setTotal(total + 1);
		cout << "draw!!" << endl;
	}
	prnt();

}



void Poker::prnt()
{
	//显示双方手牌
	for (int i = 0; i < 5; ++i) {
		cout << player[i].toString();
		fout<< player[i].toString();
		if (i + 1 < 5) {
			cout << " ";
			fout << " ";
		}
		else {
			cout << endl;
			fout << "\n";
		}
	}
	//
	for (int i = 0; i < 5; ++i) {
		cout << computer[i].toString();
		fout << computer[i].toString();
		if (i + 1 < 5) {
			cout << "   ";
			fout << " ";
		}
		else {
			cout << endl;
			fout << "\n";
		}
	}
}
