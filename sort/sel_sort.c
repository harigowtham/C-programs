#include<stdio.h>

void swap(int *a, int *b) {
        int c;
        c = *b;
        *b = *a;
        *a = c;
}

void sort(int a[], int n) {
        int min;
        for (int i = 0 ; i<n-1 ; i++) {
                int min=i;
                for (int j =i+1; j<n; j++) {
                        printf("a[i]:%d, a[j]:%d\n", a[i], a[j]);
                        if (a[min] > a[j]) {
                                min = j;
                        }
                }
                                printf("swapping: a[i]:%d, a[min]:%d\n", a[i], a[min]);
                                swap (&a[min], &a[i]);
                                printf("after swapping: a[i]:%d, a[min]:%d\n", a[i], a[min]);
        }
}

void print(int a[], int n) {
        for (int i=0; i<n; i++) {
                printf("%d,", a[i]);
        }
        printf("\n");
}

int main () {
        int a[] = {1, 8, 5, 23, 7};
        int n = sizeof(a)/ sizeof (a[1]);
        print(a, n);
        sort(a, n);
        print(a, n);
        return 1;
}
