#include<stdio.h>
// Size of given matrix is M X N
#define M 6
#define N 6


// A recursive function to replace previous value 'prevV' at '(x, y)'
// and all surrounding values of (x, y) with new value 'newV'.
void floodFillUtil(char mat[][N], int x, int y, char prevV, char newV)
{
	// Base cases
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (mat[x][y] != prevV)
		return;

	// Replace the color at (x, y)
	mat[x][y] = newV;

	// Recur for north, east, south and west
	floodFillUtil(mat, x+1, y, prevV, newV);
	floodFillUtil(mat, x-1, y, prevV, newV);
	floodFillUtil(mat, x, y+1, prevV, newV);
	floodFillUtil(mat, x, y-1, prevV, newV);
}

// Returns size of maximum size subsquare matrix
// surrounded by 'X'
int replaceSurrounded(char mat[][N])
{
// Step 1: Replace all 'O' with '-'
for (int i=0; i<M; i++)
	for (int j=0; j<N; j++)
		if (mat[i][j] == 'O')
			mat[i][j] = '-';

// Call floodFill for all '-' lying on edges
for (int i=0; i<M; i++) // Left side
	if (mat[i][0] == '-')
		floodFillUtil(mat, i, 0, '-', 'O');
for (int i=0; i<M; i++) // Right side
	if (mat[i][N-1] == '-')
		floodFillUtil(mat, i, N-1, '-', 'O');
for (int i=0; i<N; i++) // Top side
	if (mat[0][i] == '-')
		floodFillUtil(mat, 0, i, '-', 'O');
for (int i=0; i<N; i++) // Bottom side
	if (mat[M-1][i] == '-')
		floodFillUtil(mat, M-1, i, '-', 'O');

// Step 3: Replace all '-' with 'X'
for (int i=0; i<M; i++)
	for (int j=0; j<N; j++)
		if (mat[i][j] == '-')
			mat[i][j] = 'X';

}

// Driver program to test above function
int main()
{
	char mat[][N] = {{'X', 'O', 'X', 'O', 'X', 'X'},
					{'X', 'O', 'X', 'X', 'O', 'X'},
					{'X', 'X', 'X', 'O', 'X', 'X'},
					{'O', 'X', 'X', 'X', 'X', 'X'},
					{'X', 'X', 'X', 'O', 'X', 'O'},
					{'O', 'O', 'X', 'O', 'O', 'O'},
					};
	replaceSurrounded(mat);


	for (int i=0; i<M; i++)
	{
	for (int j=0; j<N; j++)
		printf("%c ", mat[i][j]);
	printf("\n");
	}
	return 0;
}



/*
#include<graphics.h>
//#include<dos.h>

void floodFill(int x,int y,int oldcolor,int newcolor)
{
	if(getpixel(x,y) == oldcolor)
	{
		putpixel(x,y,newcolor);
		floodFill(x+1,y,oldcolor,newcolor);
		floodFill(x,y+1,oldcolor,newcolor);
		floodFill(x-1,y,oldcolor,newcolor);
		floodFill(x,y-1,oldcolor,newcolor);
	}
}
//getpixel(x,y) gives the color of specified pixel

int main()
{
	int gm,gd=DETECT,radius;
	int x,y;

	printf("Enter x and y positions for circle\n");
	scanf("%d%d",&x,&y);
	printf("Enter radius of circle\n");
	scanf("%d",&radius);

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	circle(x,y,radius);
	floodFill(x,y,0,15);
	delay(5000);
	closegraph();

	return 0;
}
*/
