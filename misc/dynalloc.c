#include <stdio.h>
#include <stdlib.h>

void reallocate(int **ptr) {
  *ptr = (int *)realloc(*ptr, sizeof(int)*4);
  *(*(ptr)+3) = 40;
  return;
}

int main()
{
int *ptr = (int *)malloc(sizeof(int)*2);
int i;
int *ptr_new;

*ptr = 10;
*(ptr + 1) = 20;

ptr = (int *)realloc(ptr, sizeof(int)*3);
*(ptr + 2) = 30;
reallocate(&ptr);
for(i = 0; i < 4; i++)
	printf("%d ", *(ptr + i));
getchar();
return 0;
}

