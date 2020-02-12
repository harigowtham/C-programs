#include <stdio.h>

const int MAX = 3;

int main () {

   //int  var[] = {10, 100, 200};
   int var0 = 1;
   char var1 = 'a';
   float var2 = 0.1;

   int i;
   void *ptr[MAX];

   ptr[0] = &var0; /* assign the address of integer. */
   ptr[1] = &var1; /* assign the address of integer. */
   ptr[2] = &var2; /* assign the address of integer. */

   for ( i = 0; i < MAX; i++) {
      printf("addr of each var = %u\n", ptr[i] );
   }

   printf("Value of var[0] = %d\n",  *(int*)ptr[0] );
   printf("Value of var[1] = %c\n",  *(char*)ptr[1] );
   printf("Value of var[2] = %f\n",  *(float*)ptr[2] );

   return 0;
}
