#include<stdio.h>
int fun()
{
static int count = 0;
count++;
return count;
}

int main()
{
printf("%d ", fun()); //1
printf("%d ", fun()); //2
return 0;
}

/* static functions
 * in C, access to static functions is restricted to the file where they are declared. Therefore, when we want to restrict access to functions, we make them static. Another reason for making functions static can be reuse of the same function NAME in other files.
 */
