#include<stdio.h>

void fib(int n) {
  int a = 0, b = 1, c=0;
  if (n == 0)
    printf("0");
  else
    printf("0 1 ");
  for(int i = 1; i < n-1; i++) {
    c = a+b;
    a = b;
    b = c;
    printf("%d ", c);
  }
}

void r_fib(int a, int b, int n) {
  if (n == 0)
    printf("%d", b);
    return;
  r_fib(b, a+b, n-1);
  printf("%d", b);
}

int main() {
  fib(5);
  r_fib(0, 1, 5);
  return 0;
}
