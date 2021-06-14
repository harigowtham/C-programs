#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newnode(int key) {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->key = key;
        new->left =  NULL;
        new->right = NULL;
        return new;
}

struct node *insert(struct node *root, int key) {
        if (root == NULL)
                return newnode(key);
        if (key < root->key) {
                root->left = insert(root->left, key);
        } else {
                root->right = insert(root->right, key);
        }

        return root;
}

void inorder(struct node *root) {
        if (root != NULL) {
                inorder(root->left);
                printf("%d\n", root->key);
                inorder(root->right);
        }
}

struct node *find(struct node *root, int key) {
  if (root == NULL)
    return root;
  if (root->key == key)
    return root;
  if(key > root->key )
    return find(root->right, key);
  else
    return find(root->left, key);
}

//under how find works and look into this
struct node *max(struct node *root, int key) {
        if (root == NULL )
                return NULL;
        if (key > root->key) {
                return max(root->right, key);
        } else {
                struct node *tmpleft = max(root->left, key);
                if (tmpleft == NULL)
                        return root;
                else
                        return tmpleft;
        }

}

struct node *max_debug(struct node *root, int key){
  if (root == NULL) {
    printf("\nreturning null\n");
    return NULL;
  }

  printf("\nAt node: %d\n", root->key);

  if (key > root->key) {
    printf("\ntaking right\n");
    struct node *right =  max_debug(root->right, key);
    if (right == NULL)
      printf("\nreturning right as NULL\n");
    else
      printf("\nreturning right: %d\n", right->key);
    return right;
  } else {
    printf("\ntaking left\n");
    struct node *left = max_debug(root->left, key);
    if(left == NULL) {
      if (root == NULL)
        printf("\nreturning root: NULL\n");
      else
        printf("\nreturning root: %d\n", root->key);
      return root;
    } else {
      if (left == NULL)
        printf("\nreturning left: NULL\n");
      else
        printf("\nreturning left: %d\n", left->key);
      return left;
    }
  }
}

int main() {
        struct node *root = NULL;
        root = insert(root,50);
        root = insert(root,30);
        root = insert(root,20);
        root = insert(root,40);
        root = insert(root,70);
        root = insert(root,60);
        root = insert(root,80);
        inorder(root);
        //printf("ans:%d", max(root, 81)->key); will seg fault
        printf("ans:%d\n", max(root, 71)->key); //80
        printf("ans:%d\n", max_debug(root, 71)->key); //80
        struct node *find_node = find(root, 71);
        if (find_node == NULL)
          printf("ele not found");
        else
          printf("element from find:%d \n", find_node->key);
        return 0;
}
