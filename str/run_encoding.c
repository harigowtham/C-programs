//if you want to store a number (ie int) in a char array,
//we need to add 48 to the number so the number's ascii gets stored as we want.

#include<stdio.h>
#include<stdlib.h>

char *encode(char str[], int n) {
        char *s = (char *)malloc(sizeof(char)*(2*n+1));
        int j = 0;
        int i = 0;
        int c = 0;
        char a;
        //for (int i = 0; i < n-1; i++) {
        while(i < n) {
                a = str[i];
                c++;
                i++;
                while (a == str[i]){
                        c++;
                        i++;
                }
                s[j] = a;
                //printf("s:%c\n", s[j]);
                j++;
                s[j] = c + 48;
                //printf("s:%c\n", s[j]);
                //still uses the number c represent added to 48
                //printf("s:%d\n", s[j]);
                j++;
                c = 0;
        }
        //this doesnt make a difference
        //s[j] = '\0';
        return s;
}

int main() {
        char str[] = "aaaxwwggd";
        int n = sizeof(str)/sizeof(str[0]);
                printf("n:%d\n", n);
        char *ans = encode(str, n);
        printf("%s", ans);
        return 0;
}
