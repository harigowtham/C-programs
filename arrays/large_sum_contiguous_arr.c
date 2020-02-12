#include<stdio.h>
#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
   int temp_div = 0;
   int div = 0;

   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        /*
        temp_div = max(max_so_far, div+max_so_far);
        //temp_div = max_so_far;
        if (temp_div % 3 == 0){
                div = temp_div;
                if ((temp_div > div))
                        div = temp_div;
        }*/
   }
   return max_so_far;
}

int main()
{
   //int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int a[] = {2, -7, -6, 1, 4, 5};
   int n = sizeof(a)/sizeof(a[0]);
   int div = maxSubArraySum(a, n);
   printf("max:%d",div);
   return 0;
}
