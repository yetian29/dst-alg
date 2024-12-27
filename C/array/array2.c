#include <stdio.h>

int main(void)
{
	// Get Array Size or Length
	int myNumbers[] = {10, 25, 50, 75, 100};
	int length = sizeof(myNumbers) / sizeof(myNumbers[0]);
	printf("%lu\n", sizeof(myNumbers));
	printf("%d\n", length);
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d\n", myNumbers[i]);
	}
	return 0;
}
