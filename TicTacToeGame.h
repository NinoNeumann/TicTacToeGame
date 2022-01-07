#ifndef TicTacToeGame_H
#define TicTacToeGame_H
#include "Games.h"
#include<vector>
#include<iomanip>
#include<time.h>
#include<stack>
#define ROWS 3
#define COLUMNS 3
#define N 3		

#define MAN 1	//��ʤ����Ľ��
#define COM -1	//����ʤ����Ľ��

#define SEARCHDEPTH 9	//����������� ��Ϊ����������߾Ų�
#define STEP 9			//���������߲���

struct Move {
	int x;
	int y;
};				//�ṹ�������洢 ����� ��ǰӦ�����������


class TicTacToeGame :private Games {
private:
	vector<int> board;
	vector<int> tempBoard;
	string winner;

	//define a file ostream
	ofstream fout;
	

	int player;					//��ʾ��ǰ�غϵ������� ����ֵ MAN���ˣ� COM���������

	Move theBestMove;			//����������Ӳ���  ���꣨x��y��

	int curDepth;				//��ǰ����� ��ǰ������������е����  ��ʵ����step���� ==stepCounter
	
	int stepCounter;

	void prnt();
	void playerTurn();
	void judge_and_play();
	int isEnd();
	bool isOutOfTheRange(int row, int column);
	int index(int x, int y);
	void Gaming();
	void gameOver();


	void inital();		//һ�����ڳ�ʼ�����̵Ĺ��ߺ���


//���ڲ�����-����Сֵ�㷨�� ������ai�Կ�����  ���ܺ���
	int evaluate();		//�������� 

	int minMaxSearch(int);	//����Сֵ����������  ��Ҫ��������com �Ļغ� 
						//�Ե�ǰ���ƽ����ж� ���õݹ�ķ�ʽ �������������еĽ� ���������յݹ�������ֵĽ������һ����ֵ


public:
	TicTacToeGame();
	~TicTacToeGame();
	void play();
	
	
	
};



#endif // !TicTacToeGame_H

