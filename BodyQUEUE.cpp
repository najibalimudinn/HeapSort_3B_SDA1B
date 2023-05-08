/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
// #include "spheapsort.h"
// #include "spstack.h"
#include "spqueue.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
bool QueueListEmpty (QueueList L)
/* Mengirim true jika List Kosong */
{
	 return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateQueueList (QueueList * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
	 Last(*L) = Nil;
}

/**** Manajemen Memory ****/
nodeQueue AlokasiQueue (nodeTree X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 nodeQueue P;
	 /* Algoritma */
	 P = (nodeQueue) malloc (sizeof (QElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Address(P) = X;
	Next(P) = Nil;
	Prev(P) = Nil;
	 }
	 return (P);
}

void DeAlokasiQueue (nodeQueue P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (QueueList * L, nodeTree X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	nodeQueue P;
	 /* Aloritma */
	P = AlokasiQueue (X);
	if (P != Nil)
	{	InsertFirst (&(*L), P);		}
}


void DelVLastQueue (QueueList * L, nodeTree * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	nodeQueue PDel;
	 /* Algoritma */
	PDel = Last(*L);
	DelLastQueue (&(*L), &PDel);
	(*X) = Address(PDel);
	DeAlokasiQueue (PDel);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (QueueList * L, nodeQueue P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	 if(First(*L) == Nil)
	 {	
	 	Last(*L) = P;
		First(*L) = P;	
	 }
	 else 
	 {	
	 	Next(P) = First(*L);
	 	Prev(First(*L)) = P;	 
	 	First(*L) = P;
	 }
}


void DelLastQueue (QueueList * L, nodeQueue * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Algoritma */
	if (Prev(*P) == Nil)	/* Hanya 1 elemen */
	{	
		First(*L) = Nil;
		Last(*L) = Nil;
	}
	else	/* List Lebih dari 1 elemen */
	{	
		Last(*L) = Prev(*P);
		Next(*P) = Nil;
		Prev(*P) = Nil;
	}
}


void Enqueue (QueueList * L, nodeTree X)
{
	InsVFirst (&(*L), X);
}

void Dequeue (QueueList * L, nodeTree * X)
{
	DelVLastQueue (&(*L), &(*X));
}

