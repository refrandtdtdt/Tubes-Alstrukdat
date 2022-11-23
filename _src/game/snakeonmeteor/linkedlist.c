#include "linkedlist.h"

/* PROTOTYPE */
/****************** TEST LISTSNAKE KOSONG ******************/
boolean IsEmptySnake (ListSnake L)
{
	return First(L) == Nil;
}
/* Mengirim true jika listSnake kosong */

/****************** PEMBUATAN LISTSNAKE KOSONG ******************/
void CreateEmptySnake (ListSnake *L)
{
	First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk listSnake kosong */

/****************** Manajemen Memori ******************/
address AlokasiSnake (Point X)
{
	address P = (address)malloc(sizeof(ElmtListSnake));
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
void DealokasiSnake (address *P)
{
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LISTSNAKE ******************/
address SearchSnake (ListSnake L, Point X)
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
/* Mencari apakah ada elemen listSnake dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListSnake *L, Point X)
{
	address P = AlokasiSnake(X);
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
void InsVLast (ListSnake *L, Point X)
{
	address loc = First(*L);
	address P = AlokasiSnake(X);
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
/* menambahkan elemen listSnake di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListSnake *L, Point *X)
{
	address del = First(*L);
	First(*L) = Next(del);
	*X = Info(del);
	Next(del) = Nil;
	DealokasiSnake(&del);
    if(First(*L)==Nil){
        Last(*L)=Nil;
    }
}
/* I.S. ListSnake L tidak kosong  */
/* F.S. Elemen pertama listSnake dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListSnake *L, Point *X)
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
	DealokasiSnake(&P);
}
/* I.S. listSnake tidak kosong */
/* F.S. Elemen terakhir listSnake dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (ListSnake *L, address P)
// {
// 	Next(P) = First(*L);
// 	First(*L) = P;
// }
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
// void InsertAfter (ListSnake *L, address P, address Prec)
// {
// 	Next(P) = Next(Prec);
// 	Next(Prec) = P;
// }
// /* I.S. Prec pastilah elemen listSnake dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void InsertLast (ListSnake *L, address P)
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
// void DelFirst (ListSnake *L, address *P)
// {
// 	*P = First(*L);
// 	First(*L) = Next(*P);
// 	Next(*P) = Nil;
// }
/* I.S. ListSnake tidak kosong */
/* F.S. P adalah alamat elemen pertama listSnake sebelum penghapusan */
/*      Elemen listSnake berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListSnake *L, Point X)
{
	address del = SearchSnake(*L,X);
	address	P = First(*L);
	if(del!=Nil)
	{
		if(del==First(*L))
		{
			First(*L) = Next(del);
			DealokasiSnake(&del);
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
			DealokasiSnake(&del);			
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen listSnake beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari listSnake dan di-dealokasi */
/* Jika tidak ada elemen listSnake dengan info(P)=X, maka listSnake tetap */
/* ListSnake mungkin menjadi kosong karena penghapusan */
// void DelLast (ListSnake *L, address *P)
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
/* I.S. ListSnake tidak kosong */
/* F.S. P adalah alamat elemen terakhir listSnake sebelum penghapusan  */
/*      Elemen listSnake berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
// void DelAfter (ListSnake *L, address *Pdel, address Prec)
// {
// 	*Pdel = Next(Prec);
// 	Next(Prec) = Next(*Pdel);
// 	Next(*Pdel) = Nil;
// }
/* I.S. ListSnake tidak kosong. Prec adalah anggota listSnake  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen listSnake yang dihapus  */

/****************** PROSES SEMUA ELEMEN LISTSNAKE ******************/
void PrintInfo (ListSnake L)
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
/* I.S. ListSnake mungkin kosong */
/* F.S. Jika listSnake tidak kosong, iai listSnake dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika listSnake kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtSnake (ListSnake L)
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
/* Mengirimkan banyaknya elemen listSnake; mengirimkan 0 jika listSnake kosong */