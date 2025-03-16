#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool crackPassword(char pwd[], char pwd_attempt[], int current_position, int max_length)
{
	// Compare and print pwd_attempt
	if (strcmp(pwd_attempt, pwd) == 0)
	{
		printf("Password is found: %s\n", pwd_attempt); 
		return true;
	}

	// Base case
	if (current_position == max_length) return false; 


	// Recursive case
	for (char c = 'a'; c <= 'z'; c++)
	{
		// add character into pwd_attempt
		pwd_attempt[current_position] = c;
		pwd_attempt[current_position + 1] = '\0';
		if (crackPassword(pwd, pwd_attempt, current_position + 1, max_length)) return true;
	}
	
}

int main(void)
{
	char pwd_attempt[20] = "", pwd[] = "abc";
	int max_length = strlen(pwd);
	int current_position = 0;
	printf("%s\n", crackPassword(pwd, pwd_attempt, current_position, max_length) ? "True" : "False");
	return 0;
}
