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
- Selanjutnya adalah mendefinisikan array timenow bertipe data char dengan alokasi besar arranya 50.
- Setelah itu mendefinisikan variable `times` bertipe data `time_t` dan melakukan *assign* `time(NULL)` yang didapatkan dari `#include <time.h>` yang akan mengoutputkan waktu pada saat itu
- Menggunakan `struct tm*` dan mendefinisikan variable `temporary` yang akan menyimpan `localtime(&times)` yang mengubah variable yang berisi waktu sekarang menjadi waktu lokal.
- Berikutnya, menggunakan `strftime` yang *mengassign* variable `timenow` dengan value dari variable `temporary` dengan format yang diminta yaitu `"%Y-%m-%d_%H:%M:%S"`
- Kemudian menggunakan kondisi `if (pid2 == 0) ` yang menjadi kondisi untuk menjalankan child process telah berhasil dan dapat menjalankan proses berikutnya
- Lalu kita mendefinisikan `*argv[]` dengan tipe data char yang berisi arguments yang akan digunakan dalam `execv` yaitu disini adalah `{"mkdir", timenow, NULL}`
- Pada akhirnya, menggunakan `execv` untuk menjalankan program untuk membuat (`directory`) dengan menggunakan directory dari `mkdir` yaitu `"/usr/bin/mkdir"` dan sesuai dengan isi dari variable `timenow` 
- Pada akhirnya, `execv` harus diakhiri dengan `NULL` dan program dapat dijalankan. Karena diminta untuk membuat setiap 40 detik, maka menggunakan `sleep(40)` pada akhir while.

#### Output :

#### 3. b)

