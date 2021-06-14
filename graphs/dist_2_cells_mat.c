/*
 * Shortest distance between two cells in a matrix or grid
Difficulty Level : Hard
Last Updated : 03 Mar, 2021
Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through limited cells only. Also you can move only up, down, left and right. If found output the distance else -1. 
s represents ‘source’ 
d represents ‘destination’ 
* represents cell you can travel 
0 represents cell you can not travel 
This problem is meant for single source and destination.
Examples: 

Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1

Every move add a distance of 1

Soln:
use graph with adjaceny matrix. Have a value called distance in each of the graph's vertex.
Initialise it to zero and every time during a traversal, increment it.
Store each cell as a node with their row, column values and distance from source cell.
Start BFS with source cell.
Make a visited array with all having “false” values except ‘0’cells which are assigned “true” values as they can not be traversed.
Keep updating distance from source value in each move.
Return distance when destination is met, else return -1 (no path exists in between source and destination).
*/

// C++ Code implementation for above problem
#include <bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

// QItem for current location and distance
// from source location
class QItem {
public:
	int row;
	int col;
	int dist;
	QItem(int x, int y, int w)
		: row(x), col(y), dist(w)
	{
	}
};

int minDistance(char grid[N][M])
{
	QItem source(0, 0, 0);

	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	bool visited[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == '0')
				visited[i][j] = true;
			else
				visited[i][j] = false;

			// Finding source
			if (grid[i][j] == 's')
			{
			source.row = i;
			source.col = j;
			}
		}
	}

	// applying BFS on matrix cells starting from source
	queue<QItem> q;
	q.push(source);
	visited[source.row][source.col] = true;
	while (!q.empty()) {
		QItem p = q.front();
		q.pop();

		// Destination found;
		if (grid[p.row][p.col] == 'd')
			return p.dist;

		// moving up
		if (p.row - 1 >= 0 &&
			visited[p.row - 1][p.col] == false) {
			q.push(QItem(p.row - 1, p.col, p.dist + 1));
			visited[p.row - 1][p.col] = true;
		}

		// moving down
		if (p.row + 1 < N &&
			visited[p.row + 1][p.col] == false) {
			q.push(QItem(p.row + 1, p.col, p.dist + 1));
			visited[p.row + 1][p.col] = true;
		}

		// moving left
		if (p.col - 1 >= 0 &&
			visited[p.row][p.col - 1] == false) {
			q.push(QItem(p.row, p.col - 1, p.dist + 1));
			visited[p.row][p.col - 1] = true;
		}

		// moving right
		if (p.col + 1 < M &&
			visited[p.row][p.col + 1] == false) {
			q.push(QItem(p.row, p.col + 1, p.dist + 1));
			visited[p.row][p.col + 1] = true;
		}
	}
	return -1;
}

// Driver code
int main()
{
	char grid[N][M] = { { '0', '*', '0', 's' },
						{ '*', '0', '*', '*' },
						{ '0', '*', '*', '*' },
						{ 'd', '*', '*', '*' } };

	cout << minDistance(grid);
	return 0;
}

