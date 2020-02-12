#include<stdio.h>
#include<stdlib.h>

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void rotRightWithoutMem(int a_count, int* a, int d, int* result_count) {
int tmp = 0;
int swp = 0;
int j = 0;
int rot = d % a_count;
*result_count = a_count;
//printArray(a, a_count);
for (int i = 0; i < a_count; i++) {
    tmp = (j+rot);
    if (tmp >= a_count) {
            tmp = tmp - a_count;
    }
    swp = a[tmp];
    a[tmp] = a[j];
    j = tmp;
}
printf("Right rot:");
printArray(a, a_count);
return;
}

int* rotRight(int a_count, int* a, int d, int* result_count) {
int tmp = 0;
int rot = d % a_count;
int* res = malloc(sizeof(int)*a_count);
*result_count = a_count;
//printf("a_count :%d,", a_count);
//printArray(a, a_count);
for (int i = 0; i < a_count; i++) {
    tmp = (i+rot);
    if (tmp >= a_count) {
            tmp = tmp - a_count;
    }
    res[tmp] = a[i];
}
printf("Right rot:");
printArray(res, a_count);
return res;
}

int* rotLeft(int a_count, int* a, int d, int* result_count) {
int tmp = 0;
int rot = d % a_count;
int* res = malloc(sizeof(int)*a_count);
*result_count = a_count;
//printf("a_count :%d,", a_count);
//printArray(a, a_count);
for (int i = 0; i < a_count; i++) {
    tmp = (i-rot);
    if (tmp < 0) {
            tmp = tmp + a_count;
    }
    res[tmp] = a[i];
}
printf("Left rot:");
printArray(res, a_count);
return res;
}

int main() {
        //int a[] = {1,2,3,4,5,6};
        //this wont work while passing  arr  (ie the address of arr starting).
        //it has be a ptr to be passed.
        int *n;
        int *arr = (int *)malloc(sizeof(int)*6);
        arr[0]=1;
        arr[1]=2;
        arr[2]=3;
        arr[3]=4;
        arr[4]=5;
        arr[5]=6;
        printf("before rot:");
        printArray(arr, 6);
        int *b = rotLeft(6, arr, 14, n);
        b = rotRight(6, arr, 13, n);
        rotRightWithoutMem(6, arr, 13, n);
        return 0;
}
