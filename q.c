#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int dequeue(){
  if(rear == -1){
    printf("empty\n");
  } else if(front >= rear) {
    printf("exceeded\n");
  } else {
    front++;
    return queue[front%MAX];
  }
  return -1;
}

void enqueue(int key) {
  printf("init enq of %d\n", key);
  if (rear < front || rear + 1 - front > MAX){
    printf("enq failed as q full\n");
  } else {
    rear++;
    queue[rear % MAX] = key;
  }
}

void printq(){
  if (rear == -1 || rear == front) {
    printf("q empty\n");
    return;
  }
  printf("\n");
  for(int i = front+1; i <= rear; i++) {
    printf("%d  ", queue[i%MAX]);
  }
  printf("\n");
}

int main() {
  printf("deq:%d\n", dequeue());
  enqueue(1);
  enqueue(2);
  printq();
  printf("deq:%d\n", dequeue());
  enqueue(3);
  enqueue(4);
  enqueue(5);
  printf("deq:%d\n", dequeue());
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  printf("deq:%d\n", dequeue());
  printf("deq:%d\n", dequeue());
  printf("deq:%d\n", dequeue());
  printf("deq:%d\n", dequeue());
  printf("deq:%d\n", dequeue());
  printf("deq:%d\n", dequeue());
  enqueue(10);
  printq();
  return 0;
}

