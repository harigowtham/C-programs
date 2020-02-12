// Cprogram to find the least common ancestory in binary tree
/*
 * Find lowest common ancestor in binary tree.
 *
 * Time complexity O(n)
 * Space complexity O(h)
 */
#include<stdio.h>
#include<stdlib.h>

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
/*
struct node* getLeft(struct node* root)
{
    if (root != NULL)
    {
        root->left = getLeft(root->left);
    } else
            return root;
}

struct node* getRight(struct node* root)
{
    if (root != NULL)
    {
        root->right = getRight(root->right);
    } else
            return root;
}
*/
struct node* getLowestCommonAncestor(struct node *curr, int A, int B) {

        if(curr == NULL) {
                return NULL;
        }


        if(curr->key == A || curr->key == B)
                return curr;


        //struct node* leftNode = getLowestCommonAncestor(getLeft(curr->left), A, B);//works but complex to understand and run
        //struct node* rightNode = getLowestCommonAncestor(getRight(curr->right), A, B);// works but complex to understand and run.
        struct node* leftNode = getLowestCommonAncestor(curr->left, A, B);
        struct node* rightNode = getLowestCommonAncestor(curr->right, A, B);



        if(leftNode != NULL && rightNode != NULL)
                return curr;



        if(leftNode == NULL) {
                return rightNode;
        } else {
                return leftNode;
        }
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

    //int n1 = 120, n2 = 90; // 120
    int n1 = 80, n2 = 90; // 80
    //int n1 = 80, n2 = 22; // 50
    //int n1 = 4, n2 = 22; // 50
    struct node *lca = getLowestCommonAncestor(root, n1, n2);
    printf("%d", lca->key);
}
