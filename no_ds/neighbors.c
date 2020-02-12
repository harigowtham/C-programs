#include<stdio.h>
#include<limits.h>
#include <string.h>

typedef struct BoundedArray{
        int size;
        int *arr;
}boundedarray;

boundedarray b;

boundedarray* cellCompute(int* states, int days) {
        int i,d,pre,tmp;
        //strlen uses /0 to check the last char.
        // instead if we use if (states[i]) to check if that is the last char that wont work
        // because state[i] will have \0 as the last char and its value is 0.
        // Which it takes as a value and goes ahead.
        int length = strlen(states);
        for (d= 0; d <days; d++) {
                for(i=0;i<length;i++) {
                        if (states[i] == 0 || states[i]==1) {
                                if (i==0) {
                                        pre = states[0];
                                        states[0] = 0^states[i+1];
                                } else if (states[i+1] != 0 && states[i+1] != 1) {
                                        states[i] = 0^pre;
                                } else {
                                        tmp = states[i];
                                        states[i] == pre^states[i+1];
                                        pre = tmp;
                                }
                        }
                }
        }
        b.arr = states;
        return &b;
}

int main() {
        int a[] = {1,1,1,0,1,1,1,1};
        int days = 2;
        int i;
        int len = sizeof(a)/sizeof(a[0]);
        boundedarray *state;
        for (i = 0; i < len; i++) {
                printf("%d \t", a[i]);
        }
        printf("\n");
        state = cellCompute(a, days);
        printf("done with cellCompute\n");
        for (i = 0; i < len; i++) {
                printf("%d \t", a[i]);
        }
}
