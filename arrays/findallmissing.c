/* works
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *ptr = NULL;
    *returnSize = 1;
    for(int i = 0; i < numsSize; i++) {
        nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        //printf("%d", nums[abs(nums[i]-1)]);
    }
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            if (ptr == NULL)
                ptr = (int*) malloc(sizeof(int));
            else {
                ptr = (int *)realloc(ptr, (*returnSize * sizeof(int)));
            }
            *(ptr+(*returnSize)-1) = i+1;
            *returnSize = *returnSize+1;
        }
    }
    *returnSize = *returnSize-1;
    return ptr;
}


