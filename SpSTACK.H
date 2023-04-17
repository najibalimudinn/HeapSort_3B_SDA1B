/* File        : spNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#ifndef spstack_H
#define spstack_H
#include "boolean.h"
#include "spheapsort.h"
#include <stdio.h>
#define Nil NULL
#define Num(P) (P)->num
#define Down(P) (P)->down
#define Up(P) (P)->up
#define Top(L) (L).Top
#define Bottom(L) (L).Bottom

typedef int infotype;
typedef struct tSElmtList *nodeStack;
typedef struct tSElmtList {
	 infotype num;
	 nodeStack down;
	 nodeStack up;
	 } SElmtList;

/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct {
	  nodeStack Top;
	  nodeStack Bottom;
} StackList;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean StackListEmpty (StackList L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateStackList (StackList * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
nodeStack AlokasiStack (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlokasiStack (nodeStack P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVLast (StackList * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */


/**** Penghapusan Elemen ****/
void DelVLastStack (StackList * L, infotype * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */


/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertLast (StackList * L, nodeStack P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */



/**** Penghapusan sebuah elemen ****/
void DelLastStack (StackList * L, nodeStack * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void Push (StackList * L, infotype X);

void Pop (StackList * L, infotype * X);



#endif
