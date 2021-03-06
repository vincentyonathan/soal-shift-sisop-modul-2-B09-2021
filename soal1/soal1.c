#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>

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
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-v";
    argv[2]= "FOTO";
    argv[3]= "Pyoto";
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
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-v";
    argv[2]= "MUSIK";
    argv[3]= "Musyik";
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
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-v";
    argv[2]= "FILM";
    argv[3]= "Fylm";
    argv[4]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
//end of 1d
//start of 1e
void h_6_birthday(){
    do_makedir_foto();
    do_makedir_film();
    do_makedir_musik();
    do_download_foto();
    do_download_film();
    do_download_musik();
    do_unzip_foto();
    do_unzip_film();
    do_unzip_musik();
    do_move_foto();
    do_move_film();
    do_move_musik();
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
void do_makedir_lopyu_stevany(void) {
    pid_t pid = fork();
    if (pid == 0){
        char *argv[16];
        argv[0] = "mkdir";
        argv[1] = "-p";
        argv[2] = "lopyu_stevany";
        argv[3] = NULL;
        execv("/bin/mkdir", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_move_filmlop(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-v";
    argv[2]= "Fylm";
    argv[3]= "Lopyu_Stevany";
    argv[4]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_move_fotolop(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-v";
    argv[2]= "Pyoto";
    argv[3]= "Lopyu_Stevany";
    argv[4]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void do_move_musiklop(void){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-v";
    argv[2]= "Musyik";
    argv[3]= "Lopyu_Stevany";
    argv[4]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void move_to_folder(void){
    do_makedir_lopyu_stevany();
    do_move_fotolop();
    do_move_filmlop();
    do_move_musiklop();
}
void zipping_folder(void){
    pid_t pid = fork();
    if (pid == 0){
        char *argv[16];
        argv[0]= "zip";
        argv[1]= "-m";
        argv[2]= "-r";
        argv[3]= "Lopyu_Stevany.zip";
        argv[4]= "Lopyu_Stevany";
        argv[5]= NULL;
        execv("/bin/zip", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }    
} 
void move_folder_to_zip(){
    pid_t pid = fork();
    if (pid == 0){
    char *argv[16];
    argv[0]= "mv";
    argv[1]= "-r";
    argv[2]= "Musyik";
    argv[3]= "Lopyu_Stevany";
    argv[4]= NULL;
    execv("/bin/mv", argv);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }
}
void its_birthday(){
    pid_t pid = fork();
    if (pid == 0){
        move_to_folder();
        zipping_folder();
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }    
}         
//end of 1f

//daemon
void Daemon(){
    pid_t pid;
    int status;
    const unsigned sleep_time = 1;
    const int b_month = 3;
    const int b_day = 9;
    const int b_hour = 22;
    const int b_min = 22;
    while(1)
    {
        time_t now = time(NULL);
        struct tm *timenow=localtime(&now);
        if (b_month == timenow->tm_mon && b_day == timenow->tm_mday && b_hour == timenow->tm_hour&&b_min==timenow->tm_min&& timenow->tm_sec==0)
        its_birthday(pid,status);
        else if (b_month == timenow->tm_mon && b_day == timenow->tm_mday && b_hour-6 == timenow->tm_hour&&b_min==timenow->tm_min&& timenow->tm_sec==0)
        h_6_birthday(pid);
        while(wait(&status)>0);
        sleep(sleep_time);
    }
}

// ||---command list---||
//1a do_makedir_foto/film/musik (create folder)
//1b do_download_foto/film/musik (download link)
//1c do_unzip_foto/film/musik (unzip zip)
//1d do_move (move from x to y)
//1e Daemon (for function without time check use "zipping_folder")
//1f remove_folder
int main(void) {
    char currentDir [256];
    getcwd(currentDir,256);
    pid_t pid, sid;
    int status;

    if((pid = fork()) > 0)
        exit(EXIT_SUCCESS);

    umask(0);

    sid = setsid();
    if (sid < 0 || chdir(currentDir))
        exit(EXIT_FAILURE);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    Daemon(&status);
    return 0;
}
