
#include<stdio.h>
#include<stdlib.h>
#define COUNT 5


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


// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* invert(struct node *curr) {

        if(curr == NULL) {
                return NULL;
        }


        struct node *temp =  invert(curr->right);
        curr->right = invert(curr->left);
        curr->left = temp;
        return curr;

}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          80      22
         /  \    /  \
        4   120
            / \
           90  14

        */
    struct node *root = NULL;
    root = newNode(50);
    root->left			 = newNode(80);
    root->right			 = newNode(22);
    root->left->left		 = newNode(4);
    root->left->right	 = newNode(120);
    root->left->right->left = newNode(90);
    root->left->right->right = newNode(14);

  print2D(root);
    struct node *lca = invert(root);
  print2D(root);
}
