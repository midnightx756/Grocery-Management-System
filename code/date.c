#include <stdio.h>
#include <stdlib.h>

void dateddate(){
    FILE * data= fopen("table.txt", "r+");
    unsigned int dd,mm,yy, d1=1,m1=1,y1=0;
    int q[3], ci,i;
    float p[5];
    char da[30], n[50];
    if(data==NULL){
       printf("This is the first day you are using this application, please try the next time\n");
       return;
    }
    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%s",da);
    
    fseek(data, 0, SEEK_END);
    long int eof=ftell(data);
    rewind(data);
    if(sscanf(da, "%u/%u/%u", &dd, &mm, &yy)!=3 || dd>31 || mm>12){
        printf("Date entered is invalid, Please try again later\n");
        return;
    }
    
             while((fscanf(data, "%u/%u/%u", &d1, &m1, &y1) == 3|| ci ==1) && ftell(data) != eof){
                  for(i=0;i<10;i++){
                          fscanf(data, "%s %d %d %d %f %f %f %f %f", n, &q[0], &q[1], &q[2], &p[0], &p[1], &p[2], &p[3], &p[4]);
                           if(d1== dd && m1== mm && y1 == yy){
                                uTS(n);
                                printf("%s %d %d %d %f %f %f %f %f\n",n,q[0], q[1], q[2], p[0], p[1], p[2], p[3], p[4]);
                          }
                    }
                    ci = fscanf(data, "%c", &(char){'\0'});
            }
            printf("\n");
    
    fclose(data);
}

void printdata(){
    unsigned int mm, yy;
    FILE * dreader= fopen("table.txt", "r");
    printf("Enter the month number for the stocks to look in: ");
    scanf("%u", &mm);
    printf("Enter the year for the stocks to look into: ");
    scanf("%u", &yy);
    if(mm>12){
         printf("Month is not valid\n");
         return;
    }
  if(dreader == NULL){
      printf("This application is being used without the storage of any data, so please try storing the data first\n");
      return;
  }
  
  fseek(dreader, 0, SEEK_END);
  long int eof = ftell(dreader);
  rewind(dreader);
   int q[3],i,ci;
   char n[100];
   float p[5];
  unsigned int d1, d2, d3;
     while((fscanf(dreader, "%u/%u/%u", &d1, &d2, &d3) == 3 || ci == 1)  && ftell(dreader) != eof){
          if(d2 == mm && d3 == yy){
                  for(i=0; i<10; i++){
                        fscanf(dreader, "%s %d %d %d %f %f %f %f %f",n, q, (q+1), (q+2), p, (p+1), (p+2), (p+3), (p+4));
                  uTS(n);
                  printf("%s %d %d %d %f %f %f %f %f\n", n, q[0], q[1], q[2], p[0], p[1], p[2], p[3], p[4]);
                 }
                 printf("\n");
           }
           else if(d2 != mm){
                for(i=0;i<10;i++)
                       fscanf(dreader, "%*s %*d %*d %*d %*f %*f %*f %*f %*f");
           }
          ci = fscanf(dreader, "%c", &(char){'\0'});
     }
}
