#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "quota-v1-v2";
   const char ch = '-';
   char volname[] = "v1";
   char *ret;
   char *tempret;
   char associated [256];
   int flag = 0;

   //ret = strchr(str, ch);

   strcat(associated,"quota");

   while (strchr (str,'\0') && str != NULL) {
           ret = strchr(str, ch);
           ret = ret+1;
           tempret = strchr(ret, ch);
           if (tempret == NULL)
                   break;

           tempret = tempret + 1;
           if (!strcmp(tempret,volname)) {
                   strcat(associated,ret);
                   break;
           } else {
                   strcat (associated, tempret);
           }
           printf("Str:%s, ret: %s\n", str, ret);
           strcpy(str,ret);
   }
           printf("ass:%s",associated);

   return(0);
}
