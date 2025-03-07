#include <stdio.h>

int count = 0;
void PrintMove(char from, char to)
{
	printf("move from %c to %c\n", from, to);
	count ++;
}


void HanoiTower(int n, char from, char to, char space)
{
	if (n == 1)
	{
		PrintMove(from, to);
		return;
	};
	HanoiTower(n - 1, from, space, to);
	HanoiTower(1, from, to, space);
	HanoiTower(n - 1, space, to, from);

}

int main(void)
{
	int n = 5;
	char a, c, b;
	HanoiTower(n, 'a', 'c', 'b');
	printf("Count: %d\n", count);
	return 0;
}
