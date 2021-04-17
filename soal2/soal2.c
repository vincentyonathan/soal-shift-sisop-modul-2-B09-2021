#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>


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
    
    else{while((wait (&status) ) > 0);} 
    return 0;
}