#include <stdio.h>
#include <stdlib.h>

/* these are in no header file, and on some
systems they have a _ prepended
These symbols have to be typed to keep the compiler happy
Also check out brk() and sbrk() for information
about heap */

extern char  etext, edata, end;

int
main(int argc, char **argv)
{
    printf("First address beyond:\n");
    printf("    program text segment(etext)      %10p\n", &etext);
    printf("    initialized data segment(edata)  %10p\n", &edata);
    printf("    uninitialized data segment (end) %10p\n", &end);

    return EXIT_SUCCESS;
}
