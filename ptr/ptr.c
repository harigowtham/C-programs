// C program to demonstrate declaration of
// pointer variables.
#include <stdio.h>
int main()
{
	int x = 10;

	// 1) Since there is * in declaration, ptr
	// becomes a pointer varaible (a variable
	// that stores address of another variable)
	// 2) Since there is int before *, ptr is
	// pointer to an integer type variable
	int *ptr;

	// & operator before x is used to get address
	// of x. The address of x is assigned to ptr.
	ptr = &x;
        int *p = ptr;
        // here for *p we need to provide the address of the variable we ned it to store.
        // later when we say *p its going to point to the value of the variable.
        printf("Value of x = %d\n", *ptr);
        printf("Address of x = %p\n", &x);
        printf("Address of x/value of ptr = %p\n", ptr);
        printf("Value of p = %d\n", p); // we print address of x in decimal
        printf("Value of p in hexa = %p\n", p); // address of x
        printf("Value of *p = %d\n", *p); //note *p is not ptr. that is the way we have to initialise it. (yes its messed up)
        printf("Address of p = %p\n", &p); //the variable p will have its own address created during initialisation
//	ptr = &(100); // compile time error
//      printf("Value of Var = %d\n", **ptr); //compile errornvalid type argument of unary ‘*’ (have ‘int’)

        printf("Address of ptr = %p\n", &ptr);
        //printf("Address of &x = %p\n", &x);

        //NULL and 0x0 are the same. verify this statement.
        //so head will have 0x0 or NULL as value.
        //*head will deref a NULL to seg fault.
        int *head = NULL;

        int *tmp = head;
        //the value in tmp is head or nil or NULL.
        //I think nil, 0x0 and null are same. verify this statement.
        //this is why in the insert of a linkedlist we check for tmp == null instead of checking for *tmp == null. if we check for *tmp == NULL it will crash just like below. thats dereferencing null.
        printf("the value of tmp%p\n", tmp);
        //the addr is a random value where tmp is located.
        printf("the addr of tmp%p\n", &tmp);
        //the value of tmp is null. So the value of *tmp is deref a null segfault.
        //printf("the value of *tmp%d", *tmp);


        return 0;
}
/*
ptr.c: In function ‘main’:
ptr.c:20:8: error: lvalue required as unary ‘&’ operand
  ptr = &(100);
     */
