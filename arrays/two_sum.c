/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Hashmap. O(n) time, O(n) space
The hashmap solution for c++ is nice and simple, the c takes a bit more work and uses the external uthash (which is automatically included for c solutions).

*/

struct number_hash {
  int value;
  int index;
  UT_hash_handle hh;
};

void destroy_table(struct number_hash** table) {
  struct number_hash* curr;
  struct number_hash* tmp;

  HASH_ITER(hh, *table, curr, tmp) {
    HASH_DEL(*table, curr);
    free(curr);
  }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  struct number_hash* table = NULL;
  struct number_hash* element;
  int* ret = (int*) malloc(2 * sizeof(int));
  int remaining;
  for (int i = 0; i < numsSize; ++i) {
    remaining = target - nums[i];

    // Find if there has already been an element such that the sum is target
    HASH_FIND_INT(table, &remaining, element);
    if (element) {
      ret[0] = element->index;
      ret[1] = i;
      break;
    } else {
    // Add the new number to the hash table if it doesn't exist already
      element = (struct number_hash *) malloc(sizeof(*element));
      element->value = nums[i];
      element->index = i;

      HASH_ADD_INT(table, value, element);
    }
  }

  destroy_table(&table);

  *returnSize = 2;
  return ret;
}
