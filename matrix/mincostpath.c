/* Dynamic Programming implementation of MCP problem */
#include<stdio.h>
#include<limits.h>
#define R 3
#define C 3

int min(int x, int y, int z) {
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

void print_mat(int cost[R][C]) {
        for(int x = 0 ; x < R ; x++) {
        printf(" (");
        for(int y = 0 ; y < C ; y++){
            printf("%d     ", cost[x][y]);
        }
        printf(")\n");
        }
        printf("\n");
}

int minCost(int arr[R][C], int r, int c) {
        //this was necessary to return the min value among pre set 0 of ans1,2,3 and any of the actually value (which is more than zero)
        /*
        int ans2= arr[r][c];
        int ans3= arr[r][c];
        int ans= arr[r][c];
        int ans1 = arr[r][c];
        */
        int ans = -1;
        int ans1 = -1;
        int ans2 = -1;
        int ans3 = -1;
        printf("r:%d, c:%d, arr: %d \n", r, c, arr[r][c]);
        /*
         * cant use this base case as it leave out a few cases like r > 2 but c is still right.
         * so we handle each base before that particular entry.
        if (r > 2 && c > 3) {
                printf("returning 0\n");
               // return arr[r][c];
               return 0;
        }
        */

        if (r+1 < R)
                ans1 = minCost(arr, r+1, c);
        if ((r+1 < R) && (c+1 < C))
                ans2 = minCost(arr, r+1, c+1);
        if (c+1 < C)
                ans3 = minCost(arr, r, c+1);
        printf("ans1:%d, ans2:%d, ans3:%d, ans:%d\n", ans1, ans2, ans3, ans);
        if(ans1 != -1 && ans2 != -1) {
                ans1 = (ans1<ans2)?ans1:ans2;
                if(ans3 != -1)
                        ans1 = (ans1<ans3)?ans1:ans3;
        return ans1+arr[r][c];
        }
        else if(ans2 != -1 && ans3 != -1) {
                ans2 = (ans2<ans3)?ans2:ans3;
                if(ans1 != -1)
                        ans2 = (ans2<ans1)?ans2:ans1;
        return ans2+arr[r][c];
        } else if(ans1 != -1 && ans3 != -1) {
                ans1 = (ans1<ans3)?ans1:ans3;
                if(ans2 != -1)
                        ans1 = (ans1<ans2)?ans1:ans2;
                return ans1+arr[r][c];
        }
        //ans = min(ans1, ans2, ans2);
        printf("ret:%d, arr[%d][%d]:%d\n", ans+arr[r][c], r, c, arr[r][c]);
        return ans+arr[r][c];
}

int dyn_min() {
}

/* Driver program to test above functions */
int main()
{
        /*
   int cost[R][C] = { {3, 4, 1, 2},
                      {2, 1, 8, 9},
                      {4, 7, 8, 1} };
*/
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
     print_mat (cost);
   printf(" %d ", minCost(cost, 0, 0));
   return 0;
}

