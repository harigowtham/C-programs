#include<stdio.h>
#define max 5

int top = -1;
int s[max];

void push(int val) {
  if(top < max-1) {
    top++;
    s[top] = val;
  } else printf("stack full\n");
}

int pop() {
  if (top == -1){
    printf("empty stack\n");
    return -1;
  } else {
    return s[top--];
  }
}

void print(){
  for (int i = 0; i <= top; i++) {
    printf("%d ", s[i]);
  }
  printf("\n");
}

int main() {
  push(1);
  print();
  printf("pop: %d\n", pop());
  printf("pop: %d\n", pop());
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  push(7);
  print();
  printf("pop: %d\n", pop());
  printf("pop: %d\n", pop());
  print();
  return 0;
}
