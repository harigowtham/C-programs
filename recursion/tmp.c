//calculate number of ways coins can be used to reach a total
#include<stdio.h>
//wrong soln. takes the orders as another way to do it.
void c(int n, int total, int *ways) {
        if (total > n)
                return;
        if (total == n) {
                *ways = *ways+1;
                //*ways = (*ways)++; //(*ways)++ also doesnt work. doesnt increment
                return;
        }
        //c(n, total++, ways); total++ doesnt work. it doesnt increment. not sure why
        c(n, total+1, ways);
        c(n, total+2, ways);
        //c(n, &(*total+1), ways);
}

int cal(int n) {
        int total = 0;
        int ways = 0;
        c(n, total, &ways);
        return ways;
}

int main() {
        printf("%d",cal(3));
        return 1;
}
