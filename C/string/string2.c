#include <stdio.h>
#include <string.h>


int main(void)
{
	// String length, sizeof 
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("%d\n", strlen(alphabet));
	printf("%d\n", sizeof(alphabet));
	// Concatenate Strings
	char str1[20] = "Hello, ";
	char str2[] = "World!";
	strcat(str1, str2);
	printf("%s\n", str1);
	// Copy Strings
	char str3[20] = "Hi, Yetian";
	char str4[20];
	strcpy(str4, str3);
	printf("%s\n", str4);
	// Compare Strings
	char str5[] = "Hi, Yetian";
	printf("%d\n", strcmp(str4, str5)); // Return 0 (the strings are equal)
	printf("%d\n", strcmp(str4, str1)); // Return 4 (the strings aren't equal)
	return 0;
}
