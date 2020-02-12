#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
	printf("Value of a is %d\n", a);
}

void func()
{
	printf("Value of a is\n ");
}

void function()
{
	printf("inside function\n ");
}

int main()
{
	// fun_ptr is a pointer to function fun()
	void (*fun_ptr)(int) = &fun;

	/* The above line is equivalent of following two
	void (*fun_ptr)(int);
	fun_ptr = &fun;
	*/

	// Invoking fun() using fun_ptr
	(*fun_ptr)(10); //Value of a is 10

	void (*func_ptr)() = &func;
	(*func_ptr)(10); //Value of a is
	(*func_ptr)(); //Value of a is

        void (*function_ptr)() = function;
        (function_ptr)(); // inside function
        (*function_ptr)(); // inside function

        //below this it doesnt work
        void (*fn_ptr)() = &func();
        (*fn_ptr)();
	return 0;
}

/* Note: void * fun_ptr (int) can confuse that for a function with int as arg,
 * we are expecting a return value of ptr void.
 * So to avoid this confusion, we have to use the fnction ptr name inside a bracket with */
