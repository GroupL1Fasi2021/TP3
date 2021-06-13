#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>


int main() {

	//Variables stockage Disque
	BOOLEAN bSuccess;

	HANDLE hs = GetStdHandle(STD_OUTPUT_HANDLE);
	char espace[30];
	DWORD written = 0;
	DWORD lpSectorsPerCluster;
	DWORD lpBytesPerSector;
	DWORD lpFreeClusters;
	DWORD lpTotalClusters;

	//obtenir de l'espace disque pour le lecteur actuel

	bSuccess = GetDiskFreeSpace(
		/*Le répertoire racine du disque pour lequel les informations doivent être renvoyées.
		Si ce paramètre est NULL , la fonction utilise la racine du disque actuel.*/
		NULL,
		/*Un pointeur vers une variable qui reçoit le nombre de secteurs par cluster.*/
		&lpSectorsPerCluster,
		/*Un pointeur vers une variable qui reçoit le nombre d'octets par secteur.*/
		&lpBytesPerSector,
		/*Pointeur vers une variable qui reçoit le nombre total de clusters libres sur
		le disque qui sont disponibles pour l'utilisateur associé au thread appelant.*/
		&lpFreeClusters,
		/*Pointeur vers une variable qui reçoit le nombre total de clusters sur le disque disponibles*/
		&lpTotalClusters
	);

	//condition pour verifier les information du lecteur et apres Affichage
	if (!bSuccess) {
		//printf("Impossible d'obtenir les informations sur le lecteur. \n");
		exit(EXIT_FAILURE);
	}
	else {
		unsigned int uiKBPerCluster = lpBytesPerSector * lpSectorsPerCluster / 1024;

		//Affiche espace libre
		sprintf(espace, "%lf", (double)uiKBPerCluster * lpFreeClusters / 1024);
		char msg1[100] = "\nTP2 : NOTION DE PROCESSUS\n***************************\n\nVous disposez de : ";
		char msg2[50] = " Mo de stockage libre";
		WriteConsoleA(hs, msg1, strlen(msg1), &written, NULL);
		WriteConsoleA(hs, espace, strlen(espace), &written, NULL);
		WriteConsoleA(hs, msg2, strlen(msg2), &written, NULL);

		// Afiiche l'espace total disck
		sprintf(espace, "%lf", (double)uiKBPerCluster * lpTotalClusters / 1024);
		char msg3[50] = "\nStockage total en Mo est de : ";
		char l[100] = "\n___________________________________________________________________\n\n";
		WriteConsoleA(hs, l, strlen(l), &written, NULL);
		WriteConsoleA(hs, msg3, strlen(msg3), &written, NULL);
		WriteConsoleA(hs, espace, strlen(espace), &written, NULL);

	}

	//Temps Boucle
	//Variables
	DWORD timeLoop;
	char msgConsole[50];

	timeLoop = GetTickCount();
	int i, c = 0;
	for (i = 0; i < 1000000000; i++)
		c++;
	timeLoop = GetTickCount() - timeLoop;

	char msgBoucle[150] = "\n___________________________________________________________________\n\nBOUCLE FOR DE 0 A 1000000000\n\nCette boucle s'execute en : ";
	sprintf(msgConsole, "%d ms\n\n", timeLoop);

	if (hs != NULL && hs != INVALID_HANDLE_VALUE)
	{
		WriteConsoleA(hs, msgBoucle, strlen(msgBoucle), &written, NULL);
		WriteConsoleA(hs, msgConsole, strlen(msgConsole), &written, NULL);
	}

	//ID du processus courant
	DWORD processID = GetCurrentProcessId();
	char msgProcessID[150];
	sprintf(msgProcessID, "___________________________________________________________________\n\nL'ID du processus courant est: %d\n\n", processID);
	WriteConsoleA(hs, msgProcessID, strlen(msgProcessID), &written, NULL);

	//NOm utilisateur
	CHAR tchBuffer[256];
	// _ tcslen utilisé à la place de strlen
	DWORD dwBufferSize = strlen(tchBuffer);
	char msgUsername[200];
	if (GetUserNameA(tchBuffer, &dwBufferSize)) {
		sprintf(msgUsername, "___________________________________________________________________\n\nLe nom d'utilisateur est: %s\n\n", tchBuffer);
		WriteConsoleA(hs, msgUsername, strlen(msgUsername), &written, NULL);
	}
	else {
		WriteConsoleA(hs, "Impossible d'acquérir le nom d'utilisateur. \n", 50, &written, NULL);
		exit(EXIT_FAILURE);
	}


	char msgGroupe1[MAX_PATH] = "\nTRAVAIL REALISE PAR: \n\n1.\tBOFI NKAKA BOBY\n2.\tDIENDA KIMBUKU JAPHET\n3.\tKIRANDA BAKARI PAULIN\n4.\tKITOGA MIZUMBI MERVEILLE\n5.\tMAMBWE BAYEKWABO GRACE\n6.\tMPOVA LUZIZILA JAPHET\n7.\tMUANJI NGOYI DIVINE";
	char msgGroupe2[MAX_PATH] = "\n8.\tMUSONGELA GRACE DJARRIA\n9.\tNDAYE TSHIBUABUA MERVA\n10.\tNGALAMULUME KANU PRINCE\n11.\tNKOY ANGAL HARDY\n12.\tOMBE OLOKE BATISTA\n\n*******************************  MERCI *******************************";

	WriteConsoleA(hs, msgGroupe1, strlen(msgGroupe1), &written, NULL);
	WriteConsoleA(hs, msgGroupe2, strlen(msgGroupe2), &written, NULL);
	//c
	//Sleep(5000);
	system("pause");
	return 0;
}



