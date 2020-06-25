#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *next;
};

void print(struct node *head) {
        struct node *tmp = NULL;
        if (head == NULL)
                printf("list empty");
        else {
                tmp = head;
                //printf("%d->", tmp->data);
                while(tmp->next != NULL) {
                        printf("%d->", tmp->data);
                        tmp = tmp->next;
                }
                printf("%d->NULL", tmp->data);
                //printf("NULL");
        }

}
struct node* insertNodeAtPosition(struct node* head, int data, int position) {
        struct node *tmp = head;
        struct node *t;
        int count = 1;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if(position == 0)
            return newnode;
        if(head == NULL) {
            return newnode;
            //count++;
        } else { while (tmp->next != NULL){
                if(count < position) {
                    printf("%d\t", tmp->data);
                    tmp = tmp->next;
                    count++;
                } else if (count > position){
                    printf("%d\t", tmp->data);
                    if(tmp->next == NULL)
                        tmp->next = newnode;
                    return newnode;
                } else break;
            }
        }
        //tmp = tmp->next;
        t = tmp->next;
        tmp->next = newnode;
        newnode->next = t;
        return head;
}

struct node* append(struct node *head, int data) {
        struct node *tmp = NULL;
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        tmp = head;
        /* checking tmp wont work because tmp is the address of node
         * and supposed to be garbage (except when head is empty we
         * would have assigned it to null).other than that we dont set it as null.
         * But we do set tmp->next/node->next as null.
         * So verify only using that
         *
        while(tmp != NULL) {
                tmp = tmp->next;
        }
        tmp = newnode(data);
        */
        if (tmp == NULL) {
                return newnode;
        } else {
                while (tmp->next != NULL) {
                        tmp = tmp->next;
                }
                tmp->next = newnode;
        }
        return head;
}

int main() {
        struct node *head = NULL;
        head = append(head, 16);
        head = append(head, 13);
        //print(head);
        head = append(head, 7);
        head = insertNodeAtPosition(head, 1, 2);
        print(head);
}
