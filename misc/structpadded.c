// C program to avoid structure
// padding using pragma pack
#include <stdio.h>

// To force compiler to use 1 byte packaging
#pragma pack(1)
struct s {
	int i;
	char ch;
	double d;
};

int main()
{
	struct s A;
	printf("Size of A is: %ld", sizeof(A));
        // as pragma pack is used the value is 13 not 16 as with padding
}

/* another approach with which we can have 13 as the size
 * // C program to avoid structure
// padding using attribute
#include <stdio.h>

struct s {
	int i;
	char ch;
	double d;
} __attribute__((packed));
// Attribute informing compiler to pack all members

int main()
{
	struct s A;
	printf("Size of A is: %ld", sizeof(A));
}
*/
