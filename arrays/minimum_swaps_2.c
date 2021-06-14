#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 8

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

// works for an arr with ele ` to n. If the number are non consecutive, then
// we have to copy the array contents to another array sort it and then  use 
// that as the 'i' value below used to create the hash. As these values
//  are different from 1 to n. we have to create an array(nodeMap) of a
//  bigger size so it can hold the values for hashing.
void minS(int arr_count,int *arr) {
    int isVisited[max+1] = {0};

    int nodeMap[max+1] = {-1};

    for (int i = 1; i <= max; i++) {
      nodeMap[i] = arr[i - 1];
    }
    int countSwap = 0;

    for (int k = 1; k <= max; k++) {

      if (isVisited[k] == 1 || (k == nodeMap[k]))
          continue;
      int j = k;
      int c = 0;
      while (!isVisited[j]) {

          isVisited[j] = 1;

          j = nodeMap[arr[j-1]];
          c++;
      }

      if (c > 0)
         countSwap = countSwap + (c -1);
    }

    printf("swap count :%d", countSwap);
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
        //int n = 5;
        int *arr = (int *)malloc(sizeof(int)*max);
        arr[0]=1;
        arr[1]=2;
        arr[2]=5;
        arr[3]=3;
        arr[4]=4;
        arr[5]=8;
        arr[6]=6;
        arr[7]=7;
        printArray(arr, max);
        //minimumBribes(n, arr);
        minS(max, arr);
        return 1;
}
