/* C program for recursive implementation of Bubble sort */
//check normal bubble sort and come to this for better understanding
#include <stdio.h>


void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int* a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
	//printf("a,b:%d,%d\n", a,b); gives values like a,b:-1171810032,-1171810028
        printf("a,b:%d,%d\n", *a, *b);
}

int bubbleOne(int arr[], int n)
{
    int ret = 1;
    if (n <= 1)
    {
        return 1;
    }
	printf("in bubbleone:\n");
	printArray(arr, n);
	printf("n:%d\n", n);
	if (arr[0] > arr[1])
	{
		swap(&arr[0], &arr[1]);
		ret = 0;
	}
	return bubbleOne(arr+1, n-1) && ret;
}

void bubbleSort(int arr[], int n)
{
	if (n <= 1 || bubbleOne(arr, n))
	{
	    return;
    }
	printf("in bubblesor:\n");
	printArray(arr, n);
	printf("n:%d\n", n);
	bubbleSort(arr, n-1);
}
int main()
{
	int arr[] = {64, 34, 25, 190, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Array before sort:\n");
	printArray(arr, n);

	bubbleSort(arr, n);
	printf("Sorted array:\n");
	printArray(arr, n);
	return 0;
}

