#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>

#define size 32
#define limiters " \t\r\n\a"

pid_t home_pid;
char home[50];
char command[500];
char *commands[100];
int num_commands;
char *job_arr[32768];
long long int pid_jobs[32768];
int num_jobs;
