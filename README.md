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
  ### void cesarDechiffrage(wchar_t* message, wchar_t* messCode, int cle);
   Procédure qui déchiffre le message, passé en paramètre, en décalant chaque caractère de la valeur de la cle, passé en paramètre
   Le résultat est copié dans la chaîne de caractère messCode.
   
   
