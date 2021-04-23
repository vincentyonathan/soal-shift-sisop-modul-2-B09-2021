#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

void unzip_file();
void listFilesRecursively();

void executedprogram (char execute[], char *path[]) 
{ 
    int status; pid_t child_id;
    child_id = fork();

    if(child_id == 0){execv(execute, path);}

    else{((wait(&status))>0);return;} 
}

//2a
void unzip_file()
{
    pid_t child_id;
    int status;
    child_id = fork();

    if (child_id < 0)
    {
        exit(EXIT_FAILURE);
    }

    if(child_id == 0)
    {
        //goal
        char *New_Folder[] = {"mkdir","-p", "/Users/macbook/soal2/petshop", NULL};
        executedprogram("/bin/mkdir", New_Folder);

        //source
        char *Unzip_file[] = {"unzip", "-q", "/Users/macbook/soal2/pets.zip", "-d", "/Users/macbook/soal2/petshop", "*.jpg", NULL};
        executedprogram("/usr/bin/unzip", Unzip_file);
    }

    else { while ((wait(&status)) > 0);}
}

char* cut_jpg (char*s)
{
    int a,b;
    char* new;

    for (b = 0; s[b] != '\0'; b++);

    // panjang dari string
    a = b - 4 + 1;

    if (a < 1)return NULL;

    new = (char*) malloc (a * sizeof(char));

    for (b = 0; b < a - 1; b++)new[b] = s[b]; new[b] = '\0'; return new;
}

void listFilesRecursively(){
    struct dirent *dp;
    int status;
    pid_t child_id;
    child_id = fork();

    if(child_id < 0){exit(EXIT_FAILURE);}

    if(child_id == 0)
    {
        DIR *directory;
        char source[100]="/Users/macbook/soal2/petshop";
        directory=opendir(source);

            while((dp = readdir(directory)) != NULL)
            {
                if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
                {
                    char *sign1, *sign2, *sign3, *sign4;
                    char *namefile = dp -> d_name; char *namefilenew = cut_jpg(namefile);

                    char hasil1[100], hasil2[100]; 
                    char path2[100], path3[100];
                    char cat[50], name[50], umur[50];

                    for(sign1 = strtok_r(namefilenew, "_", &sign3); sign1!=NULL; sign1=strtok_r(NULL, "_", &sign3))
                    {
                        int x = 0;
                        char path[100]="/Users/macbook/soal2/petshop/"; 
                        char tekspath[100], fileket[100], namahewan[100];

                        strcpy(hasil1, namefile); strcpy(hasil2, namefile);
                        strcpy(path2, path); strcpy(path3, path);
                        
                        for(sign2 = strtok_r(sign1, ";", &sign4); sign2 != NULL; sign2 = strtok_r(NULL, ";", &sign4))
                        {
                            //nyimpen sesuai dengan atribut
                            if(x==0){
                                strcpy(cat, sign2);
                            }
                            if(x==1){
                                strcpy(name, sign2);
                            }
                            if(x==2){
                                strcpy(umur, sign2);
                            }
                            x = x + 1;
                        }

                        //nomer 2b
                        strcat(path, cat);
                        char *New_Folder[] = {"mkdir", "-p", path, NULL};
                        executedprogram("/bin/mkdir", New_Folder);
                        
                        //copy nama hewan biar ga ketambahan .jpg
                        strcpy(namahewan, name);

                        //nomer 2c & 2d
                        strcat(name, ".jpg");
                        strcat(path2, hasil2);
                        char *copyfolder[] = {"cp", path2, path, NULL};
                        executedprogram("/bin/cp", copyfolder);

                        //rename nama file
                        strcpy(tekspath, path);
                        strcpy(path3, path);strcat(path3, "/");
                        strcat(path3, hasil2);strcat(path, "/");
                        strcat(path, name);

                        char *renamefile[] = {"renamefile", path3, path, NULL};
                        executedprogram("/bin/mv", renamefile);

                        //nomer 2e
                        strcat(tekspath, "/keterangan.txt"); 
                        strcpy(fileket, "nama : ");strcat(fileket, namahewan);
                        strcat(fileket, "\numur : ");strcat(fileket, umur);strcat(fileket, " tahun\n\n");

                        FILE *keterangan = fopen(tekspath, "a"); fputs(fileket, keterangan);
                        fclose(keterangan);  
                    }
                }
        }
    }
    else{((wait(&status))>0);}
}

int main(){
    int status;
    pid_t child_id1, child_id2;

    child_id1= fork();
    if(child_id1 < 0){exit(EXIT_FAILURE);}
    if(child_id1 == 0)
    {
        unzip_file();
    }

    child_id2=fork();
    if(child_id2<0){exit(EXIT_FAILURE);}
    if(child_id2==0){
        listFilesRecursively();
    }

    else {((wait(&status)) > 0);}
}