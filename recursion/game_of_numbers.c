// Program to print all combination of size r in an array of size n
#include<stdio.h>
#include<limits.h>
#define mmax(a,b) ((a > b)?a:b)
#define mmin(a,b) ((a < b)?a:b)
int total = 0;
void combinationUtil(int arr[],int n,int r,int index,int data[],int i);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}

int m_r_p(int data[]) {
  int flag = 1;
  int min = -INT_MAX;
  min = mmin(data[0], data[1]);
  printf("a:%d, b:%d, min:%d\n", data[0], data[1], min);
  if (data[0] == 1 || data[1] ==1)
    return 0;
  for (int i = 2; i <= min; i++) {
    if (data[0]%i==0 && data[1] % i == 0)
      flag = 0;
  }
  printf("a:%d, b:%d, flag%d\n", data[0], data[1], flag);
  return flag;
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
    int ret = 0;
    // Current cobination is ready, print it
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ",data[j]);
        printf("\n");
        ret = m_r_p(data);
        printf("ret:%d, \n", ret);
        if(ret == 1){
          total++;
          printf("total:%d, \n", total);
        }
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return;

    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
    printf("total:%d", total);
    return 0;
}
