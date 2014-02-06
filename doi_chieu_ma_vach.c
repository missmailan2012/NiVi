#include<stdio.h>
#include<stdlib.h>

FILE* stream;
char input[4096];
char key=0;
char code[20];
char dti[]="+) Động từ nhóm 1.";
char dtii[]="+) Động từ nhóm 2.";
char dtiii[]="+) Động từ nhóm 3.";
char tti[]="+) Tính từ い.";
char ttn[]="+) Tính từ な.";
char dt[]="+) Danh từ.";
char cn[]="+) Câu nói trong các tình huống.";
int temp;

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


void show()
{
  input[0]=0;
  fgets(code,20,stream);
  if(code[1]==49)
    {
      strcpy(input,dti);
      for(temp=1;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }
  if(code[2]==50)
    {
      strcat(input,dtii);
      for(temp=0;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }

  if(code[3]==51)
    {
      strcat(input,dtiii);
      for(temp=0;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }
  if(code[4]==105)
    {
      strcat(input,tti);
      for(temp=0;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }
  if(code[5]==110)
    {
      strcat(input,ttn);
      for(temp=0;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }

  if(code[6]==100)
    {
      strcat(input,dt);
      for(temp=0;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }

  if(code[7]==99)
    {
      strcat(input,cn);
      for(temp=0;input[temp]!=0;temp++);
      input[temp]='\n';
      input[++temp]=0;
    }
  for(temp=0;input[temp]!=0;temp++);
  for(;;)
    {
      if(feof(stream))
	{
	  break;
	}
      fgets(&input[temp],4096,stream);
      if(input[temp]=='B')
	{
	  input[temp-1]=0;
	  break;
	}
      for(;input[temp]!=0;temp++);
    }
  fseek(stream,0,SEEK_SET);
  puts(input);
}

/*

void Gets(char* code)
{
  gets(input);
  input[20]=0;
  for(;input[input[20]]!=0;input[20]);
  code[9]=0;
  temp=8;
  for(;input[20]>=0;input[20]--)
    {
      code[temp]=input[input[20]];
      temp--;
    }
  while(temp>=0)
    {
      code[temp]='0';
    }
}
*/

int main()
{
  stream=fopen("data2.dict","r");
  system("clear");
  printf("\t\t");
  fflush(stdin);
  gets(code);
  while(strcmp(code,"exit"))
    {
      for(;;)
	{
	  if(feof(stream))
	    {
	      fseek(stream,0,SEEK_SET);
	      printf("Không tìm thấy mã vạch này trong cơ sở dữ liệu.\n");
	      key=0;
	      break;
	    }
	  fgets(input,4096,stream);
	  if(input[0]=='B')
	    {
	      for(temp=0;input[temp]!=0;temp++);
	      temp-=1;
	      input[temp]=0;
	      if(!strcmp(&input[1],code))
		{
		  key=1;
		  break;
		}
	    }
	}
      if(key==1)
	{
	    show();
	}
      printf("\t\t");
      fflush(stdin);
      gets(code);
      while(!strcmp(code,""))
	{
	  printf("\n");
	  system("clear");
	  printf("\t\t");
	  fflush(stdin);
	  gets(code);
	}
	system("clear");
    }
  system("clear");
  return 0;
}
