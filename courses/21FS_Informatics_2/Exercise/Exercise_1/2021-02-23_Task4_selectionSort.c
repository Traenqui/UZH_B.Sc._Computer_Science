#include <stdio.h>
void SelSort(int array[], int n) {
  int i, j, position, swap;
  for (i = 0; i < (n - 1); i++) {
    position = i;
    for (j = i + 1; j < n; j++) {
      if (array[position] > array[j])
        position = j;
    }
    if (position != i) {
      swap = array[i];
      array[i] = array[position];
      array[position] = swap;
    }
  }
  printf("\nAscending Order: ");
  for (int i = 0; i < n; i++)
    printf("%d ", array[i]);
}

void descSelSort(int array[], int n) {
  int i, j, position, swap;
  for (i = 0; i < (n - 1); i++) {
    position = i;
    for (j = i + 1; j < n; j++) {
      if (array[position] > array[j])
        position = j;
    }
    if (position != i) {
      swap = array[i];
      array[i] = array[position];
      array[position] = swap;
    }
  }

  printf("\nDescending Order: ");
  for (int i = n - 1; i >= 0; i--)
    printf("%d ", array[i]);
}

int main() {
  int a[1000];
  int num;
  int i = 0;

  printf("Values of A seperated by spaces (non-number to stop): ");
  while (scanf("%d", &a[i]) == 1) {
    i++;
  }
  num = i;
  scanf("%*s");

  printf("Result: ");
  SelSort(a, num);
  descSelSort(a, num);
  printf("\n");
  return 0;
}
