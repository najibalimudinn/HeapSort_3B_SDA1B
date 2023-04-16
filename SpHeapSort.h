#ifndef spheapsort_H
#define spheapsort_H
#include "boolean.h"
#include "spstack.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Root(B) (B).root
#define LastChild(B) (B).lastChild

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

void PrintInfo (StackList S);

nodeTree FindParent (nodeTree BT, nodeTree node);

#endif
