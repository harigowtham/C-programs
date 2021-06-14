//works
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
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
        printf("nums[i]:%d\n", nums[i]);
        printf("abs(nums[i]):%d\n", abs(nums[i]));
        printf("abs(nums[i])-1:%d\n", abs(nums[i])-1);
        nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        printf("nums[abs(nums[i]-1)]:%d\t", nums[abs(nums[i])-1]);
        printf("-nums[abs(nums[i]-1)]:%d\n", -nums[abs(nums[i])-1]);
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
	int a[] = {1, 3, 3, 3, 3, 1, 2};
	//int a[] = {1, 3, 1};
        int *p, *n;
	int size = (sizeof(a))/sizeof(a[0]);
	p = findDuplicates(a, size, n);
        for (int i = 0; i < *n; i++) {
                printf("%d", *(p+i));
        }
	return 0;
}


