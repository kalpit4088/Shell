#include "change_dir.h"

void change_dir_func(char** commands){

    char current_dir[50];
    int i;

    getcwd(current_dir, sizeof current_dir);


  if(commands[1] == NULL || commands[1] == "~"){
    chdir(home);
  }
  else if(commands[1] = "/"){
    chdir(commands[1]);
  }
  else{
    if(chdir(strcat(strcat(current_dir, "/"), commands[1])) < 0){
     // if(chdir(commands[1]) < 0){
        perror("Error");
      //}
    }
    /*else{

      getcwd(current_dir, sizeof current_dir);

      for(i=0;home[i] == current_dir[i] ; i++);

      if(i < strlen(home))
      chdir(home);
    }*/
  }
}
