/* IMPORTATION DES MODULES */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


/* FONCTION JEU DU NOMBRE CACHE */
int nbrcache() {

  int VMAX;      /* VMAX -> borne supérieur de l'intervalle dans lequel le nombre caché est généré */
	bool victoire = false;
	int diff = 0;  /* diff selectionne la difficulté */
	int essaisr;   /* essaisr compte le nombre d'essais restants */
	int N;         /* N est le nombre caché */
	int EMAX;      /* EMAX -> le nombre d'essais maximum */
	int scorenc;   /* scorenc -> score de la partie */
	int prop;      /* prop designe la proposition faite par le joueur */
	char regles;   /* regles -> sert à définir si le joueur souhaite afficher les règles */
	

	do {   /* Verification de saisie et affichage des règles du jeu */
		printf("Voulez vous lire les règles ? (o/n)\n");
		while ( (getchar()) != '\n');
		regles = getchar();
		if (regles == 'o') {
			printf("Vous devez trouver un nombre caché dans un intervalle compris entre 1 et une valeur VMAX généré aléatoirement entre 100 et 500. Si vous choisissez la difficulté facile, la valeur de VMAX vous sera révelée. Sinon, vous n'aurez pas d'informations supplémentaires sur VMAX. Le but est de trouvé le nombre caché en utilisant le moins d'essais possible. Attention : le nombre d'essais est limité.\n\n");
		}
		else if (regles != 'o' && regles != 'n') {
			printf("Saisie invalide. Veuillez faire un choix entre 'o' pour afficher les règles et 'n' pour ne pas les afficher.\n");
		}
	}
	while (regles != 'o' && regles != 'n');

	srand(time(NULL));     /* Generation des variables aléatoires */
	VMAX = (rand() % (500-100+1) + 100);
	N = (rand() % (VMAX-1+1) + 1);

	do {     /* Choix de la difficulté */
		printf("Veuillez choisir une difficulté : Facile (1) ou Normale (2)\n");
		scanf("%d", &diff);
		if (diff != 1 && diff != 2) {
			printf("Saisie incorrecte. Veuillez saisir un chiffre entre 1 et 2.\n- - -\n");
		}
	}
	while (diff != 1 && diff != 2);

	if (diff == 1) {     /* Initialisation de EMAX selon la difficulté */
		EMAX = VMAX - (80 * VMAX / 100);
		essaisr = EMAX;
		printf("\nVous avez choisi la difficulté Facile. Nombre d'essais : %d", EMAX);
		printf("\n");
	}
	else {
		EMAX = VMAX - (50 * VMAX / 100);
		essaisr = EMAX;
		printf("\nVous avez choisi la difficulté Normale. Nombre d'essais : %d", EMAX);
		printf("\n");
	}

	while (victoire == false) {     /* JEU */
		printf("Nouvel essai. Essais restants : %d", essaisr);
		if (diff == 1) {
			printf("\nRappel : Vous cherchez un nombre entre 1 et %d", VMAX);
		}
		printf("\n");
		scorenc = EMAX - essaisr;
		essaisr = essaisr - 1;

		do {    /* Verification de saisie de la proposition */
			scanf("%d", &prop);
			if (prop <= 0 || prop > VMAX) {
				if (diff == 1) {
					printf("Saisie incorrecte. Veuillez saisir un nombre entier entre 1 et %d", VMAX);
					printf("\n");
				}
				else {
					printf("Saisie incorrecte. Veuillez saisir un nombre entier entre 1 et 500\n");
				}
			}
		}
		while (prop <= 0 || prop > VMAX);

		if (prop == N) {   /* Verification de la réponse */
			printf("Vous avez GAGNE ! Score : %d", scorenc);
			printf("\n");
			victoire = true;
		}
		else {
			printf("Mauvaise réponse ! \n \n");
			victoire = false;
		}
	}

	return scorenc;
}


/* FONCTION JEU DE LA SUITE MYSTERE */
int suitemyst() {

  int n = 10;          /* borne supérieure de l'intervalle dans lequel seront compris les variables générées aléatoirement */
  int a, b, c;         /* variables de la suite générées aléatoirement */
	int scoresm;         /* score de la partie */
  int Val1;            /* valeur de u1 */
  int Val2;            /* valeur de u2 */
  int Val3;            /* valeur de u3 */
  int Val4;            /* valeur de u4 */
  int res = 0;         /* res -> proposition de l'utilisateur */
  time_t debut, fin;   /* début et fin du chrono */
	int tempsfinal;      /* tempsfinal -> difference entre debut et fin pour calculer le temps mis pour terminer la partie */


  srand(time(NULL));     /* Variables aléatoires */
	a = (rand() % (n-1+1) + 1);
  b = (rand() % (n-1+1) + 1);
  c = (rand() % (n-1+1) +1);

  Val1 = c;               /* generation de u1 */
  Val2 = a * Val1 + b;    /* generation de u2 */
  Val3 = a * Val2 + b;    /* generation de u3 */
  Val4 = a * Val3 + b;    /* generation de u4 */

  printf("Les valeurs des 3 premiers termes sont : %d %d %d\n", Val1, Val2, Val3);
  printf("Veuillez saisir votre proposition pour le 4eme terme de la suite\n");
  debut = time(NULL);  /* debut du chrono */

	
  scanf("%d", &res);
  
  if(res == Val4){
		fin = time(NULL);   /* fin du chrono */
		tempsfinal = difftime(fin, debut);    /* calcul du temps mis pour terminer la partie */
  	printf("Félicitations vous avez trouvé, vous êtes le/la BOSS !\n");
		printf("Vous avez mis %d secondes pour trouver la réponse", tempsfinal);
	}
  else {
  	printf("Dommage vous avez perdu, vous n'êtes pas le/la BOSS...\n");
		fin = time(NULL);   /* fin du chrono */
		tempsfinal = 999999999;   /* tempsfinal vaut une valeur astronomique pour que le meilleur score de la session ne puisse pas être changé */
	}

	scoresm = tempsfinal;
	return scoresm;
}


/* FONCTION JEU DU MASTERMIND */
int mastermind() {

	int var1;		                  /* var1 -> entier aléatoire pour créér la combinaison */
	int essaisr = 10;             /* essaisr désigne le nombre d'essais restants */
	char lettre;                  /* lettre permet de générer une lettre aléatoire selon la valeur de var1 */
	char voy1, voy2, voy3, voy4;  /* voyelles de la combinaison */
	char rep1, rep2, rep3, rep4;  /* propositions du joueur */
	bool victoire = false;
	float scoremm;                /* scoremm -> score de la partie */
	time_t debut, fin;            /* debut et fin du chronomètre pour calculer le score */
	int tempsfinal;               /* tempsfinal -> différence entre la fin du chrono et le début pour calculer le temps de la partie */

	srand(time(NULL));

	do {
		for (int i = 0; i < 4; i++) {	/* GENERATION DES VARIABLES ALEATOIRES */

				var1 = (rand() % 5 + 1);	/* var1 genere un nombre entre 1 et 5*/
				switch (var1) {           /* chaque voyelle correspond à un entier */
					case 0:                 /* si var1=0 alors lettre='a' */
						lettre = 'a';
						break;
					case 1:                 /* si var1=1 alors lettre='e' */
						lettre = 'e';    
						break;
					case 2:                 /* si var1=2 alors lettre='i' */
						lettre = 'i';
						break;
					case 3:                 /* si var1=3 alors lettre='o' */
						lettre = 'o';
						break;
					case 4:                 /* si var1=4 alors lettre='u' */
						lettre = 'u';
						break;
					case 5:                 /* si var1=5 alors lettre='y' */
						lettre = 'y';
						break;
				}

				if (i == 0){            /* affectation de la lettre selon la valeur du compteur */
					voy1 = lettre;
				}
				else if (i == 1){
					voy2 = lettre;
				}
				else if (i == 2){
					voy3 = lettre;
				}
				else if (i == 3){
					voy4 = lettre;
				}
			
		}
	}
	while (voy1 == voy2 || voy1 == voy3 || voy1 == voy4 || voy2 == voy3 || voy2 == voy4 || voy3 == voy4);   /* on vérifie qu'une voyelle n'est pas utilisée deux fois */
			

	printf("L'ordinateur a généré aléatoirement une suite de 4 voyelles.\nVous avez jusqu'à 10 essais pour retrouver cette suite.\n\n");
	

	debut = time(NULL);  /* début du chrono */
	do {
		do {
			printf("\nProposition pour la 1e voyelle : ");
			while ( (getchar()) != '\n');
			rep1 = getchar();

			if (rep1 != 'a' && rep1 != 'e' && rep1 != 'i' && rep1 != 'o' && rep1 != 'u' && rep1 != 'y') {
				printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINUSCULES\n");
			}
		}
		while (rep1 != 'a' && rep1 != 'e' && rep1 != 'i' && rep1 != 'o' && rep1 != 'u' && rep1 != 'y');
		
		do {
			printf("Proposition pour la 2e voyelle : ");
			while ( (getchar()) != '\n');
			rep2 = getchar();

			if (rep2 != 'a' && rep2 != 'e' && rep2 != 'i' && rep2 != 'o' && rep2 != 'u' && rep2 != 'y') {
				printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINSUCULES\n");
			}
		}
		while (rep2 != 'a' && rep2 != 'e' && rep2 != 'i' && rep2 != 'o' && rep2 != 'u' && rep2 != 'y');
		
		do {
			printf("Proposition pour la 3e voyelle : ");
			while ( (getchar()) != '\n');
			rep3 = getchar();

			if (rep3 != 'a' && rep3 != 'e' && rep3 != 'i' && rep3 != 'o' && rep3 != 'u' && rep3 != 'y') {
				printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINSUCULES\n");
			}
		}
		while (rep3 != 'a' && rep3 != 'e' && rep3 != 'i' && rep3 != 'o' && rep3 != 'u' && rep3 != 'y');
		
		do {
			printf("Proposition pour la 4e voyelle : ");
			while ( (getchar()) != '\n');
			rep4 = getchar();

			if (rep4 != 'a' && rep4 != 'e' && rep4 != 'i' && rep4 != 'o' && rep4 != 'u' && rep4 != 'y') {
				printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINSUCULES\n");
			}
		}
		while (rep4 != 'a' && rep4 != 'e' && rep4 != 'i' && rep4 != 'o' && rep4 != 'u' && rep4 != 'y');
		
		if (rep1 == voy1) {   /* affichage du nombre de voyelles correctes et bien placée */
			printf("\nUne voyelle est correcte et bien placée");
		}
		else if (rep1 == voy2) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep1 == voy3) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep1 == voy4) {
			printf("\nUne voyelle est correcte mais mal placée");
		}

		if (rep2 == voy2) {
			printf("\nUne voyelle est correcte et bien placée");
		}
		else if (rep2 == voy1) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep2 == voy3) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep2 == voy4) {
			printf("\nUne voyelle est correcte mais mal placée");
		}

		if (rep3 == voy3) {
			printf("\nUne voyelle est correcte et bien placée");
		}
		else if (rep3 == voy2) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep3 == voy1) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep3 == voy4) {
			printf("\nUne voyelle est correcte mais mal placée");
		}

		if (rep4 == voy4) {
			printf("\nUne voyelle est correcte et bien placée");
		}
		else if (rep4 == voy2) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep4 == voy3) {
			printf("\nUne voyelle est correcte mais mal placée");
		}
		else if (rep4 == voy1) {
			printf("\nUne voyelle est correcte mais mal placée");
		}

		essaisr = essaisr - 1;

		if (rep1 == voy1 && rep2 == voy2 && rep3 == voy3 && rep4 == voy4){
			victoire = true;
		}
		else if (essaisr <= 0){
			break;
		}
	}
	while (victoire == false);

	fin = time(NULL);    /* fin du chrono */
	tempsfinal = difftime(fin, debut);   /* calcul du temps de la partie */

	if (victoire == true) {
		printf("\n\nBRAVO ! \nVous avez trouvé la combinaison du Mastermind en %d essais.\n", 10-essaisr);
		printf("Vous avez mis %d secondes à trouver la combinaison.\n\n", tempsfinal);
	}
	else if (victoire == false) {
		printf("\n\nVous avez perdu ! Vous ferez mieux la prochaine fois !\n");
	}

	scoremm = tempsfinal + (10-essaisr);  /* le score équivaut au nombre d'essais et au temps mis pour trouver la combinaison */
	return scoremm;
}


/* FONCTION MAIN */
int main() {
	int choix = 0;                         /* choix du jeu */
  int score;                             /* score retourné par les fonctions de jeu */
  int highscore_nb_cache = 0;            /* meilleur score du nombre caché */
	int highscore_suite_myst = 999999999;  /* meilleur score de la suite mystère */
	int highscore_mastermind = 999999999;  /* meilleur score du mastermind */
  char reponse;                          /* réponse de l'utilisateur */

  do {
    printf("~~~ BON RETOUR PARMIS NOUS ! ~~~\nVoulez vous jouer ?(o pour oui et n pour non)\n");
    scanf(" %c", &reponse);
    if (reponse == 'o')  
    {
      do {   /* choix du jeu */
        printf("Voici les jeux disponibles :\n1 - Le nombre caché \n2 - La suite mystère \n3 - Le Mastermind\n4 - Afficher mes meilleurs scores\n\n");
        printf("Choisissez un jeu (1,2,3,4):");
        scanf("%d", &choix);  
        
        if (choix != 2 && choix != 1 && choix !=3 && choix != 4) {
          printf("\n\nSaisie incorrecte. Veuillez saisir un chiffre entre 1 et 4.\n- - - - - - - - - -\n");
        }
      }
      while (choix != 2 && choix != 1 && choix != 3 && choix != 4);
      
      if (choix == 1) {
        printf("\n\nVous avez choisi le nombre caché\n");
        score = nbrcache();
        if (highscore_nb_cache < score) {
          highscore_nb_cache = score;  
        }
			}	
      else if (choix == 2) {
        printf("\n\nVous avez choisi la suite mystère\n");
        score = suitemyst();
				if (highscore_suite_myst > score) {
					highscore_suite_myst = score;
				}
      }
      else if (choix == 3) {
        printf("\n\nVous avez choisi le Mastermind\n");
        score = mastermind();
				if (highscore_mastermind > score) {
					highscore_mastermind = score;
				}
      }
			else {
				printf("\n\nVoici vos meilleurs scores lors de cette session :\n\n");
				if (highscore_nb_cache != 0)
					printf("Meilleur score au Nombre Caché : %d\n", highscore_nb_cache);
				if (highscore_suite_myst != 999999999)
					printf("Meilleur score a la Suite Mystère : %d\n", highscore_suite_myst);
				if (highscore_mastermind != 999999999)
					printf("Meilleur score au Mastermind : %d\n\n", highscore_mastermind);
			}
    }
    else if (reponse=='n'){
      printf("A bientôt\n\n");
      printf("Vos meilleurs scores :\n");
			if (highscore_nb_cache != 0)
				printf("Meilleur score au Nombre Caché : %d\n", highscore_nb_cache);
			if (highscore_suite_myst != 999999999)
				printf("Meilleur score a la Suite Mystère : %d\n", highscore_suite_myst);
			if (highscore_mastermind != 999999999)
				printf("Meilleur score au Mastermind : %d\n", highscore_mastermind);
    }
		else {
			printf("Saisie incorrecte !\n\n");  /* verification de saisie */
		}
  } 
	while (reponse != 'n');
}   
	
	
