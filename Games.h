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
	int plWin;	//��һ�ʤ����
	int pcWin;	//���Ի�ʤ����
	int total;	//�ܴ���
	virtual void judge_and_play()=0;
public:
	Games(const string na);				//��ʼ�������Ϣ
	virtual void prnt()=0; //�����Ϸ���
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

