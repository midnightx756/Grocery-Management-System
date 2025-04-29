#include <stdlib.h>
#include <stdio.h>

void clean()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // _WIN32
}

void readuser(char a[][100], char pass[][100]){
    int i=0;
    FILE* fp= fopen("Pass.goofy_ahh","r");
    while(fscanf(fp, "%s %s", a[i],pass[i])==2)
      i++;
    fclose(fp);
}