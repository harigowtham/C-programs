#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swp(int *a, int *b) {
        int c = *b;
        *b = *a;
        *a = c;
}
// Complete the minimumBribes function below.
// below code works, not this big one
void minimumBribes(int q_count, int* q) {
        int brb = 0, tmp = 0, flag = 0;
        int *arr = (int *)malloc(sizeof(int)*q_count);
        memset(arr, 0, (sizeof arr[0])*q_count);
        int *a = (int *)malloc(sizeof(int)*q_count);
        memset(a, 0, (sizeof arr[0])*q_count);
        for(int i = 0; i < q_count; i++) {
                a[i] = q[i];
        }
        for(int i = 0; i < q_count; i++) {
                if (i < q_count-2 && i+1 == q[i+2]) {
                        swp(&q[i+1], &q[i+2]);
                        arr[q[i+1]] = arr[q[i+1]]+1;
                        arr[q[i+2]] = arr[q[i+2]]+1;
                        brb++;
                }
                if (i > 2 && i+1 == q[i-2]) {
                        swp(&q[i-1], &q[i-2]);
                        arr[q[i-1]] = arr[q[i-1]]+1;
                        arr[q[i-2]] = arr[q[i-2]]+1;
                        brb++;
                }
        }
        printArray(q, q_count);
        printf("\n");
        for(int i = 0; i < q_count; i++) {
                if (i < q_count -1 && i+1 == q[i+1]) {
                        swp(&q[i], &q[i+1]);
                        arr[q[i]] = arr[q[i]]+1;
                        arr[q[i+1]] = arr[q[i+1]]+1;
                        brb++;
                }
                if (i > 1 && i+1 == q[i-1]) {
                        swp(&q[i], &q[i-1]);
                        arr[q[i]] = arr[q[i]]+1;
                        arr[q[i-1]] = arr[q[i-1]]+1;
                        brb++;
                }
        }
        printArray(q, q_count);
        printf("\n");
        for(int i = 0; i < q_count; i++) {
                if (q[i] != i+1 || arr[i+1] > 2) {
                        flag = 1;
                }
        }
        if (flag == 1){
                flag = 0;
                printf("inside reverse\n");
                brb = 0, tmp = 0, flag = 0;
                memset(arr, 0, (sizeof arr[0])*q_count);
                printArray(arr, q_count);
                for(int i = q_count; i > 0; i--) {
                        if (i < q_count-2 && i+1 == a[i+2]) {
                                swp(&a[i+1], &a[i+2]);
                                arr[q[i+1]] = arr[q[i+1]]+1;
                                arr[q[i+2]] = arr[q[i+2]]+1;
                                brb++;
                        }
                        if (i > 2 && i+1 == a[i-2]) {
                                swp(&a[i-1], &a[i-2]);
                                arr[q[i-1]] = arr[q[i-1]]+1;
                                arr[q[i-2]] = arr[q[i-2]]+1;
                                brb++;
                        }
                }
                printArray(a, q_count);
                printf("\n");
                for(int i = q_count; i > 0; i--) {
                        if (i < q_count -1 && i+1 == a[i+1]) {
                                swp(&a[i], &a[i+1]);
                                arr[q[i]] = arr[q[i]]+1;
                                arr[q[i+1]] = arr[q[i+1]]+1;
                                brb++;
                        }
                        if (i > 1 && i+1 == a[i-1]) {
                                swp(&a[i], &a[i-1]);
                                arr[q[i]] = arr[q[i]]+1;
                                arr[q[i-1]] = arr[q[i-1]]+1;
                                brb++;
                        }
                }
                printArray(a, q_count);
                printf("\n");
                printArray(arr, q_count);
                for(int i = 0; i < q_count; i++) {
                        //if (a[i] != i+1 || arr[i+1] > 2) {
                        if (a[i] != i+1 ) {
                                printf("flag:%d, arr[i]:%d\n", flag, arr[i]);
                                flag = 1;
                        }
                }
                if (flag ==1)
                        printf("Too chaotic\n");
                else
                        printf("%d\n", brb);
        } else {
                printf("%d\n",brb);
        }
}

int max(int a,int b) {
        if (a > b)
                return a;
        else
                return b;
}

// Complete the minimumBribes function below.
// no need to swap, just use the inner loop to see how many swaps it needs,
// The traversal from front to back means we have to deal with one direction only.
// When we deal with one direction no need to be worried about actual swap.
void minB(int q_count, int* q) {
        int brb = 0;
        for(int i = 0; i < q_count; i++) {
                // i-1 is because array starts at 0 while here its needed from 1
                // check if its 2 more than swaps away, then call it chaotic
                printf("%d\n", q[i-1]);
                if (q[i-1] - (i) > 2) {
                        printf("Too chaotic\n");
                        return;
                }
                //if its not, then go from that point minus 2 to the the point
                //and see how many swaps are need (at max 2 for each value of i)
                for (int j = max(0, q[i]-2); j < i; j++) {
                        if(q[j] > q[i])
                                brb++;
                }
        }
        printf(" number of b:%d\n",brb);
}

int main() {
        int n = 5;
        int *arr = (int *)malloc(sizeof(int)*n);
        arr[0]=2;
        arr[1]=1;
        arr[2]=5;
        arr[3]=3;
        arr[4]=4;
        /*
        int n = 8;
        int *arr = (int *)malloc(sizeof(int)*n);
        arr[0]=1;
        arr[1]=2;
        arr[2]=5;
        arr[3]=3;
        arr[4]=7;
        arr[5]=8;
        arr[6]=6;
        arr[7]=4;
        */
        printArray(arr, n);
        //minimumBribes(n, arr);
        minB(n, arr);
        return 1;
}
