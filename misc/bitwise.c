#include<stdio.h>
int main () {
        int a =  1;
        int b =  2;
        int c;
        c=a&b;
                printf("c = %d \n",c);
        if (a & b) {
                printf("prints\n");
                printf("a = %d,b = %d", a,b);
        } else {
                printf("doen't\n");
                printf("a & b = %d \n",c);
                printf("a = %d,b = %d", a,b);
        }
        printf("\n3%5 : %d\n", 3%5);

        printf("xor: %d\n",1^1);//0
        printf("xor: %d\n",1^2);//3
        printf("xor: %d\n",2^1);//3
        printf("xor: %d\n",2^1^2^1);//0
        return 0;
}
