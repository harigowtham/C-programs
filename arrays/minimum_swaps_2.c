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

void minS(int arr_count,int *arr) {

}

int main() {
        /*
        int n = 5;
        int *arr = (int *)malloc(sizeof(int)*n);
        arr[0]=2;
        arr[1]=1;
        arr[2]=5;
        arr[3]=3;
        arr[4]=4;
        */
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
        printArray(arr, n);
        //minimumBribes(n, arr);
        minB(n, arr);
        return 1;
}
