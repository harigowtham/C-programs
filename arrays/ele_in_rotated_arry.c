#include<stdio.h>

int pivot(int arr[], int first, int last, int p) {
        int mid = first + (last - first)/2;
        if (arr[mid+1] < mid)
                return mid;
        if (arr[mid] > p)
                return pivot (arr, mid, last, p);
        else
                return pivot(arr, first, mid, p);
}

int bsearch(int arr[], int first, int last, int key) {
        if (first < last) {
        int mid = first + (last-first)/2;
        if (arr[mid] == key)
                return mid;
        if (arr[mid] > key)
                return bsearch(arr, first, mid, key);
        else
                return bsearch(arr, mid, last, key);
        }
        return -1;
}

int search(int arr[], int n, int key, int p) {
        if(arr[0] <= key)
                return bsearch(arr, 0, p, key);
        else
                return bsearch(arr, p, n, key);
}

int main() {
        int arr[] = {4,5,6,1,2,3};
        int n = sizeof(arr)/sizeof(arr[0]);
        int p = pivot(arr, 0, n, arr[0]);
        printf("p:%d\n", p);
        printf("found at index %d", search(arr, n, 6, p));
        return 0;
}
