#include<stdio.h>

void subString(char str[], int n)
{
    // Pick starting point
    for (int start = 0; start < n; start++)
    {
        // Pick ending point
        for (int end = start+1; end < n; end++)
        {
            //  Print characters from current
            // starting point to current ending
            // point.
            for (int k = start; k < end; k++)
                printf("%c", str[k]);
            printf("\n");
        }
    }
}

int main() {
        char str[] = "this is a test string";
        int n =sizeof(str)/sizeof(str[0]);
        subString(str, n);
        return 1;
}
