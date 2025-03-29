#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool crackPassword(char pwd_attempt[], char pwd[], int current_position)
{
	// Base case
	if (current_position == strlen(pwd))
	{
		if (strcmp(pwd_attempt, pwd) == 0) 
		{
			printf("Password: %s\n", pwd_attempt);
			return true;
		}
		return false;

	}
	
	// Recursive case
	for (int c = 'a'; c <= 'z'; c++)
	{
		pwd_attempt[current_position] = c;
		pwd_attempt[current_position + 1] = '\0';
		if (crackPassword(pwd_attempt, pwd, current_position + 1)) return true;
	}
	return false;

}


int main(void)
{
	char pwd[] = "acbad";
	int size = sizeof(pwd) /sizeof(pwd[0]);
	char pwd_attempt[size];
	for (int i = 0; i < size; i++)
	{
		pwd_attempt[i] = '\0';
	}
	printf("%s\n", crackPassword(pwd_attempt, pwd, 0) ? "Successful": "Fail");
	return 0;
}
