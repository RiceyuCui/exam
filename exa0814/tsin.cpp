#include <iostream>
#include <cstdlib>
using namespace std;

//Ͷ���ӡ�����������������

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
	cin >> seed;              //�������������
	srand(seed);              //�����Ӵ��ݸ�rand()
	sum = rollDice();         //��һ��Ͷ���ӡ��������
	
	switch(sum)
	{
	case 7:                   //�������Ϊ7��11��Ϊʤ��״̬ΪWIN
	case 11:
		status = WIN;
		break;
	case 2:                   //����Ϊ2��3��12��Ϊ����״̬ΪLOSE
	case 3:
	case 12:
		status = LOSE;
		break;
	default:                   //������������޽����״̬ΪPLAYING�����µ���
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