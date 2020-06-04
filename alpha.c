#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include "alpha.h"

wchar_t alphabet[]=L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

/*Fonction qui vérifie si le texte passé en paramètre contient des caractères spéciaux
-retourne -1 si un caractère du texte est égal à un caractère spécial
- retourne 1 sinon*/
int verifAlphaNum(wchar_t* texte) {
	wchar_t caractSpe[]= L",;:!§/.?()_-[]|}{0123456789"; // liste des caractères spéciaux
	int i=0;
	while (texte[i]!=L'\0') {
		for(int j=0; j<26; j++) {
			if (texte[i] == caractSpe[j]) {
				return -1;
			}
		}
		i+=1;
	}
	return 1;
}

/*Fonction qui vérifie si le caratère passé en paramètre est dans le tableau "alphabet" 
si le caractère est dans l'alphabet, la fonction renvoie le compteur i
sinon -1*/
int dansAlphabet(wchar_t caractere) {
	int i=0;
	while (alphabet[i] != '\0') {
		if (caractere == alphabet[i]) {
			return i;
		}
		i+=1;
	}
	return -1;
}

/*Fonction qui renvoie le rang du caractere, passé en paramètre, dans l'alphabet français*/
int alphaNum(wchar_t caract) {
	for (int i=0; i < wcslen(alphabet); i++) {
		if (caract == alphabet[i]) {
			return i%26;
		}
	}
}

/*Procédure qui copie le texte, passé en paramètre, dans le message, passé en paramètre, 
en remplacent les caractères accentués par leur équivalent sans accent*/
void convertAccents(wchar_t* texte, wchar_t* message) {
	int i = 0;
	while (texte[i] != '\0') {
		int num = dansAlphabet(texte[i]);
		if (num!=-1) {
			message[i] = alphabet[num];
		}else {
			switch(texte[i]) {
				//Pour les accents de "a"
				case L'à':
					message[i]=L'a';
					break;
				case L'â':
					message[i]=L'a';
					break;
				case L'ä':
					message[i]=L'a';
					break;
				//Pour les accents de "e"
				case L'é' :
					message[i]=L'e';
					break;
				case L'ê':
					message[i]=L'e';
					break;
				case L'è':
					message[i]=L'e';
					break;
				case L'ë':
					message[i]=L'e';
					break;
				//Pour les accents de "i"
				case L'î':
					message[i]=L'i';
					break;
				case L'ï':
					message[i]=L'i';
					break;
				//Pour les accents de "o"
				case L'ô':
					message[i]=L'o';
					break;
				case L'ö':
					message[i]=L'o';
					break;
				//Pour les accents de "u"
				case L'ù':
					message[i]=L'u';
					break;
				case L'û':
					message[i]=L'u';
					break;
				case L'ü':
					message[i]=L'u';
					break;
				//Pour les accents de "y"
				case L'ŷ':
					message[i]=L'y';
					break;
				case L'ÿ':
					message[i]=L'y';
					break;
			}
		}
		i+=1;
	}
}
