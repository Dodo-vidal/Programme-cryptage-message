#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "alpha.h"
#include "cesar.h"
#include "vigenere.h"

void main() {
	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();
	system("clear");
	wprintf(L"\n							**************************************\n");
	wprintf(L"							*    Chiffrage de messages secrets   *\n");
	wprintf(L"							**************************************\n\n");
	wprintf(L"                                                      Assurez-vous d'être à l'abris des regards !\n\n\n\n");
	wprintf(L"Veuillez saisir votre message secret :\n");
	wchar_t texte[2000];
	fgetws(texte, 2000, stdin);
	getchar();
	int correct = verifAlphaNum(texte);
	while (correct ==-1) {
		wprintf(L"Message incorrect, il ne doit pas contenir de ponctuation\nRessaisissez votre message :\n");
		fgetws(texte, 2000, stdin);
		correct = verifAlphaNum(texte);
	}
	wchar_t message[2000];
	convertAccents(texte, message);
	wchar_t messCode[2000];
	wprintf(L"Choisissez la méthode de chiffrement : César[1], Vigenère[2]\n");
	int choix;
	wscanf(L"%d", &choix);
	getchar();
	if (choix == 1) {
		int cle;
		wprintf(L"Saississez la clé de codage :\n");
        	wscanf(L"%d", &cle);
		getchar();
		wprintf(L"Voulez-vous chiffrer[1] ou déchiffrer[2] le message ?\n");
	        wscanf(L"%d", &choix);
		getchar();
        	if (choix == 1) {
			cesarChiffrage(message, messCode, cle);
			wprintf(L"Message chiffré:\n%ls\n", messCode);
		} else if (choix == 2) {
			cesarDechiffrage(message, messCode, cle);
			wprintf(L"Message déchiffré:\n%ls\n", messCode);
		}
	}
	else if (choix == 2) {
		int tabCle[200];
		wchar_t charCle[200];
        	wprintf(L"Saisissez la clé de codage (au moins deux caractères) :\n");
       		wscanf(L"%ls", &charCle);
		cleVigenere(message, charCle, tabCle);
		wprintf(L"Voulez-vous chiffrer[1] ou déchiffrer[2] le message ?\n");
                wscanf(L"%d", &choix);
		getchar();
		if (choix == 1) {
                        vigenereChiffrage(message, messCode, tabCle);
                        wprintf(L"Message chiffré:\n%ls\n", messCode);
                } else if (choix == 2) {
                        vigenereDechiffrage(message, messCode, tabCle);
                        wprintf(L"Message déchiffré:\n%ls\n", messCode);
                }
	}
}
