#include<stdio.h>
#include<string.h>
main () {
        int i = -1;
        int garbage;
        if (!NULL && 1)
                printf("prints");//prints
        else
                printf("doen't");
        if (NULL && !strcmp(NULL,"ier"))
                        printf("works");
        printf("%d", !i); //0
        printf("grabage: %d", garbage);//prints 0
        if (NULL == 0)
                printf("Null is also zero");//prints
        int *ptr = NULL;
        printf("The value of ptr is %u",ptr);//prints 0
}
