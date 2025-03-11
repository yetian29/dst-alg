#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool Palindrome(char s[], int start, int end)
{
	if (start >= end) return true;
	if (s[start] == s[end]) return Palindrome(s, start + 1, end - 1);
	return false;
}

int main(void)
{
	char s[] = "abba";
	int size = strlen(s);
	printf("%s\n", Palindrome(s, 0, size - 1) ? "Yes" : "No");
	return 0;
}
