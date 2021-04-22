# Trees and red-black Trees

## Dictionaries

A dictionary D is a dynamic data structure with the following operations (items have key and data part)

- search (D, v): searches for v in D and, eventually, returns a pointer x such that x.key = v
- delete (D, x): deletes item pointed to by x from D
- insert (D, x): inserts item pointed to by x into D

Furthermore, one may want to support the following operations (which require that keys are comparable)

- minimum (D) and $maximum (D)
- successor (D, v) and $predecessor (D, v)
- (Not always required, Trees support this, hash tables do not support this)

Possible implementations Singly linked lists

- Insert and delete: Θ(1)
- Search, min, max, succ, and pred: Θ(n)
- Ordered lists do not provide a real improvement

Binary search trees

- Binarysearch: Θ(lgn)
- Represent search space as a binary tree
- Insert & delete may yield unbalanced search trees

Balanced binary trees

- Cost of operations: Θ(lgn)
- Red-black trees as divice to keep trees balanced

## Binary Trees
A binary tree is a tree data structure in which each parent node can have at most two children.
### Types of binary Tree

#### Full binary Tree

A full Binary tree is a special type of binary tree in which every parent node/internal node has either two or no children.

#### Perfect Binary Tree

A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.

#### Complete Binary Tree

A complete binary tree is just like a full binary tree, but with two major differences

1. Every level must be completely filled
2. All the leaf elements must lean towards the left.
3. The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.

#### Degenerate or Pathological Tree

A degenerate or pathological tree is the tree having a single child either left or right.

#### Skewed Binary Tree

A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes. Thus, there are two types of skewed binary tree: left-skewed binary tree and right-skewed binary tree.

#### Balanced Binary Tree

It is a type of binary tree in which the difference between the height of the left and the right subtree for each node is either 0 or 1.

### Binary Tree Representation

A node of a binary tree is represented by a structure containing a data part and two pointers to other structures of the same type.

```c
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
```

### Tree Traversal

Traversing a tree means visiting every node in the tree. You might, for instance, want to add all the values in the tree or find the largest one. For all these operations, you will need to visit each node of the tree.

Linear data structures like arrays, stacks, queues, and linked list have only one way to read the data. But a hierarchical data structure like a tree can be traversed in different ways.

#### Inorder traversal

1. First, visit all the nodes in the subtree
2. Then the root node
3. Visit all the nodes in the right subtree

```
inorder(root->left)
display(root->data)
inorder(root->right)
```

and as c Code

```c
// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}
```

#### Preorder traversal

1. Visit root node
2. Visit all the nodes in the left subtree
3. Visit all the nodes in the right subtree

```
display(root->data)
preorder(root->left)
preorder(root->right)
```

and as C code

```c
// preorderTraversal traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
```

#### Postorder traversal

1. Visit all the nodes in the left subtree
2. Visit all the nodes in the right subtree
3. Visit the root node

```
postorder(root->left)
postorder(root->right)
display(root->data)
```

and in C code

```c
// postorderTraversal traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}
```

### Search Operations

The algorithm depends on the property of BST that if each left subtree has values below root and each right subtree has values above the root.

If the value is below the root, we can say for sure that the value is not in the right subtree; we need to only search in the left subtree and if the value is above the root, we can say for sure that the value is not in the left subtree; we need to only search in the right subtree.

```
If root == NULL
    return NULL;
If number == root->data
    return root->data;
If number < root->data
    return search(root->left)
If number > root->data
    return search(root->right)
```

If the value is found, we return the value so that it gets propagated in each recursion step as shown in the image below.

If you might have noticed, we have called return search(struct node\*) four times. When we return either the new node or NULL, the value gets returned again and again until search(root) returns the final result.
If the value is not found, we eventually reach the left or right child of a leaf node which is NULL and it gets propagated and returned.

### Insert Operations

Inserting a value in the correct position is similar to searching because we try to maintain the rule that the left subtree is lesser than root and the right subtree is larger than root.

We keep going to either right subtree or left subtree depending on the value and when we reach a point left or right subtree is null, we put the new node there.

```
If node == NULL
    return createNode(data)
if (data < node->data)
    node->left  = insert(node->left, data);
else if (data > node->data)
    node->right = insert(node->right, data);
return node;
```

The algorithm isn't as simple as it looks. Let's try to visualize how we add a number to an existing BST.

We have attached the node but we still have to exit from the function without doing any damage to the rest of the tree. This is where the return node; at the end comes in handy. In the case of NULL, the newly created node is returned and attached to the parent node, otherwise the same node is returned without any change as we go up until we return to the root.

This makes sure that as we move back up the tree, the other node connections aren't changed.

```c
// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}
```

### Deletion Operations

There are three cases for deleting a node from a binary search tree.

#### Case I

In the first case, the node to be deleted is the leaf node. In such a case, simply delete the node from the tree.

#### Case II

In the second case, the node to be deleted lies has a single child node. In such a case follow the steps below:

1. Replace that node with its child node.
2. Remove the child node from its original position.

#### Case III

In the third case, the node to be deleted has two children. In such a case follow the steps below:

1. Get the inorder successor of that node.
2. Replace the node with the inorder successor.
3. Remove the inorder successor from its original position.

```c
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
```

## Red-Black Tree

Red-Black tree is a self-balancing binary search tree in which each node contains an extra bit for denoting the color of the node, either red or black.

A red-black tree satisfies the following properties:

1. Red/Black Property: Every node is colored, either red or black.
2. Root Property: The root is black.
3. Leaf Property: Every leaf (NIL) is black.
4. Red Property: If a red node has children then, the children are always black.
5. Depth Property: For each node, any simple path from this node to any of its descendant leaf has the same black-depth (the number of black nodes).

Each node has the following attributes:

- color
- key
- leftChild
- rightChild
- parent (except root node)

### How the red-black tree maintains the property of self-balancing?

The red-black color is meant for balancing the tree.

The limitations put on the node colors ensure that any simple path from the root to a leaf is not more than twice as long as any other such path. It helps in maintaining the self-balancing property of the red-black tree.

### Operations on a Red-Black Tree

Various operations that can be performed on a red-black tree are:

#### Rotating the subtrees in a Red-Black Tree
In rotation operation, the positions of the nodes of a subtree are interchanged.

Rotation operation is used for maintaining the properties of a red-black tree when they are violated by other operations such as insertion and deletion.

There are two types of rotations:

#### Left Rotate

In left-rotation, the arrangement of the nodes on the right is transformed into the arrangements on the left node.

**Algorithm**

1. Let the initial tree be:
   ![Initial Tree]()
2. If y has a left subtree, assign x as the parent of the left subtree of y.
   ![Assign x as the parent of the left subtree of y]()
3. If the partent of x is NULL, make y as the root of the tree.
4. Else if x is the left child of p, make y as the left child of p.
5. Else assign y as the right child of p.
   ![Change the parent of x to that of y]()
6. Make y as the prent of x.
   ![Assign y as the parent of x]()

#### Right Rotate

In right-rotation, the arrangement of the nodes on the left is transformed into the arrangements on the right node.

**Algorithm**

1. Let the initial tree be:
   ![Initial Tree]()
2. If x has a right subtree, assign y as the parent of the right subtree of x.
   ![Assign y as the parent of the right subtree of x]()
3. If the parent of y is NULL, make x as the root of the tree.
4. Else if y is the right child of its parent p, make x as the right child of p.
5. Else assign x as the left child of p.
   ![Assign the parent of y as the parent of x]()
6. Make x as the parent of y.
   ![Assign x as the parent of y]()

#### Left-Right and Right-Left Rotate

In left-right rotation, the arrangements are first shifted to the left and then to the right.

1. Do left rotaion on x-y
   ![Left rotate x-y]()
2. Do right rotation on y-z
   ![Right rotate z-y]()

In right-left rotation, the arrangements are first shifted to the right and then to the left.

1. Do right rotation on x-y.
   ![Right rotate x-y]()
2. Do left rotation on z-y.
   ![Left rotate z-y]()
