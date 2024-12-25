#include <stdio.h>

int main(void)
{
	/*int myNum;*/
	/*printf("Type a number: ");*/
	/*scanf("%d", &myNum);*/
	/*printf("Your number is: %d\n", myNum);*/
	/*int myNum;*/
	/*char myChar;*/
	/**/
	/*printf("Type a number AND a character and press enter: \n");*/
	/*scanf("%d %c", &myNum, &myChar);*/
	/*printf("Your number is: %d\n", myNum);*/
	/*printf("Your character is: %c\n", myChar);*/
	/*char firstName[10];*/
	/*printf("Enter your first name: ");*/
	/*scanf("%s", firstName);*/
	/*printf("Hello %s\n", firstName);*/
	/*return 0;*/
	char fullName[10];
	printf("Type your full name: ");
	fgets(fullName, sizeof(fullName), stdin);
	printf("Hello %s", fullName);
}
