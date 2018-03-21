#include "redirection.h"
#include "execvp.h"

void redirection_func(char **commands){
char *kalpit[] = { ">" ,  "<" ,  ">>" , "|" };
int p1=0,p2=0,fd,fd1;
int i=0;
while(commands[i]!=NULL)
	{
		if(strcmp(commands[i],kalpit[1])==0)
		{
			p1=i;
			if(p1 && i>0)
			{
				commands[i]=NULL;
			}

			fd = open(commands[i+1], O_RDONLY , 0666);
			if(fd == -1)
			{
				perror("Failed to open file");
				return;
			}
			close(0);
			dup2(fd, 0);
			close(fd);
    }
		else if(strcmp(commands[i],kalpit[0])==0)
		{
			fd1 = open(commands[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0666);

      if(fd1 == -1)
			{
				perror("Failed to open file");
				return;
			}
			if(dup2(fd1, 1) != 1)
			{
				perror("dup2 fail");
				return;
			}
			p2=i;
			close(fd1);
		}
		if(p2 && i>0)
		{
			commands[i]=NULL;
		}
		i++;
	}
  execvp_func(commands);
	 dup2(fd,0);
	 dup2(fd1,1);
	 exit(1);
}
