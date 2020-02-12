#include<stdio.h>
#include<stdlib.h>
int comp(const void *a, const void *b) {
        int *a1 = (int*)a;
        int *b1 = (int *)b;
        return a - b;
}

void print(int arr[], int n) {
                printf("inside print\n");
        int x;
        int flag = 0;
       qsort(arr, n, sizeof(arr[0]), comp);
                printf("after sort\n");
        for(int i = 0; i < n-2; i++) {
                x = arr[i];
                int *l = &arr[i+1];
                int *r = &arr[n-1];
                while (*l<*r) {
                        if ((x + *l + *r) > 0){
                                *(r--);
                        } else if ((x+ *l + *r) < 0) {
                                *(l++);
                        } else if ((x + *l + *r == 0)) {
                                printf("%d,%d,%d\n", x,*l,*r);
                                flag = 1;
                                break;
                        }
                }
        }
        if (flag == 0)
        printf("not found");
        return;
}

int main() {
        int arr[] = {0, -1, 2, -3, 1};
        int n = sizeof(arr)/sizeof(arr[0]);
        print(arr, n);
        return 1;
}
