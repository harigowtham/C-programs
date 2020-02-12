#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 5

struct Node {
        int data;
        struct Node *right;
        struct Node *left;
};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node *root, int space)
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
    printf("%d \n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
/*
struct Value {
        int hvalue[10];
        int vvalue[10];
};
*/
struct Map {
        int key;
        int value[10];
};

struct Map map[100];

struct Node * newNode (int data) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
}

void hash(int key, int data) {
        int i = 0;
        //the hashing done is 'key+50' as its an int.
        // if its a string it gets complicated
        //
        while (map[key].value[i] != -1) {
                i++;
        }
        map[key].value[i]= data;
        map[key].key = key;
}

void printmap() {
        for (int i= 0; i < 100; i++) {
                //printf("key:%d  ", map[i].key);
                for(int j = 0; j < 5; j++) {
                        //if (map[i].value[j] != -1)
                        printf("%d ", map[i].value[j]);
                }
                        printf("\n ");
        }
        return;
}

void create(struct Node *root) {
        memset(map, -1, 100*sizeof(map[0]));
//        memset(map->hvalue, -1, 10*sizeof(map[0].hvalue[0]));
        memset(map->value, -1, 10*sizeof(map[0].value[0]));
	int max = createFromBottom(root, map);
        printf("the answer:\n");
        print(map, max);
}

int createFromBottom(struct Node *root,struct Map *map) {
        if(root == NULL)
                return 0;
        int l = createFromBottom(root->left, map)+1;
        int r = createFromBottom(root->right, map)+1;
        int max = (l > r)? l: r;
        hash(max, root->data);
        //printf("%d\n", max);
        return max;
}

void print(struct Map *map, int max) {
        for(int i = 1; i <= max; i++){
                for (int j = 0; j < 10; j++) {
                        if (map[i].value[j] != -1)
                        printf("%d ", map[i].value[j]);
                }
                printf("\n");
        }
}

int main()
{
	struct Node *root = newNode(20);
	root -> left = newNode(8);
	root -> right = newNode(22);
	root -> left -> left = newNode(5);
	root -> left -> right = newNode(3);
	root -> right -> left = newNode(4);
	root -> right -> right = newNode(25);
	root -> left -> right -> left = newNode(10);
	root -> left -> right -> right = newNode(14);
	create(root);
        //DEBUG
        print2D(root);
        //printmap();
	return 0;
}

