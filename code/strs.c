#include <stdio.h>
#include <stdlib.h>

char* encode(char a[])//Uses simple ceaser cipher to encode password
{
    char* b=(char*)malloc(100*sizeof(char));
    int i;
    for(i=0;a[i];i++)
    {
        if(a[i]>='A' && a[i]<='Z')
          b[i]=((a[i]-'A')+1)%26 + 'a';
        else if(a[i]>='a' && a[i]<='z')
          b[i]=((a[i]-'a')+1)%26 + 'A';
        else if(a[i]==' ')
          b[i]='?';
        else if(a[i]>='0' && a[i]<='9')
          b[i]=((a[i]-'0')+1)%10+'0'; 
        else 
         b[i]=a[i];
    }
    b[i]='\0';
    return b;
}

char* decode(char *a){
    char*b = (char*)calloc(100,sizeof(char));
    int i;
    for(i=0;i<a[i];i++)
    {
       if(a[i]>='A' && a[i]<='Z')
          b[i]=((a[i]-'A')-1+26)%26 + 'a';
        else if(a[i]>='a' && a[i]<='z')
          b[i]=((a[i]-'a')-1+26)%26 + 'A';
        else if(a[i]=='?')
          b[i]=' ';
        else if(a[i]>='0' && a[i]<='9')
          b[i]=((a[i]-'0')-1+10)%10+'0';
        else 
          b[i]=a[i];
    }
    b[i]='\0';
    return b;
}

int equal(char* a, char* b){
  int i=0;
  for(i=0;*(a+i) && *(b+i);i++){
    if(*(a+i)!=*(b+i))
       return 0;
  }
  return 1;
}

int lenpass(char a[]){
  int i=0;
  for(i=0;a[i];i++){}
  if(i>=8 && i<=16)
     return 1;
  return 0;
}

int charcheck(char a[]){
  int c1=0,c2=0,c3=0,i=0;
  for(i=0;a[i];i++){
    if(a[i]>='a' && a[i]<='z')
       continue;
    else if(a[i]>='A' && a[i]<='Z')
      c1++;
    else if(a[i]>='0' && a[i]<='9')
      c2++;
    else
      c3++;
  }
  if(c1 && c2 && c3)
    return 1;
  else
    return 0;
}