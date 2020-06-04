#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include "cesar.h"

/*Procédure qui chiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle, passé en paramètre,
le résultat est copié dans la chaîne de caractère messCode*/
void cesarChiffrage(wchar_t* message, wchar_t* messCode, int cle) {
	for (int i=0; i < wcslen(message); i++) {
		if ((L'a'<=message[i]) && (L'z'>=message[i])) {
			messCode[i]=L'a'+((message[i]-L'a')+cle)%26;
		} else if (message[i] == ' ') {
                        messCode[i]=' ';
                } else {
			messCode[i]=L'A'+((message[i]-L'A')+cle)%26;
		}
	}
}

/*Procédure qui déchiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle, passé en paramètre,
le résultat est copié dans la chaîne de caractère messCode*/
void cesarDechiffrage(wchar_t* message, wchar_t* messCode, int cle) {
	for (int i=0; i < wcslen(message); i++) {
                if ((L'a'<=message[i]) && (L'z'>=message[i])) {
                        messCode[i]=L'a'+((message[i]-L'a')-cle+2600)%26; //+2600 sert à avoir une valeur positive dans le cas d'une grosse clé
                } else if (message[i] == ' ') {
			messCode[i]=' ';
		} else {
                        messCode[i]=L'A'+((message[i]-L'A')-cle+2600)%26;
                }
        }
}
