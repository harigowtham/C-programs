#include<stdio.h>

void swp(int *a, int *b) {
        int c = *b;
        *b = *a;
        *a = c;
}


int main() {
        int a[100];
        int i,j,n;
        printf("enter number of elements\n");
        scanf("%d", &n);
        printf("n:%d\n", n);
        for (i=0;i<n;i++) {
                printf("i:%d\t", i);
                scanf("%d", &a[i]);
        }
        i = 0;
        /*
        printf("\n");
        for (i=0;i<n;i++) {
                printf("i:%d\t", i);
                printf("%d\n", a[i]);
        }
        */
        i = 0;
        j = n-1;
//        j = sizeof(a)/sizeof(a[1]);
        while(i!=j) {
                if(a[i] != 0) {
                        if(a[j] != 1) {
                    //            printf("before swp: i:%d, j:%d\t", a[i],a[j]);
                                swp(&a[i], &a[j]);
                    //            printf("after swp: i:%d, j:%d\t", a[i],a[j]);
                                //return 0;
                        } else
                                j--;
                } else {
                        i++;
                }
        }
        printf("\n");
        for (i=0;i<n;i++) {
                printf("i:%d\t", i);
                printf("%d\n", a[i]);
        }
        return 0;
}

/*
 * while(type0 < type1)
    {
        if(arr[type0] == 1)
        {
            swap(arr[type0],
                 arr[type1]);
            type1--;
        }
        else
        type0++;
    }
    */
