/*#include <stdio.h>*/
/**/
/**/
/*int count = 0;*/
/**/
/*void print(char from, char to)*/
/*{*/
/*	printf("Move from %c to %c\n", from, to);*/
/*	count++;*/
/*}*/
/**/
/*void HanoiTower(int n, char from , char to, char space)*/
/*{*/
/*	if (n == 1)*/
/*	{*/
/*		print(from, to);*/
/*		return;*/
/*	}*/
/**/
/*	HanoiTower(n - 1, from, space, to);*/
/*	HanoiTower(1, from, to, space);*/
/*	HanoiTower(n - 1, space, to, from);*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	int n = 5;*/
/*	char a = 'a';*/
/*	char b = 'b';*/
/*	char c = 'c';*/
/*	HanoiTower(n, a, b, c);*/
/*	printf("Count: %d\n", count);*/
/*	return 0;*/
/*}*/

#include <stdio.h>

int count = 0;

void Printf(char from, char to)
{
	printf("Move from %c to %c\n", from, to);
	count++;
}

void HanoiTower(int n, char from, char to, char space)
{

	// Base case
	if (n == 1)
	{
		Printf(from, to);
   	return;
	}
	
	// Recursize case
  HanoiTower(n - 1, from, space, to);
	HanoiTower(1, from, to, space);
	HanoiTower(n - 1, space, to, from);
}

int main(void)
{
	int n = 5;
	char a = 'a', b = 'b', c = 'c';
	HanoiTower(n, a, c, b);
	printf("Total Move: %d\n", count);
	return 0;
}
