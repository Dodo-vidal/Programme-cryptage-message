#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include "alpha.h"
#include "vigenere.h"

/*Procédure qui transforme la clé de caractères: charCle, en un tableau d'entiers: tabCle
	- chaque caractère est remplacé par son rang dans l'alphabet
	- la clé est répété tout le long du message
	- si le message contient un espace, le tableau tabCle contiendra un 0 au même endroit*/
void cleVigenere(wchar_t* message, wchar_t* charCle, int* tabCle) {
	int i;
	for (i=0; i < wcslen(message); i++) {
        for (int j=0; j < wcslen(charCle); j++) {
			if (message[i]==L' ') {
				tabCle[i]=0;
				j-=1;
			}else {
				tabCle[i]=alphaNum(charCle[j]);
			}
			i++;
		}
	}
}

/*Procédure qui chiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle situé à la même position,
le résultat est copié dans la chaîne de caractère messCode*/
void vigenereChiffrage(wchar_t* message, wchar_t* messCode, int* tabCle) {
	for (int i=0; i < wcslen(message); i++) {
                if ((L'a'<=message[i]) && (L'z'>=message[i])) {
                        messCode[i]=L'a'+((message[i]-L'a')+tabCle[i])%26;
                } else if (message[i] == ' ') {
                        messCode[i]=' ';
                } else {
                        messCode[i]=L'A'+((message[i]-L'A')+tabCle[i])%26;
                }
        }

}

/*Procédure qui déchiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle situé à la même position,
le résultat est copié dans la chaîne de caractère messCode*/
void vigenereDechiffrage(wchar_t* message, wchar_t* messCode, int* tabCle) {
	for (int i=0; i < wcslen(message); i++) {
                if ((L'a'<=message[i]) && (L'z'>=message[i])) {
                        messCode[i]=L'a'+((message[i]-L'a')-tabCle[i]+2600)%26;
                } else if (message[i] == ' ') {
                        messCode[i]=' ';
                } else {
                        messCode[i]=L'A'+((message[i]-L'A')-tabCle[i]+2600)%26;
                }
        }
}
