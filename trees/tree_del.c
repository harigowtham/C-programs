// Cprogram to demonstrate delete operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

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

// A utility function to do leaf node traversal of BST
void leafnode(struct node *root)
{
    if (root != NULL)
    {
        leafnode(root->left);
        leafnode(root->right);
        if (root->left == NULL && root->right == NULL)
        printf("%d ", root->key);
    }
}

void outerleft(struct node *temp)
{
    if (temp != NULL)
    {
        if (temp->left != NULL)
                printf("%d ", temp->key);
        outerleft(temp->left);
    }
}

void outerright(struct node *temp)
{
    if (temp != NULL)
    {
        outerright(temp->right);
        if (temp->right != NULL)
                printf("%d ", temp->key);
    }
}

// A utility function to do outer node traversal of BST
void outer(struct node *root)
{
        struct node *temp = root;
        outerleft(temp);
        leafnode(temp);
        outerright(temp->right);
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// A utility function to do inorder traversal of BST
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
// A utility function to do inorder traversal of BST
void desorder(struct node *root)
{
    if (root != NULL)
    {
        desorder(root->right);
        printf("%d ", root->key);
        desorder(root->left);
    }
}


// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Doesn't work
void inordercount(struct node *root, int *counted, int count)
{
    if (root != NULL)
    {
        inordercount(root->left, counted, count);
        *counted = *counted+1;
        if (*counted == count)
                printf("%d ", root->key);
        inordercount(root->right, counted, count);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
//    printf("*node:%u", *node);
   printf("node:%u\n", node);
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

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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
    //note: the address pointing to null is 0
//    printf("*root:%u", *root);
    printf("root:%u\n", root);
    root = insert(root, 50);
 //   printf("*root:%u", *root);
    printf("root:%u\n", root);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("\n2d tree \n");
  print2D(root);
    printf("leafnode traversal of the given tree \n");
    leafnode(root);
    printf("\nouter traversal of the given tree \n");
    outer(root);

    printf("\npreorder traversal of the given tree \n");
    preorder(root);
    printf("\nInorder traversal of the given tree \n");
    inorder(root);
    printf("\nkth(5th here) smallest element of the given tree \n");
    int counted, count;
    counted = 0;
    count = 2;
    inordercount(root, &counted, count);
    printf("\npostorder traversal of the given tree \n");
    postorder(root);
    printf("\ndesending order traversal of the given tree \n");
    desorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("\npreorder traversal of the given tree \n");
    preorder(root);
    printf("\nInorder traversal of the given tree \n");
    inorder(root);
    printf("\npostorder traversal of the given tree \n");
    postorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\nleafnode traversal of the given tree \n");
    leafnode(root);
    printf("\nouter traversal of the given tree \n");
    outer(root);

    printf("\n2d tree \n");
  print2D(root);
    return 0;
}
