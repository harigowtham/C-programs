int maxSubArray(int* nums, int numsSize){
    int max = INT_MIN;
    int max_so_far = INT_MIN;
    int i = 0;
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    max = nums[0];
    max_so_far = nums[0];
    for (i = 1; i < numsSize; i++) {
        if (max+nums[i] > nums[i]){
            max = max+nums[i];
        } else
            max = nums[i];
        if(max > max_so_far)
            max_so_far = max;

    }
    return max_so_far;

}


