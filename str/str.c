#include <string.h>
#include<stdio.h>
int main() {
           char str[] = "I need coffee";
           //char ptr = "hari"; //char arry cant be used as a char
           char *ptr = "hari";
   char dest[255];
   char dst[255];
   strcpy(dst,str);
   printf ("%s\n", dst);//I need coffee
   int num =strstr(str,"coffe") - str ;
   strncpy(dest,str,num);
   printf ("%s\n", dest);//I need
   printf ("%s\n", ptr);//hari
   ptr = "Gowtham";
   printf ("%s\n", ptr);//Gowtham  // works for reassignment
   //ptr+1 = "dude";errors out during compile
   printf ("%s\n", ptr+1);//owtham
   printf ("%s\n", &ptr+1);//�@
   printf ("%d\n", &ptr);//362290512
   printf ("%d\n", &ptr+1);//362290520
   printf ("%d\n", &ptr+2);//362290528
   printf ("%u\n", &ptr);//362290512
   printf ("%u\n", &ptr+1);//362290520
   printf ("%u\n", &ptr+2);//362290528V
   printf ("%u\n", *ptr);//71
   printf ("%u\n", *ptr+1);//72
   printf ("%u\n", (*ptr)+1);//72
   printf ("%s\n", *ptr);//seg fault
   printf ("%s\n", *ptr+1);
        return 0;
}

/*sizeof(char *) is the size of the pointer, so normally 4 for 32-bit machine, and 8 for 64-bit machine. One more thing, you should use %zu for size_t type in printf format. 8 is the size of a pointer, an address.
 */

/*
 * In the above line “GfG” is stored in a read only location, but pointer str is stored in a read-write memory. You can change str to point something else but cannot change value at present str. So this kind of string should only be used when we don’t want to modify string at a later stage in program.
 * */
