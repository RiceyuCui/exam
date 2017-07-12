#include <stdio.h>
#include <conio.h>
int main(void)
{
	int i, j, k;
	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 5; k++)
			{
				if (i != k && i != j && k != j)
				{
					printf("%d%d%d\n ", i, j, k);
				
				}
				
				
			}
			
		}
	}
	getch();
	return 0;
}