
#include <string.h>
#include<stdio.h>
int main() {
        char hari[100];
        char *p = "crash";
        strcpy(hari,"hey");
        printf("%s\n", hari);//hey
        strcpy(hari,"hey hari");
        printf("%s\n", hari);//hey hari
        printf("%s\n", p);//crash
        p = "it has not crashed";
        printf("%s\n", p);//it has not crashed
        hari[1] = 'w';//hwy hari
        hari+1 = 'w';// complie time error
        printf("%s\n", hari);
        return 0;
}

