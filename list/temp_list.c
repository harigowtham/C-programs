#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *next;
};

void push(struct node **node, int data) {
        struct node *nnode;
        nnode = (struct node*) malloc (sizeof (struct node));
        nnode->data = data;
        if (*node == NULL)
                nnode->next = NULL;
        else
                nnode->next = (*node);
        *node = nnode;
}

void insert (struct node ** node, int data) {
        if (node == NULL)
                printf("null node");
        else {
                struct node *nnode;
                nnode = (struct node*) malloc (sizeof (struct node));
                nnode -> data = data;
                nnode -> next = (*node) -> next;
                (*node) -> next = nnode;
        }
}

void append(struct node **node, int data) {
        struct node *tnode = *node;
        struct node *nnode;
        nnode = (struct node*) malloc (sizeof (struct node));
        nnode -> data = data;
        if (*node == NULL) {
                nnode->next = NULL;
                *node = nnode;
        } else {
                while (tnode->next != NULL) {
                        tnode = tnode->next;
                }
                nnode->next = NULL;
                tnode->next = nnode;
        }
}

void printnode(struct node *node) {
        if (node==NULL)
                printf("empty");
        else {
                /* this wont be reflected
                        node->data = 10;
                        printf("%d->", node->data);
                */

                do {
                        //printf("%d:%d,%d->", node->data, node->next, node);
                        printf("%d->", node->data);
                        node = node->next;
                } while (node->next != NULL);
                        printf("%d->", node->data);
        }
}

int main() {
        struct node* head = NULL;
        push(&head,1);
        push(&head,5);
        push(&head,3);
        /*
        append(&head, 5);
        append(&head, 6);
        append(&head, 57);
        push(&head,3);
        insert(&head->next, 8);
        */
        printnode(head);

        return 1;
}
