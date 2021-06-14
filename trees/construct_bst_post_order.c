/* A O(n) program for construction of BST from postorder traversal */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define COUNT 5

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

// A utility function to create a node
struct node* newNode (int data)
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct BST from post[]. postIndex is used
// to keep track of index in post[].
struct node* constructTreeUtil( int post[], int* postIndex, int key,
								int min, int max, int size )
{
	// Base case
	if( *postIndex < 0 )
		return NULL;

	struct node* root = NULL;

	// If current element of post[] is in range, then
	// only it is part of current subtree
	if( key > min && key < max )
	{
		// Allocate memory for root of this subtree and increment *postIndex
		root = newNode ( key );
		*postIndex = *postIndex - 1;

		if (*postIndex >= 0)
		{
			// All nodes which are in range {key..max} will go in right
			// subtree, and first such node will be root of right subtree.
			root->right = constructTreeUtil( post, postIndex, post[*postIndex],
										key, max, size );

			// Contruct the subtree under root
			// All nodes which are in range {min .. key} will go in left
			// subtree, and first such node will be root of left subtree.
			root->left = constructTreeUtil( post, postIndex, post[*postIndex],
										min, key, size );
		}
	}

	return root;
}

// The main function to construct BST from given postorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int post[], int size)
{
	int postIndex = size-1;
	return constructTreeUtil ( post, &postIndex, post[size-1], INT_MIN,
							INT_MAX, size );
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder (struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
	//int pre[] = {10, 5, 1, 7, 40, 50};//this wont work as this is a preorder list
	int post[] = {1, 7, 5, 50, 40, 10};// this will work as its post order list
	int size = sizeof( post ) / sizeof( post[0] );

	struct node *root = constructTree(post, size);

	printf("Inorder traversal of the constructed tree: \n");
	printInorder(root);
        print2D(root);

	return 0;
}

