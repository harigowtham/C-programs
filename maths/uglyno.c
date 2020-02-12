#include<stdio.h>

int main() {
        int n = 15;
        int i, count = 1;
        while (1) {
                i++;
                if (!(i%2) || !(i%3) || !(i%5))
                        count++;
                if (count == n) {
                        printf("%d", i);
                        return 1;
                }
        }
        return 1;
}
