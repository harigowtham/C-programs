#include<stdio.h>
#include<string.h>

int check(char a[], int len) {
        int j = len-1;
        printf("len:%d. a:%s\n", len,a);
        for (int i = 0; i<len/2; i++) {
                //printf("a[i]:%c, a[j]:%c\n", a[i],a[j]);
                if (a[i] != a[j])
                        return 1;
                j--;
        }
        return 0;
}

int main() {
        char a[50];
        int ret =-1;
        printf("enter string:");
        scanf("%s", a);
        int len = strlen(a);
        //int len = sizeof(a)/sizeof (a[1]);
        printf("len:%d", len);
        ret = check(a, len);
        if (!ret)
                printf("pal");
        else
                printf("no");
        return 1;
}

//doesnt work with spaces in the string
//use fgets to take spaces. it stops at enter
