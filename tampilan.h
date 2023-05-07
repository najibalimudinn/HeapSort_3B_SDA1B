#ifndef TAMPILAN_H
#define TAMPILAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include "boolean.h"
#include "spheapsort.h"
#include "spqueue.h"
#include "spstack.h"
#include "BodyQUEUE.C"
#include "BodySTACK.C"

void typewriter(const char *message, int speed); // animasi menegetik
void DisplayAwal(); // tampilan awal aplikasi
void ReadAwal(char HowBegin[15]); // variabel penampung dari tampilan awal
char GetAwal(char HowBegin[15]); 
void Mulai(int batas, int tes[]);
void PilihSort(BinTree *BT, Stacklist *S);


#endif
