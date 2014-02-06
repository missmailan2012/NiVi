#include<stdio.h>
#include<stdlib.h>

typedef struct{
  void *vector;
  void *data;
}command;

//=========================================================================================
int strlen(char* string)
{
  int leng;
  int temp;
  leng=0;
  temp=0;
  while(string[temp]!=0)
    {
      leng++;
      temp++;
    }
  return leng;
}

char* strcpy(char* dich, char* nguon)
{
  int i;
  for(i=0;i<=strlen(nguon);i++)
    {
      dich[i]=nguon[i];
    }
  dich[i]=0;
  return dich;
}

char* strcat(char* dich, char* nguon)
{
  int i;
  int temp;
  temp=strlen(dich);
  for(i=0;i<=strlen(nguon);i++)
    {
      dich[temp+i]=nguon[i];
    }
  dich[temp+i]=0;
  return dich;
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

command phantichinput(char *input)
{
  command cmd;
  if(strcmp(input,"1") ==0)

}
void thucthi(command cmd)
{
}
