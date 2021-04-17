#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>

//Nomor 2a
void unzip_file()
{
    pid_t child_id1;
    
    child_id1 = fork();

    int status;

    if(child_id1 < 0){
      //Jika gagal membuat proses baru, program akan berhenti
      exit(EXIT_FAILURE);
    }

    if(child_id1 == 0){

      // goal
      char *FolderBaru = {"MakeDir", "-p", "/Users/macbook/soal2/petshop", NULL};
      execv("/bin/MakeDir", FolderBaru);

      // source
      char *unZip[] = {"unzip", "/Users/macbook/soal2/pets.zip", "-d", "/Users/macbook/soal2/petshop", "*.jpg", NULL};
      execv("/usr/bin/unzip", unZip);
    }

    else {while((wait (&status) ) > 0);}
}


//Nomor 2b
void listFilesRecursively(char *basePath)
{
    pid_t child_id2;
    
    child_id2 = fork();

    int status;

    if(child_id2 < 0){
      //Jika gagal membuat proses baru, program akan berhenti
      exit(EXIT_FAILURE);
    }

    if(child_id2 == 0)
    {
        struct dirent *dp;
        DIR *dir=opendir(basePath);
        char path[1000], *str, nama[400], *sign;

        if(!dir) {
            return;
        }

        while((dp=readdir(dir)) != NULL)
        {
            if (strcmp(dp -> d_name, ".") != 0 && strcmp(dp -> d_name, "..") != 0){
                str = dp -> d_name;
                snprintf(nama, sizeof nama, "%s", dp -> d_name);
                sign = strtok(str, ";_");
                
                int x=0;
                while(sign != NULL){
                    if (x==0 || x==3)
                    {
                        if(fork() == 0)
                        {
                            char goal[100]; snprintf(goal, sizeof goal, "/Users/macbook/soal2/petshop/%s", sign);
                            char *NewFolder[] = {"mkdir", "-p", "/Users/macbook/soal2/petshop", goal, NULL};
                            execv("/bin/mkdir", NewFolder);
                        }
                    }
                    sign = strtok(NULL, ";_"); x++;
                }
                strcpy(path, basePath); strcat(path, "/"); strcat(path, dp->d_name);
                listFilesRecursively(path);
            }
        }
        closedir(dir);
    }
    else {while((wait (&status) ) > 0);}
}


int main()
{
    pid_t child_id1, child_id2, child_id3, child_id4, child_id5;
    
    int status;

    //2a
    child_id1 = fork();
    if(child_id1 < 0){
      exit(EXIT_FAILURE);
    }
    if(child_id1 == 0){
      //Memanggil fungsi
      unzip_file();
    }

    //2b
    child_id2 = fork();
    if(child_id2 < 0){
      exit(EXIT_FAILURE);
    }
    if(child_id2 == 0){
      listFilesRecursively("petshop");
    }
    
    else{
        while((wait (&status) ) > 0);
    } 
    return 0;
}
