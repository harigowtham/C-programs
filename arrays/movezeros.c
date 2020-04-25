#include<stdio.h>
void moveZeroes(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    while(i < numsSize) {
        if (nums[i] == 0) {
            i++;
        } else {
            nums[j] = nums[i];
            i++;
            j++;
        }
    }
    while(j < numsSize) {
        nums[j] = 0;
        j++;
    }
}

int main() {
        int arr[] = {1,32,0,0,3,5};
        int n = sizeof(arr)/sizeof(arr[0]);
        for(int i =0; i<n;i++){
                printf("%d", arr[i]);
        }
                printf("\n");
                printf("%d", n);
                printf("\n");
        moveZeroes(arr, n);
        for(int i =0; i<n;i++){
                printf("%d", arr[i]);
        }
        return 1;
}
