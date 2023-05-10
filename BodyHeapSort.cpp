#include <malloc.h> 
#include <stdio.h>  
#include <time.h>              
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


void PrintInfo(StackList *S)
{
    StackList tempStack;
    CreateStackList(&tempStack); // Buat stack sementara
    
    int isi;
    printf("\n\nData Terurut: ");
    while (!StackListEmpty(*S))
    {
        Pop(&(*S), &isi);
        Push(&tempStack, isi); // Simpan nilai dalam stack sementara
        printf("%d ", isi);
    }
    
    // Kembalikan nilai ke stack asli
    while (!StackListEmpty(tempStack))
    {
        Pop(&tempStack, &isi);
        Push(S, isi);
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

void PrintTree (BinTree BT)
{
	QueueList Q;
	CreateQueueList (&Q);
	nodeTree temp, isi;
	if (Root(BT) == Nil)
	{
		printf("**Data masih kosong!**");
		return;
	}
	printf("%d ", Info(Root(BT)));
	Enqueue (&Q, Root(BT));
	while (First(Q) != Nil)
	{
		temp = Address(First(Q));
		Dequeue (&Q, &isi);
		
		if (Left(temp) != Nil)
		{
			printf("%d ", Info(Left(temp)));
			Enqueue(&Q, Left(temp));
		}
		else
		{
			return;
		}
		
		if (Right(temp) != Nil)
		{
			printf("%d ", Info(Right(temp)));
			Enqueue(&Q, Right(temp));
		}
		else
		{
			return;
		}
	}
}

void riwayatSort(StackList *S)
{
    FILE *file;
    file = fopen("riwayat.txt", "a");
    int isi;
    
    if (file == NULL) {
        printf("Gagal membuka file.");
        return;  // Keluar dari program jika gagal membuka file
    }
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);

    //  komponen waktu
    int year = currentTime->tm_year + 1900; // Tahun (di-offset dengan 1900)
    int month = currentTime->tm_mon + 1;    // Bulan (di-offset dengan 1)
    int day = currentTime->tm_mday;         // Hari
    int hour = currentTime->tm_hour;        // Jam
    int minute = currentTime->tm_min;       // Menit
    int second = currentTime->tm_sec;       // Detik
    
    StackList tempStack;
    CreateStackList(&tempStack); // Buat stack sementara
    
    fprintf(file, "Waktu sort: %02d-%02d-%d %02d:%02d:%02d\n", day, month, year, hour, minute, second);
   
	
    while ( !StackListEmpty(*S))
    {
        Pop(S, &isi);
        Push(&tempStack, isi); // Simpan nilai dalam stack sementara
        fprintf(file, "Hasil sort: %d\n", isi);
       
    }
    fprintf(file, "\n");
    
    // Kembalikan nilai ke stack asli
    while (!StackListEmpty(tempStack))
    {
        Pop(&tempStack, &isi);
        Push(S, isi);
    }
    
    fclose(file);
}


