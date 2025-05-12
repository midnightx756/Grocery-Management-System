#include <stdio.h>
#include <stdlib.h>
#include "strs.c"

//The Authentication module of the program

//Checks whether the password is strong or not
int netvalidity(char a[]){
    if(lenpass(a) && charcheck(a))
      return 1;
    else 
     return 0;
}

// This function is used to create the username, password for the first time, when the file does not exist
void initAuth() {
    char pass[100];
    char* encpass= (char*)malloc(100*sizeof(char));
    if(encpass == NULL){
        printf("Memory could not be allocated successfully");
        exit(0);
     }
    while(!netvalidity(pass)){
        getchar();
        printf("Please create a password: ");
        scanf(" %[^\n]s", pass);
        if(netvalidity(pass)!=1)
            printf("Please create a stronger password\n");
    }
    encpass=encode(pass);
    FILE* fp;
    char fname[]="Pass.goofy_ahh";
    fp=fopen(fname,"a");
    if(fp == NULL){
        printf("File could not be opened successfully");
        exit(0);
     }
    fprintf(fp,"%s\n", encpass);
    fclose(fp);
    free(encpass);
}

//Function to check the credentials login module
int authenticator(){
    char enterpass[100],username[100];
    char ru[100][100], rp[100][20];
    int i=0,j,k,c=0;
    FILE* fp;
    char fname[]="Pass.goofy_ahh", g[100],*pass;
    fp=fopen(fname,"r");

    if(fp==NULL){
        printf("File does not exist exiting\n");
        exit(0);
    }

    while(fscanf(fp,"%s%s",ru[i], rp[i])==2)
       i++;
    
    k=i;
    for(i=1;i<=3;i++){
    printf("Enter the username, you have %d tries: ",4-i);
    scanf("%[^\n]s", username);
    getchar();
        for(c=0,j=0;j<k;j++){
            if(equal(ru[j], username)){
                c=1;
                pass=decode(rp[j]);
                break;
            }
        }
        if(c==0)
          printf("Try again\n");
        else
          break;
    }
    if(i==4 && c==0){
        printf("Sorry! The username you entered is wrong\n");
        fclose(fp);
        free(pass);
        return 0;
    }
    printf("Enter the password dear %s\n", username);
    for(i=1;i<=5;i++){
       printf("Enter the created password you have %d tries left: ",6-i);
       scanf(" %[^\n]s",enterpass);
       getchar();
       if(equal(pass,enterpass))
       {
         fclose(fp);
         free(pass);
         return 1;
       }
       else if(i<=4)
         printf("Wrong password Try again\n");
    }
    
   
    
    free(pass);
    return 0;
}

//Adds user for the first time
void adduser(){
    char* a=(char*)malloc(100*sizeof(char));
    if(a==NULL){
       printf("Memory failed to allocate");
       exit(0);
    }
    FILE* fp = fopen("Pass.goofy_ahh","a");
    if(fp==NULL){
         printf("The file could not be opened");
         exit(0);
    }
    printf("Enter your username without any space: ");
    scanf(" %[^\n]s",a);
    fprintf(fp,"%s ",a);
    fclose(fp);
}

//Adds new user but asks for the first user's permission
void addnewuser(){
   printf("For registering a new user you must input the password of the first user\n");
   FILE* fp = fopen("Pass.goofy_ahh","a+");
   char pass[20], uname[100], entpass[20], *dec;

   if(fp==NULL){
    printf("Error opening file");
    exit(0);
   }

   rewind(fp);
   fscanf(fp, "%s %s", uname, pass);

   fseek(fp,0,SEEK_END);
   dec=decode(pass);
   getchar();
   printf("Enter the password: ");
   scanf(" %[^\n]s",entpass);

   //Here I'm checking wether the user has the permission of the owner
   if(equal(dec, entpass)){
    printf("You have successfully entered the password\nPlease enter the new username:");
    scanf(" %[^\n]s", uname);
    printf("Input the password: ");
    scanf(" %[^\n]s", pass);
    fprintf(fp,"%s %s\n", uname, encode(pass));
    fclose(fp);
    free(dec);
   }

   else{
    printf("Sorry! It looks like that you are trying to steal the data\n");
    free(dec);
    fclose(fp);
    exit(0);
   }
}
