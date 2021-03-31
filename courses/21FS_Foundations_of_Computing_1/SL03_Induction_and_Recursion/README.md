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

## Correctness of algorithms

## Fractals
