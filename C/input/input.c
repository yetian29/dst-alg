#include <stdio.h>

int main(void)
{
	int myNum;
	char myChar;
	char firstName[30];
	char fullName[30];
	printf("Type your full name: ");
	fgets(fullName, sizeof(fullName), stdin);
	printf("Type a number AND a character: ");
	scanf("%d %c", &myNum, &myChar);
	printf("Enter your first name: ");
	scanf("%s", firstName);
	printf("Your number is: %d\n", myNum);
	printf("Your char is: %c\n", myChar);
	printf("Hello, %s\n", firstName);
	printf("Hello %s\n", fullName);
	return 0;
}
