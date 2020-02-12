#include <stdio.h>

// Alignment requirements
// (typical 32 bit machine)

// char     1 byte
// short int  2 bytes
// int     4 bytes
// double    8 bytes

// structure A
typedef struct structa_tag
{
char    c;
short int  s;
} structa_t;

// structure B
typedef struct structb_tag
{
short int  s;
char    c;
int     i;
} structb_t;

// structure C
typedef struct structc_tag
{
char    c;
double   d;
int 	 s;
} structc_t;

// structure D
typedef struct structd_tag
{
double   d;
int 	 s;
char    c;
} structd_t;

int main()
{
printf("sizeof(structa_t) = %d\n", sizeof(structa_t)); // expected 3  actual: 4
printf("sizeof(structb_t) = %d\n", sizeof(structb_t)); // e: 7   a:8
printf("sizeof(structc_t) = %d\n", sizeof(structc_t)); // e: 13  should be 20 after paading but it is a:24
printf("sizeof(structd_t) = %d\n", sizeof(structd_t)); // e: 13  should be 13 but is a:16 as in an array of struct d we them to remain aligned
// everything is read as 4 bytes

return 0;
}

