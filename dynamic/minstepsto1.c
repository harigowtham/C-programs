/*
 * Given a positive integer n, find the minimum number of steps(operations) s, that takes n to 1. You can perform any one of the following 3 steps(operation).
1.) Subtract 1 from it. (n= n - ­1) , 2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) , 3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).
 *
 */


//bottom up approach

#include<stdio.h>
#include<string.h>

int bottomup_minsteps(int n) {
        int count = 0;
        while(n>1) {

        if(n%3 == 0){
                n = n/3;
        }
        else if(n%2 == 0) {
                n = n/2;
        }
        else n--;
        count++;
        }
return count;
}
// its pointless to use mem because the array will never be used as the values are cmputed repeatedly.
int mem_minsteps(int n,int arr[]) {

        if (n == 1)
                return 0;
        if (arr[n] != -1)
                return arr[n];
        if(n%3 == 0){
                arr[n] = mem_minsteps(n/3, arr) +1;
        }
        else if(n%2 == 0) {
                arr[n] = mem_minsteps(n/2, arr) +1;
        }
        else {
                arr[n] = mem_minsteps(n-1, arr) +1;
        }
        return arr[n];
}

int rec_minsteps(int n) {
        if (n == 1)
                return 0;
        if(n%3 == 0){
                return rec_minsteps(n/3) +1;
        }
        else if(n%2 == 0) {
                return rec_minsteps(n/2) +1;
        }
        else {
        return rec_minsteps(n-1) +1;
        }
}

int main() {
        printf("in main");
        printf("best: number of steps: %d\n", bottomup_minsteps(7));
        int arr[100];
        memset(arr, -1, sizeof arr);
        printf("okish: number of steps: %d\n", mem_minsteps(7, arr));
        printf("number of steps: %d", rec_minsteps(7));
}
