#include <stdio.h>

int main(void)
{
	char greetings[] = "Hello, World!";
	greetings[0] = 'J';
	printf("%s\n", greetings);
	printf("%c\n", greetings[0]);

	int i, length = sizeof(greetings) / sizeof(greetings[0]);
	for (i = 0; i < length; i++)
	{
		printf("%c\n", greetings[i]);
	}
	return 0;
}
