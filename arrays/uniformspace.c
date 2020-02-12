#include<stdio.h>
#define index(c) ((int)c-(int)'a')

int main () {

        int scount = 0;

        int wcount = 0;

        int sptr, aptr;

        int j = 0;

        char s1[] = "   word qord   word2";

        int n =sizeof(s1)/sizeof(s1[0]);

        char s2[n];

        for (int i = 0; i < n-1; i++) {

                if (s1[i] == ' ')

                        scount++;

                else {

                        while (s1[i] != ' ') {

                                i++;

                        }

                        wcount++;
                        if (s1[i] != '\0')
                        scount++;

                }

        }
        printf("word count:%d, space count:%d", wcount, scount);
}
