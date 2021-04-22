# Induction and recursion

## An algorithmic language

Conditional instructions are denoted either as

```
if(condition)
  then s1
  else s2
```

or

```
if(condition) then s<sub>1</sub>
```

### While loop

```
while(condition)
  [statments that make up
  the body of the loop]
end while
```

### For loop

```
for variable := initial expression to final expression
  [statments that make up
  the body of the loop]
next (same) variable
```

### Recursion

```
function f(integer n)
  if(n = 0) then return 1
  else return 2 * f(n-1)
```

### Algorithm Correctness

Proving that a program is correct is not easy and is a large field of study. However, this problem often boils down to proving that the algorithm is mathematically correct.

Since iterative algorithms represent the most part of computer programs (remember that algorithms are good to replace humans at repeated actions), we will concentrate on studying the correctness of iterative or recursive algorithms. To do so, we will use the principle of mathematical induction.

## Sequences

- Since iterative/recursive algorithms solve a problem one step at a time, it makes sense to introduce the concept of a sequence
- In mathematics, a sequence is as a set of elements that can be indexed by an integer number (in computer science, such data structure is called array)
- Each individual element 𝑎𝑎𝑘𝑘 is called a term, where 𝑘𝑘 is called a subscript or index

## Mathematical induction

The simplest and most common form of mathematical induction infers that a statement involving a natural number n (that is, an integer n ≥ 0 or 1) holds for all values of n. The proof consists of two steps:

1. The initial or base case: prove that the statement holds for 0, or 1.
2. The induction step, inductive step, or step case: prove that for every n, if the statement holds for n, then it holds for n + 1. In other words, assume that the statement holds for some arbitrary natural number n, and prove that the statement holds for n + 1.

The hypothesis in the inductive step, that the statement holds for a particular n, is called the induction hypothesis or inductive hypothesis. To prove the inductive step, one assumes the induction hypothesis for n and then uses this assumption to prove that the statement holds for n + 1.

Authors who prefer to define natural numbers to begin at 0 use that value in the base case; those who define natural numbers to begin at 1 use that value.

### Step by step

1. Define some property P(n) that you'll prove by induction. When writing an inductive proof, you'll be proving that some property is true for 0 and that if that property holds for n, it also holds for n + 1. To make explicit what property that is, begin your proof by spelling out what property you'll be proving by induction. We've typically denoted this property P(n). If you're having trouble with this, don't worry! There's a section later on in this handout describing what this P(n) thing is all about.
2. State the the proof is by induction. After you've written out your property P(n) in step (1), say that you're going to prove, by induction, that it's true for all the numbers you care about. If you're going to prove P(n) is true for all natural numbers, say that. If you're going to prove that P(n) is true for all even natural numbers greater than five, make that clear. This gives the reader a heads-up about how the induction will proceed.
3. State and prove your base case. All inductive proofs require some kind of base case, so it's probably best to start off by proving it. You've defined what P(n) is in step (1), and now you need to prove P(0). We recommend explicitly writing out what P(0) actually states before you try to prove it. This will communicate to your reader what you're going to prove and helps make it clearer what you need to show. For example, you might write “We will prove P(0), which states that ...” or “For our base case, we'll prove P(0), namely, that …”
4. State and prove the inductive step. The inductive step in a proof by induction is to show that for any choice of k, if P(k) is true, then P(k+1) is true. Typically, you'd prove this by assuming P(k) and then proving P(k+1). We recommend specifically writing out both what the assumption P(k) means and what you're going to prove when you show P(k+1). As with step (3), this makes it clearer to the reader what they're going to see next and helps you confirm that you know what you're assuming and what you're proving.
5. Conclude the proof. This usually isn't too much – you can just say something like “completing the proof by induction” and add the little boxy ■ symbol. You're done!

## Recurrences

A recurrence relation for a sequence is a formula that relates each term to some of its predecessors with some initial values

```
a_0, a_1 ...
a_k = f(a_(k-1))

```

### Terminology

- If a\_(k) depends on its predecessor (a\_(k-1)), it is called first order recurrence realation
- If a\_(k) depends on its predecessor (a\_(k-1), a\_(k-2)), it is called second order recurrence realation

Suppose you have a sequence that satifies a certain recurrence relation with initial conditions

```
a_0, a_1, ... , a_(i-1)
a_k = f(a_(k-1), a_(k-2), ..., a_(k-j))
```

How do you find a explicit formula?

This may be very difficult (and sometimes impossible) but the most basic method is called iteration:

1. Start with the initial conditions and calculate successive terms until you see a pattern
2. Guess an explicit formula
3. Prove (or disprove) the formula

### Arithmetic Sequences

Each term of an arithmitic sequence is obtained by adding a constant to its predecessor

```
a_n = a_(n-1) + d
```

where d is a constant and a_0 is the initial value.

### Geometric Sequences

Ech term of a geometric sequence is obtained by multiplying its predecessor by a constant

```
a_n = r * a_(n-1)
```

where r is a constant and a_0 is the initial value.

Many computer science problems involve the sum of geometric sequences

- e.g. modeling the onset of a pandemic
- e.g. computing the interest accumulated after n years
- ...

## Recursive functions

- A function is said to be a recursive function if its rule of definition refers to itself.
- A recursive function has one or more base case and one or more recursive calls to itself.
- If we know the base cases are correct, and that we get the correct solution assuming the recursive calls work, then by the principle of induction we know that the function is correct.

### Recursion vs. Iteration

Any recursive algorithm can be transformed into a iterative one and vice versa, although converting a recursive one into an iterative one may be more difficult.

- **Advantages of recursion**:

  - **Easier to implement** for complex problems (e.g., Tower of Hanoi, Tromino problem)
  - More **elegant** and **easier to interpret** algorithms
  - More **concise** (fewer lines of code)

- **Disadvantages of recursion**
  - Recursion repeatedly invokes the same function: **more expensive** in processor **time** and **memory space**

## Correctness of algorithms

- **A program is correct if it produces the correct output for a set of expected inputs** (the expected outputs and expected inputs are specified in the documentation accompanying the program)
- Since **iterative algorithms represent the most part of computer programs** (remember that algorithms are meant to replace humans at repeated actions), we will concentrate on studying the **correctness of iterative or recursive algorithms**.
- To do so, we will use the method of the loop invariant, which is based on the principle of mathematical induction.

Consider an iterative/recursive algorithm that is designed to produce a certain final state from a certain initial state. Both the initial and final states can be expressed as properties involving the
input and output variables.

### Pre-Condition

The property for the initial state is called pre-condition for the algorithm and determines the domain of acceptable inputs for the algorithm.

```
Example: in gcd(A,B). pre-condition is:
"A and B are integers with A > B >= 0"
```

### Post-Condition

The property for the final state is called post-condition for the algorithm and determines what the algorithm is supposed to compute.

```
Example: in gcd(A,B), the post-condition is:
a = gcd(A,B)
```

### Correctness of Iterative/Recursive Algorithms

An iterative/recursive algorithm is correct if and only if, whenever the input variables belong to the domain of acceptable inputs and the algorithm terminates after a finite number of steps, the algorithm returns the correct output.

More formally:

An iterative/recursive algorithm is correct with respect to its pre and post- condition if and only if, whenever the algorithm variables satisfy the pre- condition and the algorithm terminates after a finite number of steps, the algorithm variables satisfy the post-condition.

### Loop Invariant

A loop invariant is a property P(n) for a loop defined on a set of integers satisfying the condition:

- For each iteration k of the loop, if the P(k) is true before the generic iteration k, then it is true after iteration, that is: P(k) -> P(k + 1) is true.

The method of loop invariants is used to prove the correctness of a loop with respect to certain pre- and post-conditions based on the principle of mathematical induction.
Entry to the loop is restricted by a condition G, called the guard.

```
[Pre-Condition for the loop]
while(G)
  [Statment in the body of the loop. None contain branching statments that lead outside the loop]
end while
[Post-Condition for the loop]
```

Let 𝑃(n) be the loop invariant for a loop. If the following four properties are true, then the loop is correct with respect to its pre and post-conditions:

1. Basis property: P(0) is true. P(0) is P(n) before the first iteration of the loop.
2. Inductive property: for any integer k ≥ 0, if the guard 𝐺𝐺 and the loop invariant P(k) are both true before an iteration of the loop, then P(k + 1) is true after iteration.
3. Eventual Falsity of the Guard: after a finite number of iterations of the loop, the guard G becomes false.
4. Correctness of the post-condition: if N is the least number of iterations after which G is false and P(n) is true, then the post-condition is satisfied

### Correctness of the Factorial algorithm

Let P(n): "fact = n!" be the loop invariant

1. **Basis property**: P(0) corresponds to the base case where the loop has not yet started. This is the case when n = 0. In this case fact = 1, and this is true because 0! = 1. So P(0) is true.
2. **Inductive property**

- inductive hypothesis: assume G and P(k) true for an arbitrary iteration k, that is assume "fact(k) = k!" is true
- We want to verify that P(k + 1) is true, i.e. fact(k+1) = (k + 1)!
- **Proof**
  - We observe that at the next iteration:

3. Eventual Falsity if the Guard:

- We want to verify whether, after a finite numbers of iterations of the loop, G becomes false
- We observe that at the end of each iteration k increases by 1
- Therefore, after n iterations, k will bekomm greater than n, making the guard G become false, which in turn will make the loop terminate

4. Correctness of the post-condition:

- if N is the least number of iterations after which G is false and P(N) is true, we want to verify whether the post-condition is satisfied
- So we want to verify that fact = N! which is true because the value of fact has not changed after the loop terminated.
