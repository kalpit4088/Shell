#include "pwd.h"
#include "current_dir.h"

void pwd_func(char** commands){
  print_current_dir(commands);
  printf("\n");
}
