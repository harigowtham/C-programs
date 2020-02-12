#include<stdio.h>
#include<stdlib.h>
#define max 50

struct node {
        int data;
        struct node *left, *right;
};

struct node* newnode(int data) {
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        return new;
}

void printtree(struct node * root) {
        if (root != NULL) {
                printtree(root->left);
                printf("%d",root->data);
                printtree(root->right);
        }
}

void push(int *s, int *top, int data) {
        if ((*top) < 50) {
                (*top)++;
                s[*top]= data;
        } else {
                printf("stack full");
        }
}

int pop(int *s, int *top) {
        int temp;
        if ((*top) == -1) {
                printf("stack empty");
        } else {
                temp  = s[*top];
                (*top)--;
        }
        return temp;

}

int *creates(int *top) {
        int *s = malloc(sizeof(int)*max);
        *top = -1;
        return s;
}

void printreverselevelorder(int *s, int *top) {
        while ((*top) >=0) {
                printf("%d", s[(*top)]);
                (*top)--;
        }
}

void enq(struct node **q, int *rear, struct node* node) {
        q[*rear]= node;
        (*rear)++;
}

struct node * deq(struct node **q, int *front) {
        struct node *temp  = q[*front];
        (*front)++;
        return temp;

}

struct node **createq(int *front,int *rear) {
        struct node **q = (struct node**)malloc(sizeof(struct node *)*max);
        *front = -1;
        *rear = -1;
        return q;
}

void rlevelorder(struct node *root) {
        int front, rear;
        int top;
        struct node **q = createq(&front, &rear);
        int *s = creates(&top);
        struct node *tmp = root;
        while(tmp) {
                printf("%d", tmp->data);
                push(s, &top, tmp->data);
                if (tmp->left)
                        enq(q, &rear, tmp->left);
                if (root->right)
                        enq(q, &rear, tmp->right);
                tmp = deq(q, &front);
        }
                printf("\n");
        printreverselevelorder(s, &top);
}

int main () {
        struct node *root = NULL;
        root=newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);
        printtree(root);
        printf("\n");
        rlevelorder(root);

        return 1;
}

