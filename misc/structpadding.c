
// C program to show an example
// of Structure padding
#include <stdio.h>

struct s {
    int i;
    char ch;
    double d;
};

int main()
{
    struct s A;
    _Bool b;
    printf("Size of b is: %ld\n", sizeof(b)); //
    printf("Size of i is: %ld\n", sizeof(A.i)); // 4
    printf("Size of ch is: %ld\n", sizeof(A.ch)); // 1
    printf("Size of d is: %ld\n", sizeof(A.d)); // 8
    printf("But the Size of A is: %ld", sizeof(A)); // 16 not 13 and it because of padding
}

