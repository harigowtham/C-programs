#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

struct lnode {
        int data;
        struct lnode *next;
};
struct lnode *lroot	 = NULL;

void print(struct lnode **head) {
        struct lnode *tmp = NULL;
        if (head == NULL)
                printf("list empty");
        else {
                tmp = *head;
                //printf("%d->", tmp->data);
                while(tmp->next != NULL) {
                        printf("%d->", tmp->data);
                        tmp = tmp->next;
                }
                printf("%d->NULL", tmp->data);
                //printf("NULL");
        }
}


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

struct lnode *newlnode(int item)
{
    struct lnode *temp =  (struct lnode *)malloc(sizeof(struct lnode));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

struct lnode* linsert(struct lnode* head, int key) {
        if (head == NULL)
                return newlnode(key);
        else {
                struct lnode *tmp = head;
                while (tmp->next != NULL)
                        tmp = tmp->next;
                tmp->next = newlnode(key);
        }
        return head;
}

void bstll(struct node* root, struct lnode** lroot) {
        if (root == NULL)
                return;
        bstll(root->left, lroot);
        *lroot = linsert(*lroot, root->key);
        bstll(root->right, lroot);
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
	struct lnode *lroot	 = NULL;
	root->left			 = newNode(8);
	root->right			 = newNode(22);
	root->left->left		 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
        print2D(root);
        bstll(root, &lroot);
        print(&lroot);
    return 0;
}
