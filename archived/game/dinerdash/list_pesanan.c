#include "list_pesanan.h"
# include <stdio.h>

List MakeList(){
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
	List L;
	for (IdxType i=0;i<MaxEl;i++){
		L.A[i].ID = Mark;
		L.A[i].durasi = Mark;
		L.A[i].harga = Mark;
		L.A[i].ketahanan = Mark;
	}
	return L;
}

boolean IsEmpty(List L){
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
	return(L.A[0].ID == Mark);
}

Makanan Get(List L, IdxType i){
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
	return L.A[i];
}

void Set(List *L, IdxType i, Makanan v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
	L->A[i] = v;
}

int Length(List L){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
	int len = 0;
	IdxType i = 0;
	while(L.A[i].ID != Mark && i<MaxEl){
		len++;
		i++;
	}
	return len;
}

IdxType FirstIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
	IdxType p = 0;
	while (L.A[p].ID == Mark) {
		p++;
	}
	return p;
}

IdxType LastIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	return(Length(L) - 1);
}

boolean IsIdxValid (List L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
	return(i >= FirstIdx(L) && i < MaxEl);
}

boolean IsIdxEff (List L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	return (i >= FirstIdx(L) && i <= LastIdx(L));
}

void Search(List L, Makanan X, IdxType* index){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen dengan ID sesuai dengan ID X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	boolean found = 0;
	IdxType i = FirstIdx(L);
	while(i <= LastIdx(L) && !found){
		if(L.A[i].ID == X.ID){
			found = 1;
		}
		else{
			i++;
		}
	}
	if (found)	{
		*index = i;
	}
	else	{
		*index = InvalidIdx;
	}
}

void InsertFirst(List *L, Makanan X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
	L->A[0] = X;
}

void InsertAt(List *L, Makanan X, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
	//L->A[Length(*L)+1].ID = Mark;
	CreateMark(L, Length(*L)+1);
	IdxType q = Length(*L);
	while(q>i){
		L->A[q] = L->A[q-1];
		q--;
	}
	L->A[i] = X;
}

void InsertLast(List *L, Makanan X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
	L->A[Length(*L)] = X;
}

void DeleteFirst(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
	DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
	IdxType q = LastIdx(*L);
	while(i<q){
		L->A[i] = L->A[i+1];
		i++;
	}
	CreateMark(L, q);
}

void DeleteLast(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
	//L->A[LastIdx(*L)] = Mark;
	CreateMark(L, LastIdx(*L));
}

List Concat(List L1, List L2){
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
	List L3 = MakeList();
	IdxType p = LastIdx(L1);
	for(IdxType i=0;i<=p;i++){
		L3.A[i] = L1.A[i];
	}
	p++;
	for(IdxType j=0;j<=LastIdx(L2);j++){
		L3.A[p] = L2.A[j];
		p++;
	}
	return L3;
}

void CreateMark(List *L, IdxType i)	{
	L->A[i].durasi = Mark;
	L->A[i].ID = Mark;
	L->A[i].harga = Mark;
	L->A[i].ketahanan = Mark;
}

void delete_zero_durability(List *L)	{
	int i = FirstIdx(*L);
	while (i <= LastIdx(*L))	{
		while (L->A[i].ketahanan == 0)	{
			DeleteAt(L, i);
		}
		i++;
	}
}