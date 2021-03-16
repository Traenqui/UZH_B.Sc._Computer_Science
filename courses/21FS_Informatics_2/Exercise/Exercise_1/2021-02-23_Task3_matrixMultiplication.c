#include <stdio.h>

int rowColCalc(int row, int column, int a[3][3], int b[3][3]) {
  int res = 0;

  for (int i = 0; i < 3; i++) {
    res = res + a[row][i] * b[i][column];
  }
  return res;
}

void matMul(int a[3][3], int b[3][3]) {
  int res[3][3];

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      res[row][column] = rowColCalc(row, column, a, b);
    }
  }

  // print
  for (int row = 0; row < 3; row++) {
    printf("Row %d of the result: ", row);
    for (int column = 0; column < 3; column++) {
      printf("%d ", res[row][column]);
    }
    printf("\n");
  }
}

int main() {
  // variables
  int mat_a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int mat_b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  matMul(mat_a, mat_b);
  return 0;
}
