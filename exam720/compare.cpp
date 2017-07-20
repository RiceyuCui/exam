#include <stdio.h>
#include <conio.h>
int main(void)
{
	int x, y, z, t;
	printf("Input three numbers: ");
	scanf("%d %d %d", &x, &y, &z);
	if (x > y)
	{
		t = x;
		x = y;
		y = t;
	}
	if (x > z)
	{
		t = x;
		x = z;
		z = t;
	}
	if (y > z)
	{
		t = y;
		y = z;
		z = t;
	}
	printf("Small to big: %d %d %d", x, y, z);
	getch();
}