#include<stdio.h>
#include<stdlib.h>

char echo1[6]="echo";
char echo2[15]=" >> data.dict";
char echo3[15]=" >> data2.dict";
char kanji[4096];
char hiragana[4096];
char katakana[4096];
char stream[4096];
char *output=&stream[4];
int temp;
int tempi;

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


int main()
{
  strcpy(stream,echo1);
  // Nhập vào thông tin 漢字 và ひらがな và カタカナ
  printf("Bạn hãy nhập vào dạng 漢字 của từ:");
  fflush(stdin);
  gets(kanji);
  printf("Bạn hãy nhập vào dạng ひらがな của từ:");
  fflush(stdin);
  gets(hiragana);
  printf("Bạn hãy nhập vào dạng カタカナ của từ:");
  fflush(stdin);
  gets(katakana);
  // Đọc thông tin về số lượng từ có trong từ điển.
  FILE* fi;
  fi=fopen("finput.dict","r");
  if(fi ==NULL)
    {
      printf("Đã sảy ra lỗi khi mở tập tin finput.dict.\n");
      exit(0);
    }
  fgets(output,15,fi);
  // Cộng thêm số từ.
  fclose(fi);
  char socong[10];
  for(temp=0; temp<=7;temp++)
    {
      socong[temp]=48;
    }
  socong[temp]=49;
  output[++temp]=0;
  congso(output,socong);
  // Cập nhập lại thông số về số lượng từ mới có trong data.
  output[temp]=0;
  fi=fopen("finput.dict","w");
  if(fi ==NULL)
    {
      printf("Đã sảy ra lỗi khi mở tập tin finput.dict.\n");
      exit(0);
    }
  fputs(output,fi);
  fclose(fi);
  // Nối các chuỗi 漢字, ひらがな và カタカナ
  output[temp]='\t';
  output[++temp]='\t';
  strcat(&output[++temp],kanji);
  for(;output[temp]!=0;temp++);
  output[temp]='\t';
  output[++temp]='\t';
  strcat(&output[++temp],hiragana);
  for(;output[temp]!=0;temp++);
  output[temp]='\t';
  output[++temp]='\t';
  strcat(&output[++temp],katakana);
  // Ghi thông tin của từ mới vào cơ sở dữ liệu.
  for(temp=0;output[temp]!=0;temp++);
  strcpy(&output[temp],echo2);
  for(temp=5;stream[temp] == 48;temp++)
    {
      if(stream[temp]!=48)
	break;
    }
  temp-=5;
  strcpy(&stream[temp],echo1);
  temp+=4;
  stream[temp]=32;
  temp-=4;
  system(&stream[temp]);
  // Nhập vào nghĩa của từ.
  puts(output);
  puts(&stream[temp]);
  temp-=1;
  output=&stream[temp];
  puts(output);
  for(tempi=0;tempi<=4;tempi++)
    {
      output[tempi]=output[tempi+1];
    }
  output[tempi]='B';
  puts(output);
  for(tempi=0;output[tempi]!='\t';tempi++);
  output[tempi]='\n';
  output[++tempi]='B';
  output[++tempi]=48;
  temp=tempi;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]=48;
  output[++tempi]='\n';
  puts(output);
  printf("1\t\tĐộng từ nhóm I.\n\n");
  printf("2\t\tĐộng từ nhóm II.\n\n");
  printf("3\t\tĐộng từ nhóm III.\n\n");
  printf("4\t\tTính từ い.\n\n");
  printf("5\t\tTính từ な.\n\n");
  fflush(stdin);
  scanf("%d",&tempi);
  switch(tempi)
    {
    case 1:output[temp]=49; break;
    case 2:output[temp+1]=50; break;
    case 3:output[temp+2]=51; break;
    case 4:output[temp+3]=105; break;
    case 5:output[temp+4]=110; break;
    }
  puts(output);
  temp+=10;
  printf("Bắt đầu nhập nghĩa cho nó:\n");
  for(;1;)
    {
      gets(&output[temp]);
      for(;output[temp]!=0;temp++);
      if( output[temp-1]=='e' && output[temp-2]=='n' && output[temp-3]=='o' && output[temp-4]=='d')
	{
	  //output[temp-5]=0;
	  break;
	}
      output[temp]='\n';
      temp++;
    }
  strcpy(&output[temp-5],echo3);
  system(output);
  return 0;
}
