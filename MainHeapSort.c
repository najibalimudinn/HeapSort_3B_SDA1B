#include "spheapsort.h"
#include "spqueue.h"
#include "spstack.h"
#include "BodyQUEUE.C"
#include "BodySTACK.C"
#include "BodyHeapSort.C"
#include <stdio.h>
#define MAXSIZE 100

int main()
{
	BinTree myTree;
	StackList sortedStack;
//	int tes[10] = {5, 2, 7, 4, 6, 1, 3, 9, 11, 10};
	int i,j,batas,tes[MAXSIZE];
	
	CreateTree (&myTree);
	CreateStackList (&sortedStack);
	
	printf("Input size Queue: ");
	scanf("%d", &batas);
	
	printf("Info Queue: ");
	for(j=0;j<batas;j++){
		scanf("%d", &tes[j]);
		printf("Queue dengan info %d telah diinsert", tes[j]);
	}
	
	for (i=0;i<batas;i++)
	{
		InsertNode (&myTree, tes[i]);
	}
	
	DescHeapSort (&myTree, &sortedStack);
	printf("Data Terurut: ");
	PrintInfo (&sortedStack);
	
	return 0;
}
