#include<stdio.h>
int main () {
        int arr[] = {10,2,3,4,5};
        int *i,*j;
        i = &arr[4];
        j = &arr[2];
        printf("arr:%d\n", arr); //ptr to array eg arr:-1346035376
        printf("&arr:%d\n", &arr); //ptr to array eg &arr:-1346035376
        printf("&arr[]:%d\n", &arr[0]); //addr of ptr to array eg &arr[]:-1346035376
        printf("arr+1:%d\n", arr+1); // addr + 1 arr+1:-1346035372
        printf("*(arr+1):%d\n", *(arr+1)); //*(arr+1):2
        printf("*(arr)+1:%d\n", *(arr)+1); //*(arr)+1:11
        printf("*(arr+3)+1:%d\n", *(arr+3)+1);// *(arr+3)+1:5
        printf("arr[5]:%d\n", arr[5]);//arr[5]:0
        printf("arr[2]:%d\n", arr[2]);//arr[2]:3
        printf("2[arr]:%d\n", 2[arr]);//2[arr]:3
        printf("arr[1] - arr[4]:%d\n", arr[1] - arr[4]);//arr[1] - arr[4]:-3
        printf("two integers apart: i - j:%d\n", i-j);//two integers apart: i - j:2
        printf("arr[-1]:%d", arr[-1]);//arr[-1]:0
        return 0;
}
