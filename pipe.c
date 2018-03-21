#include "pipe.h"

void pipe_execution(char** commands){
	int i;
	int pd[2];
        
    for( i=0; i<num_commands-1; i += 2)
    {
        pipe(pd);

        if (!fork()) {
            dup2(pd[1], 1); // remap output back to parent
            execlp(commands[i], commands[i], NULL);
            perror("pipe");
            abort();
        }

        // remap output from previous child to input
        dup2(pd[0], 0);
        close(pd[1]);
    }

    execlp(commands[i], commands[i], NULL);
    perror("pipe");
    abort();
}