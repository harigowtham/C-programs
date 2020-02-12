#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

void check(char a[]) {
    //printf("%s\n", a);
    int n = strlen(a);
    int j = n-1;
    int count = 0;
    int t = 0;
    /* this works as well
    for (int i = 0; i < n/2; i++) {
        if (a[i] != a[j]) {
            if (CHAR_TO_INDEX(a[i]) > CHAR_TO_INDEX(a[j])){
                t = CHAR_TO_INDEX(a[i])-CHAR_TO_INDEX(a[j]);
                count = t + count;
            }
            else {
                t = CHAR_TO_INDEX(a[j])-CHAR_TO_INDEX(a[i]);
                count = t + count;
            }
        }
        j++;
    }*/
    for (int i = 0; i < n/2; i++) {
        if (a[i] != a[j]) {
            if ((a[i]) > (a[j])){
                t = (a[i])-(a[j]);
                count = t + count;
            }
            else {
                t = (a[j])-(a[i]);
                count = t + count;
            }
        }
        j--;
    }
    printf("%d\n", count);
}

int main() {
    int t = 0;
    char a[10][1000];
    //printf("hi");
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%s",&a[i][0]);
}
    for (int i = 0; i < t; i++) {
    //printf("for : %s\n", a[i]);
        check(a[i]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

