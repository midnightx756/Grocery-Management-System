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
