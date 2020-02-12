// C program to store mat of two cities for a week and display it.
#include <stdio.h>
const int row = 2;
const int col = 2;
int main()
{
    int mat[row][col];
    for (int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("row %d, col %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nDisplaying values: \n\n");
    for (int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j)
        {
            printf("row %d, col %d = %d\n", i, j, mat[i][j]);
        }
    }
    return 0;
}
