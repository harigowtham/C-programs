#include<stdio.h>
#include<stdlib.h>
struct node {
        int data;
        struct node *next;
};

void push(struct node **node, int data) {
        struct node *nnode = (struct node *) malloc (sizeof (struct node));
        nnode->data = data;
        if (*node != NULL)
                nnode->next = *node;
        else
                nnode->next = NULL;
        *node = nnode;
}

void append(struct node **node, int data) {
        struct node *nnode = (struct node*) malloc(sizeof(struct node));
        nnode->data = data;
        nnode->next = NULL;
        if (node != NULL) {
                struct node *tnode = *node;
                while (tnode->next != NULL) {
                        tnode = tnode->next;
                }
                tnode->next = nnode;
        } else {
                *node = nnode;
        }
}


void print (struct node *node) {
        if (node == NULL)
                printf("no list");
        else {
                printf("%d->", node->data);
                while (node->next != NULL) {
                        node = node->next;
                        printf("%d->", node->data);
                }
        }
}

void insert (struct node **node, int data) {
        struct node *nnode = (struct node*) malloc(sizeof(struct node));
        if (*node == NULL) {
                printf("empty");
        } else {
                nnode->data = data;
                nnode->next = (*node)->next;
                (*node)->next = nnode;
                }
        }

void swap (struct node **node, int x, int y) {
        struct node *tnode = *node;
        struct node *prev1 = NULL;
        struct node *prev2 = NULL;
        struct node *prev = NULL;
        struct node *data1 = NULL;
        struct node *data2 = NULL;
        struct node *data = NULL;
        struct node *dat = NULL;
        if (*node == NULL)
                printf("empty");
        else {
                while(tnode->next != NULL) {
                        if (tnode->data == x) {
                                data1 = tnode;
                                prev1 = prev;
                        }
                        if (tnode->data == y) {
                                data2 = tnode;
                                prev2 = prev;
                        }
                        prev = tnode;
                        tnode =tnode->next;
                }
                if (prev1 == NULL || prev2 == NULL)
                        printf("ele not found");
                else {
                        /*
                        data = data1;
                        prev1->next = data2;
                        data2->next = data1->next;
                        prev2->next = data;
                        data1->next = data->next;
                        */
                        data = data1;
                        dat = data2->next;
                        prev1->next = data2;
                        data2->next = data1->next;
                        prev2->next = data;
                        data->next = dat;
                }
        }

}

int main () {
        struct node *head = NULL;
        push(&head, 1);
        push(&head, 5);
        push(&head, 3);
        append(&head, 9);
        append(&head, 7);
        insert(&head->next, 6);
        print(head);
        printf("\n");
        swap(&head, 5, 1);
        printf("\n");
        print(head);
        return 0;
}

//elements at the end are not taken care
