#include"TicTacToeGame.h"
/*
* 极大极小值搜索 的方法 的主要思想是博弈树
* 这里 由于问题为井字棋  而井字棋的结果个数是可以穷举的 
* 所以使用了一个大概类似 搜索树的方法 
*/



//constructor
TicTacToeGame::TicTacToeGame():Games("the_player") {
	//initalize the ostream 
	fout.open("the_result_of_TicTacToeGame.txt");
	//initalize the char array
	board.resize(ROWS * COLUMNS,0);
	tempBoard.resize(ROWS * COLUMNS, 0);
	stepCounter = 0;
	player = MAN;
	curDepth = 0;
}

TicTacToeGame::~TicTacToeGame()
{
	fout.close();
}

//定义了一个二维数组转换一维的公式
int TicTacToeGame::index(int x, int y) {
	return x * COLUMNS + y;
}

//this method aims to check whether the row or the column out of the range;
bool TicTacToeGame::isOutOfTheRange(int row, int column) {
	/*
	* if the row>ROWS throw a 'EXCEPTION'
	* column same with the row;
	*/
	if (row >= ROWS || column >= COLUMNS) {
		cout << "row or column is out of the range" << endl;
		return (row >= ROWS || column >= COLUMNS);
	}
	return (row >= ROWS || column >= COLUMNS);
}


//print the Board show the game;
void TicTacToeGame::prnt() {
	
	
	fout << "==============the " << getTotal() << " games==================\n";
	
	for (int i = 0; i < ROWS * COLUMNS; i += 3) {
		cout<<"||"<<setw(3)<<board[i] <<"||"<< setw(3) << board[i + 1] << setw(3) << "||" << setw(3) << board[i + 2] << setw(3) << "||\n";
		fout << "||" << setw(3) << board[i] << "||" << setw(3) << board[i + 1] << setw(3) << "||" << setw(3) << board[i + 2] << setw(3) << "||\n";
	}

	fout << "=============================================================\n";
}

//is define the player turn (the player move)
void TicTacToeGame::playerTurn() {
	int row;
	int column;
	bool flag = true;

	while (flag) {

		cout << "please input the rowNumber:";
		cin >> row;
		cout << "please input the rowNumber:";
		cin >> column;
		flag = isOutOfTheRange(row, column);
		if (board[index(row, column)] == MAN || board[index(row, column)] == COM) {
			cout << "the place taken choose another place!" << endl;
			flag = true;
		}
	}
	//after the player turn the stepCounter will self increase
	board[index(row, column)] = MAN;
	player = COM;
	stepCounter++;
}




void TicTacToeGame::judge_and_play() {
	//
	//tempBoard = board;
	curDepth = stepCounter;
	minMaxSearch(curDepth);
	cout << "the best choice x:" << theBestMove.x << " " << "Y:" << theBestMove.y << endl;
	board[index(theBestMove.x, theBestMove.y)] = COM;
	//board = tempBoard;
	player = MAN;
	stepCounter++;
}


int TicTacToeGame::isEnd() {
	//判定胜利的条件是 如果有一个counter（counterComputer  or  counterPlayer ）里面存放的 棋子摆放下标 有以下顺序 则胜利
	/*
	1 存在3个棋子下标（index） 在0~2 3~5 6~8 占据其中一个连续的三个空间 （行连续）
	2 存在3个棋子下标 列连续
	3 对角连续
	*/

	for (int i = 0; i < N; ++i) {
		if (board[i * COLUMNS + 0] + board[i * COLUMNS + 1] + board[i * COLUMNS + 2] == 3)
			return MAN;			//如果出现一行全是1 则人 胜利
		else if (board[i * COLUMNS + 0] + board[i * COLUMNS + 1] + board[i * COLUMNS + 2] == -3)
			return COM;
		if (board[0 * COLUMNS + i] + board[1 * COLUMNS + i] + board[2 * COLUMNS + i] == 3)
			return MAN;
		else if (board[0 * COLUMNS + i] + board[1 * COLUMNS + i] + board[2 * COLUMNS + i] == -3)
			return COM;
	}
	//对角线获胜情况
	if (board[0] + board[4] + board[8] == 3 || board[3] + board[4] + board[6] == 3)
		return MAN;
	else if (board[0] + board[4] + board[8] == 3 || board[3] + board[4] + board[6] == -3)
		return COM;
	else
		return 0;	//平局状况
}

void TicTacToeGame::play() {
	int ifStart = 9;

	while (1) {
		inital();
		fout << "the PlWin:" << getPlWin() << endl;
		fout << "the PcWin:" << getPcWin() << endl;
		fout << "the TotalWin:" << getTotal() << endl;
		cout << "input 1 start input 0 quit:";
		cin >> ifStart;
		switch (ifStart) {
		case 1:Gaming(); break;
		case 0:gameOver(); break;
		default:cout << "error number!" << endl; break;
		}
		
	}
}



void TicTacToeGame::Gaming() {
	while (1) {
		cout << "player first" << endl;
		playerTurn();
		prnt();
		cout << "=========================" << endl;
		if (stepCounter == 9  && isEnd() == 0) {
			cout << "平局！" << endl;
			int total = getTotal();
			setTotal(++total);
			return;
		}
		else if (isEnd() == 1) {
			cout << "Player WIN!!" << endl;
			int total = getTotal(), plWin = getPlWin();
			setTotal(++total);
			setPlWin(++plWin);
			return;
		}
		else if (isEnd() == -1) {
			cout << "Computer WIN!!" << endl;
			int total = getTotal(),pcWin = getPcWin();
			setTotal(++total);
			setPcWin(++pcWin);
			return;
		}
		judge_and_play();
		prnt();
		cout << "=========================" << endl;
		if (isEnd() == 1) {
			cout << "Player WIN!!" << endl;
			int total = getTotal(),plWin = getPlWin();
			setTotal(++total);
			setPlWin(++plWin);
			return;
		}
		else if (isEnd() == -1) {
			cout << "Computer WIN!!" << endl;
			int total = getTotal(), pcWin = getPcWin();
			setTotal(++total);
			setPcWin(++pcWin);
			return;
		}
	}
}

void TicTacToeGame::gameOver() {
	exit(0);
}

void TicTacToeGame::inital()
{
	curDepth = 0;
	board.clear();
	board.resize(ROWS*COLUMNS, 0);
	stepCounter = 0;
	player = MAN;
}

int TicTacToeGame::evaluate()
{
	int value = isEnd();
	if (value == MAN)return INT_MAX;	//如果当前棋局的最终走向为人胜利 则返回一个最大值
	if (value == COM)return INT_MIN;	//……返回最小值
	return value;							//平局 或非决胜状态 返回0
	
}

int TicTacToeGame::minMaxSearch(int depth)
{
	int value = 0;
	if (player == MAN)value = INT_MIN;
	if (player == COM)value = INT_MAX;

	//如果搜索结束 返回评价值 INT_MIN（计算机获胜）  OR  INT_MAX（人获胜）
	if (isEnd() != 0) {
		return evaluate();
	}
	//如果达到最大搜索深度 也会使得搜索函数结束 并且返回对当前棋局的评价函数
	if (depth == SEARCHDEPTH) {
		int value = evaluate();
		return value;
	}

	//搜索主体：
	//遍历当前棋局的所有落子可能 找到最适合的移动策略

	for(int i = 0;i<N;++i)
		for (int j = 0; j < N; ++j) {
			//如果当前位置无落子 
			if (board[i*COLUMNS+j] == 0) {
				//并且当前局是computer 的回合
				if (player == COM) {
					board[i * COLUMNS + j] = COM;
					player = MAN;					//
					int nextValue = minMaxSearch(depth + 1);		//
					player = COM;
					if (value > nextValue) {
						value = nextValue;
						if (depth == curDepth) {
							theBestMove.x = i;
							theBestMove.y = j;
						}
					}
				}
				else {
					board[i * COLUMNS + j] = MAN;
					player = COM;
					int nextValue = minMaxSearch(depth + 1);
					player = MAN;
					if (value < nextValue) {
						value = nextValue;
						if (depth == curDepth) {
							theBestMove.x = i;
							theBestMove.y = j;
						}
					}
				}
				board[i * COLUMNS + j] = 0;
			}
			
		}
	return value;
}








