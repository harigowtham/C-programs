#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r = 3, c = 4;
    int *arr = (int *)malloc(r * c * sizeof(int));

    int i, j, count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         *(arr + i*c + j) = ++count;

    for (i = 0; i <  r; i++){
      for (j = 0; j < c; j++)
         printf("i:%d, j:%d, i*c+j:%d, %d ",i,j,i*c+j, *(arr + i*c + j));
      printf ("\n");
    }

   /* Code for further processing and free the
      dynamically allocated memory */

   printf("%d\n", *arr);
   printf("%d\n", *arr+1);
   return 0;
}
