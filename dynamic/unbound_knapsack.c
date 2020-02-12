// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>
#include<string.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

void printlist(int K[], int W) {
        for (int i = 0; i <=W; i++)
                printf("%d ", K[i]);
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
int i, j;
int K[W+1];
memset(K, 0, sizeof K);
// fill the whole array.
for (i = 0; i <= W; i++)
{
        // to iterate between the elements in the list.
	for (j = 0; j < n; j++)
	{
                //the weight of the element selected is less than the allowed weight.
                if (wt[j] <= i)
                        //max(item value being added and item value not added.
                        //item value not added is k[i]. item value added is(val[j]+k[i-wt[j]])
                        //where val is the value and k[i-wt[j]] is the value of the previous element
                        K[i] = max(val[j] + K[i-wt[j]], K[i]);
	}
}
printlist(K, W);

return K[W];
}

int main()
{
	int val[] = {10, 30, 20};
	int wt[] = {5, 10, 15};
	int W = 100;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}
