#include <stdio.h>


int main(void)
{
		int myNumbers[] = {25, 50, 75, 100};
		// Access the Elements of an Array
		printf("%d\n", myNumbers[0]);
		// Change an Array Element
		myNumbers[0] = 19;
		printf("%d\n", myNumbers[0]);
		// Loop Through an Array
		int i;
		for (i = 0; i < 4; i++)
		{
				printf("%d\n", myNumbers[i]);
		}
		// Set Array Size
		int myNumbers[4];
		myNumbers[0] = 25;
		myNumbers[1] = 20;
		myNumbers[2] = 50;
		myNumbers[3] = 75;
		myNumbers[4] = 100;
		// Avoid Mixing Data Types
		int myArray[] = {25, 59, 75, 3.15, 5,99};
		return 0;
}
