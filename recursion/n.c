#include<stdio.h>
/*
 * two variables to print ascending order
void rec(int n, int i) {
        if (n == i)
                return;
        printf("%d", i);
        rec(n, i+1);
}

void util_rec (int n) {
        rec(n , 1);
}
*/

void util_rec(int n) {
        if (n == 0)
                return;
        util_rec(n-1);
        printf("%d", n);
}

int main() {
        util_rec(5);
}
