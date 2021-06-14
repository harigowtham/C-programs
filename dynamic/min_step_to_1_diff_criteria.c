#include<stdio.h>
#include<string.h>

int min(int x, int y, int z) {
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int unnecessary_bottomup_minsteps(int n) {

  int moves[4][n+1];
	//memset(moves, -1, sizeof(moves));
  for (int i=0; i<4;i++) {
        for(int j=0;j <n+1;j++) {
          printf("%d \t", moves[i][j]);
        }
        printf("\n");
  }
  for(int j=0;j<4;j++) {
      moves[j][0]=0;
  }

  for (int i=0; i<n+1;i++) {
        moves[0][i]=0;
        moves[1][i]=i;
  }

  for (int i=1; i<4;i++)
        moves[i][i]=1;

  printf("\n 2nd print \n");
  for (int i=0; i<4;i++) {
        for(int j=0;j <n+1;j++) {
          printf("%d \t", moves[i][j]);
        }
        printf("\n");
  }
  printf("\n 3rd print \n");
  for (int i=2; i<4;i++) {
        for(int j=1;j <n+1;j++) {
          if (j<i)
            moves[i][j]=moves[i-1][j];
          else if (j>i)
            moves[i][j]= (moves[i-1][j] < 1+moves[i][j-i])?moves[i-1][j]:1+moves[i][j-i];
          printf("%d \t", moves[i][j]);
        }
        printf("\n");
  }

  printf("\n final print \n");
  for (int i=0; i<4;i++) {
        for(int j=0;j <n+1;j++) {
          printf("i:%d, j:%d, moves:%d   ",i,j, moves[i][j]);
        }
        printf("\n");
  }
  return moves[3][n];
}

int bottomup_minsteps(int n) {
        int count = 0;
        while(n>=1) {

        if(n-3 >= 0){
                n = n-3;
        }
        else if(n-2 >= 0) {
                n = n-2;
        }
        else {
                n--;
        }
        count++;
        }
return count;
}

int rec_minsteps(int n) {
        int moves3 = 1000;
        int moves1 = 1000;
        int moves2 = 1000;
        if (n == 1 || n == 2 || n == 3)
                return 1;
        if (n < 1)
          return 0;
        if(n-3 > 0){
                moves3 = rec_minsteps(n-3) +1;
        }
        else if(n-2 > 0) {
                moves2 = rec_minsteps(n-2) +1;
        }
        else {
        moves1 =  rec_minsteps(n-1) +1;
        }
        return min(moves3, moves2, moves1);
}

int main() {
        printf("in main");
        printf("best: number of steps: %d\n", bottomup_minsteps(5));
        printf("number of steps in unnecessary_bt: %d\n", unnecessary_bottomup_minsteps(10));
        //int arr[100];
        //memset(arr, -1, sizeof arr);
        //printf("okish: number of steps: %d\n", mem_minsteps(7, arr));
        //works
        printf("number of steps: %d", rec_minsteps(9));
}
