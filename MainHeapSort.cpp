#include "tampilan.h"

#define MAXSIZE 100

int main()
{
	char opsi, hb[15];
	char message[] = "Inputkan jumlah pemain dan nilai akhir pemain, program akan mengurutkan nilai akhir pemain.";
    int speed = 100; // 0.1 detik
	int batas,tes[MAXSIZE];
	start:
	ReadAwal(hb); 
	opsi = GetAwal(hb);

		switch (opsi)
		{
		case 'A': // penjelasan
			DisplayAwal();
			printf("\n\n");
			typewriter(message, speed);
			goto start;
			break;

		case 'B': // mulai
			Mulai(batas, tes);
			break;
			default: printf("\n\nMasukkan Tidak Valid");
         	 getch();
         	 goto start;
         	 break;
		}
	
	return 0;
}
