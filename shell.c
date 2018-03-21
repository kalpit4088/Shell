#include "all.h"
#include "pwd.h"
#include "ls.h"
#include "current_dir.h"
#include "pinfo.h"
#include "echo.h"
#include "change_dir.h"
#include "execute.h"
#include "execvp.h"
#include "redirection.h"
#include "fjobs.h"
#include "pipe.h"

  void username(){
  	register struct passwd *pw;
  	register uid_t uid;
  	char comp[100];
  	uid = geteuid ();
  	pw = getpwuid (uid);
  	gethostname(comp, sizeof comp);
  	printf("%s@", pw->pw_name);
  	printf("%s:",comp );
  }

  int main(){
    int i=0;
  	home_pid = getpid();
  	getcwd(home, sizeof home);
    pid_t local_pid;
  	while(1){
  		num_commands = 0;
  		username();
  		print_current_dir();
  		printf("$ ");
  		fgets(command, 500, stdin);

  		commands[num_commands] = strtok(command, limiters);

  		while(commands[num_commands] != NULL){
  			num_commands++;
  			commands[num_commands] = strtok(NULL, limiters);
  		}

  		if(num_commands){
  			if(strcmp(commands[0] , "quit") == 0)
  				break;
  			else{
  			  // local_pid = getpid();
          execute_func(commands);
          // pid_jobs[i] = local_pid;
          printf("%d\n",local_pid);
        }
  		}
      i++;
  	}


  	return 0;
  }
