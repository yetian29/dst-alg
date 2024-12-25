#include <stdio.h>

/*int main(void)*/
/*{*/
/*		int myNumbers[] = {25, 50, 75, 100};*/
/*		int length = sizeof(myNumbers) / sizeof(myNumbers[0]);*/
/*		for (int i = 0; i < length; i++)*/
/*		{*/
/*				printf("%d\n", myNumbers[i]);*/
/*		}*/
/*		return 0;*/
/**/
/*}*/
/*int main()*/
/*{*/
/*	// Calculate sum, average*/
/*	int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};*/
/*	int sum = 0;*/
/*	int length = sizeof(ages) / sizeof(ages[0]);*/
/*	for (int i = 0; i < length; i++)*/
/*	{*/
/*		sum += ages[i];*/
/*	}	*/
/*	float average = (float) sum / length;*/
/*	printf("Sum: %d\n", sum);*/
/*	printf("Average: %.2f\n", average);*/
/*	return 0;*/
/**/
/**/
/*}*/
/*int main ()*/
/*{*/
/*	int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};*/
/*	int lowest_age = ages[0];*/
/*	int length = sizeof(ages) / sizeof(ages[0]);*/
/*	for (int i = 1; i < length; i++)*/
/*	{*/
/*		if (lowest_age > ages[i])*/
/*		{*/
/**/
/*			int tmp = lowest_age;*/
/*			lowest_age = ages[i];*/
/*			ages[i] = lowest_age;*/
/*		}*/
/*	}*/
/*	printf("Lowest Age: %d\n", lowest_age);*/
/*	return 0;*/
/*}*/
int main(void)
{
		int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
		int i, j;
		for (i = 0; i < 2; i++)
		{
				for (j = 0; j < 3; j++)
				{
						printf("%d\n", matrix[i][j]);
				}
		}
		return 0;

}
