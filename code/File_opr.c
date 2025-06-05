#include <stdlib.h>
#include <stdio.h>
//#include "string_former.c"
//#include "strs.c"

void clean()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // _WIN32
}

void store_items(char a[10][100],int b [10][3]){
   FILE * fp=fopen("Itemlist.txt","w");
   if(fp == NULL){
     printf("The file cpuld not be created");
     exit(0);
   }
   
   int i;
   for(i=0;i<10;i++){
     fprintf(fp,"%s: %d\n",a[i],b[i][0]);
   }
   fclose(fp);
}

void save(char n[10][100], int q[10][3], float p[10][2], float pe[10][2], float in[10], unsigned int d, unsigned int m, unsigned int y){
   FILE* saver = fopen("table.txt","a+"), *saveind = fopen("ind.txt","w");
   int i=0,eof=0;
   if(saver == NULL|| saveind == NULL){
     printf("Sorry but the file could not be allocated");
     exit(0);
   }
   fseek(saver,0,SEEK_END);
   fprintf(saveind,"EOF: %ld",ftell(saver));
   fclose(saveind);
   fprintf(saver,"%d/%d/%d\n",d,m,y);
   for(i=0;i<10;i++){
    sTU(n[i]);
    fprintf(saver,"%s %d %d %d %f %f %f %f %f\n",n[i],q[i][0],q[i][1],q[i][2],p[i][0],p[i][1],pe[i][0],pe[i][1],in[i]);
       }
   fputc('\n',saver);
   fclose(saver);
}

void readbackup(char a[10][100], int b[10][3]){
   FILE* destro=fopen("Itemlist.txt","r"), *dual=fopen("table.txt","r");
   int i=0;
   if(destro == NULL){
      printf("Files were not retrieved successfully");
      exit(0);
   }
   if(dual == NULL){
      while(fscanf(destro,"%99[^:]: %d",a[i],&b[i][0])==2){
          i++;
       }
    }
    else{
        while(fscanf(destro,"%99[^:]: %*d",a[i])==1){
          i++;
        } 
    }
  if(i<10)
    printf("Items could not be retrieved");
  fclose(destro);
}

void appender(int b[10][3], float c[10][2], unsigned int d, unsigned int m, unsigned int y){
   FILE* fp = fopen("table.txt", "a+"), *read = fopen("ind.txt","r");
   int i=0,eof;
   char temp[200];
   unsigned int da,mo,ye;
   if(fp==NULL || read==NULL){
      printf("File could not not be opened");
      exit(0);
   }
   fscanf(read,"%*[^:]: %d",&eof);
   fseek(fp,eof,SEEK_SET);
   fscanf(fp,"%d/%d/%d",&da, &mo, &ye);
   if(eof>0){
      fseek(fp,-1,SEEK_CUR);
   }
   while(fscanf(fp,"%[^ ] %d %d %d %f %f %*f %*f %*f",temp,  &b[i][0], &b[i][1], &b[i][2], &c[i][0], &c[i][1])==6){
       b[i][0]+=b[i][1]-b[i][2];
       b[i][1]=0;
       b[i][2]=0;
       i++;
   }
   fclose(fp);
}

/*
void main(){
     char a[10][100]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
       int  qn [10][3]={100, 0, 0};
       float pr[10][2], prol[10][2], iv[10];
       unsigned d1,d2, d3;
       readbackup(a, qn);
       appender(qn, pr, d1, d2, d3);
       corrector(a);
       for(int i=0;i<10;i++)
           printf("%s %d %d %d %f %f \n", a[i],qn[i][0],qn[i][1],qn[i][2],pr[i][0],pr[i][1]);
      for(int i=0;i<100;i++)
         printf("\n");
}
*/
