#ifndef MAP_SCOREBOARD_H
#define MAP_SCOREBOARD_H

#include "..\boolean.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

#define NIL 0
#define MaxMapEl 1000
#define mapUndef -9999

typedef char* keytype;
typedef int valuetype;
typedef int address;

typedef struct {
    keytype Key;
    valuetype Value;
} infotype;

typedef struct  {
    infotype el[MaxMapEl];
    address Count;
} ScoreMap;

typedef struct {
    char* game_name;
    ScoreMap board;
} ScoreBoard;
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxMapEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map mapUndef */
void CreateBoardEmpty(ScoreMap *M);

/* Mengirim true jika ScoreMap M kosong*/
/* Ciri Map kosong : count bernilai NIL */
boolean IsBoardEmpty(ScoreMap M);

/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan mapUndef */
valuetype ValueScore(ScoreMap M, keytype k);

/* Menambahkan Elmt sebagai elemen ScoreMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
void InsertScore(ScoreMap *M, keytype k, valuetype v);

/* Menghapus Elmt dari SCoreMap M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
void DeleteScore(ScoreMap *M, keytype k);

/* Mengembalikan true jika k adalah member dari M */
boolean IsMemberScore(ScoreMap M, keytype k);


/* Mencetak Scoreboard sesuai game yang ada di list */
/* I.S. game dan M terdefinisi */
/* F.S. Mencetak Scoreboard */
void PrintBoard(ScoreMap M);

/* Mensortir M dengan descending*/
void sortScoreboard(ScoreMap *M);

/* Memprint papan skor dalam ArrScoreMap*/
void PrintScoreboard(ScoreBoard papanskor);

/*Me-reset papan skor*/
void ResetScoreboard(ScoreMap *papanskor);

/*Me-reset arr papan skor*/
void ResetArrayScore(ScoreBoard *sb);
#endif