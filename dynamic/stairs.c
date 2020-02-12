/* A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//*ans is useless in the final program
long int stairs(int n, long int *arr,long int *ans) {
        if (n < 0)
                return 0;
        if (arr[n] != -1)
                return arr[n];
        arr[n-1] = stairs(n-1, arr, ans);
        arr[n-2] = stairs(n-2, arr, ans);
        arr[n-3] = stairs(n-3, arr, ans);
        arr[n] = arr[n-1]+arr[n-2]+arr[n-3];
/*
        *ans = *ans + stairs(n-1, arr, ans);
        *ans = *ans + stairs(n-2, arr, ans);
        *ans = *ans + stairs(n-3, arr, ans);
        arr[n] = *ans;
        */
        return arr[n];
}

int main() {
        printf("in main\n");
        //long int arr[100];
        long int *arr = (long int *)malloc(sizeof(long int)*100);
        long int ans = 0;
        memset(arr, -1, (sizeof arr)*100);
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        printf("okish: number of steps: %d\n", stairs(4, arr, &ans));
}
