

#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

struct node
{
    int key;
    struct node *left, *right;
};

struct node * nextLargestElement (struct node* root , int num )
{
        if (root == NULL)
                return NULL;
        if(root->key >= num)
                return nextLargestElement(root->left, num);
        else {
                struct node *tmp = nextLargestElement(root->right, num);
                if (tmp == NULL)
                        return root;
                else
                        return tmp;
        }
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
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
    printf("%d", (nextLargestElement (root, 37))->key);
    return 0;
}
