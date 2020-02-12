#include<stdio.h>

void printarr(int arr[], int n) {
        for (int i = 0; i<n; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

int max(int a, int b) {
        if (a > b)
                return a;
        return b;
}

void leader(int arr[], int n) {
        int a[n];
        a[n-1] = arr[n-1];
        for (int i =n-2; i>=0; i--) {
                a[i] = max(arr[i], a[i+1]);
        }
        printarr(a, n);
        for (int i = 1; i<n; i++) {
                if (arr[i] >= a[i])
                        printf("%d ", arr[i]);
        }

}

int main() {
        int arr[] = {3,12,34,2,0,-1};
        int n = sizeof(arr)/sizeof(arr[0]);
        printarr(arr, n);
        leader(arr, n);
        return 1;
}
