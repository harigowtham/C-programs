#include<stdio.h>
#include<string.h>
#define CHAR2IDX(c) ((int)c - (int)'a')
/*
struct map {
        int key;
        int value[10];
}

struct map map[30];

hash (int key, int value) {
        int i = 0;
        while (map[key].value[i] != -1) {
                i++;
        }
        map[key].value[i] = value;
        map[key].key = key;
}
*/

void remove_dup(char s[], int n) {
        int i = 0;
        int j = 0;
        int arr[30];
        memset(arr, 0, 30*(sizeof(arr[0])));
        /*
        for(int k = 0;k <30; k++){
                printf("%d", arr[k]);
        }
        */
        while (s[i] != '\0') {
                 if (arr[CHAR2IDX(s[i])] == 0 && s[i] != '\0') {
                         s[j] = s[i];
                         j++;
                 }
                 arr[CHAR2IDX(s[i])] = arr[CHAR2IDX(s[i])] + 1;
                 i++;
        }
        s[j] = '\0';
        printf("%s\n", s);
}

int main() {
        char s[] = "geeksforgeeks";
        int n = sizeof(s)/sizeof(s[0]);
        remove_dup(s, n);
        printf("%s", s);
        return 0;
}
