# Summary SL05 - Abstract Data Types & Pointers

## Dynamic data structures

### Pointer

Informal definition of pointers:

- A common technique is to allocate storage space dynamically
- That means the storage space (memory) is allocated during runtime
- Compiler reserves space only for addresses to these dynamic parts
- These addresses are usually called pointers

**Pointer** points to an address.

#### Pointers in C

To follow (chase, dereference) a pointer we write `*p`

```c
    *p = 12
```

<br>

To get the address of a variable `i` we write `&i`

```c
    p = &i
```

<br>

To allocate memory we use `malloc(sizeof(Type))`

```c
p = malloc(sizeof(int))
```

<br>

To free storage space pointed to by a pointer p we use `free`

```c
free(p)
```

<br>

Declaring pointer to type `T` we write `T*`

```c
int* p
```

`*` is used for two purposes:

- Declaring a pointer variable
  ```c
  int* p
  ```
- Following a pointer
  ```c
  *p = 15
  ```

### Linked lists

- A list of integer root -> 3 -> 4->5-|

```c
struct node {
    int val;    //value
    struct node* next; // pointer
}

struct node* root; //starting point
```

**Accessing a field:**

```c
(*p).a
// or more conveninet
p->a
```

**Creating List 88-> 52->12-|**

```c
root = malloc(sizeof(struct node));
root->val = 88;
root->next = malloc(sizeof(struct node));

p = root->next;
p->val = 52;
p->next = malloc(sizeof(struct node));

p = p->next;
p->val = 12;
p->next = NULL;
```

Example for all the basic operations.

```c
// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int item;
  struct Node* next;
};

void insertAtBeginning(struct Node** ref, int data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the item
  new_node->item = data;
  new_node->next = (*ref);

  // Move head to new node
  (*ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* node, int data) {
  if (node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = node->next;
  node->next = new_node;
}

void insertAtEnd(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *ref;

  new_node->item = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(struct Node** ref, int key) {
  struct Node *temp = *ref, *prev;

  if (temp != NULL && temp->item == key) {
    *ref = temp->next;
    free(temp);
    return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->item != key) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->item);
    node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);
}
```

#### Doubly linked list

Variants of linked lists

- Lists with explicit tail

  - Do have an extra pointer to the last item of the list
  - No need to scan the entire list if an operation applies only to the last item

- Doubly linked list
  - Each node has a field with a pointer to the previous node of the linked list
  - Provides means to quickly navigate forth and back in the linked list

Creating a node for a doubly linked list.

```c
struct node {
    int data;
    struct node *next;
    struct node *prev;
}
```

## ADT: abstract data types

An abstract data type is a mathematical model that defines a data type by its behavior from the point of view of a user (in terms of possible values, possible operations, and the behavior of operations).

It is equipped with a specific interface, i.e., a collection of signatures for the operations that can be invoked on an instance

Furthermore, it is equipped with a set of axioms (pre- and postconditions) that define the semantics of each operation (i.e. what the operations do to instances of the ADT, but not how)

Similarity with OO-paradigm

- ADT = instance variables + procedures
- Class = instance variables + methods

Some popular examples

- Stacks & queues
  - LIFO vs. FIFO principle
- Priority queues
  - Another application of heaps
- Ordered lists
  - Linked lists where items are ordered according to a key

### Stacks

Properties of stacks

- In a stack, insertion and deletion follow the last-in, first-out (LIFO) principle
- Hence, the item that has been in the stack for the shortest time is deleted first
  - Example: elimination of recursion
- Implemented by a data structure where items are
  - inserted at the end/beginning (push)
  - removed from the end/beginning (pop)
- Appropriate data structures for their implementation
  - arrays (end) or singly linked lists (beginning)

We design a solution for a single stack (i.e., stack is implicit; not a parameter in operations)

**Array implementation**

- Inserting and removing items from a stack

```c
void push(x)
    S[t] = x;
    t = t+1;
```

```c
int pop()
    t = t-1;
    return S[t];
```

- The stack is implemented by an array S[1..n] of length n
- The variable $t$ functions as pointer to top of the stack
- $S$ and $t$ are global variables.
- Notice that if **t = 1** then the stack is actually empty
- Error checking for under/overflow has been omitted

Example of basic operations with stacks.

```c
// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

// Creating a stack
struct stack {
  int items[MAX];
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Check if the stack is full
int isfull(st *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(st *s, int newitem) {
  if (isfull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Remove element from stack
void pop(st *s) {
  if (isempty(s)) {
    printf("\n STACK EMPTY \n");
  } else {
    printf("Item popped= %d", s->items[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Print elements of stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int ch;
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  printf("\nAfter popping out\n");
  printStack(s);
}
```

### Queues

**Properties of queues**

- In a queue, insertion and deletion follow the first-in, first-out (FIFO) principle
- Hence, the item that has been in the queue for the longest time is deleted first
  - Example: managing jobs of a printer
- Implemented by a data structure where items are
  - inserted at the end/beginning (enqueue)
  - removed from the beginning/end (dequeue)
- Appropriate data structures for their implementation
  - arrays or singly linked lists with an explicit tail (handy for dequeuing)

We design a solution for a single queue (i.e., queue is implicit; not a parameter in operations)

**Enqueue and Dequeue**

```c
void enqueue(int x){
    Q[t] = x;
    t = t+1 mod n;
}

int dequeue(){
    int i = h;
    h = h+1 mod n;
    return Q[i];
}
```

- The queue is implemented by an array $Q[0..n − 1]$ of length $n$ used in **circular fashion**
- Variables $h$ and $t$ function as pointers to head and tail of the queue
- Notice that if $h = t$ then the queue is actually empty

Example of a basic queue implementation

```c
// Queue implementation in C

#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
  //deQueue is not possible on empty queue
  deQueue();

  //enQueue 5 elements
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // 6th element can't be added to because the queue is full
  enQueue(6);

  display();

  //deQueue removes element entered first i.e. 1
  deQueue();

  //Now we have just 4 elements
  display();

  return 0;
}

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}
```

### Ordered Lists

- In an ordered list elements are ordered according to a key
- We design a solution for multiple ordered queues (the ordered queue is a parameter in operations)
- all arguments in procedures and functions are copies
  - give a copy of doc to somebody
  - copy is changed
  - original is still unchanged
- `node** l`- pointer to a pointer to a node, why? ensures that l never changes

```c
struct node {
    int val;
    struct node* next;
};
struct node** init() {
    struct node **l;
    l = malloc(sizeof(struct node**));
    *l = NULL;
    return l;
}

int first(struct node** l) {
    if (*l == NULL) return -1;
    else return (*l)->val;
}

void insert(struct node** l, int x) {
    struct node* p;
    struct node* q;
    if (*l == NULL || (*l)->val > x) {
        p = malloc(sizeof(struct node));
        p->val = x;
        p->next = *l;
        *l = p;
    } else {
        p = *l;
        while (p->next != NULL && p->next->val < x){
            p = p->next;
        }
        q = malloc(sizeof(struct node));
        q->val = x;
        q->next = p->next;
        p->next = q;
    }
}

struct node* root1;
struct node* root2;
```
