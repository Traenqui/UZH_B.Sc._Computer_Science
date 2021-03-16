# Exercise 1

## Goals

- Declare, initialize and use C data type: char, integer.
- Declare, initialize and use one-dimensional array and 2-dimensional array in C.
- Write for-loop in C and, printf function.
- Implement selection sorting algorithm in C.

## Indroduction to C

### Task 1. Reverse String

Write a C program with a function void reverse(char s[]) that reverses and prints a given string. Assume that all strings are at most 1000 characters long. Your program should prompt the user for an input string, read the string (terminated by a new line), and print the reversed string to the screen. Do not use any built-in library functions in this task. An input/output example is illustrated below (input is typeset in bold):

```
Please enter a string to reverse: Hello World!
Result String: !dlroW olleH
```

### Task 2. Perfect Square Number

A perfect square number is an integer that is the square of another integer. Write a C function with a loop bool isPerfectSquare(int num) that determines whether an integer is a perfect square number or not. Your program should prompt the user to type in an integer. After an integer is typed in, your program prints “TRUE” if it is a perfect square number, otherwise, “FALSE”. Do not use any built-in library functions in this task Two input/output examples are illustrated below (input is typeset in bold):

```
Enter an integer: 25
Perfect Square Number: TRUE
```

```
Enter an integer: 37
Perfect Square Number: FALSE
```

### Task 3. Matrix Multiplication

A matrix of integers is a 2-dimensional array of integers in C. Given two matrices A and B, write a C program to calculate the result of matrix multiplication of A and B. Assume that both A and B are 3 × 3 2-dimensional C arrays. Your program should initialize a 2-dimensional matrix (with any integers you like), calculate the matrix multiplication and print the result row by row. You can verify your result with calculators or any tools.

## Sorting

### Task 4. Selection Sort in Ascending and Descending Order

Write a program in C that reads an array A[0...n-1] with n integers and implements two functions void ascSelectionSort(int A[], int n) and void descSelectionSort(int A[], int n). These function should print the sorted array with ascending or descending respectively. Two input/output examples is illustrated below (input is typeset in bold):

```
Values of A separated by spaces (non-number to stop): 2 10 3 22 15 12 end
Ascending Order: 2 3 10 12 15 22
Descending Order: 22 15 12 10 3 2
```

```
Values of A separated by spaces (non-number to stop): 2 2 3 10 15 12 12 8 9 5 4 end
Ascending Order: 2 2 3 4 5 8 9 10 12 12 15
Descending Order: 15 12 12 10 9 8 5 4 3 2 2
```
