#include <stdio.h>
#include <stdlib.h>
#include "utility.c"

typedef struct{
    char names[10][100];
    int qnty[10][3];
    float price[10][2];
    float profl[10][2];
    float *inv_val;
}Items;

Items im;

void alloc(){
  im.inv_val=(float*)calloc(10, sizeof(float));
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
   }
}

void buy(){
    displaychars(im.names);
    purchase(im.qnty, im.price);
}

void seller(){
    displaychars(im.names);
  sell(im.qnty, im.price);
}

void display(){
    calculate(im.qnty, im.price, im.profl, im.inv_val);
    stock(im.names,im.qnty, im.price, im.profl, im.inv_val);
}

