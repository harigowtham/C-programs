// coin change problem.
#include<stdio.h>
#include<string.h>
#define R 4
#define C 6

int min(int x, int y, int z);

void print_mat(int cost[R][C]) {
        for(int x = 0 ; x < R ; x++) {
        printf(" (");
        for(int y = 0 ; y < C ; y++){
            printf("%d     ", cost[x][y]);
        }
        printf(")\n");
        }
        printf("\n");
}

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
//Write CPP code here
int count( int S[], int m, int n )
{
	//we need a two dimensional matrix to store the result
	int table[m+1][n+1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	for(int i=0;i<m;i++)
{table[0][i] = 1;
}

	for(int i=1;i<=m;i++)
	{

		for(int j=1;j<=n;j++)
		{
			if(S[i-1]>j)
			{
				table[i][j]=table[i-1][j];

			}

			else
			{
				table[i][j]=table[i-1][j]+table[i][j-(i-1)];
			}

     print_mat (table);
		}
	}
     print_mat (table);
	return table[m][n];
}

// Driver program to test above function
int main()
{
	int i, j;
	int arr[] = {1, 2, 3};
	int m = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", count(arr, m, 5));
	//getchar();
	return 0;
}
