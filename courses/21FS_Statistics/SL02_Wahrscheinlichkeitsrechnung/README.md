# SL02: Wahrscheinlichkeitsrechnung
## Ereignisse
Ereignisse sind Teilmengen des Ereignisraums
Die Wahrscheinlichkeit des Ereignisses ist die Summe der Wahrscheinlichkeiten der Ergebnisse, die Teil des Ereignisses sind. 
## Bedingte Wahrscheinlichkeit
Bedingte Wahrscheinlichkeit ist die Wahrscheinlichkeit des Eintretens eines Ereignisses A unter der Bedingung, dass das Eintreten eines anderen Ereignisses B bereits bekannt ist. Sie wird als P(A|B) geschrieben.
### Definitionen
- P(A|B) = P(A ∩ B) / P(B) 
- P(A|B) = P(B|A)P(A) / P(B)
## Wahrscheinlichkeits-Axiome von Kolmogroff
1. Jedem Ereignis E des Stichprobenraums ist eine reelle Zahl P(E), seine Wahrscheinlichkeit, zugeordnet
2. Für diese Funktion P: E -> P(E), gilt
	1. Die Wahrscheinlichkeiten sind nicht negativ:  P(E) ≥ 0.
	2. Die Wahrscheinlichkeit des sicheren Ereingnisses S ist eins:  P(S) = 1.
	3. Die Wahrscheinlichkeit, dass von zwei unvereinbaren Ereignissen entweder das eine oder das andere eintritt, ist gleich der Summe der beiden Wahrscheinlichkeiten: P(A ∪ B) = P(A) + P(B), falls A ∩ B = Ø

Vereinigung: A oder B tritt ein. A ∪ B = {s : s ∈ A oder s ∈ B}
Durchschnitt: A und B treten ein. A ∩ B = {s : s ∈ A und s ∈ B}
Komplementärereignis: A^c = {s : s ∈/ A}

## Eigenschaften
- Zwei Ereignisse heissen ausschöpfend, wenn gilt
A ∪ B = S, Bsp. A ∪ A^c = S
- Zwei Ereignisse werden als disjunkt bezeichnet, wenn gilt:
A ∩ B = ∅ Beispiel: A ∩ A^c = ∅
- P(∅) = 0
- P(A^c) = 1 − P(A)
	- “Odds” sind definiert als P(A)/P(A^c) = P(A)/(1 − P(A), also z.B.
P(H)/(1 − P(H)) = 0.5/0.5 = 1
- P(A ∪ B) = P(A) + P(B) − P(A ∩ B) (Additionssatz)