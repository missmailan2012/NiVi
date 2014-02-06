#include<stdio.h>

int main()
{
  char xau[80];
  gets(xau);
  for(xau[79]=0;xau[79]<=20;xau[79]++)
    printf("%d||",xau[xau[79]]);
  return 0;
}
