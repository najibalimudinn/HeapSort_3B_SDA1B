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

    printf("/ $$   /$$                                /$$$$$$                        /$$    \n");
    printf("| $$  | $$                               /$$__  $$                      | $$    \n");
    printf("| $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$ | $$  \\__/  /$$$$$$   /$$$$$$  /$$$$$$  \n");
    printf("| $$$$$$$$ /$$__  $$ |____  $$ /$$__  $$|  $$$$$$  /$$__  $$ /$$__  $$|_  $$_/  \n");
    printf("| $$__  $$| $$$$$$$$  /$$$$$$$| $$  \\ $$ \\____  $$| $$  \\ $$| $$  \\__/  | $$    \n");
    printf("| $$  | $$| $$_____/ /$$__  $$| $$  | $$ /$$  \\ $$| $$  | $$| $$        | $$ /$$\n");
    printf("| $$  | $$|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$/|  $$$$$$/| $$        |  $$$$/\n");
    printf("|__/  |__/ \\_______/ \\_______/| $$____/  \\______/  \\______/ |__/         \\___/  \n");
    printf("                              | $$                                              \n");
    printf("                              | $$                                              \n");
    printf("                              |__/    \n\n");
}

void ReadAwal(char HowBegin[15])
{
    DisplayAwal();
    printf("                    Ketik 'mulai' atau 'penjelasan': ");
    scanf(" %[^\n]%*c", HowBegin);
    for(int i=0;i<strlen(HowBegin);i++){
        HowBegin[i] = tolower(HowBegin[i]);
    }
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
    DisplayAwal();
    BinTree myTree;
	StackList sortedStack;
    int i, j;

    CreateTree(&myTree); // membuat tree kosong
	CreateStackList(&sortedStack); // membuat list kosong
	
	printf("\n\nInputkan jumlah bilangan: ");
	scanf("%d", &batas);
	
	for(j=0;j<batas;j++){
	printf("Nilai bilangan ke-%d: ", j+1);
		scanf("%d", &tes[j]);
		InsertNode(&myTree, tes[j]);
		printf("**Bilangan %d telah diinsert**\n\n\n", tes[j]);
	}

	system("pause");
	

    PilihSort(&myTree, &sortedStack);
}

void PilihSort(BinTree *BT, StackList *S)
{
	char opsi;
	system("cls");
	start:
	DisplayAwal();
	printf("\n\nData: ");
	PrintTree(*BT);
	printf("\n\n==================================");
	
	printf("\n\nUrut berdasarkan: \n");
	printf("1. Ascending\n");
	printf("2. Descending\n\n");
	printf("Pilihan: ");
	scanf(" %c", &opsi);
	
	if (opsi == '1')
	{
		system("cls");
		DisplayAwal();
		printf("\n\nData: ");
		PrintTree(*BT);
		printf("\n\n==================================");
		AscHeapSort (&(*BT), &(*S));
		riwayatSort(&(*S));
		PrintInfo(&(*BT), &(*S));	
	}
	else if (opsi == '2')
	{
		system("cls");
		DisplayAwal();
		printf("\n\nData: ");
		PrintTree(*BT);
		printf("\n\n==================================");
		DescHeapSort (&(*BT), &(*S));
		riwayatSort(&(*S));
		PrintInfo(&(*BT), &(*S));
	}
	else
	{
		printf("\n\nMasukkan tidak valid!");
		getch();
		goto start;
	}
	LastMenu(&(*BT), &(*S));
}

void LastMenu (BinTree *BT, StackList *S) {
	char opsi;
	start:
	system("cls");
	DisplayAwal();
	printf("\n\nData: ");
	PrintTree(*BT);
	printf("\n\n==================================");
	printf("\n\nMenu: \n");
	printf("1. Urutkan lagi\n");
	printf("2. Tambahkan bilangan\n");
	printf("3. Keluar\n\n");
	printf("Pilihan: ");
	scanf(" %c", &opsi);
	
	if (opsi == '1')
	{
		PilihSort(&(*BT), &(*S));	
	}
	else if (opsi == '2')
	{
		int inp, batas, j;
		system("cls");
		DisplayAwal();
		printf("\n\nInputkan jumlah bilangan: ");
		scanf("%d", &batas);
	
		for(j=0;j<batas;j++){
			printf("Nilai bilangan ke-%d: ", j+1);
			scanf("%d", &inp);
			InsertNode(&(*BT), inp);
			printf("Bilangan %d telah diinsert\n\n", inp);
		}

		system("pause");
		PilihSort(&(*BT), &(*S));
	}
	else if (opsi == '3')
	{
		exit(0);
	}
	else
	{
		printf("\n\nMasukkan tidak valid!");
		getch();
		goto start;
	}
}
