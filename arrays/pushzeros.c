#include<stdio.h>

void printarr(int arr[], int n) {
        for (int i = 0; i<n; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

/* doesnt work if there are a lot of aeros in front
void pushzero(int arr[], int n) {
        int count = 0;
        for(int i = 0; i<n; i++) {
                if ((i+count) > (n-1)) {
                        arr[i] = 0;
                }
                else {
                if(arr[i+count] == 0)
                        count++;
                arr[i] = arr[i+count];
                }
        }
}
*/
void pushzero(int arr[], int n) {
        int i,j=0;
        for(i=0;i<n;i++)
        {
                if(arr[i]!=0)
                {
                        int temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
                        j++;
                }
        }}

int main() {
        int arr[] = {0,0,0,0,0,48,0,0,4,0,7,4};
        int n = sizeof(arr)/sizeof(arr[0]);
        printarr(arr, n);
        pushzero(arr, n);
        printarr(arr, n);
        return 1;
}
