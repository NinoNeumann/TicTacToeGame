#ifndef GAMES_H
#define GAMES_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;


class Games {
private:
	string name;
	int plWin;	//玩家获胜次数
	int pcWin;	//电脑获胜次数
	int total;	//总次数
	virtual void judge_and_play()=0;
public:
	Games(const string na);				//初始化玩家信息
	virtual void prnt()=0; //输出游戏结果
	void setName(const string na);
	string getName();
	int getPcWin();
	int getPlWin();
	int getTotal();
	void setTotal(int);
	void setPcWin(int);
	void setPlWin(int);
};


#endif // !GAMES_H

