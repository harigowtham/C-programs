#include<stdio.h>
#include<stdlib.h>
  int col = 3;
  int row = 3;

void dfs(char **grid, int i, int j) {
    if (i < 0 || i > row || j > col || j < 0 || grid[i][j] != '1') {
      printf("returning\n");
      return;
    }
    printf("setting # for i:%d, j:%d\n", i, j);
    grid[i][j] = '#';
    if (i+1 < row)
      dfs(grid, i+1, j);
    if (j+1 < col)
      dfs(grid, i , j+1);
    if (i-1 >= 0)
      dfs(grid, i-1 , j);
    if (j-1 >= 0)
      dfs(grid, i , j-1);
}


int numIslands(char** grid, int *size, int* colmn) {
  printf("size:%d, colmn:%d\n", *size, * colmn);
    int col = *colmn;
    int row = *(size)/col;
    int count = 0;
    for(int i=0; i < row; i++) {
        for(int j=0; j < col; j++) {
          if (grid[i][j] == '1') {
                printf("inside for i:%d, j:%d\n", i, j);
                printf("inc count:%d\n", count);
                count = count+1;
                dfs(grid, i, j);
          }
        }
    }
    printf("ret count:%d\n", count);
    return count;
}

/* Driver program to test above functions */
void fill(char** array, int rows, int cols)
{
  int i, j, k=0;
  int size = 9;
  char a[9] = {'1', '0', '0', '1', '1', '0', '1', '0', '0'};

  for (i=0; i<rows; i++)
  {
    for (j=0; j<cols; j++)
    {
      array[i][j] = a[k++];
      printf("%c\t", array[i][j]);
    }
      printf("\n");
  }
}
int main()
{
  int size = 9;
  int col = 3;
  int row = 3;
  char **grid;
  grid = malloc(row * sizeof *grid);
  for (int i=0; i<row; i++)
  {
    grid[i] = malloc(col * sizeof *grid[i]);
  }
  fill(grid, row, col);
  /*
           *grid[0] = {'1', '0', '0'};
           *grid[1] =  {'1', '1', '0'};
          *grid[2] = {'1', '0', '0'};
          */
  printf("done filling\n");
   printf(" number of islands: %d ", numIslands(grid, &size, &col));
   return 0;
}
