#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};


void insert(struct Node **head, int data) {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        if (new == NULL)
                return;
        new->data = data;
        new->next = NULL;
        struct Node *temp = *head;
        if (temp == NULL) {
                *head = new;
                return;
        }
        while (temp->next != NULL)
                temp = temp->next;
        temp->next = new;
        return;

}

void print(struct Node *head) {
        while(head != NULL){
                printf("%d->", head->data);
                head= head->next;
        }
}

int main() {
        struct Node *head = NULL;
        insert(&head, 5);
        insert(&head, 5);
        print(head);
        return 0;
}
