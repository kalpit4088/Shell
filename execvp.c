#include "execvp.h"


void execvp_func(char** commands){
  pid_t id;
  int status;
  int flag = 0;
  int i = 1,k=0;
  while(commands[i]!= NULL){
    if(strcmp(commands[i], "&")==0) {
      k = i;
      flag = 1;
      break;
    }
    i++;
  }
  if(flag==1){
    while(commands[k]!= NULL){
      commands[k] = commands[k+1];
      k++;
    }
  }
  id=fork();
  if(id==0){
    if(execvp(commands[0],commands) < 0){
      fprintf(stderr,"Error: enter a valid command \n");
    }
    exit(1);
  }
  else{
    if(flag != 1)
    waitpid(id,&status,0);
    else{
      pid_jobs[num_jobs] = id;
      job_arr[num_jobs] = commands[1];
      // printf("%d %lld\n",num_jobs,pid_jobs[num_jobs]);
      num_jobs++;
    }
  }
}
