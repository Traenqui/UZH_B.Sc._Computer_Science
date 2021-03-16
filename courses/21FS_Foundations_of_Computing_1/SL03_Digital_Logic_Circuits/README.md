# VL3: Digital Logic Circuits

- Arithmetic Logic Unit (ALU)

  Is a combinatorial digital circuit that performs arithmetic and bitwise operators on two input integer binary numbers.

- CPU

  central processing unit

- GPU

  graphic processing unit

- Arithmetic operations

  - Addition

    $A+B$

  - Subtraction

    $A-B$

  - Negative representation

    $-A$

  - Increment by 1

    $A + 1$

  - Decrement by 1

    $A -1$

  - Copy to a register

    $R = A$

- Bitwise logical operations

  - Bitwise AND

    $A \land B$

  - Bitwise OR

    $A\lor B$

  - Bitwise XOR

    $A \oplus B$

  - Ones' complement

    all bits are inverts (used to represent negativ integers using tow's cmplement)

  - Bit shift

    all bit values are shifted by one unit to the left and a 0 is added to the right most digit, equivalent to multiplication by 2

- Multiplexer

  A 2-1 Mux, changes the output based on the Selection Input

| Type   | Distinctive Shape                                           | Rectangular Shape                                          |                                Boolean algebra                                 | Truthtable |
| ------ | ----------------------------------------------------------- | ---------------------------------------------------------- | :----------------------------------------------------------------------------: | ---------- |
| NOT    | ![alt text](https://en.wikipedia.org/wiki/File:NOT_ANSI_Labelled.svg)    | ![alt text](https://en.wikipedia.org/wiki/File:NOT_IEC_Labelled.svg)    |                {\overline {A}} or {\displaystyle \neg A}\neg A                 |
| Buffer | ![alt text](https://en.wikipedia.org/wiki/File:Buffer_ANSI_Labelled.svg) | ![alt text](https://en.wikipedia.org/wiki/File:Buffer_IEC_Labelled.svg) |                                      {A}                                       |            |
| AND    | ![alt text](https://en.wikipedia.org/wiki/File:AND_ANSI_Labelled.svg)    | ![alt text](https://en.wikipedia.org/wiki/File:AND_IEC_Labelled.svg)    |                  A\cdot B or {\displaystyle A\land B}A\land B                  |            |
| OR     | ![alt text](https://en.wikipedia.org/wiki/File:OR_ANSI_Labelled.svg)     | ![alt text](https://en.wikipedia.org/wiki/File:OR_IEC_Labelled.svg)     |                     A+B or {\displaystyle A\lor B}A\lor B                      |            |
| NAND   | ![alt text](https://en.wikipedia.org/wiki/File:NAND_ANSI_Labelled.svg)   | ![alt text](https://en.wikipedia.org/wiki/File:NAND_IEC_Labelled.svg)   |         \overline{A \cdot B} or {\displaystyle A\uparrow B}A\uparrow B         |            |
| NOR    | ![alt text](https://en.wikipedia.org/wiki/File:NOR_ANSI_Labelled.svg)    | ![alt text](https://en.wikipedia.org/wiki/File:NOR_IEC_Labelled.svg)    | \overline{A + B} or {\displaystyle A\downarrow B}{\displaystyle A\downarrow B} |            |
| XOR    | ![alt text](https://en.wikipedia.org/wiki/File:XOR_ANSI_Labelled.svg)    | ![alt text](https://en.wikipedia.org/wiki/File:XOR_IEC_Labelled.svg)    |       A\oplus B or {\displaystyle A\veebar B}{\displaystyle A\veebar B}        |            |
| XNOR   | ![alt text](https://en.wikipedia.org/wiki/File:XNOR_ANSI_Labelled.svg)   | ![alt text](https://en.wikipedia.org/wiki/File:XNOR_IEC_Labelled.svg)   |         \overline{A \oplus B} or {\displaystyle {A\odot B}}{A \odot B}         |            |
