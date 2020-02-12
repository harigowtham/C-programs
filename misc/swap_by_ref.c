#include <stdio.h>
void swapnum ( int *var1, int *var2 )
{
   int tempnum ;
   printf("\n*var1 %d", *var1);//*var1 35
   printf("\nvar1 %d", var1);//var1 151031980
   tempnum = *var1 ;
   *var1 = *var2 ;
   *var2 = tempnum ;
}

/*
void swapnum ( int var1, int var2 )
{
   int tempnum ;
   printf("\n*var1 %d", *var1);
   printf("\nvar1 %d", var1);
   tempnum = *var1 ;
   *var1 = *var2 ;
   *var2 = tempnum ;
}
*/
int main( )
{
   int num1 = 35, num2 = 45 ;
   printf("Before swapping:");
   printf("\nnum1 value is %d", num1);//num1 value is 35
   printf("\nnum2 value is %d", num2);//num2 value is 45
   printf("\n&num1 value is %d", &num1);//&num1 value is 151031980
   printf("\n&num2 value is %d", &num2);//&num2 value is 151031976

   /*calling swap function*/
   swapnum( &num1, &num2 );

   printf("\nAfter swapping:");
   printf("\nnum1 value is %d", num1);//num1 value is 45
   printf("\nnum2 value is %d", num2);//num2 value is 35
   return 0;
}
