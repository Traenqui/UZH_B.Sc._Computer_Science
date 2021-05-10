# Functions and Convolution

## Review of Set Theory

### Cantor's definition of a Set

A set S is a "collection into a whole S of define and separate objects of our intuition or our thought. These objects are called the elements of S"

Basically, a set is a collection of distinct objects. That's it. Nothing else.

- We will use the notation x ∈ S, which means that
  - x is a member of S
  - x is an element of S
  - x is in S
  - S contains x
- The above expressions are all equivalent.

### The empty Set (Ø,{})

The empty set (or null set), denoted by Ø or {}, is the unique set with no elements.

### Ordered Tuples

Let n be a positive integer and x1, x2,..., xn elemets, the following ordered set is called.

- ordered n-tuple (x1, x2,...,xn)
- if n = 2, (x1, x2) is called an ordered pair.
- if n = 3, (x1, x2, x3) is called an ordered triple

### Cartesian Products between two sets

Denoted A x B, the Cartesian product between A and B is the set of ordered pairs of elements of A and B.

More generally, given the sets A1, A2,..., An, the Cartesian product A1 x A2 x ... x An is the set of ordered n-tuples

## Review of Functions

### Definition of a Function

Let X and Y be two sets, a function f form the domain X to the co-domain Y (denoted by f : X -> Y) is a realtion that satisfies two properties.

1. Every element of X is related to some elements in Y
2. No element of X is related to more than one element in Y

Thus, given an element x ∈ X, there is a unique element in Y that is related to x by f, called f(x).

We say that f maps x into f(x)

f(x) is called:

- the output of f for the input x
  the image of x under f

The range of f (or image of X under f) = {y ∈ Y | y=f(x), ∀ 𝑥 ∈ X}

The reverse image of y = {x ∈ X | f(x) = y}

### When are two functions equal?

Let f : X -> Y and g : X -> Y be functions, then f = g if and only if f(x) = g(x) ∀ x ∈ X

## Notable functions

### Identity Function

The identity function I : X -> X maps each element x ∈ X to itself ∀ x ∈ X:

I(x) = x , ∀ x ∈ X

### Exponential Function

For positive real numbers b ≠ 1, the exponential function with base b, denoted with exp_b : R -> R+, is defined as follows:

exp_b (x) = b^x

where b^0 = 1 and b^(-x) = 1 / b^x

![Laws of Exponents]()

### Logarithmic Function

For positive real numbers b ≠ 1, the logarithm with base b of x, denoted with log_b:R+ -> R, is the exponent to which b must be raised to obtain x

log_b x = y <==> b^y = x

![Laws of Logarithmic]()

#### Logarithm with base 2

In general mathematics, the commonly used logarithms are

- logarithm with base 10 ("common logarithm")
- logarithm with base e ("natural logarithm", denoted ln())

In computer science, it is often necessary to compute logarithms with base 2. (binary number system, binary trees, divide-and-conquer algorithms,...)

In computer science, if a logarithm is written without base, you may assusme it to be log_2.

### Lenght(string) Function

Consider the function Length() that returns the number of characters in a string.

- The null string is the "string" with no characters
- It is usually denoted "" and is said to have length 0

### Boolean Functions

Consider the boolean expression: P ∧ Q

Observe that the output R is a function of the two inputs P, Q, so we can write
R = AND(P,Q)

AND: {0,1}^2 -> {0,1} is a function from the set of bit pairs {0,1}^2 to the set of bits {0,1} as defined by the input/output table.

Consider the Boolean expression:

```
S= (P ∧ Q ∧ R) ∨ (P ∧ ∼Q ∧ R) ∨ (P ∧ ∼Q ∧ ∼R)
```

f:{0,1}^3 -> {0,1} is a function from the set of bit pairs {0,1}^3 to the set of bits {0,1} as defined by the input/output table.

### Hamming-Distance Function

The Hamming distance is a metric for comparing two binary strings of equal lenght. It is used for error detection or error correction when data is transmitted over computer networks. The hamming distance returns the number of bit positions in which the two strings are different.
The function can be computedd very efficiently on hardware by performing a bitwise XOR operation (a ⊕ b), and then summing the total number of 1s in the resultant string.

### The image Function

When we look at an image, we see onjects, landscapes, colors etc., but this is not the case with compiuters. To a computer the image looks like a 2D matrix of the pixels’ values which represent intensities across the color spectrum.
Digital images consist of a H x W array of pixels in which their values represent the intensity of light at a particular pixel. H is called the image height, W the image width.
An 8-bit grayscale image can be representes as a function:

```
I : [0, W - 1] x [0, H - 1] -> [0, 255]
```

Notice that a pixel intensity with 8 bits ranges from 0 to 2^8 - 1, which is [0.255]. 0 represents black pixels, 255 white pixels. The values in between represent the intensity on the greyscale, where a low value means dark and a high value means bright.

Colors are given by a superimposition of red, green and blue, so they are called RGB images. In a computer, RGB images are thus represented with three arrays: one for the red intensity, one for green, and one for blue.

## Convolution

### Motivation

Image filtering is one of the most popular operations in images. Images filtering is a function that takes as input an image out outputs a new "filtered" image. The most famous filtering operations are "low-pass" and "high-pass" filtering. The former returns a smoothed version of the image; the latter highlights the "contours" (edges) of the image (operation known as "edge detection")

### 1D Convolution

Convolution replaces each pixel value with a "weighted sum" of all the values in its neighborhood. A option is the give uniform weights, like [1,1,1,1,1] / 5, or another possibility is to use non-uniform weights [1,4,6,4,1] / 16. Notice that in the last case we are giving more importance to the value of the center pixel.
Let f, g, y be discrete functions

## Neural Network

### Convolutional Neural Networks (CNN)

Convolutional Neural Networks (also called CNNs or ConvNets) consist of a series of convolutional layers that convolve the original image with different filters, each one dedicated to the detection of different features (lines, circles, faces, etc.).
These filters are learned through a process, called training, done with an algorithm called backpropagation.
The output of these convolutional layers is then processed by a classifier to return an output, which can be
the probability that there is, for example, a “car”, a “dog’ or any object the network was trained to recognize.

### Filters of a CNN

- **Lower layer filters** learn simple features (lines, curves)
- **Higher layer filters** learn complex patterns (eyes, faces, textures, objects)
