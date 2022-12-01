#include "arrPoint.h"
# include <stdio.h>

ArrPoint MakeArrPoint(){
/* I.S. sembarang */
/* F.S. Terbentuk arrPesnaArrPoint L kosong dengan kapasitas MaxElPoint */
	ArrPoint L;
	for (int i=0;i<MaxElPoint;i++){
		Absis(L.A[i]) = -99;
		Ordinat(L.A[i]) = -99;
	}
	return L;
}

void SetPoint(ArrPoint *L, int i, Point v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i berNullai v */
	L->A[i] = v;
}

int LengthPoint(ArrPoint L){
/* Mengirimkan banyaknya elemen efektif arrPesnaArrPoint */
/* Mengirimkan nol jika arrPesnaArrPoint kosong */
	int len = 0;
	int i = 0;
	while(Absis(L.A[i]) != -99 && i<MaxElPoint){
		len++;
		i++;
	}
	return len;
}

int LastIdxPoint(ArrPoint L){
/* Prekondisi : arrPesnaArrPoint L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	return(LengthPoint(L) - 1);
}

boolean SearchArrPoint(ArrPoint L, Point X){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen dengan ID sesuai dengan ID X di dalam arrPesnaArrPoint */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	boolean found = false;
	int i = 0;
	while(i <= LastIdxPoint(L) && !found){
		if(EQ(L.A[i],X)){
			found = true;
		}
		else{
			i++;
		}
	}
	return found;
}

void InsertLastPoint(ArrPoint *L, Point X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
	L->A[LengthPoint(*L)] = X;
}