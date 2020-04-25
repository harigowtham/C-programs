#include <stdio.h>

int main()
{
	int x = 19;
        printf("%d\n", x&1);
        //the last digit decides if its odd or even.
        //even in binary its sort of the same.
        //The last bit adds 1 to the total value of the number
        //eg: 1 in binary refers to 1,
        //10 refers to 2
        //11 refers to 3
        //100 refers to 4
        //Follows to 8421 model. where the total of all the corresponding bit gives the value.
        //So the last bit says it is adds one to the total or not.
        //and the total will always be even values (32,16,8,4,2,1) except for the one at the end.
        //So when we & 1 (00....0001) we check if the last bit is set
        //if its set then 1 is added to the even value and it is an odd number
        //If its not set then the total value is an even number
	(x & 1) ? printf("Odd") : printf("Even");
	return 0;
}

