#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

struct node {
        int data;
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

struct node* newnode (int data) {
        struct node *new = malloc(sizeof(struct node*));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        return new;
}

void preorder(struct node *root) {
        if (root != NULL) {
                printf("%d", root->data);
                preorder(root->left);
                preorder(root->right);
        }
}

struct node *insert (struct node *root, int data){
        if (root == NULL)
                return newnode(data);
        else if (data < root->data) {
                root->left = insert(root->left, data);
        } else {
                root->right = insert(root->right, data);
        }
                return root;
}

struct node *invert (struct node *root){
        if(root!=NULL) {
                struct node *tmp = root->left;
                root->left = invert(root->right);
                root->right = invert(tmp);
                return root;
        }
}

int main() {
        struct node *root = NULL;
        root=insert(root, 5);
        root=insert(root, 5);
        root=insert(root, 3);
        root=insert(root, 4);
        root=insert(root, 7);
        root=insert(root, 8);
        preorder(root);
                printf("\nafter invert \n");
  print2D(root);
        invert(root);
                printf("\nafter invert \n");
        preorder(root);
                printf("\nafter invert \n");
  print2D(root);
}
