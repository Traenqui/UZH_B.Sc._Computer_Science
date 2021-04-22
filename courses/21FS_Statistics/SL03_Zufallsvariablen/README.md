# SL03: Zufallsvariablen

## Wahrscheinlichkeitsfunktion

### Definition Wahrscheinlichkeitsfunktion

Für eine diskrete Zufallsvariable X ist die Wahrscheinlichkeitsfunktion f(x) für x in R definiert durch:
![wahrscheinlichkeitsfunktion]()
Man schreibt “für alle sonstigen x”, oder sonst als Abkürzung für “sonstige x”

## Bernoulli- und Binomialverteilung

### Bernoulliverteilung

- Zufallsexperiment mit zwei möglichen Ergebnissen
- Wir können diese generisch ‘Erfolg’ und ‘Misserfolg’ nennen
- Die Wahrscheinlichkeit eines Erfolgs ist p
- X = 1 bezeichnet das Eintreten des Erfolges

Abkürzende Notation: X ~ Bernoulli(p)
Als Formel ausgedrückt
![Bernoulliverteilung]()

### Binominalverteilung

Ausgangspunkt: Zufallsexperiment mit zwei möglichen Ergebnissen (Bernoulli)

- Aber nun wird das Zufallsexperiment N-mal wiederholt (unabhängig von einander)
- X ist die Anzahl der Erfolge in den N ‘Versuchen’

Abkürzende Notation: X ~ Binominal(N, p)
![Binominalverteilung]()

## Gesetz der Grossen Zahl

Die Wahrscheinlichkeit eines Erfolges sei p. p̂ = X / N ist der Anteil der Erfolge bei N Versuchen
![Gesetz der grossen Zahl]()

## Poisson-Verteilung

Wenn die zugrundeliegende Anzahl der ‘Versuche’ undefiniert ist, bzw. die grundsätzlich unbeschränkte Anzahl von Ereignissen in einem Zeitraum modelliert werden soll, ist oftmals die Poisson-Verteilung adäquat:

- Mögliche Erbebnisse: 0, 1, 2, …
- Wahrscheinlichkeiten: ![Poisson Wahrschinlichkeiten]()
- Hierbei ist μ eine positive Konstante.

Abkürzende Notation: X ∼ Poisson(μ)

## Erwartungswert und Varianz

Die Lage und die Streuung der Verteilung der Zufallsvariablen X wird durch den Erwartungswert und die Varianz charakterisiert.
Gewöhnliche Bezeichnungen: μ_X und σ_X^2 (oder einfach μ und σ^2)
Alternative Bezeichnungen: E(X) und Var(X)
Die Formeln für diskrete Zufallsvariablen sind wie folgt:
![Formeln E(X) & Var(X)]()
Es gibt auch noch die Sandardabweichung von X:
![Standardabweichung]()
Sie enthält die gleiche Information wie die Varianz, ist jedoch numerisch verschieden von ihr.

### Regeln

Betrachte zwei Zufallsvariablen X und Y. Dann gilt:

- E(X + Y) = E(X) + E(Y)
- Falls X und Y unabhängig sind, Var(X + Y) = Var(X) + Var(Y)

Betrachte eine Zufallsvariable X und zwei Konstanten a und b. Dann gilt:

- E(a + bX) = a + bE(X)
- Var(a + bX) = b^2Var(X)
- SA(a + bX) = |b|SA(X)

## Stetige Zufallsvariablen

Eine stetige Zufallsvariable kann jeden Wert in einem Intervall annehmen.

## Dichtefunktion

## Perzentile

Das 100x pte Perzentil, x_p, einer stetigen Verteilung erfüllt die folgende Bedingung:
P(X =< x_p) = p für p ∈ (0, 1)

Es teilt die Dichtefunktion in zwei Bereiche auf: die Wahrscheinlichkeit links von x_p beträgt p, und die Wahrscheinlichkeit rechts 1 - p.

Formal löst ein Perzentil die folgende Gleichung:
![Perzentilgleichung]()
Spezialfall: der Medial einer stetigen Verteilung ist das 50te Perzentil, d.h. P(X =< Median) = 50% = 0.5

## Normalverteilung

Die Dichtefunktion hat die Form einer Glockenkurve und ist bestimmt durch zwei Zahlen, µ und σ^2 > 0:
![Normalverteilung]()
Abgekürzende Notation: X ~ Normal(µ,σ^2)

Die Kennzahlen sind: E(X) = µ; Var(X) = σ^2

Manche Phänomene lassen sich approximativ durch eine Normalverteilung beschrieben:

- Grösse oder BMI von Personen
- Inhalte von Verpackungen

Die eigentliche Bedeutung der Normalverteilung liegt weniger bei der

- Charakterisierung der Verteilung eines Merkmals, sondern vor allem bei der Beschreibung von Variation von Studienergebnissen (Schätzresultaten)
