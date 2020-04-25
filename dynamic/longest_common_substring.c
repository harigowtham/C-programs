#include<stdio.h>

int lcs(char s1[],char s2[],int n,int m) {
        int result = 0;
        int k[n+1][m+1];
        for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                        if (i ==0 || j == 0)
                                k[i][j] = 0;
                        else if (s1[i-1] == s2[j-1]) {
                                k[i][j] = k[i-1][j-1] + 1;
                                result = (k[i][j] > result)? k[i][j]:result;
                        }
                        else
                                k[i][j] = 0;
                }
        }
    for (int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j)
        {
            printf("%d\t", k[i][j]);
        }
            printf("\n");
    }
        return result;
}

int main() {
        char s1[] = "geeksforgeeks";
        //char s2[] = "g"; //1
        char s2[] = "geeksquiz"; //5
        int n = sizeof(s1)/sizeof(s1[0]);
        int m = sizeof(s2)/sizeof(s2[0]);
        printf("%d", lcs(s1, s2, n, m));
        return 1;
}

/*
 * // Returns length of function for longest common
// substring of X[0..m-1] and Y[0..n-1]
int lcs(int i, int j, int count)
{

    if (i == 0 || j == 0)
        return count;

    if (X[i-1] == Y[j-1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
        count = max(count, max(lcs( i, j - 1, 0), lcs( i - 1, j, 0)));
    return count;
}
*/
