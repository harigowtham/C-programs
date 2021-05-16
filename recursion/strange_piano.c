// Program to print all combination of size k in an array of size n
#include<stdio.h>
#define mmax(a,b) ((a > b)?a:b)
int total = 0;
void combinationUtil(int arr[],int n,int k,int index,int data[],int i);

// The main function that prints all combinations of size k
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int k)
{
    // A temporary array to store all combination one by one
    int data[k];

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, k, 0, data, 0);
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   k      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int k, int index, int data[], int i)
{
    int max = 0;
    // Current cobination is ready, print it
    if (index == k)
    {
        max = data[0];
        for (int j=1; j<k; j++) {
            max = mmax(max, data[j]);
            printf("%d ",data[j]);
        }
        printf("\n");
        printf("%d", max);
        total = total+max;
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return;

    printf("index:%d, i:%d\n", index, i);
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, k, index+1, data, i+1);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, k, index, data, i+1);
}

// Driver program to test above functions
int main()
{
    int arr[] = {2, 4, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]); // will be got as the first input in first line
    int k = 3; //will be got as the 2nd input from firt line
    printCombination(arr, n, k);
    printf("total: %d", total);
    return 0;
}
