#include <malloc.h>
#include "spheapsort.h"
#include "spstack.h"
#include "spqueue.h"

void CreateTree (BinTree *BT)
{
	Root(*BT) = Nil;
}

nodeTree CreateNode (int X)
{
	nodeTree N = (nodeTree) malloc (sizeof (ElmtTree));
	if (N != NULL)
	{
		Info(N) = X;
		Left(N) = NULL;
		Right(N) = NULL;
	}
	else
	{
		printf("Alokasi Gagal!");
	}
	return N;
}

void InsertNode (BinTree *BT, int X)
{
	QueueList Q;
	CreateQueueList (&Q);
	nodeTree temp, isi;
	if (Root(*BT) == Nil)
	{
		Root(*BT) = CreateNode(X);
		return;
	}
	Enqueue (&Q, Root(*BT));
	while (First(Q) != Nil)
	{
		temp = Address(First(Q));
		Dequeue (&Q, &isi);
		
		if (Left(temp) != Nil)
		{
			Enqueue(&Q, Left(temp));
		}
		else
		{
			Left(temp) = CreateNode(X);
			LastChild(*BT) = Left(temp);
			return;
		}
		
		if (Right(temp) != Nil)
		{
			Enqueue(&Q, Right(temp));
		}
		else
		{
			Right(temp) = CreateNode(X);
			LastChild(*BT) = Right(temp);
			return;
		}
	}
}

void AscHeapSort (BinTree *BT, StackList *S)
{
	while (Root(*BT) != Nil)
	{
		BuildMaxHeap(&(Root(*BT)));
		DeleteNode(&(*BT), &(*S));
	}
}

void DescHeapSort (BinTree *BT, StackList *S)
{
	while (Root(*BT) != Nil)
	{
		BuildMinHeap(&(Root(*BT)));
		DeleteNode(&(*BT), &(*S));
	}
}


void BuildMaxHeap (nodeTree *node)
{
	if (*node == Nil) return;
	BuildMaxHeap(&(Left(*node)));
	BuildMaxHeap(&(Right(*node)));
	MaxHeapify(&(*node));
}

void BuildMinHeap (nodeTree *node)
{
	if (*node == Nil) return;
	BuildMinHeap(&(Left(*node)));
	BuildMinHeap(&(Right(*node)));
	MinHeapify(&(*node));
}

void MaxHeapify (nodeTree *node)
{
	nodeTree largestNode;
	int largest;
	
	largest = Info(*node);
	largestNode = *node;
	if (Left(*node) != Nil && Info(Left(*node)) > largest)
	{
		largest = Info(Left(*node));
		largestNode = Left(*node);
	}
	
	if (Right(*node) != Nil && Info(Right(*node)) > largest)
	{
		largest = Info(Right(*node));
		largestNode = Right(*node);
	}
	
	if (largestNode != *node)
	{
		Swap(&(Info(*node)), &(Info(largestNode)));
	}
}

void MinHeapify (nodeTree *node)
{
	nodeTree smallestNode;
	int smallest;
	
	smallest = Info(*node);
	smallestNode = *node;
	if (Left(*node) != Nil && Info(Left(*node)) < smallest)
	{
		smallest = Info(Left(*node));
		smallestNode = Left(*node);
	}
	
	if (Right(*node) != Nil && Info(Right(*node)) < smallest)
	{
		smallest = Info(Right(*node));
		smallestNode = Right(*node);
	}
	
	if (smallestNode != *node)
	{
		Swap(&(Info(*node)), &(Info(smallestNode)));
	}
}

void DeleteNode (BinTree *BT, StackList *S)
{
	nodeTree temp, del;
	if (Root(*BT) == LastChild(*BT))
	{
		Push (&(*S), Info(Root(*BT)));
		del = Root(*BT);
		Root(*BT) = Nil;
		LastChild(*BT) = Nil;
		free(del);
		return;
	}
	Swap (&(Info(Root(*BT))), &(Info(LastChild(*BT))));
	del = LastChild(*BT);
	temp = FindParent (Root(*BT), del);
	if (Left(temp) == LastChild(*BT))
	{
		Left(temp) = Nil;
		LastChild(*BT) = temp;
	} 
	if (Right(temp) == LastChild(*BT))
	{
		Right(temp) = Nil;
		LastChild(*BT) = Left(temp);
	}
	Push (&(*S), Info(del));
	free(del);
}

void Swap (int *info1, int *info2)
{
	int temp;
	temp = *info1;
	*info1 = *info2;
	*info2 = temp;
}

void PrintInfo (StackList *S)
{
	int isi;
	while (Top(*S) != Nil)
	{
		Pop (&(*S), &isi);
		printf("%d ", isi);
	}
}

nodeTree FindParent (nodeTree path, nodeTree search)
{
	nodeTree parent;
	if (path == Nil) return Nil;
	if (Left(path) == search || Right(path) == search) return path;
	parent = FindParent (Left(path), search);
	if (parent != Nil) return parent;
	return FindParent (Right(path), search);
}
