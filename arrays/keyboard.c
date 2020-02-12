#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define index(c) ((int)c - (int)'a')

int travel(char *s1, char *s2){
        int hash[26];
        int count = 0;
        int last = 0;
        int tmp;
        for (int i = 0; i<26; i++){
                // to make sure onnly char are given else returning -1
                if ((int)s1[i] > 96 && (int)s1[i]<123)
                        hash[index(s1[i])] = i;
                else
                        return -1;
        }
        for (int i = 0; i < strlen(s2); i++) {
                // to make sure onnly char are given else returning -1
                if ((int)s2[i] > 96 && (int)s2[i]<123) {
                        count = abs(last - hash[index(s2[i])]) + count;
                        last = hash[index(s2[i])];
                } else
                        return -1;
        }
        return count;
}

int main() {
        char *s1 = "abcdefghijklmnopqrstuvwxyz";
        char *s2 = "hari";
        printf("%d",travel(s1, s2));
        return 1;
}
