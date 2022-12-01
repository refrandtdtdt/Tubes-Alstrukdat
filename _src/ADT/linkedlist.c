#include "linkedlist.h"

/* PROTOTYPE */
/****************** TEST ListPoint KOSONG ******************/
boolean IsEmptyListPoint (ListPoint L)
{
	return First(L) == Null;
}
/* Mengirim true jika ListPoint kosong */

/****************** PEMBUATAN ListPoint KOSONG ******************/
void CreateEmptyListPoint (ListPoint *L)
{
	First(*L) = Null;
    Last(*L) = Null;
}
/* I.S. sembarang             */
/* F.S. Terbentuk ListPoint kosong */

/****************** Manajemen Memori ******************/
ADDRESS AlokasiPoint (Point X)
{
	ADDRESS P = (ADDRESS)malloc(sizeof(ElmtListPoint));
	if(P!=Null)
	{
		Info(P)=X;
        Index(P)=-1;
		Next(P)=Null;
		return P;
	}
	else
	{
		return Null;
	}
}
/* Mengirimkan ADDRESS hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka ADDRESS tidak Null, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Null */
/* Jika alokasi gagal, mengirimkan Null */
void DeAlokasiPoint (ADDRESS *P)
{
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian ADDRESS P */

/****************** PENCARIAN SEBUAH ELEMEN ListPoint ******************/
ADDRESS SearchPoint (ListPoint L, Point X)
{
	ADDRESS P = First(L);
	while(P!=Null)
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
/* Jika ada, mengirimkan ADDRESS elemen tersebut. */
/* Jika tidak ada, mengirimkan Null */

/****************** PRIMITIF BERDASARKAN NullAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListPoint *L, Point X)
{
	ADDRESS P = AlokasiPoint(X);
	if(P!=Null)
	{
		Next(P) = First(*L);
		First(*L) = P;
        if(Last(*L)==Null)
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
/* menambahkan elemen pertama dengan Nullai X jika alokasi berhasil */
void InsVLast (ListPoint *L, Point X)
{
	ADDRESS loc = First(*L);
	ADDRESS P = AlokasiPoint(X);
	if(P!=Null)
	{
		if(loc == Null)
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
/* berNullai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListPoint *L, Point *X)
{
	ADDRESS del = First(*L);
	First(*L) = Next(del);
	*X = Info(del);
	Next(del) = Null;
	DeAlokasiPoint(&del);
    if(First(*L)==Null){
        Last(*L)=Null;
    }
}
/* I.S. ListPoint L tidak kosong  */
/* F.S. Elemen pertama ListPoint dihapus: Nullai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListPoint *L, Point *X)
{
	ADDRESS P = First(*L);
	ADDRESS loc = Null;
	while(Next(P)!=Null)
	{
		loc = P;
		P = Next(P);
	}
	*X = Info(P);
	if(loc == Null)
	{
		First(*L) = Null;
        Last(*L) = Null;
	}
	else
	{
		Next(loc) = Null;
        Last(*L) = loc;
	}
	DeAlokasiPoint(&P);
}
/* I.S. ListPoint tidak kosong */
/* F.S. Elemen terakhir ListPoint dihapus: Nullai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (ListPoint *L, ADDRESS P)
// {
// 	Next(P) = First(*L);
// 	First(*L) = P;
// }
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-ADDRESS P sebagai elemen pertama */
// void InsertAfter (ListPoint *L, ADDRESS P, ADDRESS Prec)
// {
// 	Next(P) = Next(Prec);
// 	Next(Prec) = P;
// }
// /* I.S. Prec pastilah elemen ListPoint dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void InsertLast (ListPoint *L, ADDRESS P)
// {
// 	if(IsEmpty(*L))
// 	{
// 		First(*L) = P;
// 	}
// 	else 
// 	{
// 		ADDRESS loc = First(*L);
// 		while(Next(loc)!=Null)
// 		{
// 			loc = Next(loc);
// 		}
// 		Next(loc) = P;
// 	}
// }
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (ListPoint *L, ADDRESS *P)
// {
// 	*P = First(*L);
// 	First(*L) = Next(*P);
// 	Next(*P) = Null;
// }
/* I.S. ListPoint tidak kosong */
/* F.S. P adalah alamat elemen pertama ListPoint sebelum penghapusan */
/*      Elemen ListPoint berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListPoint *L, Point X)
{
	ADDRESS del = SearchPoint(*L,X);
	ADDRESS	P = First(*L);
	if(del!=Null)
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
			Next(del) = Null;
            if(del == Last(*L)){
                Last(*L) = P;
            }
			DeAlokasiPoint(&del);			
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListPoint berADDRESS P, dengan info(P)=X  */
/* Maka P dihapus dari ListPoint dan di-dealokasi */
/* Jika tidak ada elemen ListPoint dengan info(P)=X, maka ListPoint tetap */
/* ListPoint mungkin menjadi kosong karena penghapusan */
// void DelLast (ListPoint *L, ADDRESS *P)
// {
// 	*P = First(*L);
// 	ADDRESS loc = Null;
// 	while(Next(*P)!=Null)
// 	{
// 		loc = *P;
// 		*P = Next(*P);
// 	}
// 	if(loc == Null)
// 	{
// 		First(*L) = Null;
// 	}
// 	else
// 	{
// 		Next(loc) = Null;
// 	}
// }
/* I.S. ListPoint tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListPoint sebelum penghapusan  */
/*      Elemen ListPoint berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
// void DelAfter (ListPoint *L, ADDRESS *Pdel, ADDRESS Prec)
// {
// 	*Pdel = Next(Prec);
// 	Next(Prec) = Next(*Pdel);
// 	Next(*Pdel) = Null;
// }
/* I.S. ListPoint tidak kosong. Prec adalah anggota ListPoint  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListPoint yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListPoint ******************/
void PrintInfo (ListPoint L)
{
	ADDRESS P = First(L);
	printf("[");
	while(P!=Null)
	{
		printf("%d", Absis(Info(P)));
        printf(",%d", Ordinat(Info(P)));
		if(Next(P)!=Null)
		{
			printf(",");
		}
		P = Next(P);
	}
	printf("]");
}
/* I.S. ListPoint mungkin kosong */
/* F.S. Jika ListPoint tidak kosong, iai ListPoint dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNullai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListPoint kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtListPoint (ListPoint L)
{
	ADDRESS P = First(L);
	int ctr = 0;
	while(P!=Null)
	{
		ctr++;
		P = Next(P);
	}
	return ctr;
}
/* Mengirimkan banyaknya elemen ListPoint; mengirimkan 0 jika ListPoint kosong */