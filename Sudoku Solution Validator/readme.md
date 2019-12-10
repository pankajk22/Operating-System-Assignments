A Sudoku puzzle uses a 9 × 9 grid in which each column and row, as well as
each of the nine 3 × 3 subgrids, must contain all of the digits 1 · · · 9.This project consists of
designing a multithreaded application that determineswhether the solution to
a Sudoku puzzle is valid.

For Executing the file open terminal and go to folder of this file and type 
    1: gcc Q3.c -lpthread
    2: ./a.out
    3: Now add 2-D matrix of soduko you want to check.

Below are the some testcases:

1: This testcase is invalid:

1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9

2: This testcase is valid:

4 3 5 2 6 9 7 8 1
6 8 2 5 7 1 4 9 3
1 9 7 8 3 4 5 6 2
8 2 6 1 9 5 3 4 7
3 7 4 6 8 2 9 1 5
9 5 1 7 4 3 6 2 8
5 1 9 3 2 6 8 7 4
2 4 8 9 5 7 1 3 6
7 6 3 4 1 8 2 5 9

3: This testcase is valid:

1 2 8 5 4 7 6 9 3
6 3 7 9 8 1 5 2 4
4 9 5 6 3 2 7 1 8
2 1 3 7 9 4 8 5 6
5 7 4 1 6 8 9 3 2
9 8 6 3 2 5 4 7 1
3 5 1 4 7 6 2 8 9
7 4 2 8 1 9 3 6 5
8 6 9 2 5 3 1 4 7

4: This testcase is invalid:

1 2 8 5 4 7 6 9 3
6 3 7 9 8 1 5 2 4
4 9 5 6 3 2 7 1 8
2 1 3 7 9 4 8 5 6
5 7 4 1 6 8 9 3 2
9 8 6 3 8 5 4 7 1
3 5 1 4 7 6 2 8 9
7 4 2 8 1 9 3 6 5
8 6 9 2 5 3 1 4 9
