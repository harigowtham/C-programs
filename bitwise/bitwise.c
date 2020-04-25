/*Check this to brush up https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 *
 * The & (bitwise AND) in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
The | (bitwise OR) in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.
The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.
The << (left shift) in C or C++ takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
The >> (right shift) in C or C++ takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
The ~ (bitwise NOT) in C or C++ takes one number and inverts all bits of it
*/

// C Program to demonstrate use of bitwise operators
#include <stdio.h>
int main()
{
	// a = 5(00000101), b = 9(00001001)
	unsigned char a = 5, b = 9;

	// The result is 00000001
	printf("a = %d, b = %d\n", a, b); //a = 5, b = 9
	printf("a&b = %d\n", a & b); //a&b = 1

	// The result is 00001101
	printf("a|b = %d\n", a | b);//a|b = 13

        //same value results in zero, diff values results in 1
	// The result is 00001100
	printf("a^b = %d\n", a ^ b);//a^b = 12

        // equivalent to !(turns the value from true to false and vice versa)
        // but ~ switches the bit.
	// The result is 11111010
	printf("~a = %d\n", a = ~a);// ~a = 250

	// The result is 00010010
	printf("b<<1 = %d\n", b << 1);//b<<1 = 18
        //equivalent to multipled by 2 ie 9*2 = 18


	// The result is 00000100
	printf("b>>1 = %d\n", b >> 1);//b>>1 = 4
        //equivalent to devided by 2 ie 9/2 = 4 (leave the reminder as done in normal division in programming)

        //dont carry the value from one end to another. Just replace it with Zeros
        //it is always zeros. only when the movement is done with ngative values
        // or with a value more than the size of int, the result value is undefined.

	return 0;
}

