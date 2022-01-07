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

#define MAN 1	//人胜利后的结果
#define COM -1	//电脑胜利后的结果

#define SEARCHDEPTH 9	//定义搜索深度 因为井字棋最多走九步
#define STEP 9			//定义了行走步数

struct Move {
	int x;
	int y;
};				//结构体用来存储 计算机 当前应该走棋的坐标


class TicTacToeGame :private Games {
private:
	vector<int> board;
	vector<int> tempBoard;
	string winner;

	//define a file ostream
	ofstream fout;
	

	int player;					//显示当前回合的走子者 两个值 MAN（人） COM（计算机）

	Move theBestMove;			//存放最优走子策略  坐标（x，y）

	int curDepth;				//当前的深度 当前棋局在搜索树中的深度  其实就是step步数 ==stepCounter
	
	int stepCounter;

	void prnt();
	void playerTurn();
	void judge_and_play();
	int isEnd();
	bool isOutOfTheRange(int row, int column);
	int index(int x, int y);
	void Gaming();
	void gameOver();


	void inital();		//一个用于初始换棋盘的工具函数


//基于博弈树-极大极小值算法的 井字棋ai对抗策略  功能函数
	int evaluate();		//评估函数 

	int minMaxSearch(int);	//极大极小值搜索主函数  主要功能是在com 的回合 
						//对当前局势进行判断 采用递归的方式 遍历接下来所有的解 并根据最终递归所得棋局的结果给上一步赋值


public:
	TicTacToeGame();
	~TicTacToeGame();
	void play();
	
	
	
};



#endif // !TicTacToeGame_H

