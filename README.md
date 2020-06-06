# Programme-cryptage-message
Ce petit programme permet de crypter/décrypter des messages avec les méthodes de César ou Vigenère

# Programmeurs
Fahmida Feizal: https://github.com/Papillon1028 et Dorian Vidal: https://github.com/Dodo-vidal

# Language utilisé
Exclusivement le C

# Réalisation
Nous avons réalisé ce programme pour un projet informatique lors de notre 1ère année en DUT informatique à l'université Paul Sabatier

# Utilisation :
 ## Lancer le programme
    1) Téléchargez l'archive
    2) Ouvrez la console à l'emplacement du dossier décompressé
    3) Exécutez la commande "make" afin de compilé les fichiers
    4) Lancez le programme en tapant "./main"
    
 ## Crypter un message
    1) Saisissez votre message à cryper lorque le programme vous le demande (ne doit pas contenir de caractères spéciaux, ni de chiffres : ?./§!:;,('"]@^\`|[012345689, etc)
    2) Choisissez la méthode de chiffrement : 
      - Tapez 1 pour la méthode de César 
      - Tapez 2 pour la méthode de Vigenère
    3) Sasissez la clé de chiffrement : 
      - un nombre pour César 
      - une chaine de caractères (sans espaces et sans caractères accentués) pour Vigenère
    4) Tapez 1 pour choisir le cryptage
    5) Votre message crypter s'affiche
    6) Vous pouvez récupéré le message dan sle fichier "resultat.txt"
    
 ## Décrypter un message
    1) Saisissez votre message à cryper lorque le programme vous le demande (ne doit pas contenir de caractères spéciaux, ni de chiffres : ?./§!:;,('"]@^\`|[012345689, etc)
    2) Choisissez la méthode de déchiffrement : 
      - Tapez 1 pour la méthode de César 
      - Tapez 2 pour la méthode de Vigenère
    3) Saisissez la clé de déchiffrement :
      - un nombre pour César 
      - une chaine de caractères (sans espaces et sans caractères accentués) pour Vigenère
    4) Tapez 2 pour choisir le décryptage
    5) Votre message décrypté s'affiche
    6) Vous pouvez récupéré le message dan sle fichier "resultat.txt"

# Fonctions et procédures
 ## Fichier alpha.c
  ### int verifAlphaNum(wchar_t* texte);
   Fonction qui vérifie si le texte passé en paramètre contient des caractères spéciaux
   - retourne -1 si un caractère du texte est égal à un caractère spécial
   - retourne 1 sinon.
  ### int dansAlphabet(wchar_t caractere);
   Fonction qui vérifie si le caratère passé en paramètre est dans le tableau "alphabet" 
   - si le caractère est dans le tableau, la fonction renvoie le compteur i
   - sinon renvoie la valeur -1.
  ### int alphaNum(wchar_t caract);
   Fonction qui renvoie le rang du caractere, passé en paramètre, dans l'alphabet de la langue française.
  ### void convertAccents(wchar_t* texte, wchar_t* message);
   Procédure qui copie le texte, passé en paramètre, dans le message, passé en paramètre,
   en remplacent les caractères accentués par leur équivalent sans accent.
   
 ## Fichier cesar.c
  ### void cesarChiffrage(wchar_t* message, wchar_t* messCode, int cle);
   Procédure qui chiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle, passé en paramètre.
   Le résultat est copié dans la chaîne de caractère messCode.
   - si le caractère est entre "a" et "z", il est décalé de la valeur de la clé modulo 26
   - sinon si le caractère est un espace " ", le caractère est juste remplacé par un espace " "
   - sinon le caractère est compris entre "A" et "Z", il est décalé de la valeur de la clé modulo 26.
  ### void cesarDechiffrage(wchar_t* message, wchar_t* messCode, int cle);
   Procédure qui déchiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle, passé en paramètre
   Le résultat est copié dans la chaîne de caractère messCode.
   - si le caractère est entre "a" et "z", il est décalé de la valeur négative de la clé + 2600 (afin d'évité une valeur négative) modulo 26
   - sinon si le caractère est un espace " ", le caractère est juste remplacé par un espace " "
   - sinon le caractère est compris entre "A" et "Z", il est décalé de la valeur négative de la clé + 2600 (afin d'évité une valeur négative) modulo 26.
   
 ## Fichier vigenere.c
  ### void cleVigenere(wchar_t* message, wchar_t* charCle, int* tabCle);
   Procédure qui transforme la clé de caractères: charCle, en un tableau d'entiers: tabCle
   - chaque caractère est remplacé par son rang dans l'alphabet
   - la clé est répété tout le long du message
   - si le message contient un espace, le tableau tabCle contiendra un 0 au même endroit afin d'éviter un décalage sur le caractère " ".
   - Cas d'erreur : si la clé saisi contient un caractère espace.
  ### void vigenereChiffrage(wchar_t* message, wchar_t* messCode, int* tabCle);
   Procédure qui chiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle situé à la même position.
   Le résultat est copié dans la chaîne de caractère messCode
  ### void vigenereDechiffrage(wchar_t* message, wchar_t* messCode, int* tabCle);
   Procédure qui déchiffre le message, passé en paramètre, en décalant chaque caractère de la valeur négative de la cle situé à la même position.
   Le résultat est copié dans la chaîne de caractère messCode.
   
 ## Fichier void main();
  - Affichage du nom du programme
  - Demande de saisi du texte à l'utilisateur
  - Tant que le texte saisi contient des carctères spéciaux (appel de la fonction verifAlphaNum()), la saisie est redemandé à l'utilisateur
  - Demande choix de la méthode de chiffrement entre César et Vigenère
  - si l'utilisateur tape 1 : 
    - Demande de saisir la clé
    - Demande choix entre chiffrer ou déchiffrer le message
    - si l'utilisateur tape 1 : appel de la fonction cesarChiffrage()
    - si l'utilisateur tape 2 : appel de la fonction cesarDechiffrage()
  - sinon si l'utilisateur tape 2 :
    - Demande de saisir la clé
    - Demande choix entre chiffrer ou déchiffrer le message
    - si l'utilisateur tape 1 : appel de la fonction vigenereChiffrage()
    - si l'utilisateur tape 2 : appel de la fonction vigenereDechiffrage()
  - le message codé ou décodé est enregistré dans le fichier "resultat.txt"
    A chaque exécution du programme le fichier est écrasé.
    
  ### Cas d'erreurs : si l'utilisateur saisi un caractère autre que 1 ou 2 lors des choix
