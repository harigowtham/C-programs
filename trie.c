#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define char_to_index(a) a - (int)'a'

struct node {
  int is_last;
  struct node *next[26];
};

struct node *create() {
  struct node *node= (struct node *)malloc(sizeof(struct node));
  for (int i = 0; i < 26; i++) {
    node->next[i] = NULL;
  }
  node->is_last = 0;
  return node;
}

void insert(struct node *root, char *str) {
  struct node *node = NULL;
  node = root;
  int len, index;
  len = strlen(str);
  printf("%s", str);
  for (int i = 0; i < len; i++) {
    index = char_to_index(str[i]);
    if ((node->next[index]) == NULL) {
      node->next[index] = create();
    }
    node = node->next[index];
  }
  node->is_last = 1;
  return;
}

int search(struct node *root, char *str) {
  struct node *node = root;
  int index = 0, len;
  len = strlen(str);
  for (int i = 0; i < len; i++) {
    index = char_to_index(str[i]);
    if(node->next[index]){
      node = node->next[index];
    } else
        return 0;
  }
  return node->is_last;
}

int main () {
  struct node *root = create();
  char *str = "hari";
  char *str1 = "harii";
  printf("%s", str);
  insert(root, str);
  if (search (root, str1)) {
    printf("present");
  }
  return 1;
}
