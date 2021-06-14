#include<stdio.h>
#include<stdlib.h>
int hash[] = {1,3,4,2,5};

int comp(const void *a, const void *b) {
        int *a1 = (int*)a;
        int ha = hash[(*a1)];
        //printf("a:%d", a);
        int *b1 = (int *)b;
        int hb = hash[(*b1)];
        return ha - hb;
}

void printh(int arr[], int n, int hash[]) {
  for(int i = 0; i < n; i++) {
    printf("hash[%d]:%d\n", i, hash[i]);
  }
}

void printa(int arr[], int n, int hash[]) {
  for(int i = 0; i < n; i++) {
    printf("arr[%d]:%d\n", i, arr[i]);
  }
}

void sort(int arr[], int n, int hash[]) {
    qsort(arr, n, sizeof(arr[0]), comp);
}

int main() {
      //int hash[]= {1, 3, 4, 2, 5};
        int arr[] = {0, 1, 2, 3, 4};
        int n = sizeof(arr)/sizeof(arr[0]);
        printa(arr, n, hash);
        printh(arr, n, hash);
        printf("after sort of hash\n");
        sort(arr, n, hash);
        printa(arr, n, hash);
        return 1;
}
