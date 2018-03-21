#include "current_dir.h"


void print_current_dir(){

  char current_dir[50];
  int i,j;

  getcwd(current_dir, sizeof current_dir);

  int size_a = strlen(current_dir);

  //for(i = 0; i < size_a && current_dir[i] == home[i]; i++);
  printf("~/");
  i = 0;
  for(j = i+1; j < size_a; j++){
    printf("%c", current_dir[j] );
  }
}
