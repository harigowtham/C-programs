#include<stdio.h>
#include<stdlib.h>

int main() {
        int a = -1;
        printf("%d\n", a);
        a = -a;
        printf("%d\n", a);
        a = -a;
        printf("%d\n", a);
        a = -abs(a);
        printf("%d\n", a);
        return 1;
}
