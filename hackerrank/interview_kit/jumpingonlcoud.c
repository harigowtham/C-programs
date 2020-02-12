#include<stdio.h>

int JumpingOnClouds(int c_count, int* c) {
int count =0;
for (int i =0; i < c_count; i++) {
    printf("i :%d, c[i]:%d\n", i, c[i]);
    if (c[i+2] == 0) {
        count++;
        i = i+1;
        printf("i in +2 :%d, c[i]:%d \n", i, c[i]);
    } else if (c[i+1] == 0) {
        count++;
        printf("i in +1 :%d, c[i]:%d \n", i, c[i]);
    }
}
return count;
}
// Complete the jumpingOnClouds function below.
int jumpingOnClouds(int c_count, int* c) {
    if (c_count <= 0)
        return 0;
int count =0;
//missed the -1 here and the solution was different in hacker rank for {0.0}
//check the limits
for (int i =0; i < c_count-1; i++) {
    printf("i :%d, c[i]:%d\n", i, c[i]);
    if (c[i+2] == 0) {
        count++;
        i = i+1;
        printf("i in +2 :%d, c[i]:%d \n", i, c[i]);
    } else if (c[i+1] == 0) {
        count++;
        printf("i in +1 :%d, c[i]:%d \n", i, c[i]);
    }
}
return count;
}

// Driver Code
int main()
{
    //int arr[] = {0};
    int arr[] = {0,0};
    //int arr[] = {0, 0, 1, 0, 0, 1, 0};
//    int arr[] = {0, 0, 0, 1, 0,0};
    int i, arr_size = sizeof(arr) /
                      sizeof(arr[0]);

    printf("min jumps; %d",jumpingOnClouds(arr_size, arr));

    return 0;
}
