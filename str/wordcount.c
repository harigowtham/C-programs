// C program to illustrate
// fgets() which reads from buffer and file
#include <stdio.h>
#include <string.h>
#define MAX 15
int main()
{
    char buf[MAX];
    int option;
    int wc;
    char *p;
    char *token;
    FILE* fptr = NULL;
    printf("enter 1 for stdin \n \t2 for file\n");
    scanf("%d ", &option);// use a space after %d to avoid fgets reading a blank line by scanf and skipping
    switch(option) {
            case 1:
                    fgets(buf, MAX, stdin);
                    printf("string is: %s\n", buf);
                    break;
            case 2:
                    fptr = fopen ("percentage.c", "r");
                    fgets(buf, MAX, fptr);
                    printf("string is: %s\n", buf);
                    break;
    }
    p = buf;
    while((token=strtok_r(p, " ", &p))) {
            printf("%s\n", token);
            wc++;
    }
    printf("wordcount: %d\n", wc);
    printf("string is: %s\n", p);
    printf("string is: %s\n", buf);

    return 0;
}

/*
 * ./a.out
enter 1 for stdin
 	2 for file
1
hey ididot whatsup
string is: hey ididot wha
hey
ididot
wha
wordcount: 3
string is:
string is: hey
*/
