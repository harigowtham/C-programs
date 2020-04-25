//In the steps problem, the order matters: (1,2) is not the same as (2,1). With the coin problem, only the number of each type of coin used matters.

//works

int climbStairs(int n){
    int b = 1;
    int c = 2;
    int d = 0;

    if( n == 0)
        return 0;
    if( n == 1)
        return b;
    if( n == 2)
        return c;
    int i = n-2;
    while (i--) {
        d = b + c;
        b = c;
        c = d;
    }

    return d;

}

/*2 recursive approaches:
 * First one split it 3 ways and adds it
 * second one splits it n ways at the end it if it a path, then we updates a global /static/ varialbe by ref to have the right count throughout the recursive stack
/*If C(n) is number of ways of climbing the staircase, then
C(n) = C(n-1) + C(n-2) + C(n-3) .
This is because , if we reach n-1 stairs, we can hop to n by 1 step hop or
                  if we reach n-2 stairs, we can hop to n by 2 step hop or
                  if we reach n-3 stairs, we can hop to n by 3 step hop*/
/* Recursive appraoch
void c(int n, int total, int *ways) {
        if (total > n)
                return;
        if (total == n) {
                *ways = *ways+1;
                //*ways = (*ways)++; //(*ways)++ also doesnt work. doesnt increment
                return;
        }
        //c(n, total++, ways); total++ doesnt work. it doesnt increment. not sure why
        c(n, total+1, ways);
        c(n, total+2, ways);
        //c(n, &(*total+1), ways);
}
*/
