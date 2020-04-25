//works
// needs wrapper.

/*Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/
struct Map {
        int key;
        int value;
};

struct Map map[100000];                                                            \
void printmap() {
        for (int i= 0; i < 100; i++) {
                        printf("%d ", map[i].value);
                        printf("\n ");
        }
        return;
}

int singleNumber(int* nums, int numsSize){
    memset(map, -1, 100000*sizeof(map[0]));
    for(int i = 0; i < numsSize; i++) {
        int key = nums[i];
        printf("key%d\t",nums[i]);
        if (map[key+50000].value == -1)
        printf("map[key].value:%d\t",map[key+50000].value);
            map[key+50000].value = (map[key+50000].value)+1;
    }
    printmap();
    for(int j = 0; j < 100000; j++) {
        if (map[j].value == 0)
            return j-50000;
    }

    return -1;
}

