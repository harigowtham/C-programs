#include<stdio.h>
#include<math.h>

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

int raisingPower(int arr[], int n) {
        int max = 0;
        for (int i = 0; i<n-1; i++) {
                arr[i] = (int)pow(arr[i], arr[i+1]);
        }
        printarr(arr, n);
        max = arr[0];
        for (int i = 1; i<n-2; i++) {
                if (arr[i] >= max)
                        max = arr[i];
        }
        return max;

}

int main() {
        int arr[] = {3,5,4,2};
        int n = sizeof(arr)/sizeof(arr[0]);
        printarr(arr, n);
        printf("%d", raisingPower(arr, n));
        return 1;
}
