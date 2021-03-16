#include <stdbool.h>
#include <stdio.h>

bool isPerfectSquare(int num) {
  int i = 0;
  while (i * i <= num) {
    if (i * i == num) {
      return true;
    }
    i++;
  }
  return false;
}

int main() {
  bool isSquare;
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (isSquare) {
    printf("Perfect Square Number: %s\n", "TRUE");
  } else {
    printf("Perfect Square Number: %s\n", "FALSE");
  }
  return 0;
}
