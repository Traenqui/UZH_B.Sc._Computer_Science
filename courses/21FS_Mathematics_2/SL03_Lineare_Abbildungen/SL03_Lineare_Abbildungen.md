# SL03: Lineare Abbildungen

Notizen: No
Type: Vorlesung
Woche: Woche 4

# Definitionen

- Die lineare Abbildung

    Eine Abbildung $f:\mathbb{R}^n \rightarrow\mathbb{R}^m$, die jedem $x\in\mathbb{R}^n$ ein $y = f(x)\in\mathbb{R}^m$ zuordnet, heisst linear, wenn eine $m\times n$-Matrix $A$ existiert mit

    - $y = f(x) = Ax$
- Das Bild einer linearen Abbildung

    Das Bild vom $M \sube\mathbb{R}^n$ unter $f: \mathbb{R}^n \rightarrow \mathbb{R}^m$ ist

    - $f(M) = \{ y \in \mathbb{R}^m |$ es existiert ein $x\in M$ mit $f(x) = y \}$
- Determinante einer $2\times2$-Matrix

    Die Determinate einer $2\times 2$-Matrix $A$ ist

    - $det\space A = det(A) = |A| = \begin{vmatrix}
    a_{11} & a_{12}\\
    a_{21} & a_{22}
    \end{vmatrix} = a_{11}a_{22} - a_{12}a_{21}$
- Determinante

    Die Determinante einer quadratischen Matrix $A = (a_{ij})$ der Ordnung n ist induktiv wie folgt definiert:

    - Für $n=1:\space det(A) = a_{11}$
    - Für $n=2:\space det(A) = a_{11}a_{22} - a_{12}a_{21}$
    - Für $n>2:\space$Sei $A_{ij}$ die Matrix, die durch Streichen der $i$-ten Zeile und $j$-ten Spalte von $A$ entsteht $det(A) = \sum_{i=1}^n a_{i1} (-1)^{i+1} det(A_{i1})$
- Eigenwert und Eigenvektor

    Sei $A$ eine $n\times n$-Matrix, $\lambda\in\mathbb{R}$, $\vec{v}\in\mathbb{R}^n$, $\vec{v}\neq 0$ mit $A\vec{v} = \lambda\vec{v}$

- $l$-facher Eigenwert

    Sei $A$ eine $n\times n$-Matrix mit $n$ linear unabhängigen Eigenvektoren. Einen Eigenwert $\lambda$ von $A$, zu dem es $l ≤ n$ linear unabhängige Eigenvektoren gibt, nennt man $l$-fachen Eigenwert von $A$

# Sätze

- Verknüpfung linearer Abbildungen

    Gegeben sind $f:\mathbb{R}^n \rightarrow \mathbb{R}^m$ mit $f(x) = Ax$, $g:\mathbb{R}^n\rightarrow\mathbb{R}^m$ mit $g(x) = Bx$ und $h:\mathbb{R}^m\rightarrow\mathbb{R}^q$ mit $h(x) = Cx$, dann gilt:

    - $f = g \leftrightarrow A = B$
    - $f+g: \mathbb{R}^n\rightarrow\mathbb{R}^m$ ist linear mit $(f+g)(x) = (A+B)x$
    - $f-g: \mathbb{R}^n\rightarrow\mathbb{R}^m$ ist linear mit $(f-g)(x) = (A-B)x$
    - $h\circ g:\mathbb{R}^n\rightarrow\mathbb{R}^q$ ist linear mit $(h\circ g)(x) = h(Bx) = CBx$
- Charakterisierung des Bildes von $f$

    Für $A = [\vec{a}^1, \dots , \vec{a}^n]$ mit $\vec{a}^1, \dots, \vec{a}^n \in\mathbb{R}^m$ und $f(x) = Ax$ gilt: 

    - $f(\mathbb{R}^n) = lin\{\vec{a}^1,\dots,\vec{a}^n\}$
    - $dim(f(\mathbb{R}^n)) = rang(A)$
- Umkehrabbildung und Inverse

    Für $f : \mathbb{R}^n \rightarrow \mathbb{R}^m$ mit $y = f(x) = Ax$ gilt:

    - $f$ surjektiv $\leftrightarrow rang(A) = m$
    - $f$ injektiv $\leftrightarrow rang(A) = n$
    - $f$ bijektiv $\leftrightarrow rang(A) = m =n$
    - Dann existiert eine Matrix $$A^{-1} mit $A * A^{-1} = A^{-1} * A = I$
    - Die Umkehrabbildung ist $f^{-1}(x) = A^{-1}x$
- Rechenregeln invertierbarer Matrizen

    Sind $A$ und $B$reguläre Matrizen der Ordnung $n$, dann gilt:

    - $A^{-1} * A = A * A^{-1} = I$
    - $(A^{-1})^{-1} = A$
    - $(A*B)^{-1} = B^{-1} * A^{-1}$
    - $(\alpha A)^{-1} = \frac{1}{\alpha} A ^{-1}$, falls $\alpha\neq 0$
    - $(A^T)^{-1} = (A^{-1})^T$
- Eigenschaften der Determinante einer $2\times2$-Matrix

    Für eine $2\times 2$-Matrix $A$ und $\alpha \neq 0$ gilt:

    - $det(A) = 0 \leftrightarrow rang(A) < 2$
    - Vertauscht man zwei Spalten, so ändert sich das Vorzeichen, aber nicht der Betrag der Determinate
    - Ver-$\alpha$-facht man eine Spalte, so ver-$\alpha$-facht sich die Determinante
    - Sind alle Elemente unter der Hauptdiagonalen von A gleich 0, dann gilt $det(A) = a_{11}a_{22}$
- Flächenveränderung
    - Ist $f : \mathbb{R}^2 \rightarrow\mathbb{R}^2$ mit $f(x) = Ax$ und $M \sube \mathbb{R}^2$ mit der Fläche $Vol(M)$, dann gilt $Vol(f(M)) = |det(A)| * Vol(M)$
    - Ist $f : \mathbb{R}^3 \rightarrow\mathbb{R}^3$ mit $f(x) = Ax$ und $M \sube \mathbb{R}^3$ mit der Fläche $Vol(M)$, dann gilt $Vol(f(M)) = |det(A)| * Vol(M)$
- Weiter Eigenschaften von Determinanten

    Sind $A$ und $B$ zwei $2\times 2$-Matrizen, dann gilt:

    - $det(A) \neq 0 \leftrightarrow A$ invertierbar und $det(A^{-1}) = \frac{1}{det(A)}$
    - $det(AB) = det(A) det(B)$
- Entwicklungssatz für Determinanten

    $det(A) = \sum_{i=1}^n a_{ij}(-1)^{i+j} det(A_{ij})$, $j\in\{1,\dots,n\}$

    $det(A) = \sum_{j=1}^n a_{ij}(-1)^{i+j} det(A_{ij})$, $i\in\{1,\dots,n\}$

- Eigenschaften der Determinante

    Seine $A$ und $B$ quadratische Matrizen der Ordnung $n$, $\alpha\in\mathbb{R} \backslash \{0\}$

    - $det(A) = 0 \leftrightarrow rang(A) < n$
    - Vertauscht man zwei Spalten, so ändert sich  das Vorzeichen, aber nicht der Betrag der Determinante
    - Ver-$\alpha$-facht man eine Spalte, Ver-$\alpha$-facht sich die Determinante
    - Sind alle Elemente unter der Hauptdiagonalen von $A$ gleich 0, dann gilt $det(A) = a_{11}\dots a_{nn}$
    - $det(A) \neq 0 \leftrightarrow A$ invertierbar und $det(A^{-1}) = \frac{1}{det(A)}$
    - $det(AB) = det(A) det(B)$
- Eigenschaften von Eigenvektoren

    Für jeden Eigenvektor $\vec{v}\neq 0$ zum Eigenwert $\lambda$ von $A$ ist auch $\alpha\vec{v}$ mit $\alpha\in\mathbb{R}$, $\alpha\neq 0$ ein Eigenvektor zum Eigenwert $\lambda$ von $A$

- Bestimmung von Eigenwerten

    Für Eigenwert $\lambda\in\mathbb{R}$ und Eigenvektor $v\neq 0$ gilt:

    - $A\vec{v}=\lambda\vec{v}$ bzw. $(A-\lambda I)\vec{v} = 0$
- Eigenwerte und Eigenvektoren symmetrischer Matrizen

    Eine (reelle) symmetrische $n\times n$-Matrix $A$ hat $n$ reelle, linear unabhängige Eigenvektoren $\vec{v}^1,\dots,\vec{v}^n \in\mathbb{R}^n$ zu Eigenwerten $\lambda_1,\dots,\lambda_n\in\mathbb{R}$

![SL03%20Lineare%20Abbildungen%20d8a97a3c143c4ee5be09dc5bf39e6cc0/Screenshot_2021-03-18_at_11.37.25.png](SL03%20Lineare%20Abbildungen%20d8a97a3c143c4ee5be09dc5bf39e6cc0/Screenshot_2021-03-18_at_11.37.25.png)