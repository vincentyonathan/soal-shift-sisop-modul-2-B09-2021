#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//start of 1a
void do_makedir_foto(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *argv[16];
        argv[0] = "mkdir";
        argv[1] = "-p";
        argv[2] = "Pyoto";
        argv[3] = NULL;
        execv("/bin/mkdir", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_makedir_musik(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *argv[16];
        argv[0] = "mkdir";
        argv[1] = "-p";
        argv[2] = "Musyik";
        argv[3] = NULL;
        execv("/bin/mkdir", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_makedir_film(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *argv[16];
        argv[0] = "mkdir";
        argv[1] = "-p";
        argv[2] = "Fylm";
        argv[3] = NULL;
        execv("/bin/mkdir", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
//end of 1a

//start of 1b
void do_download_foto(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *wget_argv[16];
        wget_argv[0] = "wget";
        wget_argv[1] = "--no-check-certificate";
        wget_argv[2] = "-O";
        wget_argv[3] = "Foto_for_Stevany.zip";
        wget_argv[4] = "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download";
        wget_argv[5] = NULL;
        execv("/bin/wget", wget_argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_download_musik(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *wget_argv[16];
        wget_argv[0] = "wget";
        wget_argv[1] = "--no-check-certificate";
        wget_argv[2] = "-O";
        wget_argv[3] = "Musik_for_Stevany.zip";
        wget_argv[4] = "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download";
        wget_argv[5] = NULL;
        execv("/bin/wget", wget_argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_download_film(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *wget_argv[16];
        wget_argv[0] = "wget";
        wget_argv[1] = "--no-check-certificate";
        wget_argv[2] = "-O";
        wget_argv[3] = "Film_for_Stevany.zip";
        wget_argv[4] = "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download";
        wget_argv[5] = NULL;
        execv("/bin/wget", wget_argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
//end of 1b

//start of 1c

void do_unzip_foto(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "unzip";
    argv[1]= "-qq";
    argv[2]= "Foto_for_Stevany.zip";
    argv[3]= NULL;
    execv("/bin/unzip", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_unzip_musik(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "unzip";
    argv[1]= "-qq";
    argv[2]= "Musik_for_Stevany.zip";
    argv[3]= NULL;
    execv("/bin/unzip", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_unzip_film(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "unzip";
    argv[1]= "-qq";
    argv[2]= "Film_for_Stevany.zip";
    argv[3]= NULL;
    execv("/bin/unzip", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
//end of 1c

//start of 1d
void rename_fotopyoto(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "rm";
    argv[1]= "-r";
    argv[2]= "Pyoto";
    argv[3]= NULL;
    execv("/bin/rm", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_move_foto(void){
    pid_t pid = fork();
    if (pid == 0){
    rename_fotopyoto();
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "FOTO";
    argv[2]= "Pyoto";
    argv[5]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void rename_musikmusyik(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "rm";
    argv[1]= "-r";
    argv[2]= "Musyik";
    argv[3]= NULL;
    execv("/bin/rm", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_move_musik(void){
    pid_t pid = fork();
    if (pid == 0){
    rename_musikmusyik();
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "MUSIK";
    argv[2]= "Musyik";
    argv[5]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void rename_filmfylm(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "rm";
    argv[1]= "-r";
    argv[2]= "Fylm";
    argv[3]= NULL;
    execv("/bin/rm", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_move_film(void){
    pid_t pid = fork();
    if (pid == 0){
    rename_filmfylm();
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "FILM";
    argv[2]= "Fylm";
    argv[3]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
//end of 1d
//start of 1e
int pre_birthday_time(int day, int month){
    int b_month = 3,b_day = 9 ;

    return b_month == month && b_day == day;
}
void zipping_folder(void){
    pid_t pid = fork();
    if (pid == 0){
        char *argv[16];
        argv[0]= "zip";
        argv[1]= "-rmvq";
        argv[2]= "Lopyu_Stevany.zip";
        argv[3]= "FOTO";
        argv[4]= "MUSIK";
        argv[5]= "FILM";
        argv[6]= NULL;
        execv("/bin/zip", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }    
}

void Daemon(){
    pid_t child_id;
    const unsigned Sleep_time = 1;
    char *Folder_name[] = {"Fylm","Musyik","Pyoto"}




}
//end of 1e

//start of 1f
void remove_folder(void){
    pid_t pid = fork();
    if (pid == 0){
        rename_fotopyoto();
        rename_musikmusyik();
        rename_filmfylm();
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }    
}
void after_birthday(void){

}        
//end of 1f

// ||---command list---||
//1a do_makedir_foto/film/musik (create folder)
//1b do_download_foto/film/musik (download link)
//1c do_unzip_ (unzip zip)
//1d do_move (move from x to y)
//1e Daemon (for function without time check use "zipping_folder")
//1f remove_folder
int main(void) {

    return 0;
}