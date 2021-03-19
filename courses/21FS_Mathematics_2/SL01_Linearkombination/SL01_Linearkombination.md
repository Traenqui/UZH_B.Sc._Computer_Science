# SL01: Linearkombination

Notizen: Yes
Type: Vorlesung
Unterlagen: SL01%20Linearkombination%20d4343322de4a42b29878a4cf24086cf8/SL01_Kapitel_6.pdf
Woche: Woche 1

# Linearkombination

- Norm eines Vektors
    - $||\vec{v}|| = \sqrt{\vec{v}_1^2 + \vec{v}_2^2 + ... + \vec{v}_n^2}$
    - $\vec{0} =$ Nullvektor
    - $e^k = \begin{pmatrix}
        0\\
        \vdots\\
        1\\
        \vdots\\
        0
      \end{pmatrix}$ , k-ter (kanonischer) Einheitsvektor
- Richtung eines Vektors
    - $\frac{\vec{v}}{||\vec{v}||}, \vec{v} \in \mathbb{R}^m, \vec{v} \neq 0$
    - Hat die Norm = 1
- Skalarprodukt
    - $(\vec{v}^1)^T \vec{v}^2 = \langle \vec{v}^1,\vec{v}^2\rangle = \sum_{\substack{i=1}} ^m
     \vec{v}_i^1 \vec{v}_i^2$
- Orthogonal

    Zwei Vektoren sind orthogonal, wenn das Skalarprodukt Null ist.

- Linearkombination
    - $\alpha_1, ..., \alpha_n \in \mathbb{R} \space , \space \vec{v}^1,...,\vec{v}^n \in \mathbb{R}^m$
    - $\sum{\substack{i=1}}^n \alpha_i\vec{v}^i = \alpha_1\vec{v}^1 + ... \space + \alpha_n\vec{v}^n \in \mathbb{R}^m$
- Lineare abhänigkeit

    $\vec{v}^1,...\space\vec{v}^n \in\mathbb{R}^m\space,\space n ≥ 2$, heissen linear abhängig, wenn mindesten einer der Vektoren als Linearkombination der anderen darstellbar.

    - $\vec{v}^1,\vec{v}^2\neq0$ linear abhängig $\iff$es existiert $\alpha\in\mathbb{R}$ mit $\vec{v}^1 = \alpha\vec{v}^2$
    - $\vec{v}^1,\vec{v}^2\neq0$ orthogonal $⇒$ $\vec{v}^1,\vec{v}^2$ linear unabhängig
    - $\vec{v}^1,...\space,\vec{v}^n\in\mathbb{R}^m$ linear unabhängig $\iff\alpha_1=...=\alpha_n=0$ als einzige Lösung von $\alpha_1\vec{v}^1+...+\alpha_n\vec{v}^n=0$
- Lineare Hülle
    - Menge alles Linearkombinationen
    - $lin{\{\vec{v}^1,...\space,\vec{v}^n\}} = \{\sum_{\substack{i=1}}^n \alpha_i\vec{v}^i|\space\alpha_1,...\space\alpha_n\in\mathbb{R}^m\} \subseteq\mathbb{R}^m$
- Linearer Raum

    $V\subseteq\mathbb{R}^m$, $V\neq\{\}$ heisst Linearer Raum oder Vektorraum, wenn:

    - $\vec{v}\in V ⇒ \alpha\vec{v}\in V, \space\forall\space\alpha\in\mathbb{R}\space(⇒\vec{0}\in V)$
    - $\vec{v},\vec{w}\in V ⇒ \vec{v} + \vec{w} \in V, \space\forall\space\vec{v},\vec{w}\in V$

    $V = lin{\{\vec{v}^1,...\space,\vec{v}^n\}}$ ist ein linearer Raum

- Erzeugenden System

    Die Menge $\{\vec{v}^1,...\space\vec{v}^n\}$ heisst Erzeugendensystem von $V$, wenn $V = lin{\{\vec{v}^1,...\space,\vec{v}^n\}}$

- Basis
    - $B = \{ \vec{b}^1,\dots,\vec{b}^n\}$ heisst Basis von $V$, wenn $\vec{b}^1,\dots,\vec{b}^n$ ($n = dim(V)$) linear unabhängig sind und $lin\{\vec{b}^1,\dots,\vec{b}^n\} = V$
- Dimension
    - $n = dim(V)$, n bezogen auf die linear unabhängigen Vektoren
- Gerade, Ebene, Hyperebene
    - Der lineare Raum $V \sube \mathbb{R}^m$ heisst
        - Punkt, wenn $dim(V) = 0$
        - Gerade, wenn $dim(V) =1$
        - Ebene, wenn $dim(V) = 2$
        - Hyperebene, wenn $dim(V) = m-1$
- Erzeugendensysteme und Basiswechsel
    - ist $u = \alpha_1 \vec{v}^1 + \dots + \alpha_i \vec{v}^i + \dots + \alpha_n \vec{v}^n$ mit $\alpha_i\neq 0$
        - $V = lin\{\vec{v}^1,\dots,\vec{v}^i,\dots,\vec{v}^n\} = lin\{\vec{v}^1,\dots,\vec{u},\dots,\vec{v}^n\}$
    - Ist zusätzlich $\{\vec{v}^1,\dots,\vec{v}^i,\dots,\vec{v}^n\}$ eine Basis von $V$
        - $\{\vec{v}^1,\dots,\vec{u},\dots,\vec{v}^n\}$ eine Basis von $V$
- Kanonische Basis
    - Die Basis $\{\vec{e}^1,\dots,\vec{e}^m\}$ des $\mathbb{R}^m$ heisst kanonische Basis des $\mathbb{R}^m$
- Basis des euklidischen Raums
    - $\vec{v}^1,\dots,\vec{v}^m\in\mathbb{R}^m$ linear unabhängig $⇒ lin\{\vec{v}^1,\dots,\vec{v}^m\} = \mathbb{R}^m$
- Maximale Anzahl linear unabhängiger Vektoren
    - Für $n > m$ sind $\vec{v}^1,\dots,\vec{v}^n\in\mathbb{R}^m$ stets linear abhängig
- $m\times n$ Matrix
    - Seien $m,n\in \mathbb{N}$ und $a_{1,1}, \dots , a_{1,n},  a_{2,1}, \dots , a_{m,1}, \dots , a_{m,n} \in \mathbb{R}$
    - $A = \begin{pmatrix}
    a_{1,1} & a_{1,2} & \dots & a_{1,n}\\
    a_{2,1} & a_{2,2} & \dots & a_{2,n} \\
    \vdots & \vdots & \ddots & \vdots \\
    a_{m,1} & a_{m,2} & \dots & a_{m,n}
    \end{pmatrix} = (a_{ij})_{i=1,\dots,m,\space j=1,\dots n}$
- Transponierte
    - $A = \begin{pmatrix}
    a_{1,1} & a_{1,2} & \dots & a_{1,n}\\
    a_{2,1} & a_{2,2} & \dots & a_{2,n} \\
    \vdots & \vdots & \ddots & \vdots \\
    a_{m,1} & a_{m,2} & \dots & a_{m,n}
    \end{pmatrix} => A^T = \begin{pmatrix}
    a_{1,1} & a_{2,1} & \dots & a_{m,1}\\
    a_{1,2} & a_{2,2} & \dots & a_{m,2} \\
    \vdots & \vdots & \ddots & \vdots \\
    a_{1,n} & a_{2,n} & \dots & a_{m,n}
    \end{pmatrix}$
- Quadratische Matrix
    - $A = \begin{pmatrix}
    a_{1,1} & \dots & a_{1,n}\\
    \vdots & \ddots & \vdots \\
    a_{n,1} & \dots & a_{n,n}
    \end{pmatrix}$
    - symmetrische Matrix, wenn $a_{i,j} = a_{j,i} \space\forall\space i,j=1, \dots ,n$
    - Diagonalmatrix, wenn $a_{i,j} = 0 \space\forall\space i \neq j$
    - Einheitsmatrix, wenn $a_{i,j} = 1 \space\forall\space i, \space a_{i,j} = 0 \space\forall\space i \neq j$
- Matrix-Vektor-Multiplikation
    - $A = \begin{pmatrix}
    a_{1,1} & \dots & a_{1,n}\\
    \vdots & \ddots & \vdots \\
    a_{n,1} & \dots & a_{n,n}
    \end{pmatrix} * 
    \begin{pmatrix}
    x_1 \\
    \vdots \\ x_n
    \end{pmatrix} = 
    \begin{pmatrix}
    \sum_{k=1}^n a_{1,k}x_k \\
    \vdots \\ 
    \sum_{k=1}^n a_{m,k}x_k
    \end{pmatrix}$
- Matrix-Multiplikation
    - $\begin{pmatrix}
    a_{1,1} & \dots & a_{1,n}\\
    \vdots & \ddots & \vdots \\
    a_{n,1} & \dots & a_{n,n}
    \end{pmatrix} * \begin{pmatrix}
    b_{1,1} & \dots & b_{1,n}\\
    \vdots & \ddots & \vdots \\
    b_{n,1} & \dots & b_{n,n}
    \end{pmatrix} = \begin{pmatrix}
    \sum_{k=1}^n a_{1,k}b_{k,1} & \dots & \sum_{k=1}^n a_{1,k}b_{k,p}\\
    \vdots & \ddots & \vdots \\ 
    \sum_{k=1}^n a_{m,k}b_{k,1} & \dots & \sum_{k=1}^n a_{m,k}b_{k,p}
    \end{pmatrix}$
- Nullzeilen, -spalten und die Nullmatrix

    Man spricht von einer

    - **Nullzeile,** wenn alle Elemente der Zeile Null sind
    - **Nullspalte**, wenn alle Elemente der Spalte Null sind
    - **Nullmatrix**, wenn alle Spalten Nullspalten sind
- Produkt einer Konstanten mit einer Matrix

    $\alpha A = \begin{pmatrix}
    \alpha a_{1,1} & \dots & \alpha a_{1,n}\\
    \vdots & \ddots & \vdots \\
    \alpha a_{n,1} & \dots & \alpha a_{n,n}
    \end{pmatrix}$

- Regeln der Matrizenmultiplikation

    Sei $A$ eine $m\times n$-Matrix, $B$ einer $n\times p$-Matrix, $C$ einer $p\times q$-Matrix, $\alpha\in\mathbb{R}$

    - $(A*B)^T = B^T * A^T$
    - $A*(B*C) = (A*B)*C$
    - $A*\alpha * B = \alpha * A*B$
    - Ist $I$ die Einheitsmatrix passender Ordnung, so gilt $A*I=A$
- Zeilenstufenform

    Die Matrix lieget in Zeilenstufenform vor, wenn

    - Nullzeilen unterhalb aller Zeilen stehen, die keine Nullzeilen sind und
    - in jedem Paar von zwei Zeilen, die keine Nullzeilen sind, das führende Element der obern Zeile links von dem führenden Element der unteren Zeile steht.
- Lineare Unabhängigkeit von Zeilenvektor

    Alle Zeilenvektoren einer Matrix in Zeilenstufenform, die keine Nullvektoren sind, sind linear unabhängig.