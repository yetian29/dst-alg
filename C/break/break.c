#include <stdio.h>


int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		// Break
		// if (i == 9) break;
		if (i != 6) continue;
		printf("%d\n", i);
	}
	return 0;
}