#include<stdio.h>

int maxSubArraySum(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        printf("i:%d, a[i]:%d\n", i, a[i]);
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here) {
            printf("Before: max_so_far:%d, max_ending_here:%d\n", max_so_far, max_ending_here);
            max_so_far = max_ending_here;
            printf("After: max_so_far:%d, max_ending_here:%d\n", max_so_far, max_ending_here);
        }
            printf("max_so_far:%d, max_ending_here:%d\n", max_so_far, max_ending_here);

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, -10, 1, 5, -3, 11};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    printf("max sum:%d", max_sum);
    return 0;
}
