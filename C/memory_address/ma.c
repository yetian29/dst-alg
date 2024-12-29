#include <stdio.h>


int main(void)
{
	int myAge = 24;
	int* ptr = &myAge;
	int myNumbers[4] = {20, 30, 40, 50};
	*myNumbers = 10;
	*(myNumbers + 1) = 15;
	printf("%p\n", myNumbers);
	printf("%p\n", &myNumbers[0]);
	for (int i = 0; i < 4; i++)
	{
		printf("%p\n", &myNumbers[i]);
		printf("%d\n", *(myNumbers + i));
	}
	/*printf("%p\n", &myAge);*/
	/*printf("%p\n", ptr);*/
	/*printf("%d\n", *ptr);*/
	return 0;
}
