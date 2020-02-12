// This code is adopted from http://algs4.cs.princeton.edu/33balanced/SplayBST.java.html
#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

// An AVL tree node
struct node
{
	int key;
	struct node *left, *right;
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
    printf("%d\n", root->key);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}


/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *x)
{
	struct node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at
// root. This function modifies the tree and returns the new root
struct node *splay(struct node *root, int key)
{
	// Base cases: root is NULL or key is present at root
	if (root == NULL || root->key == key)
		return root;

	// Key lies in left subtree
	if (root->key > key)
	{
		// Key is not in tree, we are done
		if (root->left == NULL) return root;

		// Zig-Zig (Left Left)
		if (root->left->key > key)
		{
			// First recursively bring the key as root of left-left
			root->left->left = splay(root->left->left, key);

			// Do first rotation for root, second rotation is done after else
			root = rightRotate(root);
		}
		else if (root->left->key < key) // Zig-Zag (Left Right)
		{
			// First recursively bring the key as root of left-right
			root->left->right = splay(root->left->right, key);

			// Do first rotation for root->left
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}

		// Do second rotation for root
		return (root->left == NULL)? root: rightRotate(root);
	}
	else // Key lies in right subtree
	{
		// Key is not in tree, we are done
		if (root->right == NULL) return root;

		// Zig-Zag (Right Left)
		if (root->right->key > key)
		{
			// Bring the key as root of right-left
			root->right->left = splay(root->right->left, key);

			// Do first rotation for root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key)// Zag-Zag (Right Right)
		{
			// Bring the key as root of right-right and do first rotation
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		// Do second rotation for root
		return (root->right == NULL)? root: leftRotate(root);
	}
}

// Function to insert a new key k in splay tree with given root
struct node *insert(struct node *root, int k)
{
	// Simple Case: If tree is empty
	if (root == NULL) return newNode(k);

	// Bring the closest leaf node to root
	root = splay(root, k);

	// If key is already present, then return
	if (root->key == k) return root;

	// Otherwise allocate memory for new node
	struct node *newnode = newNode(k);

	// If root's key is greater, make root as right child
	// of newnode and copy the left child of root to newnode
	if (root->key > k)
	{
		newnode->right = root;
		newnode->left = root->left;
		root->left = NULL;
	}

	// If root's key is smaller, make root as left child
	// of newnode and copy the right child of root to newnode
	else
	{
		newnode->left = root;
		newnode->right = root->right;
		root->right = NULL;
	}

	return newnode; // newnode becomes new root
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Drier program to test above function*/
int main()
{
	struct node *root = newNode(100);
	root->left = newNode(50);
	root->right = newNode(200);
  print2D(root);
  printf("==============================================\n");
	root->left->left = newNode(40);
	root->left->left->left = newNode(30);
	root->left->left->left->left = newNode(20);
  print2D(root);
  printf("==============================================\n");
	root = insert(root, 25);
	printf("Preorder traversal of the modified Splay tree is \n");
  print2D(root);
  printf("==============================================\n");
	preOrder(root);
  print2D(root);
  printf("==============================================\n");
	return 0;
}
