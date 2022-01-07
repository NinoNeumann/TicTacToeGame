#include"TicTacToeGame.h"
/*
* ����Сֵ���� �ķ��� ����Ҫ˼���ǲ�����
* ���� ��������Ϊ������  ��������Ľ�������ǿ�����ٵ� 
* ����ʹ����һ��������� �������ķ��� 
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

//������һ����ά����ת��һά�Ĺ�ʽ
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
	//�ж�ʤ���������� �����һ��counter��counterComputer  or  counterPlayer �������ŵ� ���Ӱڷ��±� ������˳�� ��ʤ��
	/*
	1 ����3�������±꣨index�� ��0~2 3~5 6~8 ռ������һ�������������ռ� ����������
	2 ����3�������±� ������
	3 �Խ�����
	*/

	for (int i = 0; i < N; ++i) {
		if (board[i * COLUMNS + 0] + board[i * COLUMNS + 1] + board[i * COLUMNS + 2] == 3)
			return MAN;			//�������һ��ȫ��1 ���� ʤ��
		else if (board[i * COLUMNS + 0] + board[i * COLUMNS + 1] + board[i * COLUMNS + 2] == -3)
			return COM;
		if (board[0 * COLUMNS + i] + board[1 * COLUMNS + i] + board[2 * COLUMNS + i] == 3)
			return MAN;
		else if (board[0 * COLUMNS + i] + board[1 * COLUMNS + i] + board[2 * COLUMNS + i] == -3)
			return COM;
	}
	//�Խ��߻�ʤ���
	if (board[0] + board[4] + board[8] == 3 || board[3] + board[4] + board[6] == 3)
		return MAN;
	else if (board[0] + board[4] + board[8] == 3 || board[3] + board[4] + board[6] == -3)
		return COM;
	else
		return 0;	//ƽ��״��
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
			cout << "ƽ�֣�" << endl;
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
	if (value == MAN)return INT_MAX;	//�����ǰ��ֵ���������Ϊ��ʤ�� �򷵻�һ�����ֵ
	if (value == COM)return INT_MIN;	//����������Сֵ
	return value;							//ƽ�� ��Ǿ�ʤ״̬ ����0
	
}

int TicTacToeGame::minMaxSearch(int depth)
{
	int value = 0;
	if (player == MAN)value = INT_MIN;
	if (player == COM)value = INT_MAX;

	//����������� ��������ֵ INT_MIN���������ʤ��  OR  INT_MAX���˻�ʤ��
	if (isEnd() != 0) {
		return evaluate();
	}
	//����ﵽ���������� Ҳ��ʹ�������������� ���ҷ��ضԵ�ǰ��ֵ����ۺ���
	if (depth == SEARCHDEPTH) {
		int value = evaluate();
		return value;
	}

	//�������壺
	//������ǰ��ֵ��������ӿ��� �ҵ����ʺϵ��ƶ�����

	for(int i = 0;i<N;++i)
		for (int j = 0; j < N; ++j) {
			//�����ǰλ�������� 
			if (board[i*COLUMNS+j] == 0) {
				//���ҵ�ǰ����computer �Ļغ�
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








