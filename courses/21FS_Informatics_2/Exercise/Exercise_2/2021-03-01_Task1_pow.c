#include <stdio.h>

int exponent(int x, int pow) {
  if (pow != 0)
    return (x * exponent(x, pow - 1));
  else
    return 1;
}

int main() {
  int base, power;

  printf("Please enter the base: ");
  scanf("%d", &base);
  printf("Please enter the power: ");
  scanf("%d", &power);

  int res = exponent(base, power);
  printf("The result is: %d", res);
  return 0;
}
