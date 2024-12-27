#include <stdio.h>

int main(void)
{
	// Calculate average, sum, lowestAge of ages
	int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
	int length = sizeof(ages) / sizeof(ages[0]);
	int i, sum = 0;
	float average;

	for (i = 0; i < length; i++)
	{
		sum += ages[i];
	}
	average = (float) sum / length;
	int lowestAge = ages[0];
	for (i = 1; i < length; i ++)
	{
		if (lowestAge > ages[i])
		{
			lowestAge = ages[i];
		}
	}

	printf("The sum ages is: %d\n", sum);
	printf("The average ages is: %.2f\n", average);
	printf("The lowestAge is: %d\n", lowestAge);
	return 0;
}
