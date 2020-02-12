#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct node *newnode(int data) {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->data = data;
        node->next = NULL;
        return node;
}

void print(struct node *head) {
        struct node *tmp = head;
        while(tmp != NULL) {
                printf("%d->", tmp->data);
                tmp = tmp->next;
        }
        printf("NULL");
}

struct node *insert(struct node *head, int data) {
        struct node *tmp = head;
        /* checking tmp wont work because tmp is the address of node
         * and supposed to be garbage. we dont set it as null.
         * But we do set tmp->next/node->next as null.
         * So verify only using that
         *
        while(tmp != NULL) {
                tmp = tmp->next;
        }
        tmp = newnode(data);
        */
        if(tmp ==NULL) {
                return newnode(data);
        }
        while (tmp->next != NULL) {
                tmp = tmp->next;
        }
        tmp->next = newnode(data);
        return head;
}

void insert(struct node **headref, int data) {
        struct node *tmp = head;
        /* checking tmp wont work because tmp is the address of node
         * and supposed to be garbage. we dont set it as null.
         * But we do set tmp->next/node->next as null.
         * So verify only using that
         *
        while(tmp != NULL) {
                tmp = tmp->next;
        }
        tmp = newnode(data);
        */
        if(tmp ==NULL) {
                return newnode(data);
        }
        while (tmp->next != NULL) {
                tmp = tmp->next;
        }
        tmp->next = newnode(data);
        return head;
}
int add(struct node *head, struct node *head1, struct node *res) {
        if (head != NULL && head1 != NULL) {
                res = insert(res, head->data+head1->data);
                int carry = add(head->next, head1->next, res->next);
        }
}

int main() {
        struct node *head = NULL;
        head = insert(head, 5);
        head = insert(head, 6);
        head = insert(head, 3);
        print(head);
        return 0;
        struct node *head1 = NULL;
        head1 = insert(head1, 8);
        head1 = insert(head1, 4);
        head1 = insert(head1, 2);
        print(head1);
        struct node *res = NULL;
        int p = add(head, head1, res);
        printf("\n");
        print(res);
}
