#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
        int data;
        struct Node *right;
        struct Node *left;
};

struct Node * newNode (int data) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
}

int minimum(int a, int b) {
        if (a>b)
                return b;
        return a;
}
/* with global variables
 *
int secondmin = 9999;
int min = 9999;
void globalprint2ndlowest(struct Node *root) {
        if(root == NULL)
                return ;
        if (root->data < secondmin) {
                if (root->data < min) {
                        secondmin = min;
                        min = root->data;
                } else if (min != root->data)
                        secondmin = root->data;
        }
        printf("root->data:%d\n",root->data);
        printf("min:%d\n",min);
        printf("2ndmin:%d\n",secondmin);
	print2ndlowest(root->left);
	print2ndlowest(root->right);
}
*/

int print2ndlowest(struct Node *root, int min, int secondmin) {
        if(root == NULL)
                return secondmin;
        if (root->data < secondmin) {
                if (root->data < min) {
                        secondmin = min;
                        min = root->data;
                } else if (min != root->data)
                        secondmin = root->data;
        }
        printf("root->data:%d\n",root->data);
        printf("min:%d\n",min);
        printf("2ndmin:%d\n",secondmin);
        int m = minimum(print2ndlowest(root->left, min, secondmin), print2ndlowest(root->right, min, secondmin));
        printf("%d\n",m);
        return m;

}

int main()
{
	struct Node *root = newNode(2);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(2);
	root -> right -> left = newNode(5);
	root -> right -> right = newNode(3);
	printf("%d",print2ndlowest(root, 999, 999));
        //globalprint2ndlowest(root);
        //printf("%d", secondmin);
	return 0;
}

