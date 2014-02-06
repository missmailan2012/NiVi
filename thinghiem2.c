#include<stdio.h>
#include<stdlib.h>

char strcmp(char* string1, char* string2)
{
  int i;
  i=0;
  while(string1[i]!=0 && string2[i] != 0)
    {
      if(string1[i] > string2[i])
	return 1;
      if(string1[i] < string2[i])
	return -1;
      i++;
    }
  if(string1[i] == 0 && string2[i] !=0)
    return -1;
  if(string1[i] ==0 && string2[i] == 0)
    return 0;
  if(string1[i] != 0 && string2[i] == 0)
    return 1;
}


char strcmp(char* string1, char* string2)
{
  int i;
  i=0;
  while(string1[i]!=0 && string2[i] != 0)
    {
      if(string1[i] > string2[i])
	return 1;
      if(string1[i] < string2[i])
	return -1;
      i++;
    }
  if(string1[i] == 0 && string2[i] !=0)
    return -1;
  if(string1[i] ==0 && string2[i] == 0)
    return 0;
  if(string1[i] != 0 && string2[i] == 0)
    return 1;
}
char xau[50];
int main()
{
  printf("ban hay nhap vao mot chuoi: \n");
  gets(xau);
  printf("%d\n", strcmp(xau,"thu"));
  return 0;
}
