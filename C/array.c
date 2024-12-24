#include <stdio.h>

int main(void)
{
		int myNumbers[] = {25, 50, 75, 100};
		int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
		for (int i = 0; i < length; i++)
		{
				printf("%d\n", myNumbers[i]);
		}
		return 0;

}
