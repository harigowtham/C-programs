#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="quotad-v1-v2";
  char * pch;
  char ass[50]="";
  char volname[] = "v1";
  printf ("string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    if (strcmp(pch,volname)) {
            strcat(ass,pch);
            strcat(ass,"-");
    }
    pch = strtok (NULL, " ,.-");
  }
    printf ("%s\n",ass);
  return 0;
}
