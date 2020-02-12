#include<stdio.h>
#include<string.h>
main () {
        int *i = malloc(4);
        *i = 10;
        printf("in main i:%d \n", i);//in main i:35996256
        printf("in main address of *i:%d \n", &*i);//in main address of *i:35996256
        printf("in main address of i:%d \n", &i);//in main address of i:-656203784
        xyz(i);
        printf("in main:%d \n", *i);//in main:10
        return 0;
}

void xyz(int *i) {
        printf("inside xyz i: %u\n", i);//inside xyz i: 35996256
        printf("inside xyz addr of i: %u\n", &i);//inside xyz i: 2136868456
        i = malloc(4);
        *i = 20;
        printf("inside xyz: %d\n", *i);//inside xyz: 20
        printf("inside xyz addr of *i: %d\n", &*i);//inside xyz addr of *i: 35997328
        printf("inside xyz i: %u\n", i);//inside xyz i: 35997328
        printf("inside xyz addr of i: %u\n", &i);//inside xyz i: 2136868456
}
/*
main () {
        int *i = 10;
        xyz(i);
        printf("%d", *i);
        return 0;
}
this will seg fault as i has no space.
*/
