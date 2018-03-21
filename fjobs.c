#include "fjobs.h"

void jobs_func(char **commands){
  int i=0;
  char status[1000],status1[1000],status2[1000],status4[1000];
  for(i=0;i<num_jobs;i++){
    char show_status[1024],id_name[1000];

    sprintf(id_name, "%lld", pid_jobs[i]);

    strcpy(show_status,"/proc/");

    strcat(show_status,id_name);

    strcat(show_status,"/status");

    FILE *mem = fopen(show_status, "r");

    fscanf(mem, "%s %s %s %s", status1, status2, status4, status);
    // printf("%s %s %s %s\n",status1,status2,status4,status);

    if(strcmp(status,"S")==0){
      printf("[%d] 'Running' [%s]\n", i,id_name);
    }
    else{
      printf("[%d] 'Running' [%s]\n", i,id_name);
    }
  }
}
