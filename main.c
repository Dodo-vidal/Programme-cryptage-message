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
	
	//Affichage du nom du programme
	wprintf(L"\n							**************************************\n");
	wprintf(L"							*    Chiffrage de messages secrets   *\n");
	wprintf(L"							**************************************\n\n");
	wprintf(L"                                                      Assurez-vous d'être à l'abris des regards !\n\n\n\n");
	
	wprintf(L"Veuillez saisir votre message secret :\n");
	wchar_t texte[2000];
	fgetws(texte, 2000, stdin); //Enregistrement du texte saisi au clavier
	getchar();
	
	//Tant que le texte saisi au clavier contient des caractères spéciaux, il doit être ressaisi
	int correct = verifAlphaNum(texte);
	while (correct ==-1) {
		wprintf(L"Message incorrect, il ne doit pas contenir de ponctuation\n\nRessaisissez votre message :\n");
		fgetws(texte, 2000, stdin);
		correct = verifAlphaNum(texte);
	}
	
	wchar_t message[2000];//Tableau de caractères qui contiendra le texte désaccentué
	convertAccents(texte, message);//élimination des caractères accentué
	
	wchar_t messCode[2000];//Tableau de caractères qui contiendra le message chiffré ou déchiffré
	
	wprintf(L"Choisissez la méthode de chiffrement : César[1], Vigenère[2]\n");
	int choix;
	wscanf(L"%d", &choix);
	getchar();
	
	//Dans le cas où l'utilisateur à choisi la méthode de César
	if (choix == 1) {
		int cle;
		choix=0;

		wprintf(L"Saississez la clé de codage :\n");
		wscanf(L"%d", &cle);
		getchar();
		
		wprintf(L"Voulez-vous chiffrer[1] ou déchiffrer[2] le message ?\n");
	   	wscanf(L"%d", &choix);
		getchar();
		
		//Dans le cas où l'utilisateur à choisi de chiffrer le message
        	if (choix == 1) {
			cesarChiffrage(message, messCode, cle);
			wprintf(L"Message chiffré:\n%ls\n", messCode);
		//Dans le cas où l'utilisateur à choisi de déchiffrer le message
		} else if (choix == 2) {
			cesarDechiffrage(message, messCode, cle);
			wprintf(L"Message déchiffré:\n%ls\n", messCode);
		}
	}
	//Dans le cas où l'utilisateur à choisi la méthode de Vigenère
	else if (choix == 2) {
		wchar_t charCle[200];//clé en caractères qui sera saisie au clavier
		int tabCle[200];//clé en valeur numérique
		choix=0;

	        wprintf(L"Saisissez la clé de codage (sans espaces) :\n");
       		wscanf(L"%ls", &charCle);
		cleVigenere(message, charCle, tabCle);//la cle en caractères est transformé en entiers
		
		wprintf(L"Voulez-vous chiffrer[1] ou déchiffrer[2] le message ?\n");
		wscanf(L"%d", &choix);
		getchar();
		
		//Dans le cas où l'utilisateur à choisi de chiffrer le message
		if (choix == 1) {
            		vigenereChiffrage(message, messCode, tabCle);
            		wprintf(L"Message chiffré:\n%ls\n", messCode);
		//Dans le cas où l'utilisateur à choisi de déchiffrer le message
        	} else if (choix == 2) {
            		vigenereDechiffrage(message, messCode, tabCle);
           		wprintf(L"Message déchiffré:\n%ls\n", messCode);
        	}
	}

	//Enregistrement du traitement de cryptage dans le fichier resultat.txt
	FILE* fichier;
	fichier = fopen("resultat.txt", "w+");
	if (fichier!= NULL) {
		fwprintf(fichier, L"Le résultat du traitement est :\n%ls", messCode);
		fclose(fichier);
		wprintf(L"\n\nRetrouvez le résultat du chiffrement/déchiffrement dans le fichier resultat.txt\n\n\n\n");
	}else {
		wprintf(L"\nErreur : le résultat du traitement n'a pas pu être copié dans le fichier resultat.txt\nIl s'affiche néanmoins au-dessus\n\n");
	}
}
