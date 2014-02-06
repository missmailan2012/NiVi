#include<stdio.h>
#include<stdlib.h>

char* congso(char* a, char* b)
{
  char giaima(char* input)
  {
    switch(*input)
      {
      case 48: return 0;
      case 49: return 1;
      case 50: return 2;
      case 51: return 3;
      case 52: return 4;
      case 53: return 5;
      case 54: return 6;
      case 55: return 7;
      case 56: return 8;
      case 57: return 9;
      }
  }
  char mahoa(char* input)
  {
    switch(*input)
      {
      case 0: return 48;
      case 1: return 49;
      case 2: return 50;
      case 3: return 51;
      case 4: return 52;
      case 5: return 53;
      case 6: return 54;
      case 7: return 55;
      case 8: return 56;
      case 9: return 57;
      }
  }
  char temp,x,y;
  char tong_temp, luuso;
  x=y=tong_temp=luuso=0;
  for(temp=8;temp >=0;temp--)
    {
      x=giaima(&a[temp]);
      y=giaima(&b[temp]);
      tong_temp=x+y+luuso;
      luuso=0;
      if(tong_temp>=10)
	{
	  luuso++;
	  tong_temp-=10;
	}
      a[temp]=mahoa(&tong_temp);
    }
  if(luuso ==1)
    {
      printf("Bị tràn số.\n\n");
    }
}


char xau1[90];
char xau2[90];
char i;
int main()
{
  FILE* input;
  FILE* input2;
  input=fopen("my.txt","r");
  if(input ==NULL)
    {
      printf("Co loi trong qua trinh mo file.\n");
      exit(0);
    }
  input2=fopen("my2.txt","r");
  if(input2 ==NULL)
    {
      printf("Co loi trong qua trinh mo file.\n");
      exit(0);
    }
  fgets(xau1,90,input);
  fgets(xau2,90,input2);
  for(i=0;xau1[i]!=0;i++)
    {
      printf("%d||",xau1[i]);
    }
  printf("\n");
  xau1[--i]=0;
  printf("%d\n",i);
  printf("%s",xau1);
  printf("\n");
  for(i=0;xau2[i]!=0;i++)
    {
      printf("%d||",xau2[i]);
    }
  printf("\n");
  xau2[--i]=0;
  printf("%s\n",xau2);
  congso(xau1,xau2);
  printf("%s",xau1);
  return 0;
}

