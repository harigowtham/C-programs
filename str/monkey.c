// minimum number of space necessary is to be calculate. that part major is yet to be done

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printstr(char p[], int n) {
        for (int i =0; i < n; i++) {
                printf("%c",p[i]);
        }
                printf("\n");

}

int check(char str[], char fav[][10]) {
        int k, yes = 0;
        for(int i = 0; i<= 2; i++) {
                k = 0;
                for(int j =0; j< 10; j++) {
                        if(fav[i][j] != '\0') {
                        //if(str[k] != '\0' && fav[i][j] != '\0') {
                                if (str[k] == fav[i][j])
                                        k++;
                                else {
                                        yes = 1;
                                        break;
                                }

                        }
                        else {
                                yes = 0;
                                break;
                        }
                }
                if (!yes)
                return 0;
        }
        return -1;
}
//without dp
int ismonkeystr(char pi[], char fav[][10], int pos, int n) {
        printf("inside ismonkeystr\n");
        if (pos == (n-1))
                return 1;
        char str[100] = "";
        int j = 0;
        for(int i=pos; i<n; i++) {
                str[j] = pi[i];
                printf("%s\n", str);
                int ret = check(str, fav);
                if(ret == 0)
                        return (1 && (ismonkeystr(pi, fav, i+1, n)));
                j++;
        }
        return 0;
}
/*
//yet to write with dp
int ismonkeystr(char pi[], char fav[][10], int pos, int n) {
        printf("inside ismonkeystr\n");
        if (pos == (n-1))
                return 1;
        char str[100] = "";
        int j = 0;
        for(int i=pos; i<n; i++) {
                str[j] = pi[i];
                printf("%s\n", str);
                int ret = check(str, fav);
                if(ret == 0)
                        return (1 && (ismonkeystr(pi, fav, i+1, n)));
                j++;
        }
        return 0;
}
*/

int main() {
        char pi[] = "12382598130";
        char fav[][10] = {"121", "3825", "98130"};
        int n = sizeof(pi)/sizeof(pi[0]);
        printf("%s\n",pi);
        printstr(pi, n);
        // 1 if its a monkey str, 0 if its not a monkey str
        printf("ismonkey%d\n", ismonkeystr(pi, fav, 0, n));
        printf("check%d\n", check("325", fav));
}
