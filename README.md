# Dynamic Programming
 
Problem: In this project, expected to design an algorithm that will allow the word group to be placed on an ad banner in such a way that there is minimal space in each line.

Steps: Use a given N length type to type up to M characters per line
perform your algorithm by doing the following actions to place them in rows.

1. A space that will be formed if words from i. word to j. are written in a line
Calculate space [i, j] indicating the number of values 1 ≤ i ≤ j ≤ n.

2. When words from i. word to j. word is written in a line, the spaces in this line
calculate spaceCost [i, j] for values 1 ≤ i ≤ j ≤ n.

3. Calculate the cost [j] indicating the lowest price from the 1st word to the word j.
lineAdr how many words each line starts with, depending on the minimum cost [j]
in the array.

4. Print the text line by line to the screen.

5. Print the total space price.
