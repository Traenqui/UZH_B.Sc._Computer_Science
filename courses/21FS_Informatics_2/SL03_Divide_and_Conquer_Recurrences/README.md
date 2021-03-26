# Divide and Conquer, Recurrences

## Divide and Conquer

- Recursive algoritms: divide-and-conquer approach
- Principle: if problem size is small enough to be solved trivially then solve it; else

  1. Divide problem into number of subproblems
  2. Conquer subproblems by solving them recursively
  3. Combine solutions of the subproblem into solution for the original problem

- Fundamental properties of a decomposition
  - It reduces the problem to smaller problems
  - Often, these smaller problems are the same as the original problem
  - A sequence of decompositions eventually yields the base case (trivial solution)
  - It must contribute to solving the original problem

### Quick Sort

#### Rough Idea

- Quicksort is a divide-and-conquer algorithm
  - Divide: partition array into two subarrays such that the items in the lower part <= the items in the upper part
  - Conquer: recursively sort the two subarrays
  - Combine: trivial since sorting is in place

```c
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void QuickSort(int A[], int n, int l, int r)
{
    if (l < r)
    {
        int m = LomutoPartition(A, n, l, r) || HoarePartition(A, n, l, r);
        QuickSort(A, n, l, m - 1); // smallest Elements
        QuickSort(A, n, m + 1, r)  // largest Elements

        // Important no Merge needed at the end
    }
}

int LomutoPartition(int A[], int n, int l, int r)
{
    // pivot (Element to be placed at right position)
    int pivot = A[r]; // middle element (pivot) (we take rightmost element as middle element)
    int i = l - 1;
    for (int j = l; j < r - 1; j++) { // elements l..r-1 are inserted into either the smaller or larger part

         // If current element is smaller than the pivot
        if (A[j] < pivot)
        {
            i = i + 1; // increment index of smaller element
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int HoarePartition(int A[], int n, int l, int r)
{
    int p = A[(l + r) / 2];
	int i = l - 1;
	int j = r + 1;
	while (true) {
		do {
			i++; // searches in the left part for a wrong (too large) element
		} while (A[i] < p);

        do {
			j--; // searches in the right part for a wrong (too small) element
		} while (A[j] > p);

        if (i >= j) {
            return j;
        } else {
		    swap(&A[i], &A[j]); // Swap of "wrong" elements
        }

	}
}

int main()
{
    int A = {7,8,2,6,5,1,3};

}
```

**Performance**
Worst Case

- Occurs when the array is already completely sorted
- Partitioning produces one subproblem with $n − 1$ items and one with 0 elements
- If such a partitioning arises at each recursive call then $T (n) = T (n − 1) + T (0) + Θ(n) = T (n − 1) + Θ(n)$
  where $Θ(n)$ is the cost of partitioning the array
- Sum of the costs incurred at each level of the recursion yields an arithmetic series (i.e., $\sum{i=0}^{n}i$)
- It thus follows that, in the worst case, $T(n) = Θ(n^{2})$

Best Case

- Partitioning produces two subproblems of size $n/2$
- If such a partitioning arises at each recursive call then
  $T (n) = 2T (n/2) + Θ(n)$
- It thus follows that, in the best case, $T (n) = Θ(n lg n)$

Average case

- Actually much closer to best case than to worst case
- Quick sort’s behavior is determined by the ordering of the array elements
- In average, there is a mix of “good” and “bad” splits
- Underlying assumption: all permutations of the input numbers are equally likely
- Randomized algorithm: partition around random item (instead of last item)
  - Running time is independent of input ordering
  - No specific input triggers worst case behavior
  - Worst case determined only by output of the random-number generator
- Randomization is a general tool to improve algorithms with bad worst-case but good average-case complexity

https://www.geeksforgeeks.org/quick-sort/

### Merge Sort

Closely follows the divide-and-conquer paradigm
To sort an n-element sequence proceed as follows

- **Divide**: divide the sequence into two n/2-element sequences
- **Conquer**: sort the two sequences recursively using merge sort
- **Combine**: merge the two sorted sequences to produce the solution

Recursion stops when the sequence that must be sorted has length 1.

```c
void mergeSort(int A[], int l, int r){
    if (l < r){
        int m = floor((l+r)/2);
        mergeSort(A,l,m);
        mergeSort(A,m+1,r);
        merge(A,l,r,m);
    }
}

void merge(int A[], int l, int r, int m){
    int B[100];

    int bSize=0;
    for (int i=l; i <= m;i++){
        B[i] = A[i];
        bSize++;
    }
    for (int i=m+1; i<r; i++){
        //reverse filling
        B[r+m-i+1] = A[i];
        bSize++;
    }

    int nA = sizeof(B)/sizeof(B[0]);
    int i=l;
    int j=r;

    for (int k=l; k<r;k++){
        if (B[i] < B[j]){
            A[k] = B[i];
            i=i+1;
        } else {
            A[k] = B[j];
            j=j-1;
        }
    }

}
```

**Time Complexity**: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.

**T(n) = 2T(n/2) + Theta(n)**

The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is **Theta(nLogn)**.

Time complexity of Merge Sort is **Theta(nLogn)** in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and take linear time to merge two halves.

Auxiliary Space: **O(n)**

Algorithmic Paradigm: Divide and Conquer

Sorting In Place: No in a typical implementation

## Recurrences

Informal definition

- Running times of algorithms with recursive calls can be described using recurrences
- A recurrence is an equation or inequality that describes a function in terms of tits value on smaller inputs
- Example: the running time of merge sort is described by the following recurrence

T(n)
= Θ(1) | if n=1
= 2T(n/2) + Θ(n) | if n > 1

### Solving recurrences

#### Repeat (backward) substitution

- Is not a strictly formal proof
- The procedure is straightforward
  - Substitute, expand, substitute, expand, etc.
  - Observe a pattern and determine the expression after the 􏰀 i-th substitution
  - Find out what the highest value of i should be to get the base case of the recurrence
  - Insert the cost of the base case and the expression for i into the observed expression

Observe pattern

```
  T (n)
= 2T (n/2) + 2n + 3                  // Substitute
= 2(2T (n/4) + n + 3) + 2n + 3       // Expand
= 4T (n/4) + 4n + 9                  // Substitute
= 4(2T(n/8) + n/2 + 3) + 4n + 9      // Expand
=8T(n/8)+3·2n+(4+2+1)3               // Find Pattern
```

= 2<sup>i</sup>T(n/2<sup>i</sup>) + 2in + 3 ∑ <sup>i−1</sup><sub>j=0</sub> 2j

- Upper boun for i is **lg n**
- Insert this for i and simplify
- -> **Θ(n lg n)**

#### Substitution method

Basic methodology

- The substitution method for solving recurrences entails two steps
  1. Guess the form of the solution
  2. Use induction to prove the solution

```
Example: consider the recurrence T (n) = 4T (n/2) + n

Guessed solution: T(n) = n^3, i.e. T(n) is of the form n^3

Mathematical induction: need to show that T (n) ≤ cn^3

Need to show that T(n) ≤ cn3 for T(n) = 4T(n/2) + n

    T (n)   = 4T (n/2) + n          (recurrence)
            ≤ 4c(n/2)^3 + n         (inductive hyp.)
            = cn^3/2 + n            (simplification)
            = cn^3 − (cn^3/2 − n)   (rearrangement)
            ≤ cn3                   (for c ≥ 2, n ≥ 1)


It follows that T (n) = O(n3)
```

#### Recursion trees

Basic methodology

- A recursion tree is a convenient way to visualize what happens when a recurrence is iterated
- Good for guessing asymptotic solutions to recurrences
- Example:consider T(n) = T(n/4) + T(n/2) + n^2

Tree will give you a guess which you will use to do a substitution.

#### Master method

To solve a class of recurrences that have the form

> T(n) = aT(n/b) + f(n)

Assumptions:

- a ≥ 1,
- b > 1,
- f(n) asymptotically positive

- T (n) describes running time of a divide-and-conquer algorithm
  - a subproblems of size n/b are solved recursively, each in timeT(n/b)
  - f(n) is the cost of dividing the problem and combining the solutions

```
T(n) = f(n) + aT(n/b)
= f(n) + af(n/b) + aT(n/b2)
= f (n) + af (n/b) + a2 f (n/b2 ) + . . .
+ alogb n−1f(n/blogb n−1) + alogb nT(1) = 􏰈logb n−1 aif(n/bi) + Θ(nlogb a)
i=0
```

- logb n levels
- a <sup>log b n</sup> = n <sup>log b a </sup> (leaves)

Underlying intuitions

- Three possible cases
  - Running time dominated by the cost at the root (case 3)
  - Running time domiated by the cost at the leaves (case 1)
  - Running time evenly distributed throughout tree (case 2)
- Solve recurrence by identifying dominant term
- In each case compare f(n) with n <sup>log<sub>b</sub> a</sup>

**Case 1**: f(n) = O(nlogb a−ε) yields T(n) = Θ(nlogb a)
**Case 2**: f(n) = Θ(nlogb a) yields T(n) = Θ(nlogb a logb n)
**Case 3**: f(n) = Ω(nlogb a+ε) and af(n/b) ≤ cf(n) (c < 1, n > n0) yield T(n) = Θ(f(n))n
