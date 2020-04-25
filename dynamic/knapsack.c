// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
int i, w;
int K[n+1][W+1];

// Build table K[][] in bottom up manner
// The table is a lot bigger. here its K[10][50].
// We make the first row and col 0 as per dyn prg.
// the we fill it 1 after the other from left to right.
// Note: the n corresponds to the items available (1 to 3 here,
// through which we can access the weight or the value)
// but the w is from 0 to 50 (not just the overall weight 50 or the weights of each item.
// So we calculate the value for each weight index. Each of the row is going to have the previous weight value so far.)
// draw a table, should help better than explaining here.
for (i = 0; i <= n; i++)
{
	for (w = 0; w <= W; w++)
	{
		if (i==0 || w==0)
                        //for the first row and col to be zero
			K[i][w] = 0;
                //only after the weight of the ith item is hit, we perform calculation to see the max.
                else if (wt[i-1] <= w)
                        //            val[i-1] is the value of the item being added(item of that row).
                        //                       k[i-1][w-wt[i-1]]value of with the weight of that item removed . Only previous element is there (got by perfoming the below step.
                        //                       this means value of the row added with the value of the previous item.(to get previous item, subtract the weight of the current item from the above row.(use above row because this row is manipulated.)
                        //                                          k [i-1][w] value of the previous item)
                        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
                else
                        // to get the value for the previous element, we pull down the value if there is an value above it.
                        K[i][w] = K[i-1][w];

	}
}

return K[n][W];
}

int main()
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}



/*
 * table:
 *      0  1 2 3 ... 10 .... 20 ... 30 ...50
 *      0  0 0 0 ..                        0
 *      1  0 0 ...   60 60 ..60 ...       60
 *      2  0 0 ..   .60 .....100 ...160 ...160
 *      3  0 0 ..   .60......100....160...220
 *

/* A Naive recursive implementation of 0-1 Knapsack problem with time complexity O(2^n)*/
//this approach is easy but the other is recommended.
/*
#include<stdio.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
// Base Case
if (n == 0 || W == 0)
	return 0;

// If weight of the nth item is more than Knapsack capacity W, then
// this item cannot be included in the optimal solution
if (wt[n-1] > W)
	return knapSack(W, wt, val, n-1);

// Return the maximum of two cases:
// (1) nth item included
// (2) not included
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
					knapSack(W, wt, val, n-1)
				);
}

// Driver program to test above function
int main()
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}
*/
