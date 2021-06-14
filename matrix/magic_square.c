#include<stdio.h>
#include<stdlib.h>

/*
 * We define a magic square to be an nxn  matrix of distinct positive integers from 1 to n^2 where the sum of any row, column, or diagonal of length n is always equal to the same number: the magic constant.

You will be given a 3x3 matrix s of integers in the inclusive range |1-9|. We can convert any digit  to any other digit b in the range |1-9| at cost of |a-b|. Given s, convert it into a magic square at minimal cost. Print this cost on a new line.

Note: The resulting magic square must contain distinct integers in the inclusive range |1-9|.

Example

$s = [[5, 3, 4], [1, 5, 8], [6, 4, 2]]

The matrix looks like this:

5 3 4
1 5 8
6 4 2
We can convert it to the following magic square:

8 3 4
1 5 9
6 7 2
This took three replacements at a cost of |5-8| + |8-9| + |4-7| = 7

*/

int main () {

int magic_mat[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, 
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},  
};

int A[3][3];
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
        scanf("%d", &A[i][j]);
}

int min_cost = 81;
for (int k = 0; k < 8; k++) {
    int crt_cost = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            crt_cost += abs( A[i][j] - magic_mat[k][i][j] );
    }
    if (crt_cost < min_cost)
        min_cost = crt_cost;
}

printf("cost: %d", min_cost);
return 0;
}

/*
 * The 8 valid combinations of 3 numbers that add to 15 are:

9 5 1
7 5 3
2 5 8
4 5 6
2 9 4
6 1 8
6 7 2
8 3 4
All 8 of those combinations need to appear in the square as a row, column or diagonal. The centre cell must appear in the middle row, middle column and both diagonals. So it must be a number that appears four times, and the only digit that does is 5. So 5 must be the centre.

Similarly, each of the corner pieces must form part of a row, a column and a diagonal. So each corner cell must be a number that appears 3 times. Those are the even numbers 2, 4, 6 and 8. That means the diagonals must be "2 5 8" and "4 5 6"

2 _ 4
_ 5 _
6 _ 8
That leaves the middle edge cells, each of which needs to appear in a row and a column. These are the odd numbers 1, 3, 7 and 9. So the middle row and column must be "9 5 1" and "7 5 3". Just insert these into the above such that the rows and columns add up correctly, leaving you with:

2 9 4
7 5 3
6 1 8
From that you can take the mirror images (horizontally and vertically) and the rotation of each.

Mirror images:

4 9 2 | 2 9 4
3 5 7 | 7 5 3
8 1 6 | 6 1 8
-------------
8 1 6 | 6 1 8
3 5 7 | 7 5 3
4 9 2 | 2 9 4
Rotations:

8 3 4 | 4 3 8
1 5 9 | 9 5 1
6 7 2 | 2 7 6
-------------
6 7 2 | 2 7 6
1 5 9 | 9 5 1
8 3 4 | 4 3 8*/
