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
        struct node *new = malloc(sizeof(struct node));
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
        return root;
}

struct node *max_debug(struct node *root, int key){
  if (root == NULL) {
    printf("\nreturning null\n");
    return NULL;
  }

  printf("\nAt node: %d\n", root->data);

  if (key > root->data) {
    printf("\ntaking right\n");
    struct node *right =  max_debug(root->right, key);
    if (right == NULL)
      printf("\nreturning right as NULL\n");
    else
      printf("\nreturning right: %d\n", right->data);
    return right;
  } else {
    printf("\ntaking left\n");
    struct node *left = max_debug(root->left, key);
    if(left == NULL) {
      if (root == NULL)
        printf("\nreturning root: NULL\n");
      else
        printf("\nreturning root: %d\n", root->data);
      return root;
    } else {
      if (left == NULL)
        printf("\nreturning left: NULL\n");
      else
        printf("\nreturning left: %d\n", left->data);
      return left;
    }
  }
}

struct node *find(struct node *root, int key) {
  if (root == NULL)
    return root;
  if (root->data == key)
    return root;
  if(key > root->data )
    return find(root->right, key);
  else
    return find(root->left, key);
}

int main() {
        struct node *root = NULL;
        root=insert(root, 50);
        //root=insert(root, 5);
        root=insert(root, 30);
        root=insert(root, 40);
        root=insert(root, 70);
        root=insert(root, 80);
        preorder(root);
        printf("\nafter invert \n");
         print2D(root);
        //struct node * tmp = invert(root);
        //printf("\nafter invert \n");
        //print2D(tmp);
        preorder(root);
                printf("\nafter invert \n");
        int m = 71;
        printf("\ncal max_debug for: %d\n", m);
        printf("max_debug from element:%d \n", max_debug(root, m)->data);
        int f = 60;
        printf("\ncal find for: %d\n", f);
        struct node *find_node = find(root, f);
        if (find_node == NULL)
          printf("ele not found");
        else
          printf("element from find:%d \n", find_node->data);
}
