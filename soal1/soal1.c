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

void h_6_birthday(){
    do_download_foto();
    do_download_film();
    do_download_musik();
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
void Daemon(){
    pid_t pid;
    const unsigned sleep_time = 1;
    const int b_month = 3;
    const int b_day = 9;
    const int b_hour = 22;
    const int b_min = 22;
    while(1)
    {
        time_t now=time(NULL);
        struct tm *timenow=localtime(&now);
        if (b_month == timenow->tm_mon && b_day == timenow->tm_mday && b_hour == timenow->tm_hour&&b_min==timenow->tm_min&& timenow->tm_sec==0)
        itsbirthday(pid, status);
        else if (b_month == timenow->tm_mon && b_day == timenow->tm_mday && b_hour == timenow->tm_hour&&b_min==timenow->tm_min&& timenow->tm_sec==0)
        h_6_birthday(pid);
        while(wait(status)>0);
        sleep(sleep_interval);
    }
} if ()
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
void itsbirthday(void){
    pid_t pid = fork();
    if (pid == 0){
        zipping_folder();
        remove_folder();
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }    
}   
}      
//end of 1f

// ||---command list---||
//1a do_makedir_foto/film/musik (create folder)
//1b do_download_foto/film/musik (download link)
//1c do_unzip_foto/film/musik (unzip zip)
//1d do_move (move from x to y)
//1e Daemon (for function without time check use "zipping_folder")
//1f remove_folder
int main(void) {
    pid_t pid, sid;
    int status;
    if((pid = fork()) > 0)
        exit(EXIT_SUCCESS);
    umask(0);
    sid = setsid();
    if (sid < 0 || chdir(workingDir))
        exit(EXIT_FAILURE);

    Daemon(&status);
    return 0;
}
