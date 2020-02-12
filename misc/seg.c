#include<stdio.h>
#include<stdlib.h>

struct node {
        char a;
};

int main() {
        int a[5] = {1,2,3,4,5};
        //printf("%d", a[100]); doesnt seg fault.
        //printf("%d", a[100000]); //does seg fault
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->a = 'a';
        p->a = 'b';
        printf("%c", p->a);
        return 0;
}
