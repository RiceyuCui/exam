#include <stdio.h>

//给状态机定义状态集

typedef enum
{
	STATE1,
	STATE2,
	STATE3,
	STATE4,
	STATE5,
	STATE6,
	STATE7,
}STATE;



int main(void)
{
	int num = 0;
	STATE current_state = STATE1;
	printf("请输入密码.\n");

	//第一步，实现用户循环输入密码
	while (1)
	{
		scanf("%d", &num);
		printf("num = %d.\n",num);

		//处理用户文本输入

		switch (current_state)
		{
			case STATE1:
				if (num == 1)
				{
					current_state = STATE2;				
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE2:
				if (num == 2)
				{
					current_state = STATE3;				
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE3:
				if (num == 3)
				{
					current_state = STATE4;				
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE4:
				if (num == 4)
				{
					current_state = STATE5;				
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE5:
				if (num == 5)
				{
					current_state = STATE6;				
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE6:
				if (num == 6)
				{
					current_state = STATE7;				
				}
				else
				{
					current_state = STATE1;
				}
				break;
			default:
				current_state = STATE1;
				break;

		}

		if (current_state == STATE7)
		{
			printf("锁开了.\n");
			break;

		}
	}

	return 0;

}