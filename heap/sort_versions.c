//doesnt work. suggestion would be use the heap as a struct instead of a
// char array. So the struct can be traversed and normal heap calculation
//  will work.. Replace 2 space by 4 doesnt work.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

char heap[1000];
//memset(heap, '$', sizeof(char));
int heapsize = 1;
int size;
//
//in ascii dec 48 to 57 is 0 to 9 of char
//in asciidec 65 to 90 is A to Z in char
//in ascii dec 97 to 122 is a to Z in char
//for str[1] they need char to have higher priority so need to do an addition
//check for that.
//While str[0] normal compare is enough
//return true if str is small than the heap value
int compare(int now, char str[]) {
  //compare str[0]
  printf("compare: now:%d, heap's now:%c%c, str:%s \n", now, heap[now], heap[now+1], str);
  if(now == 0) return 0;
  if(heap[now] == '#')
    return 1;
  if(str[0] < heap[now]) {
    return 1;
  } else if (str[0] == heap[now]) {
    //compare str[i]
    if (str[1] < 60) {
      //compare digits
      if (heap[now+1] > 60)
        return 0;
      if (str[1] < heap[now+1])
        return 1;
    } else if (str[1] > 60) {
      //compare alpha
      if (heap[now+1] < 60)
        return 0;
      if (str[1] < heap[now+1])
        return 1;
    }
  }
  return 0;
}

void printh() {
  printf("printing heap; heapsize:%d\n", heapsize);
  for (int i = 1; i < 20; i = i+2) {
      printf("%c", heap[i]);
      printf("%c  ", heap[i+1]);
  }
  printf("\n");
}

void insert(char str[]) {
  printf("in insert, heapsize:%d\n", heapsize);
  int now = heapsize;
  heap[heapsize] = str[0];
  heap[heapsize+1] = str[1];
  printf("in insert, now:%d\n", now);
  //return true if str is small
  while(compare(now/4, str)) {
    printf("compare:true");
    heap[now] = heap[heapsize/4];
    heap[now+1] = heap[(heapsize/4)+1];
    now = now/4;
  }
  heap[now] = str[0];
  heap[now+1] = str[1];
  heapsize = heapsize+2;
  printf("inserted:%s\n",heap);
}

char *pop() {
  //printf("inside pop\n");
  char *last = malloc(2*sizeof(char));
  char *min = malloc(2*sizeof(char));
  char *tmp = malloc(2*sizeof(char));
  int child, now;
  min[0] = heap[1];
  min[1] = heap[2];
  //printf("pop arr:%c\n", heap[1]);
//  printf("popping:%s\n", min);
  last[0] = heap[heapsize-2];
  last[1] = heap[heapsize-1];
  heapsize = heapsize-2;
  for(now = 1; now*4 <= heapsize; now = child) {
    child = now*4+1;
    tmp[0] = heap[child];
    tmp[1] = heap[child+1];
    if(child != heapsize && compare(child+2,tmp)) {
      child = child+2;
    }
    if (!compare(child, last)) {
      heap[now] = heap[child];
      heap[now+1] = heap[child+1];
    } else
      break;
  }
  heap[now] = last[0];
  heap[now+1] = last[1];
//  printf("popping:%s\n", min);
  return min;
}

void sort(char **str, int r, int c) {
  //printf("inside sort\n");
  for(int i = 0; i < r; i++) {
    insert(str[i]);
  }
  //printf("inside sort, done with insert\n");
    printh();
  for(int i = 0; i < r; i++) {
    printf("popped:%s\n", pop());
    //printh();
  }
}

void printa() {
  printf("print array: \t");
  for (int i = 1; i <= heapsize+1; i++) {
      printf("%c", heap[i]);
  }
  printf("\n");
}

void print(char **str, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%c", str[i][j]);
    }
    printf("\t");
  }
    printf("\n");
  for (int i = 0; i < r; i++) {
      printf("%s\t", str[i]);
  }
    printf("\n");
}

void set() {
  printf("setting array: \t");
  for (int i = 1; i <= 100; i++) {
      heap[i] = '$';
  }
}

int main() {
  //char *str[] = {"aa", "cb", "bb", "a1", "b2"};
  char *str[] = {"da", "cb", "bb", "a1", "b2"};
  int n = sizeof(str[1])/sizeof(str);
  printf("n:%d\n", n);
  heap[0] = '#';
  set(str);
  print(str, 5, 2);
  printh();
  sort(str, 5, 2);
  printa();
  printh();
  /*
  char *ans;
  ans = pop();
  printf("popped:%s\n", ans);
  printa();
  printh();
  */
  return 0;
}
