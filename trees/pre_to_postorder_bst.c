//doesnt work
/*
#include <stdio.h>

void getPostOrderBST(int pre[], int N)
{
	int pivotPoint = 0;

	// Run loop from 1 to length of pre
	for(int i = 1; i < N; i++)
	{
		if (pre[0] <= pre[i])
		{
			pivotPoint = i;
			break;
		}
	}

	// Print from pivot length -1 to zero
	for(int i = pivotPoint - 1; i > 0; i--)
	{
		printf("%d  ", pre[i]);
	}

	// Print from end to pivot length
	for(int i = N - 1; i >= pivotPoint; i--)
	{
		printf("%d  ", pre[i]);
	}
	printf("%d  ", pre[0]);
}

// Driver Code
int main()
{
	int pre[] = { 40, 30, 32, 35,
				80, 90, 100, 120 };
	//int pre[] = {10, 5, 1, 7, 40, 50};
  int pre[] = {50, 30, 20, 40, 70, 60, 80};
	int size = sizeof( pre ) / sizeof( pre[0] );
	
	getPostOrderBST(pre, size);
	
	return 0;
}
*/
// C++ program for finding postorder
// traversal of BST from preorder traversal
//doesnt work
#include <stdio.h>
#include <limits.h>

// Function to find postorder traversal from
// preorder traversal.
void findPostOrderUtil(int pre[], int n, int minval,
					int maxval, int *preIndex)
{

	// If entire preorder array is traversed then
	// return as no more element is left to be
	// added to post order array.
	if (*preIndex == n)
		return;

	// If array element does not lie in range specified,
	// then it is not part of current subtree.
	if (pre[*preIndex] < minval || pre[*preIndex] > maxval) {
		return;
	}

	// Store current value, to be printed later, after
	// printing left and right subtrees. Increment
	// preIndex to find left and right subtrees,
	// and pass this updated value to recursive calls.
	int val = pre[*preIndex];
	*preIndex++;

	// All elements with value between minval and val
	// lie in left subtree.
	findPostOrderUtil(pre, n, minval, val, *preIndex);

	// All elements with value between val and maxval
	// lie in right subtree.
	findPostOrderUtil(pre, n, val, maxval, *preIndex);

	printf("%d   ", val);
}

// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{

	// To store index of element to be
	// traversed next in preorder array.
	// This is passed by reference to
	// utility function.
	int *preIndex = 0;

	findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}

// Driver code
int main()
{
	int pre[] = { 40, 30, 35, 80, 100 };

	int n = sizeof(pre) / sizeof(pre[0]);

	// Calling function
	findPostOrder(pre, n);
	return 0;
}

