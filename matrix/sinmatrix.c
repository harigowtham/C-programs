#include<stdio.h>

void sinmatrix(int n, int m, int arr[n][m]) {
        int t;
        int k = -1;
        int i;
        int j;
        for (i = 0; i < m; i++) {
                for(j =0; j < n; j++) {
                        if (i%2 == 0) {
                                k++;
                                printf("%d ", arr[k][i]);
                        } else {
                                printf("%d", arr[k][i]);
                                k--;
                        }
                                printf("\n");
                }
        }
}


int main() {
        int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
        sinmatrix(3,4,arr);
        return 1;
}
