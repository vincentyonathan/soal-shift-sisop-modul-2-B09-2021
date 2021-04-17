#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>

int main(int argc, char *argv[]) 
{
  //3d
  

  pid_t pid, sid;
  int status;
  pid = fork(); 
  if (pid < 0) 
  {
    exit(EXIT_FAILURE);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  //if ((chdir("/")) < 0) {
    //exit(EXIT_FAILURE);
  //}

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) 
  {
    //3a
    pid_t pid2;
    int status,status2,status3;
    pid2 = fork();
    char timenow[50];
    time_t times = time(NULL);
    struct tm* temporary = localtime(&times);
    strftime(timenow, 50, "%Y-%m-%d_%H:%M:%S", temporary);
     if (pid2 == 0) 
     {
        char *argv[] = {"mkdir", timenow, NULL};
        execv ("/usr/bin/mkdir", argv);
     }
     
     else 
     {
       pid_t pid5;
       while ((wait(&status)) > 0); //agar menunggu folder jadi terlebuh dahulu
       chdir(timenow);
     	//3b
     	  int i;
        for (i = 1 ; i < 11 ; i ++, sleep(5)) 
        {
          pid5 = fork();
          if (pid5 == 0)
          {
            char timenow2[50];
            time_t epoch = time(NULL);
            struct tm* temp = localtime(&epoch);
            strftime(timenow2, 50, "%Y-%m-%d_%H:%M:%S", temp);
            long long size = ((long long)epoch % 1000)+50;
            char sizelink[100] = "https://picsum.photos/";
            char ukuran[10];
            sprintf(ukuran, "%lld", size);
            strcat(sizelink, ukuran);

            char dir[100];
            strcpy(dir , timenow2);

            char *arguments[] = {"wget", "-q", "-O", dir, sizelink ,NULL};
            execv("/usr/bin/wget", arguments);
          }
        }
          pid_t pid3;
          while ((wait(&status2)) > 0); //agar menunggu folder jadi terlebuh dahulu
          char target[50];
          char encryp[50] = "Download Success";
          int sizet = strlen(encryp);
          int z;
          for(z=0 ; z<sizet; z++)
          {
            if(encryp[z] == ' ')
            {
              continue;
            }
            else if(encryp[z] >='a' && encryp[z] <= 'z')
            {
              encryp[z] += 5;
              if (encryp[z] > 'z')
              {
                encryp[z] = encryp[z] - 'z' + 'a' - 1;
              }
            }

            else if (encryp[z] >='A' && encryp[z] <= 'Z')
            {
              encryp[z] += 5;
              if (encryp[z] + 5 > 'Z')
              {
                if (encryp[z] > 'Z')
                {
                  encryp[z] = encryp[z] - 'Z' + 'A' - 1;
                }
              }
            }
            
          }
          //3c
          pid3 = fork();
          chdir(".."); //balik ke direktori sebelumnya
          if (pid3 == 0 )
          {
            //for txt
            strcpy(target, timenow);
            strcat(target, "/");
            strcat(target, "status.txt"); //target/status.txt
            FILE* txt = fopen(target, "w");
            fputs(encryp, txt);
            fclose(txt);

            //for zip
            strcpy(target, timenow);
            strcat(target, ".zip");
            
            char *args[] = {"zip", "-r", target, timenow , NULL};
            execv("/usr/bin/zip", args);
          }
          pid_t pid4;
          while ((wait(&status3)) > 0); //agar menunggu folder jadi terlebuh dahulu
          pid4 = fork();

          if (pid4 == 0)
          {
            char *arg[] = {"rm", "-r",timenow, NULL};
            execv("/usr/bin/rm", arg);
          }
      }
     sleep(40);
  }
}
