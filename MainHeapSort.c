#include "spheapsort.h"
#include "spqueue.h"
#include "spstack.h"
#include <stdio.h>

int main()
{
	BinTree myTree;
	StackList sortedStack;
	int tes[10] = {5, 2, 7, 4, 6, 1, 3, 9, 11, 10};
	int i;
	
	CreateTree (&myTree);
	CreateStackList (&sortedStack);
	
	for (i=0;i<10;i++)
	{
		InsertNode (&myTree, tes[i]);
	}
	
	DescHeapSort (&myTree, &sortedStack);
	printf("Data Terurut: ");
	PrintInfo (&sortedStack);
	
	return 0;
}
