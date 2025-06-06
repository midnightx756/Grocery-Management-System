#include <stdio.h>
#include "string_former.c"
#include "date.c"
#include "auth.c"
#include "data.c"

/*
A Grocery Management System (GMS) is a software application designed to help a departmental store track, mangae, and streamline the process of purchasing, stocking, and and selling groceries (make it for 10 items). It can be used by grocery store owners to maimntain an organized inventoryand ensure ensure the efficient running of operations.
*/
int main()
{
    int ch,ch1, ch2;
    char* a;
    FILE* fp=fopen("Pass.goofy_ahh","r");
    if(fp == NULL){
       adduser();
       initAuth();
       clean();
       store();
    } 
    else if(!authenticator()){
        fclose(fp);
        printf("Sorry! Looks like you forgot your password or the username\n");
        printf("Now enter your choice\n1 for adding new user(requires permission of owner)\n2 for exiting\n");
        scanf("%d",&ch2);
        
        if(ch2==1)
          addnewuser();
        else
          exit(0);
    }
    
    alloc();
    dated();
    clean();
    do{
        printf("Welcome to grovcery management system, Here You can easily manage your inventory\n");
        printf("Enter \n1 for buying\n2 for selling\n3 for seeing stock\n4 for seeing a stock of particular date\n5 for printing the stock in a particular month and year\n6 for exiting\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                buy();
                clean();
                break;
            case 2:
               seller();
               clean();
                break;
            case 3:
               display();
               printf("Do You want to clear the screen:\n1 for yes\n2 for no: ");
               scanf("%d",&ch1);
               if(ch1==1)
                  clean();
               break;
           case 4: 
              dateddate();
               printf("Do You want to clear the screen:\n1 for yes\n2 for no: ");
               scanf("%d",&ch1);
               if(ch1==1)
                  clean();
              break;
           case 5: 
               printdata();
               printf("Do You want to clear the screen:\n1 for yes\n2 for no: ");
               scanf("%d",&ch1);
               if(ch1==1)
                  clean();
              break;
        }
    }while(ch!=6);
    printf("Thankyou for using our software\n");
    dsave();
    dealloc();
    for(ch=0;ch<1000;ch++);
    clean();
    return 0;
}
