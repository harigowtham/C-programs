#include<stdio.h>

void main () {
        char a ="a";
        char b ="b";
        printf("%d\n", a- (int)'a'); //-113
        printf("%d\n", a -(int)'b'); //-114
        printf("%d\n", a -(int)"b"); //-4195842
        printf("%d\n", (int)'b' - a);//114
        //printf("%d\n", (int)'B' - a);//114
        //with capital letters it gives values such as -81, -82, -4195842, 82, 50
}
