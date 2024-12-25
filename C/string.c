#include <stdio.h>

int main() {
  char greetings[] = "Hello World!";
  greetings[0] = 'J';
  printf("%s\n", greetings);

  return 0;
}
