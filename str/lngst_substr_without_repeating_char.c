#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHARS 256

int lstr(char s[], int n) {
        int max = 0;
        int cur = 0;
        int tmp = 0;

        int *arr = (int *)malloc(sizeof(int)*CHARS);
        memset(arr, -1, (sizeof(int)*256));

        for (int i =0; i <n; i++ ) {
                if (arr[s[i]] == -1) {
                        arr[s[i]] = i;
                        cur++;
                        max = (max > cur)? max : cur;
                } else {
                        tmp = cur-arr[s[i]];
                        arr[s[i]] = i;
                        max = (max > tmp)? max : tmp;
                        cur = 1;
                }
        }
        return max;
}

int main() {
        char s[] = "abcdabc";
        int n = sizeof(s)/sizeof(s[0]);
        printf("length of longest substr without repeating char : %d", lstr(s, n));
        return 1;
}
