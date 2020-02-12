#include<stdio.h>

int main() {
        int *child[26];
        for (int i=0;i<26;i++) {
                child[i] = i+1;
                printf("%d", child[i]);
        }
}

//doesnt work
