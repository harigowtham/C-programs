//works
///*Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//*/
# include<stdio.h>
# include<stdlib.h>
# define bool int

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *ptr = NULL;
    *returnSize = 1;
    for(int i = 0; i < numsSize; i++) {
        nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        if (nums[abs(nums[i])-1] > 0) {
            if (ptr == NULL)
                ptr = (int*) malloc(sizeof(int));
            else {
                ptr = (int *)realloc(ptr, (*returnSize * sizeof(int)));
            }
            *(ptr+(*returnSize)-1) = abs(nums[i]);
            *returnSize = *returnSize+1;
        }
    }
    *returnSize = *returnSize-1;
    return ptr;
}

/* Driver function to test above functions */
int main()
{
	//int a[] = {1, 3, 3, 3, 3, 1, 2};
	int a[] = {1, 3, 1};
        int *p, *n;
	int size = (sizeof(a))/sizeof(a[0]);
	p = findDuplicates(a, size, n);
        for (int i = 0; i < *n; i++) {
                printf("%d", *(p+i));
        }
	return 0;
}


