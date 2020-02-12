/*
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

    return 0;
}
*/
/*
 * C Program to Count the Number of Repeated Occurrences
 * of a particular Word in a String
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[100], word[20], unit[20], c;
    int i = 0, j = 0, count = 0;

    printf("Enter string: ");
    i = 0;
    do
    {
        fflush(stdin);
        c = getchar();
        string[i++] = c;

    } while (c != '\n');
    string[i - 1] = '\0';
    printf("Enter the word you want to find: ");
    scanf("%s", word);
    for (i = 0; i < strlen(string); i++)
    {
        while (i < strlen(string) && !isspace(string[i]) && isalnum(string[i]))
        {
            unit[j++] = string[i++];
        }
        if (j != 0)
        {
            unit[j] = '\0';
            if (strcmp(unit, word) == 0)
            {
                count++;
            }
            j = 0;
        }
    }

    printf("The number of times the word '%s' found in '%s' is '%d'.\n", word, string, count);
}

/*C Program to Count the Number of Repeated Occurrences of a particular Word in a String
This C Program counts the number of repeated occurrences of a particular word in a string.
Here is a source code of the C program that counts the number of repeated occurrences of a particular word in a string. The C program is successfully compiled and run on a Linux system. The program output is also shown below.
*/
