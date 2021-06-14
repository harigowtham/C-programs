#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node* create() {
  struct node *node = (struct node*)malloc(sizeof(struct node));
  return node;
}

struct node* append(struct node *head, int key) {
  struct node *node = NULL;
  struct node *tmp = head;
  node = create();
  node->data = key;
  node->next=NULL;
  if(head == NULL) {
    head = node;
    return head;
  }
  while(tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = node;
  return head;
}

struct node *add(struct node *head, int key) {
  struct node *node = NULL;
  node = create();
  node->data = key;
  node->next=head;
  return node;
}

void added(struct node **head, int key) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node = create();
  node->data = key;
  node->next= *head;
  *head = node;
}

void print_node(struct node* head) {
  if (head==NULL) {
    printf("empty");
    return;
  }
  printf("%d->", head->data);
  while(head->next != NULL) {
    head = head->next;
    printf("%d->", head->data);
  }
  printf("NULL\n");
  return;
}

void rev(struct node **head) {
  //struct node *tmp, *prev, *last = NULL; doesn't work
  struct node *tmp = NULL;
  struct node *prev = NULL;
  struct node *last = NULL;

  struct node *cur = *head;
  if (cur == NULL) {
    return;
  }
  if (cur->next == NULL) {
    return;
  }
  while(cur != NULL && cur->next != NULL) {
    if (cur->next->next == NULL) {
      cur->next->next = cur;
      last = cur->next;
      cur->next = prev;
      *head = last;
      return;
    }
    tmp = cur->next->next;
    cur->next->next = cur;
    last = cur->next;
    cur->next = prev;
    cur = tmp;
    prev = last;
  }
  /*
  if (cur == NULL) {
    *head = prev;
    return;
  }
  */
  if (cur->next == NULL) {
    cur->next = prev;
  }
  *head = cur;
  return;
}

void removeloop(struct node *head, struct node *p2) {
  printf("removing loop\n");
  struct node *p1 = head;
  while (p1->next != p2->next) {
    p1 = p1->next;
    p2 = p2->next;
  }
  p2->next = NULL;
  print_node(head);
}

int detect_loop(struct node *head) {
  struct node *p1 = head;
  struct node *p2 = NULL;
  if(head == NULL) {
    return 0;
  }
  else {
    p2 = head->next;
    while(p1->next != NULL && p2->next != NULL && p2->next->next != NULL) {
      if (p1 == p2) {
        removeloop(head, p2);
        return 1;
      }
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return 0;
  }
}

int main() {
  struct node *head = NULL;
  head = append(head, 1);
  head = append(head, 2);
  //app(&head, 3);
  head = add(head, 0);
  added(&head, -1);
  print_node(head);
  rev(&head);
  print_node(head);
  struct node *head1 = NULL;
  struct node *t = create();
  t->data = 3;
  t->next=NULL;
  printf("t:%d, data:%d, next%d\n", t, t->data, t->next);
  struct node *t1 = create();
  t1->data = 4;
  t->next = t1;
  printf("t: %d, data:%d, next%d\n", t, t->data, t->next);
  printf("t1: %d, data:%d, next%d\n", t1, t1->data, t1->next);
  struct node *t2 = create();
  t2->data = 5;
  t1->next = t2;
  struct node *t3 = create();
  t3->data = 6;
  t2->next = t3;
  t3->next=t3;
  head1 = t;
  if (detect_loop(t)) {
    printf("loop there");
  } else {
    printf("no loop");
  }
  //print_node(t);
  return 0;
}
