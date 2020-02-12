//need to handle the spaces at the end. in that case, its getting messed up, rest are all good.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[100] = "   hey           how   are   you   ";
    int i = 0, j = 0, count = 0, space = 0, total = 0;
    int sp_btw = 0, additional_sp_btw = 0, t_sp = 0;

    printf("string is '%s' \n", string);
    printf("Enter string: ");
    i = 0;
    /* use this to get custom input
    do
    {
        fflush(stdin);
        c = getchar();
        string[i++] = c;

    } while (c != '\n');
    string[i - 1] = '\0';
    i = 0;
    */

    //number of spaces
    for (i = 0; i < strlen(string); i++)
    {
            if (isspace(string[i])) {
                    space++;
            }
    }
    printf("number of spaces:%d\n", space);

    //number of words
    for (i = 0; i < strlen(string); i++)
    {
            while (i < strlen(string) && isspace(string[i])) {
                    i++;
            }
            while (i < strlen(string) && !isspace(string[i])) {
                    i++;
            }
            count++;
    }
    printf("number of words:%d\n", count);

    //move the words together to the front
    for (i = 0; i < strlen(string); i++)
    {
            while (i < strlen(string) && isspace(string[i])) {
                    i++;
            }
            while (i < strlen(string) && !isspace(string[i])) {
                    string[j] = string[i];
                    j++;
                    i++;
            }
            string[j] = ' ';
            j++;
    }
    printf("string is '%s' \n", string);

    //make all the ending char as space
    for (i = j-1; i < strlen(string); i++)
    {
            string[i] = ' ';
    }
    printf("string is '%s' \n", string);

    //calculate the space between words
    additional_sp_btw = space % count;
    sp_btw = space/(count-1);
    t_sp = sp_btw;
    printf("additional space between is '%d' \n", additional_sp_btw);
    printf("space between is '%d' \n", sp_btw);

    //replace the spaces at the back with words
    //for starting at the right place
    j--;
    //for the unnecessary decrement at the end
    j--;
    for (i = strlen(string)+1; i >= 0; i--)
    {
            if (i == j)
                    break;
            while (i >= sp_btw && i >= j && j >=0 && !isspace(string[j])) {
                    string[i] = string[j];
                    string[j] = ' ';
                    j--;
                    i--;
            }
            while (i >= sp_btw && i >= j && j >= 0 && isspace(string[j])) {
                    while (i >= sp_btw && i >= j && j>=0 && t_sp) {
                            string[i] = ' ';
                            total--;
                            i--;
                            t_sp--;
                    }
                    j--;
            }
            t_sp = sp_btw;
            if (additional_sp_btw) {
                    string[i] = ' ';
                    additional_sp_btw--;
                    i--;
            }
    }
    printf("string is '%s' \n", string);
}
