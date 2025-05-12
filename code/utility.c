#include <stdio.h>

void purchase(char n[10][100], int a[10][3], float b[10][2]){
    int i=0,q=0;
    float price;
    do{
        printf("Enter the item number, or enter 11 to exit: ");
        scanf("%d",&i);
        if(i<11){
             i=i-1;
            if(a[i][0]<20)
              printf("Warning: Stock is too low");
            printf("Enter the quantity of %s purchased: ",n[i]);
            scanf("%d",&q);
            a[i][1]+=q;
            printf("Enter the net cost: ");
            scanf("%f",&price);
            b[i][0]+=price;
        }
    }while(i<10);
}

void sell(char n[10][100], int a[10][3], float b[10][2]){
    int i=0,q=0;
    float price;
    do{
        printf("Enter the item number, or enter 11 to exit: ");
        scanf("%d",&i);
        if(i<11){
            i=i-1;
            printf("Enter the quantity of %s sold: ",n[i]);
            scanf("%d",&q);
            if(a[i][0]+a[i][1]>=q){
                 a[i][2]+=q;
                 printf("Enter the net selling price: ");
                 scanf("%f",&price);
                 b[i][1]+=price;
            }
            printf("The stock is less than what your input\n");
        }
    }while(i<10);
}

void calculate(int a[10][3], float b[10][2], float c[10][2], float d[10]){
    int i=0;
    for(;i<10;i++){
         c[i][0]=a[i][2]*b[i][1]-a[i][1]*b[i][0];
         c[i][1]=(c[i][0]/(a[i][1]*b[i][0]))*100;
         d[i]=(a[i][0]+a[i][1]-a[i][2])*b[i][1];
    }
}

void stock(char a[10][100], int b[10][3], float c[10][2], float d[10][2], float e[10]){
   int i=0;
    printf("Name Stock  Purchased Amount  Sold Amount  Net Cost  Net Retail price  Profit/loss  Profit/loss percentage Inventory Value\n");
   for(i=0;i<10;i++){
    printf("%s \t %d \t %d \t %d \t %f \t %f \t %f \t %f \t %f", a[i], b[i][0],b[i][1],b[i][2], c[i][0], c[i][1], d[i][0], d[i][1], e[i]);
    
   }printf("\n");
}

void displaychars(char a[10][100], int b[10][3]){
   int i;
   printf("All the items are listed with their respective indices\n");
   for(i=0;i<10;i++)
      printf("ID: %d Name: %s Stock: %d\n",i+1, a[i],b[i][0]+b[i][1]-b[i][2]);
   printf("\n");
}
