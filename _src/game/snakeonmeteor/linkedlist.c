#include "linkedlist.h"

/* PROTOTYPE */
/****************** TEST ListPoint KOSONG ******************/
boolean IsEmptyListPoint (ListPoint L)
{
	return First(L) == Nil;
}
/* Mengirim true jika ListPoint kosong */

/****************** PEMBUATAN ListPoint KOSONG ******************/
void CreateEmptyListPoint (ListPoint *L)
{
	First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk ListPoint kosong */

/****************** Manajemen Memori ******************/
address AlokasiPoint (Point X)
{
	address P = (address)malloc(sizeof(ElmtListPoint));
	if(P!=Nil)
	{
		Info(P)=X;
        Index(P)=-1;
		Next(P)=Nil;
		return P;
	}
	else
	{
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DeAlokasiPoint (address *P)
{
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN ListPoint ******************/
address SearchPoint (ListPoint L, Point X)
{
	address P = First(L);
	while(P!=Nil)
	{
		if(EQ(Info(P),X))
		{
			return P;
		}
		P = Next(P);
	}
	return P;
}
/* Mencari apakah ada elemen ListPoint dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListPoint *L, Point X)
{
	address P = AlokasiPoint(X);
	if(P!=Nil)
	{
		Next(P) = First(*L);
		First(*L) = P;
        if(Last(*L)==Nil)
        {
            Last(*L) = P;
        } else if(Last(*L)==First(*L))
        {
            Last(*L) = Next(First(*L));
        }
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListPoint *L, Point X)
{
	address loc = First(*L);
	address P = AlokasiPoint(X);
	if(P!=Nil)
	{
		if(loc == Nil)
		{
			First(*L) = P;
		}
		else
		{
			Next(Last(*L)) = P;
            Last(*L) = P;
		}
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListPoint di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListPoint *L, Point *X)
{
	address del = First(*L);
	First(*L) = Next(del);
	*X = Info(del);
	Next(del) = Nil;
	DeAlokasiPoint(&del);
    if(First(*L)==Nil){
        Last(*L)=Nil;
    }
}
/* I.S. ListPoint L tidak kosong  */
/* F.S. Elemen pertama ListPoint dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListPoint *L, Point *X)
{
	address P = First(*L);
	address loc = Nil;
	while(Next(P)!=Nil)
	{
		loc = P;
		P = Next(P);
	}
	*X = Info(P);
	if(loc == Nil)
	{
		First(*L) = Nil;
        Last(*L) = Nil;
	}
	else
	{
		Next(loc) = Nil;
        Last(*L) = loc;
	}
	DeAlokasiPoint(&P);
}
/* I.S. ListPoint tidak kosong */
/* F.S. Elemen terakhir ListPoint dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (ListPoint *L, address P)
// {
// 	Next(P) = First(*L);
// 	First(*L) = P;
// }
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
// void InsertAfter (ListPoint *L, address P, address Prec)
// {
// 	Next(P) = Next(Prec);
// 	Next(Prec) = P;
// }
// /* I.S. Prec pastilah elemen ListPoint dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void InsertLast (ListPoint *L, address P)
// {
// 	if(IsEmpty(*L))
// 	{
// 		First(*L) = P;
// 	}
// 	else 
// 	{
// 		address loc = First(*L);
// 		while(Next(loc)!=Nil)
// 		{
// 			loc = Next(loc);
// 		}
// 		Next(loc) = P;
// 	}
// }
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (ListPoint *L, address *P)
// {
// 	*P = First(*L);
// 	First(*L) = Next(*P);
// 	Next(*P) = Nil;
// }
/* I.S. ListPoint tidak kosong */
/* F.S. P adalah alamat elemen pertama ListPoint sebelum penghapusan */
/*      Elemen ListPoint berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListPoint *L, Point X)
{
	address del = SearchPoint(*L,X);
	address	P = First(*L);
	if(del!=Nil)
	{
		if(del==First(*L))
		{
			First(*L) = Next(del);
			DeAlokasiPoint(&del);
		}
        else
		{
			while(Next(P)!=del)
			{
				P = Next(P);
			}
			Next(P) = Next(del);
			Next(del) = Nil;
            if(del == Last(*L)){
                Last(*L) = P;
            }
			DeAlokasiPoint(&del);			
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListPoint beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari ListPoint dan di-dealokasi */
/* Jika tidak ada elemen ListPoint dengan info(P)=X, maka ListPoint tetap */
/* ListPoint mungkin menjadi kosong karena penghapusan */
// void DelLast (ListPoint *L, address *P)
// {
// 	*P = First(*L);
// 	address loc = Nil;
// 	while(Next(*P)!=Nil)
// 	{
// 		loc = *P;
// 		*P = Next(*P);
// 	}
// 	if(loc == Nil)
// 	{
// 		First(*L) = Nil;
// 	}
// 	else
// 	{
// 		Next(loc) = Nil;
// 	}
// }
/* I.S. ListPoint tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListPoint sebelum penghapusan  */
/*      Elemen ListPoint berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
// void DelAfter (ListPoint *L, address *Pdel, address Prec)
// {
// 	*Pdel = Next(Prec);
// 	Next(Prec) = Next(*Pdel);
// 	Next(*Pdel) = Nil;
// }
/* I.S. ListPoint tidak kosong. Prec adalah anggota ListPoint  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListPoint yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListPoint ******************/
void PrintInfo (ListPoint L)
{
	address P = First(L);
	printf("[");
	while(P!=Nil)
	{
		printf("%d", Absis(Info(P)));
        printf(",%d", Ordinat(Info(P)));
		if(Next(P)!=Nil)
		{
			printf(",");
		}
		P = Next(P);
	}
	printf("]");
}
/* I.S. ListPoint mungkin kosong */
/* F.S. Jika ListPoint tidak kosong, iai ListPoint dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListPoint kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtListPoint (ListPoint L)
{
	address P = First(L);
	int ctr = 0;
	while(P!=Nil)
	{
		ctr++;
		P = Next(P);
	}
	return ctr;
}
/* Mengirimkan banyaknya elemen ListPoint; mengirimkan 0 jika ListPoint kosong */