# soal-shift-sisop-modul-2-B09-2021

* Vincent Yonathan    - 05111940000186
* Aprilia Annisa      - 05111940000199
* Pramudityo Prabowo  - 05111940000210
---

### Soal Modul 2
[Soal Shift Modul 2](https://docs.google.com/document/d/121ZqwL7KXiKy3YpQgP6INuYlb4969WOj1GlZ9umO65w/edit)

---

### Daftar isi
* [Soal 1](#soal-1)
* [Soal 2](#soal-2)
* [Soal 3](#soal-3)

---
### Soal 3
*Praktikan* diminta membantu Ranora dalam membuat tugas magangnya di “FakeKos Corp.” yang bekerja dalam keamanan data. Ranora ditugaskan untuk membuat program untuk tugas pertamanya.

#### 3. a)
*Praktikan* diminta membuat program C yang membuat direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss] setiap 40 detik.

#### Source Code :
```c
...
int main(int argc, char *argv[]) 
{
  while (1) 
  {
    //3a
    pid_t pid2;
    int status,status2,status3,stats;
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
     ...
     sleep(40);
  }
}
```
- Pengerjaan dilakukan menggunakan `Daemon` yang ditandai dengan while(1).
- Mendeklarasikan `pid2` (parent id) bertipe data `pid_t` untuk melakukan fork
- Pada source code berikut juga didefinisikan status untuk membuat program menunggu sebuah proses yang didefinisikan pada kode sebelumnya
- Kemudian, Program akan menjalankan fork dan menyimpannya ke pid2
- Selanjutnya adalah mendefinisikan array `timenow` bertipe data char dengan alokasi besar arranya 50.
- Setelah itu mendefinisikan variable `times` bertipe data `time_t` dan melakukan *assign* `time(NULL)` yang didapatkan dari `#include <time.h>` yang akan mengoutputkan waktu pada saat itu
- Menggunakan `struct tm*` dan mendefinisikan variable `temporary` yang akan menyimpan `localtime(&times)` yang mengubah variable yang berisi waktu sekarang menjadi waktu lokal.
- Berikutnya, menggunakan `strftime` yang *mengassign* variable `timenow` dengan value dari variable `temporary` dengan format yang diminta yaitu `"%Y-%m-%d_%H:%M:%S"`
- Kemudian menggunakan kondisi `if (pid2 == 0) ` yang menjadi kondisi untuk menjalankan child process telah berhasil dan dapat menjalankan proses berikutnya
- Lalu kita mendefinisikan `*argv[]` dengan tipe data char yang berisi arguments yang akan digunakan dalam `execv` yaitu disini adalah `{"mkdir", timenow, NULL}`
- Pada akhirnya, menggunakan `execv` untuk menjalankan program untuk membuat (`directory`) dengan menggunakan directory dari `mkdir` dengan argumen `"/usr/bin/mkdir"` dan sesuai dengan isi dari variable `timenow` 
- Lalu `execv` harus diakhiri dengan `NULL` dan program dapat dijalankan. Karena diminta untuk membuat setiap 40 detik, maka menggunakan `sleep(40)` pada akhir while.

#### Output :

#### 3. b)
*Praktikan* diminta mengisi 10 foto dari https://picsum.photos/ pada folder/direktori setelah setiap direktori pada nomor 3.a) selesai. Setiap gambar tersebut akan didownload dengan selang waktu 5 detik dan akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

#### Source Code :
```c
...
  pid_t temp;
     while ((wait(&stats)) > 0);
     temp = fork();
     if(temp == 0)
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
 ...
```
Tahap Inisialisasi :
- Pada soal 3 b.) ini, pertama dideklarasikan dahulu `pid_t` dengan nama `temp` yang akan menjadi kondisi untuk program dijalankan. 
- Kemudian memakai ```c while ((wait(&stats)) > 0);``` dimana ini digunakan agar program ini dijalankan menunggu proses sebelumnya selesai terlebih dahulu.
- Setelah itu melakukan `fork()` yang disimpan ke `temp` seperti proses pada umumnya 

Tahap Soal :
- `fork` digunakan sebagai kondisi dalam menjalankan code dan ketika telah dipenuhi maka code akan dijalankan.
- Mendeklarasikan lagi `pid_t` dengan nama disini `pid5` .
- Kemudian memakai ```c while ((wait(&status)) > 0);``` dimana ini digunakan agar program ini dijalankan menunggu proses sebelumnya selesai terlebih dahulu.
- Selanjutnya, karena gambar akan di*download* dalam folder yang telah dibuat dalam 3 a.) maka harus menggunakan `chdir(timenow);` dimana `timenow` merupakan variable yang menyimpan nama dari folder yang dibuat dengan format yang diminta.
- Karena pada soal diminta mendownload 10 foto, maka melakukan deklarasi variable looping `i` dan kemudian menggunakan forloop sebanyak 10 kali.
- Pada forloop tersebut, dilakukan `fork()` menggunakan `pid5=fork();` sebagai kondisionalnya dengan `if(pid5 == 0)`,
- Jika kondisional tersebut terpenuhi, barulah melakukan coding untuk permintaan soal
- Sama seperti nomor 3 a.) yaitu adalah mendefinisikan array `timenow2` bertipe data char dengan alokasi besar arranya 50.
- Setelah itu mendefinisikan variable `epoch` bertipe data `time_t` dan melakukan *assign* `time(NULL)` yang didapatkan dari `#include <time.h>` yang akan mengoutputkan waktu pada saat itu
- Menggunakan `struct tm*` dan mendefinisikan variable `temp` yang akan menyimpan `localtime(&times)` yang mengubah variable yang berisi waktu sekarang menjadi waktu lokal.
- Berikutnya, menggunakan `strftime` yang *mengassign* variable `timenow2` dengan value dari variable `temp` dengan format yang diminta yaitu `"%Y-%m-%d_%H:%M:%S"`.
- Langkah berikutnya adalah mendeklarasikan variable `size` bertipe data `long long` untuk menyimpan ukuran yang diminta dari foto yaitu `((long long)epoch % 1000)+50`.
- Kemudian juga mendeklarasikan variable array `sizelink` bertipe data `char` dan berukuran 100 yang didalamnya di*assign* link dari foto yang akan diunduh yaitu "https://picsum.photos/"
- Kemudian mendeklarasikan juga variable array `ukuran` dengan tipe data `char` dengan ukuran 10 untuk menampung hasil dari `size` yang merupakan langkah selanjutnya dari code yaitu ` sprintf(ukuran, "%lld", size);`
- Setelah itu karena link fotonya ternyata dapat diset ukurannya dengan cara menambahkan argumen dibelakang `/`, maka kita melakukan `strcat(sizelink, ukuran);` agar link nya tepat untuk mengunduh foto sesuai ukuran yang diinginkan.
- Kemudian terakhir mendeklarasikan variable array `dir` bertipe data `char` berukuran 100 dan nantinya akan diisi nama directory `timenow2` untuk nanti `wget` mengetahui harus masuk ke directory mana terlebih dahulu
- Langkah setelahnya, mendefinisikan `*arguments[]` dengan tipe data `char` yang berisi arguments yang akan digunakan dalam `execv` yaitu disini adalah `{"wget", "-q", "-O", dir, sizelink ,NULL}`
- Langkah terakhir adalah menggunakan `execv` untuk menjalankan program untuk melakukan download (`wget -q -O`) dengan menggunakan directory dari `dir` dari link pada `sizelink` dan ditambahkan argumen `"/usr/bin/wget"`. 

#### Output :

### 3. c)
Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

#### Source Code :
Caesar Cipher :
Pada algoritma Caesar Cipher pada soal ini, diminta untuk menambahkan ASCII alphabet yang ada di kata "Download Success" sebanyak 5, karena itu algoritma pada program adalah :
```c
...
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
```
- Pertama, seperti biasanya akan dideklarasikan `pid_t` dengan nama `pid3` yang akan menjadi kondisi untuk program dijalankan. 
- Kemudian memakai ```c while ((wait(&stats2)) > 0);``` dimana ini digunakan agar program ini dijalankan menunggu proses sebelumnya selesai terlebih dahulu.
- Setelah itu, mendeklarasikan variable yang dibutuhkan yaitu `target` dan `encryp` yang berbentuk array dan bertipe data `char` dimana `encryp` akan diisikan oleh *statement* yang diminta oleh soal yaitu "Download Success". Kemudian juga dideklarasikan variable `sizet` bertipe data `int` untuk menyimpan panjang dari statement di `encryp` menggunakan fungsi `len(encryp)`.
- Setelah itu, algoritma Caesar Cipher ini menggunakan looping sehingga mendefinisikan variable looping `z` dan melakukan forloop sebanyak `sizet` atau panjang kalimat pada `encryp`.
- Setelah itu menjalankan berbagai kondisi yaitu apabila looping pada saat itu adalah *spasi* atau `encryp[z] == ' '`, maka program akan dilanjutkan. Algoritma setelahnya yaitu apabila `encryp[z]` ada dalam batas ASCII 'a' dan 'z', maka akan langsung ditambahkan dengan 5. Namun, apabila tidak maka akan dikembalikan ke batasan ASCII 'a' sampai 'z' menggunakan `encryp[z] = encryp[z] - 'z' + 'a' - 1;`.
- Begitupula dengan kondisi ketika `encryp[z]` ada dalam batas ASCII 'A' dan 'Z', maka akan langsung ditambahkan dengan 5. Namun, apabila tidak maka akan dikembalikan ke batasan ASCII 'A' sampai 'Z' menggunakan `encryp[z] = encryp[z] - 'Z' + 'A' - 1;`.

Tahap Soal (Txt dan Zipping) :

```c
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
          //pid4 = fork();
          // if (pid4 == 0)
          // {
            char *arg[] = {"rm", "-r",timenow, NULL};
            execv("/usr/bin/rm", arg);
          // }
      }
  ....
```
txt :
- Pada tahap yang diminta oleh soal yaitu zipping, seperti biasanya akan melakukan `fork()` menggunakan `pid3` yang telah dideklarasikan pada tahap Caesar Cipher diatas.
- Kemudian menggunakan `chdir(..)` agar tidak terbuat dalam folder yang sama seperti pada gambar pada 3.b).
- Setelah itu, kembali menggunakan kondisional `if(pid3 == 0)`
- Didalam kondisional tersebut, dijalankan pertama adalah menggunakan `strcpy` untuk mengisi variable `target` dengan `timenow` yaitu format nama folder pada 3.a). Kemudian melakukan `strcat` agar menambahkan suatu kalimat di bagian belakang `target` yang terisi `timenow` sekarang sebagai direktorinya, yaitu "/" dengan syntax `strcat(target, "/");`
- Kemudian, agar penamaan sesuai "status.txt" maka direktori `target` tadi harus dilakukan `strcat` lagi untuk ditambahkan `status.txt`.
- Kemudian mendeklarasikan file dengan variable `txt` agar bisa diakses untuk ditutup yang bertugas membuka `target` yaitu file yang dibuat dan `w` untuk write.
- Kemudian dilakukan `fputs` untuk mengisi file `txt` yang berbentuk .txt tersebut dengan `encryp` yang berisi statement "Download Success" yang telah terenkripsi.

zip :
- Untuk zip, tahap pertama yang dilakukan adalah dengan mengisi variable `target` dengan `timenow` dan menambahkan kalimat dibelakangnya menggunakan `strcat`. String tersebut berisi ".zip" sehingga `target` sekarang terisi dengan "(timenow).zip"
- Kemudian memendefinisikan `*args[]` dengan tipe data `char` yang berisi arguments yang akan digunakan dalam `execv` yaitu disini adalah `{"zip", "-r", target, timenow , NULL}`
- Langkah terakhir adalah menggunakan `execv` untuk menjalankan program untuk melakukan zip (`zip -r`) dengan argumen `"/usr/bin/zip"`. 

menghapus folder awal :
- Menggunakan ```c while ((wait(&stats)) > 0);``` dimana ini digunakan agar program ini dijalankan menunggu proses sebelumnya selesai terlebih dahulu yaitu pembentukan zip.
- Kemudian memendefinisikan `*arg[]` dengan tipe data `char` yang berisi arguments yang akan digunakan dalam `execv` yaitu disini adalah `{"rm", "-r",timenow, NULL}`.
- Langkah terakhir adalah menggunakan `execv` untuk menjalankan program untuk melakukan remove (`rm -r`) dengan argumen `"/usr/bin/rm"`. 

#### Output :

### 3. d)
*Praktikan* diminta membuat program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan menggunakan program bash.

#### Source Code :

#### Output :


### 3. e)
*Praktikan* diminta membuat program utamanya dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

#### Source Code :

#### Output :


