#include<stdio.h>
#include<stdlib.h>
#define max 50

struct node {
        int data;
        struct node *left, *right;
};

struct node **createq(int *front, int *rear) {
        struct node **q = (struct node **)malloc(sizeof(struct node *)*max);
        *front = -1;
        *rear = -1;
        return q;
}

void enq(struct node **q, int *rear, struct node *ele) {
        q[*rear] = ele;
        (*rear)++;

}

struct node *newnode(int key) {
        struct node *new = (struct node *)malloc(sizeof(struct node*));
        new->data = key;
        new->left = NULL;
        new->right = NULL;
        return new;
}

void main() {
        int front, rear;
        struct node **q = createq(&front, &rear);
        enq(q, &rear, newnode(1));
        for(int i = 0; i < max; i++)
                printf("%d ", q[i]->data);

}
