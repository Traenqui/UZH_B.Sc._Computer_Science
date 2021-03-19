# VL3: Lineare Gleichungssysteme

Notizen: Yes
Type: Vorlesung

- Gleichungssysteme und Lösbarkeit

    Eine Menge von $m$ Gleichungen mit $n$ Variablen heisst Gleichungssystem. Ein Gleichungssystem heisst lösbar, wenn $\mathbb{L}\neq\{\}$. Gleichungssysteme mit gleicher Lösungsmenge heissen äquivalent.

- Lineares Gleichungssystem (LGS)

    $A * x = b$

    - Ist $b = 0$ heisst das LGS homogen, sonst inhomogen
- Erweiterte Koeffizientenmatrix

    $A * x = b$ bzw $(A|b)$

- Matrix in expliziter Form

    Eine Matrix in Zeilenstufenform liegt in expliziter Form vor, wenn

    - jedes führende Element eine 1 ist und
    - oberhalb führender Elemente alle Elemente gleich 0 sind.

    $Ax= b$ ist in expliziter Form, wenn $A$ in expliciter Form ist.

- Lösbarkeit LGS in expliziter Form

    Ist $A$ in expliziter Form mit Nullzeilen in Zeilen $i >r$, dann

    - ist das LGS $Ax=b$ lösbar $\leftrightarrow$ $b_i = 0$ für alle $i > r$
    - kann man die Lösungsmenge $\mathbb{L}$ von $Ax=b$ einfach bestimmen
    - heisst $x \in\mathbb{L}$ Basislösung, wenn $x_j \neq 0$für höchstens $r$ Komponenten
- Elementare Zeilenumformungen

    Sei $Ax=b$ ein LGS mit $m$ Gleichungen und $n$ Variablen. $\alpha\in\mathbb{R}$

    - Multipliziert man eine Zeile von $(A|b)$ mit $\alpha\neq 0$ oder
    - addiert man das $\alpha$-fache einer Zeile von $(A|b)$ zu einer anderen,

    dann entsteht ein äquivalentes LGS.

    Sei $Ax = b$ ein LGS mit $m$ Gleichungen und $n$ Variablen, $\alpha\in\mathbb{R}$.

    Vertauscht man zwei Zeilen bon $(A|b)$, entsteht ein äquivalentes LGS.

- Steichen von Nullzeilen
    - Streicht man Nullzeilen von $(A|b)$, entsteht ein äquivalentes LGS.
- Affiner Raum

    $A = \{\vec{v}^0 +\sum_{i=1}^m\alpha_i\vec{v}^i|\alpha_1,\dots,\alpha_m\in\mathbb{R}\} \sube\mathbb{R}^n$ mit 0

- Gleichheit affiner Räume

    $A=\{\vec{v}^0 + \sum_{i=1}^m \alpha_i\vec{v}^i | \alpha_1, \dots,\alpha_m \in \mathbb{R}\} \sube \mathbb{R}^n$ mit $\vec{v}^0,\dots,\vec{v}^m \in\mathbb{R}^n$ 

- Lösbarkeit eines LGS

    $Ax=b$ lösbar $\leftrightarrow$ $b\in lin\{\vec{a}^1,\dots,\vec{a}^n\}$

- Der Rang

    Maximale Anzahl linear unabhängiger Spaltenvektoren von A

- Eigenschaften des Rangs

    Sei $A$ eine $n$ x $n$ Matrix

    - $rang(A) =$ maximale Anzahl linear unabhängiger Spaltenvektoren
    - $rang(A)=$ maximale Anzahl linear unabhängiger Zeilenvektoren
    - $rang(A) =$ $rang(A^T) ≤ min\{m,n\}$, A hat vollen Rang, wenn $rang(A) = min\{m,n\}$
    - $rang(A) = n \leftrightarrow$ alle Spaltenvektoren linear unabhängig
    - $rang(A) = m \leftrightarrow$ alle Zeilenvektoren linear unabhängig
- Berechnung des Rangs und Lösbarkeit

    Ist $Ax =b$ äquivalent zu $Ãx = \tilde b$ und liegt $Ã$ in Zeilenstufenform vor mit genau $r$ Zeilen, die keine Nullzeilen sind, dann gilt:

    - $rang(A) = r$
    - $\tilde b_i = 0$ für alle $i > r ⇒$ LGS lösbar mit $n-r$ freien Variablen
    - $\tilde b_i \neq 0$ für alle $i > r ⇒$ LGS nicht lösbar

![VL3%20Lineare%20Gleichungssysteme%20a0e8522849d24b9bb53949139238a999/Screenshot_2021-03-08_at_16.54.39.png](VL3%20Lineare%20Gleichungssysteme%20a0e8522849d24b9bb53949139238a999/Screenshot_2021-03-08_at_16.54.39.png)

![VL3%20Lineare%20Gleichungssysteme%20a0e8522849d24b9bb53949139238a999/Screenshot_2021-03-17_at_20.58.53.png](VL3%20Lineare%20Gleichungssysteme%20a0e8522849d24b9bb53949139238a999/Screenshot_2021-03-17_at_20.58.53.png)