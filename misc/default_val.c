#include<stdio.h>

void main () {
        int a;
        if (a) {
        printf("default is true");
        } else {
        printf("default is int false:%d", a);//default is int false:0%
        }
        char s;
        if (s) {
        printf("default is true");
        } else {
        printf("default is str false:%s", s);//default is str false:(null)
        }
}

//default is false
