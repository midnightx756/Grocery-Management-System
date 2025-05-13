#include <stdio.h>
#include <stdlib.h>
#include "utility.c"
#include "File_opr.c"

typedef struct{
    char names[10][100];
    int qnty[10][3];
    float price[10][2];
    float profl[10][2];
    float *inv_val;
}Items;

typedef struct{
    unsigned int dd : 5;
    unsigned int mm : 4;
    unsigned int yy;
}date;

date d;
Items im;

void alloc(){
  im.inv_val=(float*)calloc(10, sizeof(float));
 int i=0,j=0;
 for(;i<10;i++){
      for(j=0;j<2;j++){
         im.price[i][j]=0.0;
         im.profl[i][j]=0.0;
      }
      im.inv_val[i]=0.0;
      for(j=0;j<3;j++){
         im.qnty[i][j]=0;
      }
 }
  if(im.inv_val==NULL){
     printf("Failed to allocate Memory");
     exit(0);
  }
   readbackup(im.names, im.qnty);
   appender(im.qnty, im.price, d.dd, d.mm, d.yy);
   corrector(im.names);
}

void dealloc()
{
    free(im.inv_val);
}

void store(){
    int i=0;
   for(i=0;i<10;i++){
    printf("Enter the item name: ");
    scanf(" %[^\n]s",im.names[i]);
    printf("Enter its The stock you currently have of that item: ");
    scanf("%d",&im.qnty[i][0]);
    store_items(im.names,im.qnty);
   }
}

void buy(){
    displaychars(im.names, im.qnty);
    purchase(im.names, im.qnty, im.price);
}

void seller(){
    displaychars(im.names, im.qnty);
  sell(im.names, im.qnty, im.price);
}

void display(){
    calculate(im.qnty, im.price, im.profl, im.inv_val);
    stock(im.names,im.qnty, im.price, im.profl, im.inv_val);
}

void dsave(){
   save(im.names, im.qnty, im.price, im.profl, im.inv_val, d.dd, d.mm, d.yy);
}

void dated(){
    char a[20];
    unsigned int da,m,y;
    printf("Enter the date in dd/mm/yyyy format: ");
    scanf(" %[^\n]s",a);
    if(sscanf(a,"%u/%u/%u",&da, &m, &y)!=3)
      { 
         printf("You inputted the wrong format, please re - enter the date\n");
         dated();
      }
    else{
       d.dd=da;
       d.mm=m;
       d.yy=y;
    }
}
