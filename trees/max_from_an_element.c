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
        printf("ans:%d", max(root, 57)->key); //60
        return 0;
}
