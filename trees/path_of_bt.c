#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node {
        int data;
        struct node *left,*right;
};
typedef struct node node;

node* newnode(int data) {
        node *new  = (node *)malloc(sizeof(node));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
}

node** creates(int *top) {
	node **s = (node **) malloc(sizeof(node *)*MAX );
	*top = -1;
	return s;
}

void push (node **s, node *data, int *top) {
	(*top)++;
	s[(*top)] = data;
}
node* pop (node **s, int *top) {
	node *tmp = s[(*top)];
	(*top)--;
	return tmp;
}

void printpath (node **s, int *top) {
        node *tmp;
        int temp = *top;
        while (temp >= 0) {
                tmp = s[(temp)];
                printf("%d\t", tmp->data);
                temp--;
        }
        printf("\n");
}

void print (node *root, node **s, int *top, int key) {
        node *temp = root;
	node *no;
        if(temp) {
		push(s, temp, top);
                printf("%d\n", temp->data);
                printf("after push %d\n", *top);
                if (temp->data == key) {
                printpath(s, top);
		return;
                }
                if (temp->left) {
                        print(temp->left, s, top, key);
                        /*
                        printf("before pop of left %d\n", *top);
                        no = pop(s, top);
                        printf("after pop of left %d\n", *top);
                        */
                }
                if (temp->right) {
                        print(temp->right, s, top, key);
                        /*
                        printf("before pop of right%d\n", *top);
                        no = pop(s, top);
                        printf("after pop of right %d\n", *top);
                        */
                }
        //pop has to be done one for a round not twice like above
        no = pop(s, top);
        }
}

int main () {
	int top;
        int key = 5;
	node **s = creates(&top);
        node *root = newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);
        print(root, s, &top, key);
        //printpath(s, &top);
        return 1;
}
