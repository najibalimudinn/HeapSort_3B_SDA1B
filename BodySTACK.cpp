/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spstack.h"
#include "spheapsort.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean StackListEmpty (StackList L)
/* Mengirim true jika List Kosong */
{
	 return (Top(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateStackList (StackList * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 Top(*L) = Nil;
	 Bottom(*L) = Nil;
}

/**** Manajemen Memory ****/
nodeStack Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 nodeStack P;
	 /* Algoritma */
	 P = (nodeStack) malloc (sizeof (SElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Num(P) = X;
	Down(P) = Nil;
	Up(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (nodeStack P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

void InsVLast (StackList * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	nodeStack P;
	 /* Algoritma */
	P = Alokasi (X);
	if (P != Nil)
	{	InsertLast (&(*L), P);		}
}

void DelVLast (StackList * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	nodeStack PDel;
	 /* Algoritma */
	PDel = Bottom(*L);
	DelLast (&(*L), &PDel);
	(*X) = Num(PDel);
	DeAlokasi (PDel);
}

void InsertLast (StackList * L, nodeStack P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	/* Algoritma */
	if (Top(*L) != Nil)
	{
		 Down(Bottom(*L)) = P;
		 Up(P) = Bottom(*L);
		 Bottom(*L) = P;
	}
		else
	{	
		Top(*L) = P;
		Bottom(*L) = P;
	}
}

void DelLast (StackList * L, nodeStack * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Algoritma */
	if (Up(*P) == Nil)	/* Hanya 1 elemen */
	{	
		Top(*L) = Nil;
		Bottom(*L) = Nil;
	}
	else	/* List Lebih dari 1 elemen */
	{	
		Bottom(*L) = Up(*P);
		Down(*P) = Nil;
		Up(*P) = Nil;
	}
}

void Push (StackList * L, infotype X)
{
	InsVLast(&(*L), X);
}

void Pop (StackList * L, infotype *X)
{
	DelVLast(&(*L), &(*X));
}
