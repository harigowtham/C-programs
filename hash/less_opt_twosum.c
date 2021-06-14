#include<stdio.h>
#include<string.h>

int *twosum(int *arr, int n, int sum) {
  printf("inside twosum\n");
  int tmp_arr[n*2];
  static int ans[2];
  memset(tmp_arr, -1, sizeof(tmp_arr));
  int  t;
  for(int i = 0; i < n; i++) {
    printf("loop iter:%d\n", i);
    printf("%d", tmp_arr[arr[i]+n]);
    if(tmp_arr[arr[i]+n] != -1) {
      ans[0] = tmp_arr[arr[i]+n];
      ans[1] = arr[i];
      printf("ans[0]:%d, ans[1]:%d\n", ans[0], ans[1]);
      return ans;
    }
    t = sum - arr[i];
    tmp_arr[t+n] = arr[i];
  }
  return ans;
}

int main() {
  int arr[] = {2,7,11,15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("arr%d, n%d\n", arr, n);
  int *val = twosum(arr, n, 9);
  printf("%d,%d", val[0], val[1]);
  return 0;
}
