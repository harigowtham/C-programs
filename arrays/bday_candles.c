#include<stdio.h>
#include<limits.h>

int birthdayCakeCandles(int candles_count, int* candles) {
    int count = 0;
    int max = INT_MIN;
    for(int i = 0; i < candles_count; i++) {
        if (*(candles + i) >= max) {
            printf("count: %d, max:%d \n", count, max);
            if (max == *(candles + i)) {
                count = count+1;
                printf("count val incremented to :%d\n", count);
            } else {
              max = *(candles+i);
              printf("count val is 1\n");
              count = 1;
            }
        }
    }
    return count;
}

int main() {
  int arr[] = {3,2,1,3};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("%d", birthdayCakeCandles(size, arr));
  return 0;
}
