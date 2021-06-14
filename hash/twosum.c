// C program to find if a target exists
// target is the sum of two number in the array
// and efficient soln is in arrays dir
#include<stdio.h>
#include<stdlib.h>
    int arr[3];


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //int *arr = (int *) malloc(sizeof(int));
    arr[0] = 0;
    arr[1] = 0;
    //arr[2] = '\0';
    for (int i =0; i<numsSize; i++) {
    for (int j=i+1; j<numsSize; j++) {
        if ((*(nums+i))+(*(nums+j)) == target)  {
            arr[0] = i;
            arr[1] = j;
        }
        }
    }
    return arr;
}
int main () {
        int arr[] = {2,7,11,15};
        int *Sum, size;
	int n = sizeof(arr)/sizeof(arr[0]);
        Sum = twoSum(arr, n, 10, &size);
        for (int i=0; i<2; i++) {
            printf("%d", Sum[i]);
        }
}
