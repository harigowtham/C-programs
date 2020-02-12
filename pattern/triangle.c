#include<stdio.h>
/*
int main() {
        int n =5;
        int k = 0;
        for (int i = 1; i <= (n); i++){
                for (int j = 1; j< (2*n); j++) {
                        if (j <= (n-i))
                                printf(" ");
                        if (j > (n-i) && (j <=(n)))
                                printf("%d", ++k);
                        if(j >= (n+1) && (j <= (n+i-1))) {
                                printf("%d", --k);
                        }
                }
                printf("\n");
        }

}
ans:
    1
   232
  34543
 4567654
567898765


int main() {
        int n = 4;
        int k;
        for (int i = 1; i <= n; i++) {
                        k = i;
                for (int j =1; j<=n; j++) {
                        if (j <= (n-i))
                                printf(" ");
                        if (j >= (n-i+1)) {
                                printf("%d", k);
                                k++;
                        }
                }
                printf("\n");
        }
        return 1;
}

ans:
   1
  23
 345
4567


*/

int main() {
        int n = 5;
        int k;
        for(int i=1; i<=n;i++) {
                k = 1;
                for (int j=1; j <= (n*2); j++) {
                        if(j <= i)
                                printf("%d", k++);
                        if ((j > i) && (j <= ((2*n)-i))) {
                                printf(" ");
                        }
                        if (j > ((2*n)-i))
                                printf("%d", --k);
                }
                printf("\n");
        }
        return 1;
}

















