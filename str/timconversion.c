#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* timeConversion(char* s) {
    int len = strlen(s);
    int i = 0;
    //char *res = (char *)malloc((len*sizeof(char))-3);
    char res[len];
    if (*(s+len-2) == 'A'){
        if ((*(s) == '1') && (*(s+1) == '2')) {
            *(res) = '0';
            *(res +1) = '0';
            i = 2;
        }
    }
    if (*(s + len -2) == 'P') {
    printf("inside\n");
        if(*(s+1) == '1')
            *(res) = '1';
            *(res+1) ='3';
        if(*(s+1) == '2')
            *(res) = '1';
            *(res+1) ='4';
        if(*(s+1) == '3')
            *(res) = '1';
            *(res+1) ='5';
        if(*(s+1) == '4')
            *(res) = '1';
            *(res+1) ='6';
        if(*(s+1) == '5')
            *(res) = '1';
            *(res+1) ='7';
        if(*(s+1) == '6')
            *(res) = '1';
            *(res+1) ='8';
        if(*(s+1) == '7')
            *(res) = '1';
            *(res+1) ='9';
        if((*(s+1) == '8') && (*(s+1) == '1')) {
            *(res+1) ='0';
            *(res) = '2';
        }
        if((*(s+1) == '9') && (*(s+1) == '1')) {
            *(res+1) ='1';
            *(res) = '2';
        }
        if((*(s+1) == '0') && (*(s+1) == '1')) {
            *(res+1) ='2';
            *(res) = '2';
        }
        if((*(s+1) == '1') && (*(s+1) == '1')) {
            *(res+1) ='3';
            *(res) = '2';
        }
        if((*(s+1) == '2') && (*(s+1) == '1')) {
            *(res+1) ='4';
            *(res) = '2';
        }
        i = 2;
    }
    for (i; i < len-2; i++) {
        *(res + i) = *(s + i);

    }
    *(res + len-1) = '\O';
    printf("%s", res);
    return res;

}

void print(char *s) {
  while(*s != '\0')
    printf("%c", s);
}

int main() {

  //char *s = (char *)malloc((9*sizeof(char)));
  char *s = "07:05:45PM";
  printf("%s", s);
  char *res;
  res = timeConversion(s);
  printf("%s", res);
  //print(res);
  return 1;
}
