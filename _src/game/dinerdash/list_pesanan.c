#include "list_pesanan.h"
# include <stdio.h>

ListPesanan MakeListPesanan(){
/* I.S. sembarang */
/* F.S. Terbentuk listPesnaListPesanan L kosong dengan kapasitas MaxEl */
	ListPesanan L;
	for (IdxType i=0;i<MaxEl;i++){
		L.A[i].ID = Mark;
		L.A[i].durasi = Mark;
		L.A[i].harga = Mark;
		L.A[i].ketahanan = Mark;
	}
	return L;
}

boolean IsEmptyPesanan(ListPesanan L){
/* Mengirimkan true jika listPesnaListPesanan L kosong, mengirimkan false jika tidak */
	return(L.A[0].ID == Mark);
}

Makanan GetPesanan(ListPesanan L, IdxType i){
/* Prekondisi : listPesnaListPesanan tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen listPesnaListPesanan yang ke-i */
	return L.A[i];
}

void SetPesanan(ListPesanan *L, IdxType i, Makanan v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
	L->A[i] = v;
}

int LengthPesanan(ListPesanan L){
/* Mengirimkan banyaknya elemen efektif listPesnaListPesanan */
/* Mengirimkan nol jika listPesnaListPesanan kosong */
	int len = 0;
	IdxType i = 0;
	while(L.A[i].ID != Mark && i<MaxEl){
		len++;
		i++;
	}
	return len;
}

IdxType FirstIdxPesanan(ListPesanan L){
/* Prekondisi : listPesnaListPesanan L tidak kosong */
/* Mengirimkan indeks elemen pertama */
	IdxType p = 0;
	while (L.A[p].ID == Mark) {
		p++;
	}
	return p;
}

IdxType LastIdxPesanan(ListPesanan L){
/* Prekondisi : listPesnaListPesanan L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	return(LengthPesanan(L) - 1);
}

boolean IsIdxValidPesanan (ListPesanan L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran listPesnaListPesanan */
/* yaitu antara indeks yang terdefinisi untuk container*/
	return(i >= FirstIdxPesanan(L) && i < MaxEl);
}

boolean IsIdxEffPesanan (ListPesanan L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk listPesnaListPesanan */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	return (i >= FirstIdxPesanan(L) && i <= LastIdxPesanan(L));
}

void SearchPesanan(ListPesanan L, Makanan X, IdxType* index){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen dengan ID sesuai dengan ID X di dalam listPesnaListPesanan */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	boolean found = 0;
	IdxType i = FirstIdxPesanan(L);
	while(i <= LastIdxPesanan(L) && !found){
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

void InsertFirstPesanan(ListPesanan *L, Makanan X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
	L->A[0] = X;
}

void InsertAtPesanan(ListPesanan *L, Makanan X, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
	//L->A[Length(*L)+1].ID = Mark;
	CreateMark(L, LengthPesanan(*L)+1);
	IdxType q = LengthPesanan(*L);
	while(q>i){
		L->A[q] = L->A[q-1];
		q--;
	}
	L->A[i] = X;
}

void InsertLastPesanan(ListPesanan *L, Makanan X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
	L->A[LengthPesanan(*L)] = X;
}

void DeleteFirstPesanan(ListPesanan *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
	DeleteAtPesanan(L, 0);
}

void DeleteAtPesanan(ListPesanan *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
	IdxType q = LastIdxPesanan(*L);
	while(i<q){
		L->A[i] = L->A[i+1];
		i++;
	}
	CreateMark(L, q);
}

void DeleteLastPesanan(ListPesanan *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
	//L->A[LastIdx(*L)] = Mark;
	CreateMark(L, LastIdxPesanan(*L));
}

ListPesanan ConcatPesanan(ListPesanan L1, ListPesanan L2){
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah ListPesanan yang merupakan gabungan dari L1 dan L2 */
	ListPesanan L3 = MakeListPesanan();
	IdxType p = LastIdxPesanan(L1);
	for(IdxType i=0;i<=p;i++){
		L3.A[i] = L1.A[i];
	}
	p++;
	for(IdxType j=0;j<=LastIdxPesanan(L2);j++){
		L3.A[p] = L2.A[j];
		p++;
	}
	return L3;
}

void CreateMark(ListPesanan *L, IdxType i)	{
	L->A[i].durasi = Mark;
	L->A[i].ID = Mark;
	L->A[i].harga = Mark;
	L->A[i].ketahanan = Mark;
}

void delete_zero_durability(ListPesanan *L)	{
	int i = FirstIdxPesanan(*L);
	while (i <= LastIdxPesanan(*L))	{
		while (L->A[i].ketahanan == 0)	{
			DeleteAtPesanan(L, i);
		}
		i++;
	}
}