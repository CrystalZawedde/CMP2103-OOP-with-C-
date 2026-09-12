Sudoku is a grid divided into smaller boxes (also called regions or blocks),
Some cells, called fixed cells, are populated with numbers from 1 to 9.
The objective is to fill the empty cells, also called free cells, with the numbers 1 to 9 so that
every row, column, and 3 * 3 box contains the numbers 1 to 9
See examples at https://sudoku.com/


For convenience, we use the value 0 to indicate a free cell. The
grid can be naturally represented using a two-dimensional list, as shown in Figure 11.5b.
To find a solution for the puzzle, we must replace each 0 in the grid with an appropriate
number from 1 to 9.

![soduku](./soduku.png)