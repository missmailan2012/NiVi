#include<stdio.h>
#include<stdlib.h>


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




int main()
{
  char kitu[2]; kitu[1]=0;
  char *xau, *xautemp;
  xau=(char*)malloc(sizeof(char));
  xau[0]=0;
  char i;
  do
    {
      kitu[0]=getchar();
      if(kitu[0] == '\n')
	{
	  break;
	}
      if(xau[0] == 0)
	{
	  xau=(char*)calloc(2,sizeof(char));
	  xau[0]=kitu[0];
	  xau[1]=0;
	  continue;
	}
      if(xau[0] != 0)
	{
	  xautemp=(char*)calloc(strlen(xau)+1, sizeof(char));
	  xautemp[strlen(xau)]=0;
	  strcpy(xautemp,xau);
	  strcat(xautemp,kitu);
	  free(xau);
	  xau=xautemp;
	}
    }while(kitu[0] != '\n');
  puts(xau);
  return 0;
}
