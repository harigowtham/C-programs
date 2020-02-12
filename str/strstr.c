#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "quota-v1-v2-v3";
   const char ch = '-';
   char volname[] = "v3";
   char *ret;
   char *tempret;
   char associated [256];
   int num;
   char dest[256];
   char tempdest[256];

   //ret = strchr(str, ch);

   strcat(associated,"quota-");

   while (strchr (str,'\0') && str != NULL) {
           ret = strchr(str, ch);
           if (ret == NULL) {
                   break;
           }

           ret = ret+1;
           tempret = strchr(ret, ch);
           if (tempret == NULL){
                   if (strcmp(ret,volname)) {
                           strcat (associated, ret);
                   }
                   break;
           }

           tempret = tempret + 1;
           num = strstr(ret,tempret) - ret;
           strncpy(dest,ret,num);
           dest[num-1] = '\0';
           if (!strcmp(dest,volname)) {
           } else {
                   strcat (associated, dest);
                   strcat (associated, "-");
           }
           printf("Str:%s, ret: %s\n", str, ret);
           strcpy(str,ret);
   }
           printf("\tdest:%s\t size:%d",dest, sizeof(dest));
           printf("\tass:%s\n",associated);

   return(0);
}
