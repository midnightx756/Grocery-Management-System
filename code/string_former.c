#include <stdio.h>

void sTU(char a[]){
      int i=0;
      for(i=0;a[i];i++){
             if(a[i] == ' '){
                  a[i] = '_';
             }
      }
}

void uTS(char a[]){
      int i=0;
      for(i=0;a[i];i++){
            if(a[i] == '_'){
                  a[i] = ' ';
            }
      }
}
/*
void main(){
     char str[100] =  "Hello Dragon Knight";
     printf("Orignal string: %s\n", str);
     sTU(str);
      printf("Replaced spaces with underscore: %s\n", str);
      uTS(str);
         printf("Replaced spaces with underscore: %s\n", str);
}*/
