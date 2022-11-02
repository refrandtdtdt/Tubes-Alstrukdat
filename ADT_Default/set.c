/*
NIM : 18221161
Nama : Reyhan Putra Ananda
Tanggal : 30 Oktober 2022
Topik Praktikum : Set dan Map
Deskripsi : Implementasi set.h
*/

#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S) {
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S) {
    return (S.Count == 0);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S) {
    return (S.Count == MaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt) {
    if (IsEmpty(*S)) {
        (*S).Count++;
        (*S).Elements[0] = Elmt;
    } else { // !IsEmpty(*S)
        if (!IsMember(*S, Elmt)) {
            (*S).Count++;
            (*S).Elements[(*S).Count - 1] = Elmt;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt) {
    if (IsMember(*S, Elmt)) {
        if ((*S).Count == 1) {
            (*S).Count--;
        } else {
            int idxElmt;
            int i = 0;
            boolean found = false;
            while (i < (*S).Count && found == false) {
                if ((*S).Elements[i] == Elmt) {
                    idxElmt = i;
                    found = true;
                }
                i++;
            }
            int j = idxElmt;
            for (j; j < (*S).Count - 1; j++) {
                (*S).Elements[j] = (*S).Elements[j+1];
            }
            (*S).Count--;
        }
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt) {
    int i = 0;
    boolean found = false;
    while (i < S.Count && found == false) {
        if (S.Elements[i] == Elmt) {
            found = true;
        }
        i++;
    }
    return (found);
}
/* Mengembalikan true jika Elmt adalah member dari S */