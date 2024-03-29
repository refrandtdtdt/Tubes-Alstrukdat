#ifndef COMMAND_H
#define COMMAND_H

/*Spesifikasi Command*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "boolean.h"
# include "ADT/functions.h"
# include "ADT/queue_modif.h"
# include "ADT/array_modif.h"
# include "ADT/stack_modif.h"
# include "ADT/stack_history.h"
# include "ADT/mesinkar.h"
# include "ADT/mesinkata_modif.h"
# include "ADT/map_scoreboard.h"
# include "game/dinerdash/dinerdash.h"
# include "game/game_kartu/main_game_card.h"
# include "game/GameToH/GameToH.h"
# include "game/snakeonmeteor/snakeonmeteor.h"
# include "game/Hangman/hangman.h"
# include "game/ourlovestory/our_love_story.h"

void Help();
/* memberikan bantuan untuk tiap-tiap command
I.S. Sembarang
F.S. Mencetak bantuan-bantuan sesuai input
*/

void Quit();
/*
perintah untuk mengeluarkan program
I.S. Sembarang
F.S. mengakhiri program ketika input QUIT diberikan
*/
// void Start()
// {
//     Load()
// }

void Load(char *filename, TabGame *list, ScoreBoardList *scores, StackHistory *history, boolean init);
/*
Perintah untuk membaca save file yang ingin dibuka oleh user
I.S. Sembarang
F.S. Jika terdapat save file sesuai nama file masukan user, maka akan membaca save file tersebut. Jika tidak,
     maka akan mengeluarkan pesan bahwa tidak dapa tmenemukan save file tersebut
*/

void Save(char* filename, TabGame list, ScoreBoardList scores, StackHistory history);
/*
Perintah untuk menyimpan state pemain saat ini ke dalam sebuah file
I.S. Sembarang
F.S. 
*/

void buatgame (TabGame *T); 
/*
prosedur ini akan membaca masukkan nama game yang ingin ditambahkan ke dalam Binomo
I.S Sembarang
F.S Game berhasil ditambahkan ke dalam array game yang tersedia 
Apabila game yg ditambahkan sudah ada di dalam array game sebelumnya maka game tidak ditambahkan kembali
*/

void ListGame (TabGame T);
/* proses : menuliskan list atau daftar game yang terdapat dalam Binomo */
/* I.S T boleh kosong */
/* F.S Jika T tidak kosong indeks dan nama game ditulis berderet ke bawah
Contoh output
1. RNG 
2. LUNCH SLOW
3. DINOSAUR IN EARTH */
/* Jika T kosong : Hanya Menulis "Tidak ada game yang tersimpan "*/

void HapusGame();
/*I.S Tab terdefinisi dan tidak kosong */
/*F.S elemen game ke-i dihapus dari tab game sesuai dengan keinginan user*/
/*Syarat penghapusan game: 
- Game yang dapat dihapus hanyalah game yang dibuat secara custom sendiri oleh user
- Lima Game pertama yang terdapat dlaam file konfigurasi (game default) tidak dapat dihapus 
- Game yang berada dalam queue game (antrian game) tidak dapat dihapus */

void tambahAntrianGame (TabGame daftar_game, Queue * antrian_game);
/*
Prosedur ini akan membaca masukan game yang akan ditambahkan user ke dalam antrian game
I.S. Sudah tersedia daftar game dan antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila masukan masih di dalam rentang nomor game di dalam daftar game, maka game dengan nomor game sesuai
                masukan akan masuk ke antrian game
     Kondisi 2) Apabila masukan di luar rentang, akan mengeluarkan pesan kesalahan dan user akan diminta untuk input
                masukan lagi sampai masukan valid
*/

void mainkanGame (Queue * antrian_game, ScoreBoardList *scores, StackHistory *history);
/*
Prosedur ini akan langsung memainkan game yang terletak pada antrian pertama pada antrian game
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila game dalam antrian pertama bisa dimainkan, maka akan mengeluarkan output sedang loading 
                game, lalu memainkan game. Game yang dimainkan akan dikeluarkan dari atrian game
     Kondisi 2) Apabila game dalam antrian pertama tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan
                output bahwa tidak bisa memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari
                antrian game
Note : apabila antrian game kosong, akan mengeluarkan output bahwa belum ada game dalam antrian dan cara memasukkan
       game ke dalam antrian
*/

void lewatiGame (Queue * antrian_game, int jumlah_skip, StackHistory *history, ScoreBoardList *scores);
/*
Prosedur ini akan melewati sebanyak <jumlah_skip> game, game yang dilewati akan dikeluarkan dari antrian game,
lalu langsung memainkan game yang terletak pada antrian pertama pada antrian game setelah game-game tadi dilewati
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila <jumlah_skip> tidak melebihi jumlah antrian game dan game dalam antrian pertama setelah
                skip bisa dimainkan, maka akan mengeluarkan output sedang loading game, lalu memainkan game.
                Game yang dimainkan akan dikeluarkan dari antrian game
     Kondisi 2) Apabila <jumlah_skip> tidak melebihi jumlah antrian game dan game dalam antrian pertama setelah
                skip tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan output bahwa tidak bisa
                memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari antrian game
     Kondisi 3) Apabila <jumlah_skip> sama atau melebihi jumlah antrian game, maka semua game dalam antrian akan
                dikeluarkan dari antrian game, lalu menampilkan pesan bahwa tidak ada permainan lagi dalam antrian
                game  
Asumsi : <jumlah_skip> sudah pasti valid setelah memanggil prosedur ini (<jumlah_skip> >= 0) 
Note : apabila antrian game kosong, akan mengeluarkan output bahwa belum ada game dalam antrian dan cara memasukkan
       game ke dalam antrian
*/

void GameTambahan(ScoreBoard * scoreboard);
/*
Perintah untuk memainkan game di mana langsung masuk ke tahap game over dengan langsung mengeluarkan skor akhir berupa
integer random
I.S. Sembarang
F.S. Mengeluarkan output angka random
*/

void RNG(ScoreBoard * scoreboard);
/*
Perintah untuk memainkan game RNG di mana sistem akan menentukan angka acak, lalu pemain akan diberikan kesempatan untuk
menebak angka tersebut. Sistem akan memberitahu apakah angka tebakan lebih besar atau lebih kecil dari angka random sistem
I.S. Sembarang
F.S. Dikeluarkan output tentang tebakan dari pemain dan skornya
*/

void resetHistory(StackHistory *stackHistory);

void showHistory(int parameter, StackHistory stackHistory);

void ResetScores(ScoreBoardList *scores);

void showScoreBoard(ScoreBoardList scores, int jumlahGame);

#endif