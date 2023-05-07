#include "tampilan.h"

void typewriter(const char *message, int speed)
{
    system("cls");
    int len = strlen(message);

    for (int i = 0; i < len; i++)
    {
        putchar(message[i]);
        fflush(stdout);
        Sleep(speed); // jeda sesuai kecepatan yang diberikan
    }
}

void DisplayAwal()
{
    system("cls");

    printf("//$$   //$$                                //$$$$$$                        //$$    \n");
    printf("| $$  | $$                               //$$__  $$                      | $$    \n");
    printf("| $$  | $$  //$$$$$$   //$$$$$$   //$$$$$$ | $$  \__//  //$$$$$$   //$$$$$$  //$$$$$$  \n");
    printf("| $$$$$$$$ //$$__  $$ |____  $$ //$$__  $$|  $$$$$$  //$$__  $$ //$$__  $$|_  $$_//  \n");
    printf("| $$__  $$| $$$$$$$$  //$$$$$$$| $$  \ $$ \____  $$| $$  \ $$| $$  \__//  | $$    \n");
    printf("| $$  | $$| $$_____// //$$__  $$| $$  | $$ //$$  \ $$| $$  | $$| $$        | $$ //$$\n");
    printf("| $$  | $$|  $$$$$$$|  $$$$$$$| $$$$$$$//|  $$$$$$//|  $$$$$$//| $$        |  $$$$//\n");
    printf("|__//  |__// \_______// \_______//| $$____//  \______//  \______// |__//         \___//  \n");
    printf("                              | $$                                              \n");
    printf("                              | $$                                              \n");
    printf("                              |__//    \n");

    printf("                    Ketik 'mulai' atau 'penjelasan': ");
}

void ReadAwal(char HowBegin[15])
{
    DisplayAwal();
    scanf(" %[^\n]%*c", HowBegin);
}

char GetAwal(char HowBegin[15])
{
    char how[] = "penjelasan";
    char begin[] = "mulai";
    char result;
    if (strcmp(HowBegin, how) == 0)
    {
        result = 'A';
    }
    else if (strcmp(HowBegin, begin) == 0)
    {
        result = 'B';
    }
    else
    {
        result = 'C';
    }
    return (result);
}

void Mulai(int batas, int tes[]) {
    system("cls");
    BinTree myTree;
	StackList sortedStack;
    int i, j;

    CreateTree(&myTree); // membuat tree kosong
	CreateStackList(&sortedStack); // membuat list kosong
	
	printf("Inputkan jumlah pemain: ");
	scanf("%d", &batas);
	
	for(j=0;j<batas;j++){
	printf("Skor akhir: ");
		scanf("%d", &tes[j]);
		printf("Skor akhir %d telah diinsert\n\n", tes[j]);
	}
	
	for (i=0; i<batas; i++) {
		InsertNode(&myTree, tes[i]);
	}

    DescHeapSort (&myTree, &sortedStack);
	printf("\n\nData Terurut: ");
	PrintInfo (&sortedStack);
}
