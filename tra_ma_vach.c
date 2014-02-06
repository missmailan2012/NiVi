#include<stdio.h>
#include<stdlib.h>

char stream[4096];
char *input=&stream[16];
int temp;

char echo1[8]="grep '";
char echo2[14]="' data.dict";

char* strcpy(char* str1, char* str2)
{
  int i;
  for(i=0;str2[i]!=0;i++)
    {
      str1[i]=str2[i];
    }
  str1[i]=str2[i];
  return str1;
}

char* strcat(char* str1, char* str2)
{
  int x=-1;
  while(str1[++x]!=0);
  int y;
  for(y=0;str2[y]!=0;y++)
    {
      str1[x]=str2[y];
      x++;
    }
  str1[x]=str2[y];
  return str1;
}

int strcmp(char *str1, char *str2)
{
  int temp;
  temp=0;
  for(; str1[temp] !=0 && str2[temp] !=0;temp++)
    {
      if(str1[temp]< str2[temp])
	return -1;
      if(str1[temp] >str2[temp])
	return 1;
    }
  if(str1[temp]< str2[temp])
    return -1;
  if(str1[temp] >str2[temp])
    return 1;
  if(str1[temp]==str2[temp])
    return 0;
}

int main()
{
  strcpy(&stream[10],echo1);
  system("clear");
  printf("\t\t");
  fflush(stdin);
  gets(input);
  printf("\n\n");
  while(strcmp(input,"exit"))
    {
      while(!strcmp(input,""))
	{
	  fflush(stdin);
	  gets(input);
	}
      for(temp=16;stream[temp] != 0;temp++);
      strcat(&stream[temp],echo2);
      system(&stream[10]);
      printf("\n\n");
      printf("\t\t");
      fflush(stdin);
      gets(input);
      system("clear");
    }
  return 0;
}

