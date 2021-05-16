#include <stdio.h>
#define mkstr(s) #s
#define concat(a, b) a##b//gets x and y and creates xy. xy's value 30 is printed
int main(void)
{
	printf(mkstr(hari));
  int xy=30;
  printf("%d", concat(x, y));//adds the arguments on both the sides of ## into and creates one.
	return 0;
}

