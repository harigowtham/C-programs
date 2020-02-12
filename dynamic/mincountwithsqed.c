#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MIN(a,b) (a<b)?a:b

int mincountofsqed(int n) {
        int ans=0;
        int min=0;
        if (n < 0)
                return 0;
        for (int i = ceil(n/2); i > 0; i--) {
                if (i*i > n)
                        continue;
                else if (i*i == n)
                        return 1;
                else if (i*i < n) {
                        ans = mincountofsqed(n- (i*i))+ 1;
                }
                if (min == 0)
                        min = ans;
                min = MIN(ans, min);
        }
        return min;
}

int mem_mincountofsqed(int n, int *arr) {
        int ans=0;
        int min=0;
        if (n < 0)
                return 0;
        if (arr[n] != -1)
                return arr[n];
        // sqrt gives square root of the number.
        // this reduces the number of iterations we need to do
        // in c to use sqrt from math lib, it has to be linked while building the executable.
        // else it errors out.
        // command to build math while building this c program is  gcc -g mincountwithsqed.c -lm
        for (int i = ceil((int)sqrt(n)); i > 0; i--) {
                if (i*i > n)
                        continue;
                else if (i*i == n)
                        return 1;
                else if (i*i < n) {
                        ans = mem_mincountofsqed((n- (i*i)), arr)+ 1;
                }
                if (arr[n] == -1)
                        arr[n] = ans;
                min = arr[n] = MIN(ans, arr[n]);
        }
        return min;
}

int main() {
        printf("in main\n");
        //long int arr[100];
        int *arr = (int *)malloc(sizeof(int)*100);
        int ans = 0;
        memset(arr, -1, (sizeof arr)*100);
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 3;
        printf("mem: number of steps: %d\n", mem_mincountofsqed(8, arr));
        printf("rec: number of steps: %d\n", mincountofsqed(8));
}
