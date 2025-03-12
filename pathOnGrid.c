/*#include <stdio.h>*/
/**/
/*int CountPath(int i, int j, int D, int C)*/
/*{*/
/*	if (i > D || j > C) return 0;*/
/*	if (i == D && j == C) return 1;*/
/*	int count = CountPath(i, j + 1, D, C) + CountPath(i + 1, j, D, C);*/
/*	return count;*/
/*}*/
/**/
/**/
/*int main(void)*/
/*{*/
/*	int i = 2, j = 2;*/
/*	int D = 3, C = 4;*/
/*	printf("Count: %d\n", CountPath(i, j, D, C));*/
/*	return 0;*/
/*}*/


// Di cheo xuong + di tu trai qua phai + di tu tren xuong duoi
#include <stdio.h>

int CountPath(int i, int j, int D, int C)
{
	if (i > D || j > C) return 0;
	if (i == D && j == C) return 1;
	return CountPath(i, j + 1, D, C) + CountPath(i + 1, j, D, C) + CountPath(i + 1, j + 1, D, C);
}

int main(void)
{
	int i = 2, j = 2, D = 3, C = 4;
	printf("Count: %d\n", CountPath(i, j, D, C));
}
