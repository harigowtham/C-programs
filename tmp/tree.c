#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    int data;
    struct bst* left;
    struct bst* right;
}bst;

bst *root;

void preorder(bst *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int insert(bst **node, int data)
{
    if(*node == NULL)
    {
        *node= (bst* )malloc(sizeof(bst));
        if(*node == NULL)
        {
            return -1;
        }
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return 0;
    }

    if( (*node)->data > data)
    {
        return insert(&(*node)->left, data);
        //return insert(&(*node)->left, data);
        //& and * dont cancel each other.
    }
    else if( (*node)->data < data )
    {
        return insert(&(*node)->right, data);
    }
    else
    {
        printf("Data already present.\n");
        return 0;
    }

}

void print(bst **node) {
        if(*node != NULL)
        {
                printf("%d\n", (*node)->data);
                print(&(*node)->left);
                print(&(*node)->right);
        }
}

int main() {
printf("%d", insert(&root, 2));
printf("%d", insert(&root, 3));
printf("%d", insert(&root, 4));
printf("done:\n");
    preorder(root);
printf("print:\n");
print(&root);
return 1;
}

