#include <iostream>
#include <cstdlib>
using namespace std;

//投骰子、计算和数、输出和数

int rollDice()
{
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	int sum = die1 + die2;

	cout << "player rolled " << die1 << "+" << die2 << "=" << sum << endl;

	return sum;
}

enum GameState{WIN, LOSE, PLAYING};

int main()
{
	int sum, myPoint;
	GameState status;
	unsigned seed;
	int rollDice();
	cout << "Please enter an unsigned integer: ";
	cin >> seed;              //输入随机数种子
	srand(seed);              //将种子传递给rand()
	sum = rollDice();         //第一轮投骰子、计算和数
	
	switch(sum)
	{
	case 7:                   //如果和数为7或11则为胜，状态为WIN
	case 11:
		status = WIN;
		break;
	case 2:                   //和数为2、3或12则为负，状态为LOSE
	case 3:
	case 12:
		status = LOSE;
		break;
	default:                   //其他情况，尚无结果，状态为PLAYING，记下点数
		status = PLAYING;
		 myPoint = sum;
		 cout << "point is " << myPoint <<endl;
		 break;
	}

	while (status == PLAYING)
	{
		sum = rollDice();
		if (sum == myPoint)
		{
			status = WIN;
		}
		else if (sum == 7)
			status = LOSE;
	}

	if (sum == WIN)
	{
		cout << "player wins" << endl;

	}
	else 
	{
		cout << "player loses" << endl;
	}

	
	return 0;
}