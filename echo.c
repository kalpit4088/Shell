#include "echo.h"

void echo_func(char** commands){
  int i;
  if(commands[1] == NULL){
    printf("\n");
  }
  else{
    i = 1;
    while(commands[i]!=NULL){
      printf("%s ",commands[i]);
      i++;
    }
    printf("\n");
  }
}
