#ifndef spheapsort_H
#define spheapsort_H
#include "spstack.h"
#include "spqueue.h"
#include <stdbool.h>
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Root(B) (B).root
#define LastChild(B) (B).lastChild

const char *namaFile = "riwayat.txt";
typedef struct tElmtTree *nodeTree;
typedef struct tElmtTree {
	int info;
	nodeTree left;
	nodeTree right;
} ElmtTree;

typedef struct {
	nodeTree root;
	nodeTree lastChild;
} BinTree;


void CreateTree (BinTree *BT);

nodeTree CreateNode (int X);

void InsertNode (BinTree *BT, int X);

void AscHeapSort (BinTree *BT, StackList *S);

void DescHeapSort (BinTree *BT, StackList *S);

void BuildMaxHeap (nodeTree *node);

void BuildMinHeap (nodeTree *node);

void MaxHeapify (nodeTree *node);

void MinHeapify (nodeTree *node);

void DeleteNode (BinTree *BT, StackList *S);

void Swap (int *info1, int *info2);

void PrintInfo(BinTree *BT, StackList *S);

nodeTree FindParent (nodeTree BT, nodeTree node);

void PrintTree (BinTree BT);

void riwayatSort( StackList *S);

void lihatRiwayatSort(const char *namaFile );



#endif
