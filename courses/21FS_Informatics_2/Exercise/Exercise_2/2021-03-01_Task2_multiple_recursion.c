#include <stdio.h>

int sequence(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  if ((n - 1) % 3 == 0)
    return ((sequence(n - 1) / 3) + sequence(n - 2));
  else
    return (sequence(n - 1) + sequence(n - 2));
}

int main() {
  int n, res;
  printf("Enter n: ");
  scanf("%d", &n);

  printf("Sequence: ");
  for (int i = 1; i <= n; i++)
    printf("%d ", sequence(i));

  printf("\n");
  return 0;
}
