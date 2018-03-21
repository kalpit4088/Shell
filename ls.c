#include "ls.h"

void ls_func(char** commands){
  DIR           *dp;
  struct dirent *dirp;

  dp = opendir(".");

  if(dp == NULL){
    perror("Cannot open directory ");
    exit(2);
  }

  // implement ls
  if(commands[1] == NULL){

    while ((dirp = readdir(dp)) != NULL){
      if(strcmp(dirp->d_name, ".")!=0 && strcmp(dirp->d_name, "..")!=0)
      printf("%s\n", dirp->d_name);
    }
  }

// implement ls -a
  else if(strcmp(commands[1], "-a") == 0){
    while ((dirp = readdir(dp)) != NULL){
      printf("%s\n", dirp->d_name);
    }
  }

  // implement ls -l
  else if(strcmp(commands[1], "-l") == 0){
    struct tm *tm;
    char buff[100];
    time_t t = time (0);

    while ((dirp = readdir(dp)) != NULL){
      struct stat fileStat;
      stat(dirp->d_name,&fileStat);
      struct passwd *pw = getpwuid(fileStat.st_uid);
      struct group  *gr = getgrgid(fileStat.st_gid);
      if(strcmp(dirp->d_name, ".")!=0 && strcmp(dirp->d_name, "..")!=0){
        printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
        printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");
        printf("%ld ",fileStat.st_nlink);
        printf("%s ",pw->pw_name);
        printf("%s  ",gr->gr_name);
        printf("%ld ",fileStat.st_size);
        tm = localtime(&t);
        strftime(buff, sizeof(buff), "%d.%m.%Y %H:%M:%S", tm);
        printf("%s ", buff);
        printf("\t%s\n", dirp->d_name);
      }
    }
  }
  else if(strcmp(commands[1], "-la") == 0 || strcmp(commands[1], "-al") == 0){
    struct tm *tm;
    char buff[100];
    time_t t = time (0);

    while ((dirp = readdir(dp)) != NULL){
      struct stat fileStat;
      stat(dirp->d_name,&fileStat);
      struct passwd *pw = getpwuid(fileStat.st_uid);
      struct group  *gr = getgrgid(fileStat.st_gid);
      printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
      printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
      printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
      printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
      printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
      printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
      printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
      printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
      printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
      printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
      printf(" ");
      printf("%ld ",fileStat.st_nlink);
      printf("%s ",pw->pw_name);
      printf("%s  ",gr->gr_name);
      printf("%ld ",fileStat.st_size);
      tm = localtime(&t);
      strftime(buff, sizeof(buff), "%d.%m.%Y %H:%M:%S", tm);
      printf("%s ", buff);
      printf("\t%s\n", dirp->d_name);
    }

  }
  else
    fprintf(stderr,"Error : No such file or directory\n");
  closedir(dp);
}
