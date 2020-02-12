#include<stdio.h>

void swap(int *a, int *b) {
        int c = *b;
        *b = *a;
        *a = c;
}

void segregate0and1(int arr[],
                    int size)
{
    int type0 = 0;
    int type1 = size - 1;

    while(type0 < type1)
    {
        if(arr[type0] == 1)
        {
            swap(&arr[type0],
                 &arr[type1]);
            type1--;
        }
        else
        type0++;
    }
}

// Driver Code
int main()
{
    int arr[] = {0, 1, 0, 1, 1, 0};
    int i, arr_size = sizeof(arr) /
                      sizeof(arr[0]);

    segregate0and1(arr, arr_size);

    printf("Array after segregation is ");
    for (i = 0; i < arr_size; i++)
       printf("%d \t",arr[i]);

    return 0;
}
