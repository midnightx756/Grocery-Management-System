#include <stdio.h>
#include "auth.c"
#include "data.c"

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
        printf("Enter \n1 for buying\n2 for selling\n3 for seeing stock\n4 for exit\n");
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
        }
    }while(ch!=4);
    printf("Thankyou for using our software\n");
    dsave();
    dealloc();
    clean();
    return 0;
}
