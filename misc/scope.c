#include<stdio.h>

int main() {
        int x = 3;
        m();
        printf("%d", x);
}

void m() {
        x = 8;
        n();
}

void n() {
        printf("%d", x);
}

/* errors out as:
scope.c: In function ‘m’:
scope.c:10:9: error: ‘x’ undeclared (first use in this function)
         x = 8;

scope.c: In function ‘n’:
scope.c:15:22: error: ‘x’ undeclared (first use in this function)
         printf("%d", x);
*/
