#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include "alpha.h"

wchar_t alphabet[]=L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

int verifAlphaNum(wchar_t* texte) {
	//Verification caractere speciaux
	wchar_t caractSpe[]= L",;:!§/.?()_-[]|}{0123456789";
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

int alphaNum(wchar_t caract) {
	for (int i=0; i < wcslen(alphabet); i++) {
		if (caract == alphabet[i]) {
			return i%26;
		}
	}
}

void convertAccents(wchar_t* texte, wchar_t* message) {
	int i = 0;
	while (texte[i] != '\0') {
		int num = dansAlphabet(texte[i]);
		if (num!=-1) {
			message[i] = alphabet[num];
		}else {
			switch(texte[i]) {
				case L'à':
					message[i]=L'a';
					break;
				case L'â':
					message[i]=L'a';
					break;
				case L'ä':
					message[i]=L'a';
					break;
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
				case L'î':
					message[i]=L'i';
					break;
				case L'ï':
					message[i]=L'i';
					break;
				case L'ô':
					message[i]=L'o';
					break;
				case L'ö':
					message[i]=L'o';
					break;
				case L'ù':
					message[i]=L'u';
					break;
				case L'û':
					message[i]=L'u';
					break;
				case L'ü':
					message[i]=L'u';
					break;
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
