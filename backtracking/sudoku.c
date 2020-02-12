#include<stdio.h>
//#include<bool.c>
#define N 9
#define UNASSIGN 0

void printgrid(int grid[N][N]) {
        for(int i = 0; i < N; i++){
                for (int j = 0; j < N; j++) {
                        printf("%2d", grid[i][j]);
                }
                printf("\n");
        }
}

// find the unassigned as well
int isunassigned(int grid[N][N], int *row, int *col) {
        for (*row = 0; *row< N; (*row)++){
                for (*col = 0; *col < N; (*col)++) {
                        if (grid[*row][*col] == UNASSIGN)
                                return 1;
                }
        }
        return 0;
}

int rowsafe(int grid[N][N],int row,int num) {
        for (int i = 0; i<N; i++){
                if (grid[row][i] == num)
                        return 1;
        }
        return 0;
}

int colsafe(int grid[N][N],int col, int num) {
        for (int i = 0; i<N; i++){
                if (grid[i][col] == num)
                        return 1;
        }
        return 0;
}

int boxsafe(int grid[N][N], int row, int col, int num) {
        for (int i = 0; i<3; i++){
                for (int j = 0; j<3; j++) {
                        if (grid[i+row][j+col] == num)
                                return 1;
                }
        }
        return 0;
}

int issafe(int grid[N][N], int row, int col, int num) {
        return (!rowsafe(grid, row, num) && !colsafe(grid, col, num) && !boxsafe(grid, row-(row%3), col-(col%3),num));
}

int sudoku(int grid[N][N]){
        int row = 0;
        int col = 0;
        if (!isunassigned(grid, &row, &col))
                return 1;
        for (int i = 1;i <= N; i++) {
                if (issafe(grid, row, col, i)) {
                        grid[row][col] = i;
                if (sudoku(grid))
                        return 1;
                grid[row][col] = UNASSIGN;
                }
        }
        return 0;
}

int main() {
        int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
        if (sudoku(grid))
                printgrid(grid);
        return 1;
}
