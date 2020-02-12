#include<stdio.h>

int check(int arr[], int size, int num) {
        if (size < 0)
                return 0;
        if (!check(arr, size-1, num)) {
                if (arr[size] == num)
                        return 1;
                else
                        return 0;
        }
        /*
        } else
                return 1;
                */
}

int main() {
        int arr[] = {1,2,3,4,5};
        int n = sizeof(arr)/sizeof(arr[0]);
        if(check(arr,n, 9))
                printf("present");
        else
                printf("absent");
}
