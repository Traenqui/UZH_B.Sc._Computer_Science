#include <stdio.h>

int pascal(int i, int j) {
  if (i == j)
    return 1;
  if (j == 0)
    return 1;
  return pascal(i - 1, j) + pascal(i - 1, j - 1);
}

void printPascal(int n) {
  for (int row = 0; row < n; row++) {
    printf("Row %d: ", row);
    for (int column = 0; column <= row; column++)
      printf("%d ", pascal(row, column));
    printf("\n");
  }
}

int find_recursive(int row, int totalRow) {
  if (row == totalRow) {
    return 0;
  }
  return 2 + find_recursive(row + 1, totalRow);
}

void formatPascal(int n) {
  for (int row = 0; row < n; row++) {
    printf("%*c", find_recursive(row, n), ' ');
    for (int column = 0; column <= row; column++)
      printf("%d   ", pascal(row, column));
    printf("\n");
  }
}
int main() {
  int rows;

  printf("Enter number of rows: ");
  scanf("%d", &rows);
  formatPascal(rows);

  return 0;
}
