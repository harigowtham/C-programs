// C++ program to find the longest path in a matrix
// with given constraints
//
// Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.

//We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

#include <stdio.h>
#include <string.h>
#define n 3
#define INT_MIN -2147483647

int max (int a, int b) {
        if (a>b)
                return a;
        else
                return b;
}

// Returns length of the longest path beginning with mat[i][j].
// This function mainly uses lookup table dp[n][n]
int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n])
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return 0;

	// If this subproblem is already solved
	if (dp[i][j] != -1)
		return dp[i][j];

	// To store the path lengths in all the four directions
	int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;

	// Since all numbers are unique and in range from 1 to n*n,
	// there is atmost one possible direction from any cell
	if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1]))
		x = 1 + findLongestFromACell(i, j + 1, mat, dp);

	if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1]))
		y = 1 + findLongestFromACell(i, j - 1, mat, dp);

	if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j]))
		z = 1 + findLongestFromACell(i - 1, j, mat, dp);

	if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j]))
		w = 1 + findLongestFromACell(i + 1, j, mat, dp);

	// If none of the adjacent fours is one greater we will take 1
	// otherwise we will pick maximum from all the four directions
	return dp[i][j] = max(x, max(y, max(z, max(w, 1))));
}

// Returns length of the longest path beginning with any cell
int finLongestOverAll(int mat[n][n])
{
	int result = 1; // Initialize result

	// Create a lookup table and fill all entries in it as -1
	int dp[n][n];
	memset(dp, -1, sizeof dp);

	// Compute longest path beginning from all cells
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1)
				findLongestFromACell(i, j, mat, dp);

			// Update result if needed
			result = max(result, dp[i][j]);
		}
	}

	return result;
}

// Driver program
int main()
{
	int mat[n][n] = { { 1, 2, 9 },
 			  { 5, 3, 8 },
			  { 4, 6, 7 } };
        printf("Length of the longest path is %d", finLongestOverAll(mat));
	return 0;
}

