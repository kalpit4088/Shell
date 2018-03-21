#include "pinfo.h"

void pinfo_func(char** commands){
  int flag1;
  FILE *fptr;

  char  source[50]={}, source_a[50]={}, c;

  source[0]= '/';
  source[1]= 'p';
  source[2]= 'r';
  source[3]= 'o';
  source[4]= 'c';
  source[5]= '/';
  source[6]= '\0';

  if(commands[1] == NULL){
    snprintf (source_a, sizeof(source_a), "%d",home_pid);
    strcat(source, source_a);
    strcat(source, "/status");
    fptr = fopen(source, "r");
    if (fptr == NULL)
    {
      printf("Cannot open file \n");
      exit(0);
    }
    c = fgetc(fptr);
    while (c != EOF)
    {
      printf ("%c", c);
      c = fgetc(fptr);
    }

    fclose(fptr);
  }

  else{
    flag1 = 1;
    strcat(source, commands[1]);
    strcat(source, "/status");
    fptr = fopen(source, "r");
    if (fptr == NULL)
    {
      printf("Cannot open file \n");
      flag1 = 0;
    }
    if(flag1){
      c = fgetc(fptr);
      while (c != EOF)
      {
        printf ("%c", c);
        c = fgetc(fptr);
      }
      fclose(fptr);
    }
  }
}
