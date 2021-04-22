# SL04 Heapsort & Quicksort

## Binary Trees

- Each node may have a left or a right **child**.
- Each node has at most one **parent**
- The **root** has no parent
- A **leaf** has no children
- The **depth** (level) of a node x is the length of the path from the root to x
- The **height** of a node x is the length of the longest path from x to a leaf
- The **right subtree** of a node x is the tree rooted at the right child of x
- The **left subtree** of a node x is the tree rooted at the left child of x

### Complete trees

- A **complete binary tree** is a binary tree where
  - all the leaves have the same depth
  - all internal nodes have two children
- A **nearly complete binary tree** is a binary tree where
  - all levels of non-maximal depth $d$ are full (have $2^{d}$ nodes)
  - all the leaves with maximal depth are as far left as possible

## Heapsort

### Heap

- A binary tree is a (binary) **heap** if and only if
  - it is a nearly complete binary tree and, furthermore,
  - each node is greater than or equal to all its children

**Fundamental Properties**

- Let $i$ be a node index.
- Heap property: `A[parent(i)] >= A[i]`
- A binary heap can be efficiently stored as an array

  - Because it is a nearly complete binary tree.

- Finding parent, left child, and right child:

  ```
      Algo: Parent(i)
      return ⌊i/2⌋;

      Algo: Left(i)
      return 2*i;

      Algo: Right(i)
      return 2*i + 1;
  ```

**Max-Heap** is where the largest element is at the root.
**Min-Heap** is where the smallest element is at the root.

### Heapify

- Heapify takes as **inputs**:

  - Array $A$
  - index $i$ in Array $A$
  - number of heap elements

- Binary trees rooted at left(i) and right(i) are binary heaps
- $A[i]$ may be smaller than its children, thus violating the heap property
- `heapify(A, i, s)` transforms the binary tree rooted at i into a binary heap
- Strategy: move $A[i]$ down the heap until the heap property is satisfied again

```c
void Heapify(int A[], int i, int s){
    int m = i;
    int l = Left(i);
    int r = Right(i);

    // Checks if left exists and if left elements is larger than parent
    if (l < s && A[l] > A[m]){
        m = l;
    }

    // Checks if right exists and if right elements is larger than parent
    if (r < s && A[r] > A[m]){
        m = r;
    }


    if (i != m){
        exchange(A[i], A[m]);
        Heapify(A, m, s);
    }
}
```

**Running Time**

- The running time of heapify on a subtree of size n rooted at $i$ includes time to
  - determine relationship between elements: $Θ(1)$
  - run heapify on a subtree rooted at one of $i$'s children
- $2n/3$ is the worst case size of the subtree (half filled bottom level) and thus

  - T(n) <= T(2n/3) + Θ(1), ie. T(n) = O(lg n)

### Insert a Node

Algorithm for insertion in a Max Heap

```
If there is no node,
  create a newNode.
else (a node is already present)
  insert the newNode at the end (last node from left to right.)

heapify the array
```

The new node will be compared with its parent, and exchanged to fit the Max Heap criteria. In other words it wanders to the root.

```c
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
```

### Delete Element from Heap

Algorithm for deletion in Max Heap

```
If nodeToBeDeleted is the leafNode
  remove the node
Else swap nodeToBeDeleted with the lastLeafNode
  remove noteToBeDeleted

heapify the array
```

Swap the selected Element with the last element of the Array. Remove it and heapify the array.

```c
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
```

### Build Heap

Build a Heap from an Array A with n elements into a heap

- Note that elements in A[⌊n/2⌋+1...n] are 1-element heaps

```c
void BuildHeap(int A[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
}
```

**Running Time**

- There are O(n) calls to heapify and so T(n) = O(n lg n)
- Not an asymptotically tight bound - but good enough for an overall $O(n lg n)$ bound for heap sort
- Intuition for tight bound: time for heapify to run at a node i varies with the height of i
  - An n-element binary heap has height lg n
  - The heap has at most $⌈n/2h+1⌉$ nodes of height $h$
  - The cost for one call of heapify is O(h)

### Heap Sort

```c
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
```

**Running time**
Heapsort runs in time $O(n)+ n O(lgn)=O(nlgn)$

**How Heap Sort works?**

1. Since the tree satisfies Max-Heap property, then the largest item is stored at the root node.
2. **Swap**: Rwmove the root element and put at the end of the array (nth position). Put the last item of the tree (heap) at the acant place
3. **Remove**: Reduce the heap by 1
4. **Heapify**: Heapify the root element again so that we have the highest element at root
5. The process is repeated until all the items of the list are sorted.

## Quicksort

### Rough Idea

- Quicksort is a divide-and-conquer algorithm
  - Divide: partition array into two subarrays such that the items in the lower part <= the items in the upper part
  - Conquer: recursively sort the two subarrays
  - Combine: trivial since sorting is in place

### Hoare's Partition

Hoare’s Partition Scheme works by initializing two indexes that start at two ends, the two indexes move toward each other until an inversion is (A smaller value on the left side and greater value on the right side) found. When an inversion is found, two values are swapped and the process is repeated.

```
partition(arr[], lo, hi)
   pivot = arr[lo]
   i = lo - 1  // Initialize left index
   j = hi + 1  // Initialize right index

   // Find a value in left side greater
   // than pivot
   do
      i = i + 1
   while arr[i] < pivot

   // Find a value in right side smaller
   // than pivot
   do
      j--;
   while (arr[j] > pivot);

   if i >= j then
      return j

   swap arr[i] with arr[j]
```

### Lomuto Partition

This scheme chooses a pivot that is typically the last element in the array.

```
partition(arr[], lo, hi)
    pivot = arr[hi]
    i = lo     // place for swapping
    for j := lo to hi – 1 do
        if arr[j] <= pivot then
            swap arr[i] with arr[j]
            i = i + 1
    swap arr[i] with arr[hi]
    return i
```

### Implementation

```c
void QuickSort(int A[], int n, int l, int r){
    if (l<r){
        int m = LomutoPartition(A, n, l, r) || HoarePartition(A, n, l, r);
        QuickSort(A, n, l, m-1); // smallest Elements
        QuickSort(A, n, m+1, r)  // largest Elements

        // Important no Merge needed at the end
    }
}


int LomutoPartition(int A[], int n, int l, int r){
    int x = A[r]; // middle element (pivot) (we take rightmost element as middle element)
    int i = l-1;
    for(int j=l; j< r-1; j++){ // elements l..r-1 are inserted into either the smaller or larger part
        i = i+1; // smaller part grows by one
        exchange(A[i], A[j]);
    }
    exchange(A[i+1], A[r]); // putting pivot in right place
    return i+1;
}


int HoarePartition(int A[], int n, int l, int r){
    int x = A[r];
    int i = l-1;
    while (true){
        repeat j=j-1 until A[j] < x; // searches in the right part for a wrong (too small) element
        repeat i=i+1 until A[i] > x; // searches int he left part for a wrong (too large) element
        if (i < j){
            exchange(A[i], A[j]); // Swap of "wrong" elements
        } else {
            return i;
        }
    }
}
```

**Performance**
Worst Case

- Occurs when the array is already completely sorted
- Partitioning produces one subproblem with $n − 1$ items and one with 0 elements
- If such a partitioning arises at each recursive call then $T (n) = T (n − 1) + T (0) + Θ(n) = T (n − 1) + Θ(n)$
  where $Θ(n)$ is the cost of partitioning the array
- Sum of the costs incurred at each level of the recursion yields an arithmetic series (i.e., $\sum\_{i=0}^{n}i$)
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
