# Exercise 3

## Goals

- practice calculation of asymptotic tight bound.
- practice running time analysis
- practice best case and worst case analysis
- identify the influence of a parameter

## Algorithmic Complexity and Correctness

### Task 1.

Consider algorithm whatDoIDo(A, n, k) below. Input array A[] contains n integers, and k is an integer.

1. What does the algorithm whatDoIDo(A, n, k) do?
2. Implement algorithm whatDoIDo(A, n, k) in C, and call your implementation in a complete C program.
3. Conduct an exact analysis of the running time of the algorithm whatDoIDo(A, n, k).
4. Determine the best and worst case of the algorithm. What is the running time and asymptotic complexity in each case
5. What influence does the parameter k have in the asymptotic complexity?
6. List special cases, and provide an example for each special case if possible.

### Task 2.

Calculate the asymptotic tight bound for the following functions and rank them by their order of growth (lowest first). Clearly work out the calculation step by step in your solution.

### Task 3.

Let n be an exact power of 2, n = 2^k.
Use mathematical induction over k to show that the solution of the recurrence involving positive constants c, d > 0

is T(n) = dn + cn log(n)

_Hint:_ you may want to rewrite the above as T(2^k) = d2^k + c2^klog(2^k) = d2^k + c2^k \* k
