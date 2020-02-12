#include<stdio.h>

void fib(int a, int b, int n) {
        if (n==0)
                return;
        printf("%d\t", a+b);
        fib(b, a+b, n-1);
}

int main() {
        printf("1\t1\t");
        fib(1,1,10);
        return 0;
}
