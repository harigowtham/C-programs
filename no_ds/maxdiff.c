// easy but takes more time. O(n^2)
// better soln below.
// The problem is to calculate:
// Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
//
//Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
//  Output: 6  (j = 7, i = 1)
//
//  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
//  Output: 8 ( j = 8, i = 0)
//
// Input:  {6, 5, 4, 3, 2, 1}
//  Output: -1

#include <bits/stdc++.h>

using namespace std;
/* For a given array arr[], returns the maximum j – i such that
	arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n)
{
	int maxDiff = -1;
	int i, j;

	for (i = 0; i < n; ++i)
	{
		for (j = n-1; j > i; --j)
		{
			if(arr[j] > arr[i] && maxDiff < (j - i))
				maxDiff = j - i;
		}
	}

	return maxDiff;
}

int main()
{
	int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	cout<< "\n" << maxDiff;
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)


//Time Complexity: O(n)
//Auxiliary Space: O(n)


#include <stdio.h>

/* Utility Functions to get max and minimum of two integers */
int max(int x, int y)
{
	return x > y? x : y;
}

int min(int x, int y)
{
	return x < y? x : y;
}

/* For a given array arr[], returns the maximum j – i such that
	arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n)
{
	int maxDiff;
	int i, j;

	int *LMin = (int *)malloc(sizeof(int)*n);
	int *RMax = (int *)malloc(sizeof(int)*n);

/* Construct LMin[] such that LMin[i] stores the minimum value
	from (arr[0], arr[1], ... arr[i]) */
	LMin[0] = arr[0];
	for (i = 1; i < n; ++i)
		LMin[i] = min(arr[i], LMin[i-1]);

	/* Construct RMax[] such that RMax[j] stores the maximum value
	from (arr[j], arr[j+1], ..arr[n-1]) */
	RMax[n-1] = arr[n-1];
	for (j = n-2; j >= 0; --j)
		RMax[j] = max(arr[j], RMax[j+1]);

	/* Traverse both arrays from left to right to find optimum j - i
		This process is similar to merge() of MergeSort */
	i = 0, j = 0, maxDiff = -1;
	while (j < n && i < n)
	{
		if (LMin[i] < RMax[j])
		{
			maxDiff = max(maxDiff, j-i);
			j = j + 1;
		}
		else
			i = i+1;
	}

	return maxDiff;
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	printf("\n %d", maxDiff);
	getchar();
	return 0;
}

