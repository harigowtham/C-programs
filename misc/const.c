#include<stdio.h>
int main()
{
	const int var = 10;
	var = 15;
	printf("var = %d\n", var);
	return 0;
}

/*
 * prog.c: In function 'main':
prog.c:5:9: error: assignment of read-only variable 'var'

=====================================================================================

//Write C code here
#include<stdio.h>
#include<stdlib.h>
int main()
{
	const int var = 10;

	int *ptr = &var;
	*ptr = 12;

	printf("var = %d\n", var);

	return 0;
}

when done with ptr, it works with a warning:

prog.c: In function 'main':
prog.c:6:16: warning: initialization discards 'const' qualifier
from pointer target type [-Wdiscarded-qualifiers]
     int *ptr = &var;
var = 12


==========================================================================================


We can change pointer to point to any other integer variable, but cannot change value of object (entity) pointed using pointer ptr. Pointer is stored in read-write area (stack in present case). Object pointed may be in read only or read write area. Let us see following examples.

#include <stdio.h>
int main(void)
{
	int i = 10;
	int j = 20;
	const int *ptr = &i; // ptr is pointer to constant

	printf("ptr: %d\n", *ptr);
	*ptr = 100;	 // error: object pointed cannot be modified
			using the pointer ptr

	ptr = &j;	// valid
	printf("ptr: %d\n", *ptr);

	return 0;
}
error: assignment of read-only location ‘*ptr’



up qualification: where a int * becomes a const int * :
ptr was a const int* when it was assigned to &j which was a normal variable, it was up qualified.

#include <stdio.h>

int main(void)
{
	int const i = 10; // i is stored in read only area
	int j = 20;

	int const *ptr = &i;	 // pointer to integer constant. Here i
				is of type "const int", and &i is of
				type "const int *". And p is of ype
				"const int", types are matching no issue

	printf("ptr: %d\n", *ptr);

	*ptr = 100;	  error

	ptr = &j;	 valid. We call it as up qualification. In
			C/C++, the type of "int *" is allowed to up
			qualify to the type "const int *". The type of
			&j is "int *" and is implicitly up qualified by
			the compiler to "cons tint *"

	printf("ptr: %d\n", *ptr);

	return 0;
}
 error: assignment of read-only location ‘*ptr’


 above has a lot of problems refer the link below for correct values:

 https://www.geeksforgeeks.org/const-qualifier-in-c/

*/
