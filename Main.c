#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int Buff_int[1024];
  char Buff_char[1024];
}buff;

typedef struct{
  int* config_int;
  char* config_char;
}config;

typedef struct{
  int* header_int;
  char* header_char;
}header;

typedef struct{
  buff Buff;
  config Config;
  header Header;
}sql_data;

char kiemduyet(int *tro1, int *tro2)
{
  char i;
  for(i=0;i<7;i++)
    {
      if(tro1[i]!=tro2[i])
	return -1;
    }
  return 1;
}

void load(sql_sys Sql, FILE* main)
{
  input[1023]=0; // Biến count_next;
  input[1022]=0; // Biến break 9;
  input[1021]=0; // Biến back_next;
  input[1020]=0; //  Biến getchar và kí tự NULL;
  input[1006]=101;
  input[1007]=110;
  input[1008]=100;
  input[1009]=109;
  input[1010]=97;
  input[1011]=105;
  input[1012]=110;
  /*
  while(input[1022] < 10)
    {
      input[1020]=fgetc(main);
      input[1022]++;
      }*/
  while(1)
    {
      input[1020]=fgetc(main);
      input[input[1023]]=input[1020];
      for(input[1021]=1013;input[1021] < 1020;input[1021]++)
	{
	  input[input[1021]]=input[input[1021]+1];
	}
      input[1020]=0;
      if(kiemduyet(&input[1006],&input[1013])==1)
	{
	  input[1023]++;
	  input[input[1023]]=0;
	  break;
	}
      input[1023]++;
    }
  input[1023]=0;
  while(input[input[1023]+8]!=0)
    {
      input2[input[1023]]=input[input[1023]];
      input[1023]++;
    }
  input2[input[1023]]=0;
}

int main()
{
  FILE* main;
  FILE* temp_main;
  main=fopen("main.cfg","r");
  if(main == NULL)
    {
      printf("Có lỗi đã xuất hiện trong việc mở file \"main.cfg\"\n");
      exit(0);
    }
  temp_main=fopen("main.temp","w");
  if(temp_main ==NULL)
    {
      printf("Có lỗi trong việc tạo ra \"main.temp\"\n");
      exit(0);
    }
  load(input,input2,main);
  system("clear");
  puts(input2);
  printf("\n\n");
  gets(input2);
  return 0;
}
