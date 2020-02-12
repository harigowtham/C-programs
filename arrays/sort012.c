#include<stdio.h>

void printarr(int arr[], int n) {
        for (int i = 0; i<n; i++) {
                printf("%d", arr[i]);
        }
        printf("\n");
}

void sort(int arr[], int n) {
        int i0 = 0;
        int i1 = 0;
        int i2 = 0;
        int k = 0;
        for (int i = 0; i<n; i++) {
                if (arr[i] == 0)
                        i0++;
                else if (arr[i] == 1)
                        i1++;
                else if (arr[i] == 2)
                        i2++;
        }
                printf("%d,%d,%d\n", i0, i1,i2);
        for (int i = 0; i < n; i++) {
                if (i < i0)
                        arr[i] = 0;
                if (i >= i0 && i-i0 < i+i1)
                        arr[i] = 1;
                if (i >= i0+i1 && i-i1-i2 < i+i2+i1)
                        arr[i] = 2;
        }
}

int main() {
        int arr[] = {1,1,0,0,0,2,2,1,0};
        int n = sizeof(arr)/sizeof(arr[0]);
        printarr(arr, n);
        sort(arr, n);
        printarr(arr, n);
        return 1;
}
