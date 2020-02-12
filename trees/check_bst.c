#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define COUNT 5

#define mmax(a,b) ((a > b)?a:b)
#define mmin(a,b) ((a > b)?b:a)

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

/*
 * this doesnt compare the whole tree, it compares only the root's data with its left and
 * right's data, but root'a data has to be compared with left and right SUBTREE's data
int isbst(struct node *root) {
        if (root == NULL)
                return 0;
        else if (root->left != NULL)
                if (root->key > root->left->key)
                        return isbst(root->left) && 0;
                else if (root->key < root->left->key)
                        return 1;
                else
                        return 0;
        else if (root->right != NULL)
                if (root->key < root->right->key)
                        return isbst(root->right) && 0;
                else if (root->key > root->right->key)
                        return 1;
                else
                        return 0;
}
*/
int isbst(struct node* node, int min, int max)
{
  /* an empty tree is BST */
  if (node==NULL)
     return 1;

  /* false if this node violates the min/max constraint */
  if (node->key < min || node->key > max)
     return 0;

  /* otherwise check the subtrees recursively,
   tightening the min or max constraint */
  return
    isbst(node->left, min, node->key-1) &&  // Allow only distinct values
    isbst(node->right, node->key+1, max);  // Allow only distinct values
}

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == 0) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	struct node *root	 = newNode(20);
	root->left			 = newNode(8);
	root->right			 = newNode(22);
	root->left->left		 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
    /*
    struct node *root = NULL;
    root = insert(root, 50);
    root->left = newNode(100);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
        */
  print2D(root);
    if (isbst(root, INT_MIN, INT_MAX))
            printf("is a bst");
    else
            printf("is a not bst");
    return 0;
}
