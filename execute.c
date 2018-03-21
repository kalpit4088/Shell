 #include "execute.h"

void execute_func(char **commands){



  char *kalpit[] = { ">" ,  "<" ,  ">>" , "|" };
    int i=0,flag=0;
  while(commands[i]!=NULL){
    if((strcmp(commands[i], kalpit[0]) == 0) || (strcmp(commands[i],kalpit[1])==0) || (strcmp(commands[i], kalpit[2])==0)){
      flag = 1;
      break;
    }
    else{
      flag = 0;
    }
    i++;
  }
    if(flag == 1){
       redirection_func(commands);
    }



    for(i = 0;i < num_commands;i++){
      if(strcmp(commands[i], "|") == 0){
        break;
      }
    }
    if(i == num_commands){
        if(strcmp(commands[0], "pwd\0") == 0){
      print_current_dir();
      printf("\n");
    }

    else if(strcmp(commands[0], "cd\0") == 0){
      change_dir_func(commands);
    }


    else if(strcmp(commands[0], "ls\0") == 0){
      ls_func(commands);
    }


    else if(strcmp(commands[0], "pinfo") == 0){
      pinfo_func(commands);
    }

      else if(strcmp(commands[0], "setenv\0") == 0){
        setenv(commands[1], commands[2], 0);
      }
      else if(strcmp(commands[0], "getenv\0") == 0){
        printf("%s\n",getenv(commands[1]));
      }

      else if(strcmp(commands[0], "unsetenv\0") == 0){
        unsetenv(commands[1]);
      }

      else if(strcmp(commands[0],"jobs\0") == 0){
          jobs_func(commands);
      }


    else
      execvp_func(commands);
  }

    else{
      pipe_execution(commands);
    }

}
