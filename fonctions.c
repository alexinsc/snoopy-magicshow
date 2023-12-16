////////////////
//Bibliotheque//
////////////////
#include "fonctions.h"

//////////
//Macros//
//////////
#define SNOOPY 'S'
#define BLOC 'X'
#define BALLE 'O'
#define OISEAU 'P'
#define VIDE '.'
#define BLOC_CASSABLE 'C'
#define NB_LIGNES 10
#define NB_COLONNES 20

/////////////
//STRUCTURE//
/////////////

//Structure qui va stocker la position de snoopy//
positionSnoopy positionS(int niveauActuel) { //Création de la structure positionS
    if(niveauActuel == 1){ //Si le niveau actuel est le niveau 1
        positionSnoopy positionSnoopy = {3,3}; //On initialise la position de snoopy en X=3 et Y=3
        return positionSnoopy; //On retourne la position de snoopy
    }
    if(niveauActuel == 2){ //Si le niveau actuel est le niveau 2
        positionSnoopy positionSnoopy = {5,8}; //On initialise la position de snoopy en X=5 et Y=8
        return positionSnoopy; //On retourne la position de snoopy
    }
    if(niveauActuel == 3){ //Si le niveau actuel est le niveau 3
        positionSnoopy positionSnoopy = {4,9}; //On initialise la position de snoopy en X=4 et Y=9
        return positionSnoopy; //On retourne la position de snoopy
    }
}

//Structure qui va stocker la position des blocs déplacable//
positionBloc positionBlock(int niveauActuel) { //Création de la structure qui va stocker la position des blocs déplacable
    if(niveauActuel == 1){ //On initialise la position des différents blocs pour le niveau 1
        positionBloc positionBloc = {1,11,4,16,7,3,8,17};
        //On définit les coordonnées des différents blocs
        return positionBloc; //On retourne la position des blocs
    }
    if(niveauActuel == 2){ //On initialise la position des différents blocs pour le niveau 2
        positionBloc positionBloc = {0,13,2,18,5,7,8,10,9,16};
        //On définit les coordonnées des différents blocs
        return positionBloc; //On retourne la position des blocs
    }
    if(niveauActuel == 3){ //On initialise la position des différents blocs pour le niveau 3
        positionBloc positionBloc = {1,9,2,1,3,17,5,1,7,10,7,15,7,18,9,10};
        //On définit les coordonnées des différents blocs
        return positionBloc; //On retourne la position des blocs
    }
}

//Structure qui va stocker la position des blocs cassables//
positionBlocCassable positionBlocC(int niveauActuel) {
    if(niveauActuel == 1){ //On initialise la position des différents blocs cassable pour le niveau 1
        positionBlocCassable positionBlocCassable = {4,9};
        //On définit les coordonnées des différents blocs cassables
        return positionBlocCassable; //On retourne la position des blocs cassable
    }
    if(niveauActuel == 2){ //On initialise la position des différents blocs cassable pour le niveau 2
        positionBlocCassable positionBlocCassable = {3,1,1,6}; //On définit les coordonnées des différents blocs cassables
        return positionBlocCassable; //On retourne la position des blocs cassable
    }
    if(niveauActuel == 3){ //On initialise la position des différents blocs cassable pour le niveau 3
        positionBlocCassable positionBlocCassable = {3,5,3,14,8,5}; //On définit les coordonnées des différents blocs cassables
        return positionBlocCassable; //On retourne la position des blocs cassable
    }
}

//Structure qui va stocker la position des blocs pieges//
positionBlocPiege positionBlocP(int niveauActuel) {
    if(niveauActuel == 1){ //On initialise la position des différents blocs piege pour le niveau 1
        positionBlocPiege positionBlocPiege = {1,9}; //On définit les coordonnées des différents blocs pieges
        return positionBlocPiege; //On retourne la position des blocs piege
    }
    if(niveauActuel == 2){ //On initialise la position des différents blocs piege pour le niveau 2
        positionBlocPiege positionBlocPiege = {6,2,5,14,8,0}; //On définit les coordonnées des différents blocs pieges
        return positionBlocPiege; //On retourne la position des blocs piege
    }
    if(niveauActuel == 3){ //On initialise la position des différents blocs piege pour le niveau 3
        positionBlocPiege positionBlocPiege = {4,5,6,4,0,18}; //On définit les coordonnées des différents blocs pieges
        return positionBlocPiege; //On retourne la position des blocs piege
    }
}

//Structure qui va calculer le score//
Score score(float nbCoupsNiveau1,float nbCoupsNiveau2,float nbCoupsNiveau3){
    Score score = {nbCoupsNiveau1,nbCoupsNiveau2,nbCoupsNiveau3,0}; //On initialise les variables de la structure score
    if(score.nbCoupsNiveau1 != 0 && score.nbCoupsNiveau2 != 0 && score.nbCoupsNiveau3 != 0) { //Si le nombre de coups de chaque niveau est différent de 0
        score.resultat = 10000 * ((1/score.nbCoupsNiveau1) + (1/score.nbCoupsNiveau2) + (1/score.nbCoupsNiveau3)); //On calcule le score
    }
    else if(score.nbCoupsNiveau1 != 0 && score.nbCoupsNiveau2 != 0 && score.nbCoupsNiveau3 == 0) { //Si le nombre de coups des niveau 1 et 2 est différent de 0
        score.resultat = 10000*((1/ score.nbCoupsNiveau1) + (1/score.nbCoupsNiveau2));//On calcule le score
    }
    else if(score.nbCoupsNiveau1 != 0 && score.nbCoupsNiveau2 == 0 && score.nbCoupsNiveau3 == 0) { //Si le nombre de coups du niveau 1 uniquement est différent de 0
        score.resultat = (1/score.nbCoupsNiveau1)*10000;//On calcule le score
    }
    else { //Si aucun niveau est terminé
        score.resultat = 0; //On définit le score à 0
    }
    printf("Score : %f\n", score.resultat); //On affiche le score
    return score;//On retourne le score
}

/////////////
//FONCTIONS//
/////////////
//Fonction qui va lire le fichier contenant le niveau et le stocker dans une matrice//
char initialisationMatrice(char niveau[10][20],int niveauActuel) {
    if (niveauActuel == 1) { //Si le joueur est au niveau 1
        lireMatriceDepuisFichier(niveau, "../niveau1.txt"); //On lit le fichier contenant le niveau 1
        return niveau[10][20]; //On retourne la matrice obtenue
    }
    if (niveauActuel == 2) { //Si le joueur est au niveau 2
        lireMatriceDepuisFichier(niveau, "../niveau2.txt"); //On lit le fichier contenant le niveau 2
        return niveau[10][20]; //On retourne la matrice obtenue
    }

    if (niveauActuel == 3) { //Si le joueur est au niveau 3
        lireMatriceDepuisFichier(niveau, "../niveau3.txt"); //On lit le fichier contenant le niveau 3
        return niveau[10][20]; //On retourne la matrice obtenue
    }
}

//Fonction qui va gérer le déplacement des blocs déplacable//
int blocDeplacable(char niveau[10][20], int* pEtatBloc1, int* pEtatBloc2, int* pEtatBloc3, int* pEtatBloc4, int*pEtatBloc5, int* pEtatBloc6, int* pEtatBloc7, int* pEtatBloc8, int* positionSnoopyX, int* positionSnoopyY, char direction, positionBloc* positionB) {
    if (niveau[*positionSnoopyX][*positionSnoopyY] == BLOC) { //Si la position de Snoopy est la même que la position d'un bloc alors :
        if (*positionSnoopyX == positionB->positionBlocX1 && *positionSnoopyY == positionB->positionBlocY1 && *pEtatBloc1 == 0) { //Si la position de Snoopy est la même que la position du premier bloc et que le premier bloc n'a pas été déplacé alors :
            // On déplace le premier bloc en fonction de la direction dans laquelle Snoopy se déplace
            if (direction == 'z' && positionB->positionBlocX1 >= 0 && positionB->positionBlocX1 == *positionSnoopyX) { //Si la direction entrée par le joueur est z ou Z et que la position du premier bloc en X est supérieur ou égale à 0 et que la position du premier bloc en X est égale à la position de Snoopy en X alors :
                if (positionB->positionBlocX1 == 0) { //Si la position du premier bloc en X est égale à 0 alors :
                    return 1; //On retourne 1 afin de dire que le bloc ne peut pas être déplacé dans la direction voulu
                }
                positionB->positionBlocX1 -= 1; //On déplace le premier bloc d'une case vers le haut
                niveau[positionB->positionBlocX1][positionB->positionBlocY1] = BLOC; //On définit la nouvelle position du premier bloc comme étant un bloc sur la matrice
                *pEtatBloc1 = 1; // Marquer le premier bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX1 <= 9 && positionB->positionBlocX1 == *positionSnoopyX) { //Si la direction entrée par le joueur est s ou S et que la position du premier bloc en X est inférieur ou égale à 9 et que la position du premier bloc en X est égale à la position de Snoopy en X alors :
                if (positionB->positionBlocX1 == 9) { //Si la position du premier bloc en X est égale à 9 alors :
                    return 1; //On retourne 1 afin de dire que le bloc ne peut pas être déplacé dans la direction voulu
                }
                positionB->positionBlocX1 += 1; //On déplace le premier bloc d'une case vers le bas
                niveau[positionB->positionBlocX1][positionB->positionBlocY1] = BLOC; //On définit la nouvelle position du premier bloc comme étant un bloc sur la matrice
                *pEtatBloc1 = 1; // Marquer le premier bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY1 >= 0 && positionB->positionBlocY1 == *positionSnoopyY) { //Si la direction entrée par le joueur est q ou Q et que la position du premier bloc en Y est supérieur ou égale à 0 et que la position du premier bloc en Y est égale à la position de Snoopy en Y alors :
                if(positionB->positionBlocY1 == 0){ //Si la position du premier bloc en Y est égale à 0 alors :
                    return 1; //On retourne 1 afin de dire que le bloc ne peut pas être déplacé dans la direction voulu
                }
                positionB->positionBlocY1 -= 1; //On déplace le premier bloc d'une case vers la gauche
                niveau[positionB->positionBlocX1][positionB->positionBlocY1] = BLOC; //On définit la nouvelle position du premier bloc comme étant un bloc sur la matrice
                *pEtatBloc1 = 1; // Marquer le premier bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY1 <= 19 && positionB->positionBlocY1 == *positionSnoopyY) { //Si la direction entrée par le joueur est d ou D et que la position du premier bloc en Y est inférieur ou égale à 19 et que la position du premier bloc en Y est égale à la position de Snoopy en Y alors :
                if(positionB->positionBlocY1 == 19){ //Si la position du premier bloc en Y est égale à 19 alors :
                    return 1; //On retourne 1 afin de dire que le bloc ne peut pas être déplacé dans la direction voulu
                }
                positionB->positionBlocY1 += 1; //On déplace le premier bloc d'une case vers la droite
                niveau[positionB->positionBlocX1][positionB->positionBlocY1] = BLOC; //On définit la nouvelle position du premier bloc comme étant un bloc sur la matrice
                *pEtatBloc1 = 1; // Marquer le premier bloc comme déplacé
            }
            //On applique le même raisonnement pour les autres blocs déplacable
        } else if (*positionSnoopyX == positionB->positionBlocX2 && *positionSnoopyY == positionB->positionBlocY2 && *pEtatBloc2 == 0) {
            // Déplacement du deuxième bloc
            if (direction == 'z' && positionB->positionBlocX2 >= 0 && positionB->positionBlocX2 == *positionSnoopyX) {
                if(positionB->positionBlocX2 == 0){
                    return 1;
                }
                positionB->positionBlocX2 -= 1;
                niveau[positionB->positionBlocX2][positionB->positionBlocY2] = BLOC;
                *pEtatBloc2 = 1; // Marquer le deuxième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX2 <= 9 && positionB->positionBlocX2 == *positionSnoopyX) {
                if(positionB->positionBlocX2 == 9){
                    return 1;
                }
                positionB->positionBlocX2 += 1;
                niveau[positionB->positionBlocX2][positionB->positionBlocY2] = BLOC;
                *pEtatBloc2 = 1; // Marquer le deuxième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY2 >= 0 && positionB->positionBlocY2 == *positionSnoopyY) {
                if(positionB->positionBlocY2 == 0){
                    return 1;
                }
                positionB->positionBlocY2 -= 1;
                niveau[positionB->positionBlocX2][positionB->positionBlocY2] = BLOC;
                *pEtatBloc2 = 1; // Marquer le deuxième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY2 <= 19 && positionB->positionBlocY2 == *positionSnoopyY) {
                if(positionB->positionBlocY2 == 19){
                    return 1;
                }
                positionB->positionBlocY2 += 1;
                niveau[positionB->positionBlocX2][positionB->positionBlocY2] = BLOC;
                *pEtatBloc2 = 1; // Marquer le deuxième bloc comme déplacé
            }
        } else if (*positionSnoopyX == positionB->positionBlocX3 && *positionSnoopyY == positionB->positionBlocY3 && *pEtatBloc3 == 0) {
            // Déplacement du troisième bloc
            if (direction == 'z' && positionB->positionBlocX3 >= 0 && positionB->positionBlocX3 == *positionSnoopyX) {
                if(positionB->positionBlocX3 == 0){
                    return 1;
                }
                positionB->positionBlocX3 -= 1;
                niveau[positionB->positionBlocX3][positionB->positionBlocY3] = BLOC;
                *pEtatBloc3 = 1; // Marquer le troisième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX3 <= 9 && positionB->positionBlocX3 == *positionSnoopyX) {
                if(positionB->positionBlocX3 == 9){
                    return 1;
                }
                positionB->positionBlocX3 += 1;
                niveau[positionB->positionBlocX3][positionB->positionBlocY3] = BLOC;
                *pEtatBloc3 = 1; // Marquer le troisième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY3 >= 0 && positionB->positionBlocY3 == *positionSnoopyY) {
                if(positionB->positionBlocY3 == 0){
                    return 1;
                }
                positionB->positionBlocY3 -= 1;
                niveau[positionB->positionBlocX3][positionB->positionBlocY3] = BLOC;
                *pEtatBloc3 = 1; // Marquer le troisième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY3 <= 19 && positionB->positionBlocY3 == *positionSnoopyY) {
                if(positionB->positionBlocY3 == 19){
                    return 1;
                }
                positionB->positionBlocY3 += 1;
                niveau[positionB->positionBlocX3][positionB->positionBlocY3] = BLOC;
                *pEtatBloc3 = 1; // Marquer le troisième bloc comme déplacé
            }
        } else if (*positionSnoopyX == positionB->positionBlocX4 && *positionSnoopyY == positionB->positionBlocY4 && *pEtatBloc4 == 0) {
            // Déplacement du quatrième bloc
            if (direction == 'z' && positionB->positionBlocX4 >= 0 && positionB->positionBlocX4 == *positionSnoopyX) {
                if(positionB->positionBlocX4 == 0){
                    return 1;
                }
                positionB->positionBlocX4 -= 1;
                niveau[positionB->positionBlocX4][positionB->positionBlocY4] = BLOC;
                *pEtatBloc4 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX4 <= 9 && positionB->positionBlocX4 == *positionSnoopyX) {
                if(positionB->positionBlocX4 == 9){
                    return 1;
                }
                positionB->positionBlocX4 += 1;
                niveau[positionB->positionBlocX4][positionB->positionBlocY4] = BLOC;
                *pEtatBloc4 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY4 >= 0 && positionB->positionBlocY4 == *positionSnoopyY) {
                if(positionB->positionBlocY4 == 0){
                    return 1;
                }
                positionB->positionBlocY4 -= 1;
                niveau[positionB->positionBlocX4][positionB->positionBlocY4] = BLOC;
                *pEtatBloc4 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY4 <= 19 && positionB->positionBlocY4 == *positionSnoopyY) {
                if(positionB->positionBlocY4 == 19){
                    return 1;
                }
                positionB->positionBlocY4 += 1;
                niveau[positionB->positionBlocX4][positionB->positionBlocY4] = BLOC;
                *pEtatBloc4 = 1; // Marquer le quatrième bloc comme déplacé.
            }
        } else if (*positionSnoopyX == positionB->positionBlocX5 && *positionSnoopyY == positionB->positionBlocY5 && *pEtatBloc5 == 0) {
            // Déplacement du quatrième bloc
            if (direction == 'z' && positionB->positionBlocX5 >= 0 && positionB->positionBlocX5 == *positionSnoopyX) {
                if(positionB->positionBlocX5 == 0){
                    return 1;
                }
                positionB->positionBlocX5 -= 1;
                niveau[positionB->positionBlocX5][positionB->positionBlocY5] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX5 <= 9 && positionB->positionBlocX5 == *positionSnoopyX) {
                if(positionB->positionBlocX5 == 9){
                    return 1;
                }
                positionB->positionBlocX5 += 1;
                niveau[positionB->positionBlocX5][positionB->positionBlocY5] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY5 >= 0 && positionB->positionBlocY5 == *positionSnoopyY) {
                if(positionB->positionBlocY5 == 0){
                    return 1;
                }
                positionB->positionBlocY5 -= 1;
                niveau[positionB->positionBlocX5][positionB->positionBlocY5] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY5 <= 19 && positionB->positionBlocY5 == *positionSnoopyY) {
                if(positionB->positionBlocY5 == 19){
                    return 1;
                }
                positionB->positionBlocY5 += 1;
                niveau[positionB->positionBlocX5][positionB->positionBlocY5] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé.
            }
        } else if (*positionSnoopyX == positionB->positionBlocX6 && *positionSnoopyY == positionB->positionBlocY6 && *pEtatBloc5 == 0) {
            // Déplacement du quatrième bloc
            if (direction == 'z' && positionB->positionBlocX6 >= 0 && positionB->positionBlocX6 == *positionSnoopyX) {
                if (positionB->positionBlocX6 == 0) {
                    return 1;
                }
                positionB->positionBlocX6 -= 1;
                niveau[positionB->positionBlocX6][positionB->positionBlocY6] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX6 <= 9 &&
                       positionB->positionBlocX6 == *positionSnoopyX) {
                if (positionB->positionBlocX6 == 9) {
                    return 1;
                }
                positionB->positionBlocX6 += 1;
                niveau[positionB->positionBlocX6][positionB->positionBlocY6] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY6 >= 0 &&
                       positionB->positionBlocY6 == *positionSnoopyY) {
                if (positionB->positionBlocY6 == 0) {
                    return 1;
                }
                positionB->positionBlocY6 -= 1;
                niveau[positionB->positionBlocX6][positionB->positionBlocY6] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY6 <= 19 &&
                       positionB->positionBlocY6 == *positionSnoopyY) {
                if (positionB->positionBlocY6 == 19) {
                    return 1;
                }
                positionB->positionBlocY6 += 1;
                niveau[positionB->positionBlocX6][positionB->positionBlocY6] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé.
            }
        } else if (*positionSnoopyX == positionB->positionBlocX7 && *positionSnoopyY == positionB->positionBlocY7 && *pEtatBloc5 == 0) {
            // Déplacement du quatrième bloc
            if (direction == 'z' && positionB->positionBlocX7 >= 0 &&
                positionB->positionBlocX7 == *positionSnoopyX) {
                if (positionB->positionBlocX7 == 0) {
                    return 1;
                }
                positionB->positionBlocX7 -= 1;
                niveau[positionB->positionBlocX7][positionB->positionBlocY7] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX7 <= 9 &&
                       positionB->positionBlocX7 == *positionSnoopyX) {
                if (positionB->positionBlocX7 == 9) {
                    return 1;
                }
                positionB->positionBlocX7 += 1;
                niveau[positionB->positionBlocX7][positionB->positionBlocY7] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY7 >= 0 &&
                       positionB->positionBlocY7 == *positionSnoopyY) {
                if (positionB->positionBlocY7 == 0) {
                    return 1;
                }
                positionB->positionBlocY7 -= 1;
                niveau[positionB->positionBlocX7][positionB->positionBlocY7] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY7 <= 19 &&
                       positionB->positionBlocY7 == *positionSnoopyY) {
                if (positionB->positionBlocY7 == 19) {
                    return 1;
                }
                positionB->positionBlocY7 += 1;
                niveau[positionB->positionBlocX7][positionB->positionBlocY7] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé.
            }
        }else if (*positionSnoopyX == positionB->positionBlocX8 && *positionSnoopyY == positionB->positionBlocY8 && *pEtatBloc5 == 0) {
            // Déplacement du quatrième bloc
            if (direction == 'z' && positionB->positionBlocX8 >= 0 && positionB->positionBlocX8 == *positionSnoopyX) {
                if (positionB->positionBlocX8 == 0) {
                    return 1;
                }
                positionB->positionBlocX8 -= 1;
                niveau[positionB->positionBlocX8][positionB->positionBlocY8] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 's' && positionB->positionBlocX8 <= 9 &&
                       positionB->positionBlocX8 == *positionSnoopyX) {
                if (positionB->positionBlocX8 == 9) {
                    return 1;
                }
                positionB->positionBlocX8 += 1;
                niveau[positionB->positionBlocX8][positionB->positionBlocY8] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'q' && positionB->positionBlocY8 >= 0 &&
                       positionB->positionBlocY8 == *positionSnoopyY) {
                if (positionB->positionBlocY8 == 0) {
                    return 1;
                }
                positionB->positionBlocY8 -= 1;
                niveau[positionB->positionBlocX8][positionB->positionBlocY8] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé
            } else if (direction == 'd' && positionB->positionBlocY8 <= 19 &&
                       positionB->positionBlocY8 == *positionSnoopyY) {
                if (positionB->positionBlocY8 == 19) {
                    return 1;
                }
                positionB->positionBlocY8 += 1;
                niveau[positionB->positionBlocX8][positionB->positionBlocY8] = BLOC;
                *pEtatBloc5 = 1; // Marquer le quatrième bloc comme déplacé.
            }
        }
        else{
            printf("Ce bloc a deja ete deplace\n");
            return 1;
        }
    }
}

//Fonction qui va gérer les blocs cassable//
int blocCassable(char niveau[10][20],positionBlocCassable* positionBC,int positionSnoopyX,int positionSnoopyY,char direction){
    char touche = 0;
    if(niveau[positionSnoopyX][positionSnoopyY] == BLOC_CASSABLE){ //Si la position de Snoopy est la même que la position d'un bloc cassable alors :
        if(positionSnoopyX == positionBC->X1 && positionSnoopyY == positionBC->Y1) { //Si la position de Snoopy est la même que la position du premier bloc cassable enregistré dans la structure alors :
            if (direction == 'z' && positionBC->X1 > 0 && positionBC->X1 == positionSnoopyX) {
                niveau[positionBC->X1][positionBC->Y1] = VIDE; //On définit la position actuelle du premier bloc cassable comme étant "vide" sur la matrice
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n"); //On demande au joueur d'entrer la touche secrète pour casser le bloc
                scanf(" %c", &touche); //On stocke la touche entrée par le joueur dans la variable touche
                if (touche == 'p') { //Si la touche entrée par le joueur est p alors :
                    niveau[positionBC->X1][positionBC->Y1] = VIDE; //On définit la position actuelle du premier bloc cassable comme étant "vide" sur la matrice
                } else { //Sinon :
                    niveau[positionBC->X1][positionBC->Y1] = BLOC_CASSABLE; //On définit la nouvelle position du premier bloc cassable comme étant un bloc cassable sur la matrice
                    return 1; //On retourne 1 afin de dire que le bloc n'a pas été cassé
                }
                //On applique le même raisonnement pour les autres directions
            } else if (direction == 's' && positionBC->X1 < 9 && positionBC->X1 == positionSnoopyX) {
                niveau[positionBC->X1][positionBC->Y1] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X1][positionBC->Y1] = VIDE;
                } else {
                    niveau[positionBC->X1][positionBC->Y1] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y1 > 0 && positionBC->Y1 == positionSnoopyY) {
                niveau[positionBC->X1][positionBC->Y1] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X1][positionBC->Y1] = VIDE;
                } else {
                    niveau[positionBC->X1][positionBC->Y1] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBC->Y1 < 19 && positionBC->Y1 == positionSnoopyY) {
                niveau[positionBC->X1][positionBC->Y1] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X1][positionBC->Y1] = VIDE;
                } else {
                    niveau[positionBC->X1][positionBC->Y1] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBC->X2 && positionSnoopyY == positionBC->Y2) {
            if (direction == 'z' && positionBC->X2 > 0 && positionBC->X2 == positionSnoopyX) {
                niveau[positionBC->X2][positionBC->Y2] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X2][positionBC->Y2] = VIDE;
                } else {
                    niveau[positionBC->X2][positionBC->Y2] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBC->X2 < 9 && positionBC->X2 == positionSnoopyX) {
                niveau[positionBC->X2][positionBC->Y2] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X2][positionBC->Y2] = VIDE;
                } else {
                    niveau[positionBC->X2][positionBC->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y2 > 0 && positionBC->Y2 == positionSnoopyY) {
                niveau[positionBC->X2][positionBC->Y2] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X2][positionBC->Y2] = VIDE;
                } else {
                    niveau[positionBC->X2][positionBC->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            } else if(direction=='d' && positionBC->Y2 < 19 && positionBC->Y2 == positionSnoopyY){
                niveau[positionBC->X2][positionBC->Y2] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c",&touche);
                if(touche == 'p'){
                    niveau[positionBC->X2][positionBC->Y2] = VIDE;
                }
                else{
                    niveau[positionBC->X2][positionBC->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBC->X3 && positionSnoopyY == positionBC->Y3) {
            if (direction == 'z' && positionBC->X3 > 0 && positionBC->X3 == positionSnoopyX) {
                niveau[positionBC->X3][positionBC->Y3] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X3][positionBC->Y3] = VIDE;
                } else {
                    niveau[positionBC->X3][positionBC->Y3] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBC->X3 < 9 && positionBC->X3 == positionSnoopyX) {
                niveau[positionBC->X3][positionBC->Y3] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X3][positionBC->Y3] = VIDE;
                } else {
                    niveau[positionBC->X3][positionBC->Y3] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y3 > 0 && positionBC->Y3 == positionSnoopyY) {
                niveau[positionBC->X3][positionBC->Y3] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X3][positionBC->Y3] = VIDE;
                } else {
                    niveau[positionBC->X3][positionBC->Y3] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBC->Y3 < 19 && positionBC->Y3 == positionSnoopyY) {
                niveau[positionBC->X3][positionBC->Y3] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c",&touche);
                if(touche == 'p'){
                    niveau[positionBC->X3][positionBC->Y3] = VIDE;
                }
                else{
                    niveau[positionBC->X3][positionBC->Y3] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBC->X4 && positionSnoopyY == positionBC->Y4) {
            if (direction == 'z' && positionBC->X4 > 0 && positionBC->X4 == positionSnoopyX) {
                niveau[positionBC->X4][positionBC->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X4][positionBC->Y4] = VIDE;
                } else {
                    niveau[positionBC->X4][positionBC->Y4] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBC->X4 < 9 && positionBC->X4 == positionSnoopyX) {
                niveau[positionBC->X4][positionBC->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X4][positionBC->Y4] = VIDE;
                } else {
                    niveau[positionBC->X4][positionBC->Y4] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y4 > 0 && positionBC->Y4 == positionSnoopyY) {
                niveau[positionBC->X4][positionBC->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X4][positionBC->Y4] = VIDE;
                } else {
                    niveau[positionBC->X4][positionBC->Y4] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBC->Y4 < 19 && positionBC->Y4 == positionSnoopyY) {
                niveau[positionBC->X4][positionBC->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c",&touche);
                if(touche == 'p'){
                    niveau[positionBC->X4][positionBC->Y4] = VIDE;
                }
                else{
                    niveau[positionBC->X4][positionBC->Y4] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBC->X5 && positionSnoopyY == positionBC->Y5) {
            if (direction == 'z' && positionBC->X5 > 0 && positionBC->X5 == positionSnoopyX) {
                niveau[positionBC->X5][positionBC->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X5][positionBC->Y5] = VIDE;
                } else {
                    niveau[positionBC->X5][positionBC->Y5] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBC->X5 < 9 && positionBC->X5 == positionSnoopyX) {
                niveau[positionBC->X5][positionBC->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X5][positionBC->Y5] = VIDE;
                } else {
                    niveau[positionBC->X5][positionBC->Y5] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y5 > 0 && positionBC->Y5 == positionSnoopyY) {
                niveau[positionBC->X5][positionBC->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X5][positionBC->Y5] = VIDE;
                } else {
                    niveau[positionBC->X5][positionBC->Y5] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBC->Y5 < 19 && positionBC->Y5 == positionSnoopyY) {
                niveau[positionBC->X5][positionBC->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X5][positionBC->Y5] = VIDE;
                } else {
                    niveau[positionBC->X5][positionBC->Y5] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBC->X6 && positionSnoopyY == positionBC->Y6) {
            if (direction == 'z' && positionBC->X6 > 0 && positionBC->X6 == positionSnoopyX) {
                niveau[positionBC->X6][positionBC->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X6][positionBC->Y6] = VIDE;
                } else {
                    niveau[positionBC->X6][positionBC->Y6] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBC->X6 < 9 && positionBC->X6 == positionSnoopyX) {
                niveau[positionBC->X6][positionBC->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X6][positionBC->Y6] = VIDE;
                } else {
                    niveau[positionBC->X6][positionBC->Y6] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y6 > 0 && positionBC->Y6 == positionSnoopyY) {
                niveau[positionBC->X6][positionBC->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X6][positionBC->Y6] = VIDE;
                } else {
                    niveau[positionBC->X6][positionBC->Y6] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBC->Y6 < 19 && positionBC->Y6 == positionSnoopyY) {
                niveau[positionBC->X6][positionBC->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X6][positionBC->Y6] = VIDE;
                } else {
                    niveau[positionBC->X6][positionBC->Y6] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBC->X7 && positionSnoopyY == positionBC->Y7) {
            if (direction == 'z' && positionBC->X7 > 0 && positionBC->X7 == positionSnoopyX) {
                niveau[positionBC->X7][positionBC->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X7][positionBC->Y7] = VIDE;
                } else {
                    niveau[positionBC->X7][positionBC->Y7] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBC->X7 < 9 && positionBC->X7 == positionSnoopyX) {
                niveau[positionBC->X7][positionBC->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X7][positionBC->Y7] = VIDE;
                } else {
                    niveau[positionBC->X7][positionBC->Y7] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBC->Y7 > 0 && positionBC->Y7 == positionSnoopyY) {
                niveau[positionBC->X7][positionBC->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X7][positionBC->Y7] = VIDE;
                } else {
                    niveau[positionBC->X7][positionBC->Y7] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBC->Y7 < 19 && positionBC->Y7 == positionSnoopyY) {
                niveau[positionBC->X7][positionBC->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBC->X7][positionBC->Y7] = VIDE;
                } else {
                    niveau[positionBC->X7][positionBC->Y7] = BLOC_CASSABLE;
                    return 1;
                }
            }
        }
    }
}

//Fonction qui va gérer les blocs piege//
int blocPiege(char niveau[10][20],positionBlocPiege* positionBP,int positionSnoopyX,int positionSnoopyY,char direction,int* nbVie){
    char touche = 0; //On définit la variable touche comme étant un caractère
    if(niveau[positionSnoopyX][positionSnoopyY] == BLOC_CASSABLE){ //Si la position de Snoopy est la même que la position d'un bloc cassable alors :
        if(positionSnoopyX == positionBP->X1 && positionSnoopyY == positionBP->Y1) { //Si la position de Snoopy est la même que la position du premier bloc cassable enregistré dans la structure alors :
            if (direction == 'z' && positionBP->X1 > 0 && positionBP->X1 == positionSnoopyX) {//Si la direction est égale à z et que la position du premier bloc cassable en X est supérieur à 0 et que la position du premier bloc cassable en X est égale à la position de Snoopy en X alors :
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n"); //On demande au joueur d'entrer la touche secrète pour casser le bloc
                scanf(" %c", &touche); //On stocke la touche entrée par le joueur dans la variable touche
                if (touche == 'p') { //Si la touche entrée par le joueur est p alors :
                    niveau[positionBP->X1][positionBP->Y1] = VIDE; //On définit la position actuelle du premier bloc cassable comme étant "vide" sur la matrice
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else { //Sinon :
                    niveau[positionBP->X1][positionBP->Y1] = BLOC_CASSABLE; //On définit la nouvelle position du premier bloc cassable comme étant un bloc cassable sur la matrice
                    return 1; //On retourne 1 afin de dire que le bloc n'a pas été cassé
                }
                //On applique le même raisonnement pour les autres directions
            } else if (direction == 's' && positionBP->X1 < 9 && positionBP->X1 == positionSnoopyX) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X1][positionBP->Y1] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X1][positionBP->Y1] = BLOC_CASSABLE;
                    *nbVie = 0;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y1 > 0 && positionBP->Y1 == positionSnoopyY) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X1][positionBP->Y1] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X1][positionBP->Y1] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBP->Y1 < 19 && positionBP->Y1 == positionSnoopyY) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X1][positionBP->Y1] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X2][positionBP->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            }
            //On applique le même raisonnement pour les autres blocs cassables
        } else if(positionSnoopyX == positionBP->X2 && positionSnoopyY == positionBP->Y2){
            if (direction == 'z' && positionBP->X2 > 0 && positionBP->X2 == positionSnoopyX) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X2][positionBP->Y2] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X2][positionBP->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 's' && positionBP->X2 < 9 && positionBP->X2 == positionSnoopyX) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X2][positionBP->Y2] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X2][positionBP->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y2 > 0 && positionBP->Y2 == positionSnoopyY) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X2][positionBP->Y2] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X2][positionBP->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            }  else if (direction == 'd' && positionBP->Y2 < 19 && positionBP->Y2 == positionSnoopyY) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c",&touche);
                if(touche == 'p'){
                    niveau[positionBP->X2][positionBP->Y2] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                }
                else{
                    niveau[positionBP->X2][positionBP->Y2] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBP->X3 && positionSnoopyY == positionBP->Y3) {
            if (direction == 'z' && positionBP->X3 > 0 && positionBP->X3 == positionSnoopyX) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X3][positionBP->Y3] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X3][positionBP->Y3] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBP->X3 < 9 && positionBP->X3 == positionSnoopyX) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X3][positionBP->Y3] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X3][positionBP->Y3] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y3 > 0 && positionBP->Y3 == positionSnoopyY) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X3][positionBP->Y3] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X3][positionBP->Y3] = BLOC_CASSABLE;
                    return 1;
                }
            } else if(direction=='d' && positionBP->Y3 < 19 && positionBP->Y3 == positionSnoopyY){
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c",&touche);
                if(touche == 'p'){
                    niveau[positionBP->X3][positionBP->Y3] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                }
                else{
                    niveau[positionBP->X3][positionBP->Y3] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if (positionSnoopyX == positionBP->X4 && positionSnoopyY == positionBP->Y4) {
            if (direction == 'z' && positionBP->X4 > 0 && positionBP->X4 == positionSnoopyX) {
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                niveau[positionBP->X4][positionBP->Y4] = VIDE;
                if (touche == 'p') {
                    niveau[positionBP->X4][positionBP->Y4] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X4][positionBP->Y4] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBP->X4 < 9 && positionBP->X4 == positionSnoopyX) {
                niveau[positionBP->X4][positionBP->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);

                if (touche == 'p') {
                    niveau[positionBP->X4][positionBP->Y4] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X4][positionBP->Y4] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y4 > 0 && positionBP->Y4 == positionSnoopyY) {
                niveau[positionBP->X4][positionBP->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);

                if (touche == 'p') {
                    niveau[positionBP->X4][positionBP->Y4] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X4][positionBP->Y4] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBP->Y4 < 19 && positionBP->Y4 == positionSnoopyY) {
                niveau[positionBP->X4][positionBP->Y4] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X4][positionBP->Y4] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X4][positionBP->Y4] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBP->X5 && positionSnoopyY == positionBP->Y5) {
            if (direction == 'z' && positionBP->X5 > 0 && positionBP->X5 == positionSnoopyX) {
                niveau[positionBP->X5][positionBP->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X5][positionBP->Y5] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X5][positionBP->Y5] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBP->X5 < 9 && positionBP->X5 == positionSnoopyX) {
                niveau[positionBP->X5][positionBP->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X5][positionBP->Y5] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X5][positionBP->Y5] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y5 > 0 && positionBP->Y5 == positionSnoopyY) {
                niveau[positionBP->X5][positionBP->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X5][positionBP->Y5] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X5][positionBP->Y5] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBP->Y5 < 19 && positionBP->Y5 == positionSnoopyY) {
                niveau[positionBP->X5][positionBP->Y5] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X5][positionBP->Y5] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X5][positionBP->Y5] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBP->X6 && positionSnoopyY == positionBP->Y6) {
            if (direction == 'z' && positionBP->X6 > 0 && positionBP->X6 == positionSnoopyX) {
                niveau[positionBP->X6][positionBP->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X6][positionBP->Y6] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X6][positionBP->Y6] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBP->X6 < 9 && positionBP->X6 == positionSnoopyX) {
                niveau[positionBP->X6][positionBP->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X6][positionBP->Y6] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X6][positionBP->Y6] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y6 > 0 && positionBP->Y6 == positionSnoopyY) {
                niveau[positionBP->X6][positionBP->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X6][positionBP->Y6] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X6][positionBP->Y6] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBP->Y6 < 19 && positionBP->Y6 == positionSnoopyY) {
                niveau[positionBP->X6][positionBP->Y6] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X6][positionBP->Y6] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X6][positionBP->Y6] = BLOC_CASSABLE;
                    return 1;
                }
            }
        } else if(positionSnoopyX == positionBP->X7 && positionSnoopyY == positionBP->Y7) {
            if (direction == 'z' && positionBP->X7 > 0 && positionBP->X7 == positionSnoopyX) {
                niveau[positionBP->X7][positionBP->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X7][positionBP->Y7] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X7][positionBP->Y7] = BLOC_CASSABLE;
                    return 1;
                }

            } else if (direction == 's' && positionBP->X7 < 9 && positionBP->X7 == positionSnoopyX) {
                niveau[positionBP->X7][positionBP->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X7][positionBP->Y7] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X7][positionBP->Y7] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'q' && positionBP->Y7 > 0 && positionBP->Y7 == positionSnoopyY) {
                niveau[positionBP->X7][positionBP->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X7][positionBP->Y7] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X7][positionBP->Y7] = BLOC_CASSABLE;
                    return 1;
                }
            } else if (direction == 'd' && positionBP->Y7 < 19 && positionBP->Y7 == positionSnoopyY) {
                niveau[positionBP->X7][positionBP->Y7] = VIDE;
                printf("Veuillez rentrer la touche speciale pour casser le bloc :\n");
                scanf(" %c", &touche);
                if (touche == 'p') {
                    niveau[positionBP->X7][positionBP->Y7] = VIDE;
                    *nbVie = *nbVie - 1; //On enlève une vie au joueur
                    printf("Vous avez perdu une vie, %d vie restante\n",*nbVie); //On affiche un message pour dire au joueur qu'il a perdu
                    return 0; //On retourne 0 afin de dire que le bloc a été cassé
                } else {
                    niveau[positionBP->X7][positionBP->Y7] = BLOC_CASSABLE;
                    return 1;
                }
            }
        }
    }
}

//Fonction qui affiche le menu principal du jeu//
int menu() { //Création de la fonction menu
    int choix;
    printf("1. Regles du jeu\n");
    printf("2. Lancer un nouveau Jeu a partir du niveau 1\n");
    printf("3. Charger une partie\n");
    printf("4. Mot de passe\n");
    printf("5. Scores\n");
    printf("6. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

//Fonction qui va détecter si Snoopy est sur la case d'un oiseau//
int detectionOiseau(char niveau[10][20], int pPositionSnoopyX, int pPositionSnoopyY, int pNombreOiseaux) {
    if (niveau[pPositionSnoopyX][pPositionSnoopyY] == OISEAU) { //Si la position de Snoopy est la même que la position d'un oiseau alors :
        pNombreOiseaux += 1; //On incrémente le nombre d'oiseaux récupérés
        printf("Nombre d'oiseaux recupere : %d/4\n", pNombreOiseaux); //On affiche le nombre d'oiseaux récupérés sur le nombre d'oiseaux total
    }
    return pNombreOiseaux; //On retourne le nombre d'oiseaux récupérés
}

//Fonction qui va lancer un niveau en fonction du mot de passe entrée par le joueur//
int motDePasse() {
    char motDePasse[100]; //On définit la variable motDePasse

    //On demande au joueur d'entrer un mot de passe
    printf("Entrez le mot de passe :\n");
    scanf("%s", motDePasse); //On stocke le mot de passe entrée par le joueur dans la variable motDePasse

    if (strcmp(motDePasse, "niveau1Snoopy") == 0) { //Si le mot de passe entrée par le joueur est identique à "niveau1Snoopy" alors :
        printf("Mot de passe correct, vous allez commencer le niveau 1.\n"); //On affiche un message de confirmation
        return 1; //On retourne 1 afin que le niveau 1 se lance
    }
    else if (strcmp(motDePasse, "niveau2Snoopy") == 0) { //Si le mot de passe entrée par le joueur est identique à "niveau2Snoopy" alors :
        printf("Mot de passe correcte, vous allez commencer le niveau 2\n"); //On affiche un message de confirmation
        return 2; //On retourne 2 afin que le niveau 2 se lance
    }
    else if(strcmp(motDePasse, "niveau3Snoopy") == 0){ //Si le mot de passe entrée par le joueur est identique à "niveau3Snoopy" alors :
        printf("Mot de passe correcte, vous allez commencer le niveau 3\n"); //On affiche un message de confirmation
        return 3; //On retourne 3 afin que le niveau 3 se lance
    }
    else {
        printf("Mot de passe incorrecte\n"); //Si le mot de passe entrée par le joueur est incorrect alors on affiche un message d'erreur
    }
}

//////////////
//Procedures//
//////////////
//Fonction qui va afficher le niveau (afficher la matrice actualisé//
void afficherNiveau(char niveau[10][20]) { //Création de la fonction afficherNiveau
    /*On effectue une mise en forme de la matrice de la manière suivante :
     * +------+
     * [......]
     * [......]
     * +------+
     * */
    printf("+----------------------------------------+\n");
    for (int i = 0; i < 10; i++) { //On parcourt la matrice selon les coordonnées x et y
        printf("[");
        for (int j = 0; j < 20; j++) {
            printf("%c ", niveau[i][j]); //On affiche le caractère lu dans la matrice
        }
        printf("]\n");
    }
    printf("+----------------------------------------+\n");
}

//Fonction qui va déplacer la balle en diagonale et gérer les collisions//
void deplacementBalle(char niveau[10][20], int* pPositionBalleX, int* pPositionBalleY, int* pDirectionBalleX, int* pDirectionBalleY) {
    // Sauvegarde de la prochaine position de la balle
    int nextPositionX = *pPositionBalleX + *pDirectionBalleX; //On définit la prochaine position de la balle en X
    int nextPositionY = *pPositionBalleY + *pDirectionBalleY; //On définit la prochaine position de la balle en Y

    // Vérification des collisions avec les blocs
    if (niveau[nextPositionX][nextPositionY] == BLOC || niveau[nextPositionX][nextPositionY] == BLOC_CASSABLE || niveau[nextPositionX][nextPositionY] == OISEAU){ //Si la prochaine position de la balle est un bloc, un bloc cassable ou un oiseau alors :
        // Pivoter la direction de la balle de 90 degrés
        int temp = *pDirectionBalleX; //On définit une variable temporaire qui va stocker la direction de la balle en X
        *pDirectionBalleX = -*pDirectionBalleY; //On modifie la direction de la balle en X
        *pDirectionBalleY = temp; //On modifie la direction de la balle en Y
        //Ces modifications permettent à la balle d'effectuer un rebond de 90° lors d'une collision avec un bloc, un bloc cassable ou un oiseau

    } else { //Si la prochaine position de la balle n'est pas un bloc, un bloc cassable ou un oiseau alors :
        // Suppression de la position actuelle de la balle
        niveau[*pPositionBalleX][*pPositionBalleY] = VIDE; //On définit la position actuelle de la balle comme étant vide
        // Mise à jour de la position de la balle
        *pPositionBalleX = nextPositionX; //On définit la position de la balle en X comme étant la prochaine position de la balle en X
        *pPositionBalleY = nextPositionY; //On définit la position de la balle en Y comme étant la prochaine position de la balle en Y
    }

    // Gestion des rebonds sur les bords du niveau
    if (*pPositionBalleX == 0 || *pPositionBalleX == 9) { //Si la position de la balle en X est égale à 0 ou 9 alors (0 et 9 qui sont les bords de la matrice):
        *pDirectionBalleX = -*pDirectionBalleX; //On modifie la direction de la balle en X
    }
    if (*pPositionBalleY == 0 || *pPositionBalleY == 19) { //Si la position de la balle en Y est égale à 0 ou 19 alors (0 et 19 qui sont les bords de la matrice):
        *pDirectionBalleY = -*pDirectionBalleY; //On modifie la direction de la balle en Y
    }

    // Placement de la balle à sa nouvelle position
    niveau[*pPositionBalleX][*pPositionBalleY] = BALLE; //On définit la nouvelle position de la balle comme étant une balle sur la matrice
}

//Fonction qui va s'occuper du déplacement de Snoopy//
void deplacerSnoopy(char niveau[10][20],int* nbVie, int* pPositionSnoopyX, int* pPositionSnoopyY,float* pNombreDeCoups,int* pNombreOiseaux,int* etatBloc1, int* etatBloc2, int* etatBloc3, int* etatBloc4, int* etatBloc5,int* etatBloc6, int* etatBloc7, int* etatBloc8, positionBloc* positionBl, positionBlocCassable* positionBC, positionBlocPiege* positionBP, int* etat, int positionBalleX, int positionBalleY) {
    char input, tPause; //On définit les variables input et tPause
    int r = 0, ls = 0,lp = 0;
    printf("Entrez une direction (z,Z = haut; s,S = bas; q,Q = gauche; d,D = droite; p,P = Pause; k,K = Sauvegarde) : \n"); //On demande au joueur d'entrer une direction
    scanf(" %c", &input); //On stocke la direction entrée par le joueur dans la variable input

    if (*pPositionSnoopyX == positionBalleX && *pPositionSnoopyY == positionBalleY) { //Si la position de Snoopy est la même que la position de la balle alors :
        niveau[*pPositionSnoopyX][*pPositionSnoopyY] = BALLE; //On incrémente le nombre de coups de 1
    } else {
        niveau[*pPositionSnoopyX][*pPositionSnoopyY] = VIDE; //On définit la position actuelle de snoopy comme étant "vide" sur la matrice
    }
    switch (input) { //On définit les différentes actions à effectuer en fonction de la direction entrée par le joueur
        case 'z':
        case 'Z':
            //Si la direction entrée par le joueur est z ou Z alors :
            if (*pPositionSnoopyX > 0) {//Si la position de snoopy en X est supérieur à 0 (Snoopy ne soit pas tout en haut de la matrice) :
                *pPositionSnoopyX -= 1; //On déplace snoopy d'une case vers le haut
                if (niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC) { //Si la position de Snoopy est la même que la position d'un BLOC alors :
                    r = blocDeplacable(niveau, etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5, etatBloc6, etatBloc7, etatBloc8, pPositionSnoopyX,pPositionSnoopyY, input, positionBl); //On appelle la fonction blocDeplacable
                    if (r == 1) { //Si la fonction blocDeplacable retourne 1 alors cela signifie que le bloc sur lequelle est Snoopy a déjà été déplacé
                        *pPositionSnoopyX += 1; //On remet Snoopy à sa position initiale
                    }
                }
                if(niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC_CASSABLE){ //Si la position de Snoopy est la même que la position d'un BLOC_CASSABLE alors :
                    ls = blocCassable(niveau, positionBC,*pPositionSnoopyX,*pPositionSnoopyY,input); //On appelle la fonction blocCassable
                    if(ls == 1){ //Si la fonction blocCassable retourne 1 alors cela signifie l'utilisateur a rentré la mauvaise touche secrete donc le bloc n'a pas été cassé
                        *pPositionSnoopyX += 1; //On remet Snoopy à sa position initiale
                    }
                    lp = blocPiege(niveau, positionBP, *pPositionSnoopyX, *pPositionSnoopyY, input, nbVie); //On appelle la fonction blocPiege
                    if (lp == 1) { //Si la fonction blocPiege retourne 1 alors cela signifie l'utilisateur a rentré la mauvaise touche secrete donc le bloc n'a pas été cassé
                        *pPositionSnoopyX += 1; //On remet Snoopy à sa position initiale
                    }
                }
            }
            break;

        case 's':
        case 'S':
            //Si la direction entrée par le joueur est s ou S alors :
            if (*pPositionSnoopyX < 9) { //Si la position de snoopy en X est inférieur à 9 (Snoopy ne soit pas tout en bas de la matrice) :
                *pPositionSnoopyX += 1; //On déplace snoopy d'une case vers le bas
                if (niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC) {
                    r = blocDeplacable(niveau, etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5, etatBloc6,etatBloc7,etatBloc8, pPositionSnoopyX,pPositionSnoopyY, input,  positionBl);
                    if(r == 1){
                        *pPositionSnoopyX -= 1;
                    }
                }
                if(niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC_CASSABLE){
                    ls = blocCassable(niveau, positionBC,*pPositionSnoopyX,*pPositionSnoopyY,input);
                    if(ls == 1){
                        *pPositionSnoopyX -= 1;
                    }
                    lp = blocPiege(niveau, positionBP, *pPositionSnoopyX, *pPositionSnoopyY, input, nbVie);
                    if (lp == 1) {
                        *pPositionSnoopyX -= 1;
                    }
                }
            }
            break;

        case 'q':
        case 'Q':
            //Si la direction entrée par le joueur est q ou Q alors :
            if (*pPositionSnoopyY > 0) { //Si la position de snoopy en Y est supérieur à 0 (Snoopy ne soit pas tout à gauche de la matrice) :
                *pPositionSnoopyY -= 1; //On déplace snoopy d'une case vers la gauche
                if (niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC) {
                    r = blocDeplacable(niveau, etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5,etatBloc6,etatBloc7,etatBloc8, pPositionSnoopyX,pPositionSnoopyY, input,  positionBl);
                    if(r == 1){
                        *pPositionSnoopyY += 1;
                    }
                }
                if(niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC_CASSABLE){
                    ls = blocCassable(niveau, positionBC,*pPositionSnoopyX,*pPositionSnoopyY,input);
                    if(ls == 1){
                        *pPositionSnoopyY += 1;
                    }
                    lp = blocPiege(niveau, positionBP, *pPositionSnoopyX, *pPositionSnoopyY, input, nbVie);
                    if (lp == 1) {
                        *pPositionSnoopyY += 1;
                    }
                }
            }
            break;

        case 'd':
        case 'D':
            //Si la direction entrée par le joueur est d ou D alors :
            if (*pPositionSnoopyY < 19) { //Si la position de snoopy en Y est inférieur à 19 (Snoopy ne soit pas tout à droite de la matrice) :
                *pPositionSnoopyY += 1; //On déplace snoopy d'une case vers la droite
                if (niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC) {
                    r = blocDeplacable(niveau, etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5,etatBloc6,etatBloc7,etatBloc8, pPositionSnoopyX,pPositionSnoopyY, input,  positionBl);
                    if(r == 1){
                        *pPositionSnoopyY -= 1;
                    }
                }
                if(niveau[*pPositionSnoopyX][*pPositionSnoopyY] == BLOC_CASSABLE){
                    ls = blocCassable(niveau, positionBC,*pPositionSnoopyX,*pPositionSnoopyY,input);
                    if(ls == 1){
                        *pPositionSnoopyY -= 1;
                    }
                    lp = blocPiege(niveau, positionBP, *pPositionSnoopyX, *pPositionSnoopyY, input, nbVie);
                    if (lp == 1) {
                        *pPositionSnoopyY -= 1;
                    }
                }
            }
            break;

        case 'p':
        case 'P':
            //Si la direction entrée par le joueur est p ou P alors :
            printf("Menu pause, entrez n'importe qu'elle touche pour quitter le menu pause.\n"); //On affiche le menu pause
            scanf(" %c",&tPause); //On stocke la touche entrée par le joueur dans la variable tPause afin que lorsque il appuie sur entrée le menu pause disparait
            break;

        case 'k':
        case 'K':
            *etat = 1;
            break;
        default:
            printf("Entrez une saisie valide\n"); //Si le joueur entre une direction invalide alors on lui affiche un message d'erreur
            break;
    }
    *pNombreOiseaux = detectionOiseau(niveau, *pPositionSnoopyX, *pPositionSnoopyY, *pNombreOiseaux); //On appelle la fonction detectionOiseau afin de regarder si Snoopy est sur la case d'un oiseau
    niveau[*pPositionSnoopyX][*pPositionSnoopyY] = SNOOPY; //On définit la nouvelle position de Snoopy comme étant Snoopy sur la matrice
    *pNombreDeCoups += 1; //On incrémente le nombre de coups
}

void detectionVie(int* pNombreDeVie, int positionBalleX, int positionBalleY,int positionSnoopyX, int positionSnoopyY) {
    if (positionSnoopyX == positionBalleX && positionSnoopyY == positionBalleY) { //Si la position de Snoopy est la même que la position de la balle alors :
        *pNombreDeVie -= 1; //On enlève une vie au joueur
        printf("Vous avez perdu une vie, il vous reste %d vies.\n", *pNombreDeVie); //On affiche un message pour dire au joueur qu'il a perdu une vie
        if (*pNombreDeVie == 0) { //Si le nombre de vie est égale à 0 alors :
            printf("Vous avez perdu, vous n'avez plus de vie.\n"); //On affiche un message pour dire au joueur qu'il a perdu
        }
    }
}

////////////
///Niveau///
////////////
void niveau1(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy1, float* nombreDeCoupsNvx1,float nombreDeCoupsNvx2,float nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP,int etatNiveau1, float* scor,int* nombreDeVie){
    Score score1 = {*nombreDeCoupsNvx1,nombreDeCoupsNvx2,nombreDeCoupsNvx3,0};
    printf("Vous allez comencer le niveau 1.\n"); //On affiche un message pour dire que le joueur va commencer le niveau 1
    initialisationMatrice(niveau,1); //On appelle la fonction initialisationMatrice afin de créer le niveau 1
    int etatBloc1 = 0, etatBloc2 = 0, etatBloc3 = 0, etatBloc4 = 0,etatBloc5 = 0, etatBloc6=0, etatBloc7=0, etatBloc8=0; //On définit les variables etatBloc1, etatBloc2, etatBloc3, etatBloc4 et etatBloc5 comme étant égale à 0 variable indiquant si le bloc n°x a déjà été déplacé
    int positionSnoopyX = positionSnoopy1.X, positionSnoopyY = positionSnoopy1.Y; //On définit les variables positionSnoopyX et positionSnoopyY comme étant égale à la position de Snoopy en X et en Y
    int etat=0; //On définit la variable sauvegarde comme étant égale à 0
    while (nombreOiseaux < 4 && *nombreDeVie > 0) { //Tant que le nombre d'oiseaux récupérés est inférieur à 4 et que le nombre de vie est supérieur à 0 alors :
        afficherNiveau(niveau); //On affiche le niveau actualisé
        deplacementBalle(niveau, &positionBalleX, &positionBalleY, &directionBalleX, &directionBalleY); //On effectue le déplacement de la balle présente le niveau
        deplacerSnoopy(niveau, nombreDeVie, &positionSnoopyX, &positionSnoopyY, nombreDeCoupsNvx1, &nombreOiseaux, &etatBloc1, &etatBloc2, &etatBloc3, &etatBloc4, &etatBloc5,&etatBloc6,&etatBloc7,&etatBloc8, &positionB, &positionBC, &positionBP, &etat, positionBalleX, positionBalleY); //On effectue le déplacement de Snoopy
        detectionVie(nombreDeVie, positionBalleX, positionBalleY, positionSnoopyX, positionSnoopyY); //On détecte si Snoopy est sur la même case que la balle
        if (etat == 1){
            sauvegardeNiveau(niveau, 1, etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5, etatBloc6, etatBloc7, etatBloc8, positionSnoopyX, positionSnoopyY,nombreOiseaux,positionBalleX, positionBalleY, directionBalleX, directionBalleY, positionB, positionBC, positionBP,*nombreDeVie, *nombreDeCoupsNvx1, nombreDeCoupsNvx2, nombreDeCoupsNvx3);
            etat = 0;
            printf("Vous avez sauvegardé la partie\n");
        }
        if (nombreOiseaux == 4) { //Si tout les oiseaux ont été récupérés alors :
            printf("Vous termine le niveau 1!\n"); //On affiche un message de confirmation
            etatNiveau1 = 1; //On indique que le niveau 1 a été terminé
            printf("Nombre de coups : %f\n", *nombreDeCoupsNvx1); //On affiche le nombre de coups effectué par le joueur
            score1 = score(*nombreDeCoupsNvx1,0,0); //On appelle la fonction score afin de calculer le score du joueur
            *scor = score1.resultat; //On stocke le score du joueur dans la variable scor
            sauvegardeScore(scor);//On appelle la fonction sauvegardeScore afin de sauvegarder le score du joueur
        }
    }
}

//Pour les niveau 2 et 3 on applique le même raisonnement que pour le niveau 1
void niveau2(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy, float nombreDeCoupsNvx1,float* nombreDeCoupsNvx2,float nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC,positionBlocPiege positionBP,int etatNiveau2, float* scor,int* nombreDeVie){
    Score score1 = {nombreDeCoupsNvx1,*nombreDeCoupsNvx2,nombreDeCoupsNvx3,0};
    printf("Vous allez comencer le niveau 2.\n");
    initialisationMatrice(niveau,2);
    int etatBloc1 = 0, etatBloc2 = 0, etatBloc3 = 0, etatBloc4 = 0, etatBloc5 = 0, etatBloc6 = 0, etatBloc7 = 0, etatBloc8 = 0;
    int positionSnoopyX = positionSnoopy.X, positionSnoopyY = positionSnoopy.Y;
    int etat=0;
    while (nombreOiseaux < 4 && *nombreDeVie > 0) {
        afficherNiveau(niveau);
        deplacementBalle(niveau, &positionBalleX, &positionBalleY, &directionBalleX, &directionBalleY);
        deplacerSnoopy(niveau,nombreDeVie, &positionSnoopyX, &positionSnoopyY, nombreDeCoupsNvx2, &nombreOiseaux,
                       &etatBloc1, &etatBloc2, &etatBloc3, &etatBloc4, &etatBloc5,&etatBloc6,&etatBloc7,&etatBloc8, &positionB, &positionBC, &positionBP, &etat, positionBalleX, positionBalleY);
        detectionVie(nombreDeVie, positionBalleX, positionBalleY, positionSnoopyX, positionSnoopyY);
        if (nombreOiseaux == 4) {
            printf("Vous termine le niveau 2!\n");
            etatNiveau2 = 1;
            score1 = score(nombreDeCoupsNvx1,*nombreDeCoupsNvx2,nombreDeCoupsNvx3);
            *scor = score1.resultat;
            sauvegardeScore(scor);
        }
    }
}

void niveau3(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy, float nombreDeCoupsNvx1,float nombreDeCoupsNvx2,float* nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC,positionBlocPiege positionBP,int etatNiveau3, float* scor,int* nombreDeVie){
    Score score1 = {0,0,0,0};
    printf("Vous allez comencer le niveau 3.\n");
    initialisationMatrice(niveau,3);
    int etatBloc1 = 0, etatBloc2 = 0, etatBloc3 = 0, etatBloc4 = 0,etatBloc5 = 0,etatBloc6 = 0,etatBloc7 = 0,etatBloc8 = 0;
    int positionSnoopyX = positionSnoopy.X, positionSnoopyY = positionSnoopy.Y;
    int etat=0;
    while (nombreOiseaux < 4 && *nombreDeVie > 0) {
        afficherNiveau(niveau);
        deplacementBalle(niveau, &positionBalleX, &positionBalleY, &directionBalleX, &directionBalleY);
        deplacerSnoopy(niveau,nombreDeVie, &positionSnoopyX, &positionSnoopyY, nombreDeCoupsNvx3, &nombreOiseaux,
                       &etatBloc1, &etatBloc2, &etatBloc3, &etatBloc4, &etatBloc5,&etatBloc6,&etatBloc7,&etatBloc8, &positionB, &positionBC, &positionBP, &etat, positionBalleX, positionBalleY);
        detectionVie(nombreDeVie, positionBalleX, positionBalleY, positionSnoopyX, positionSnoopyY);
        if (nombreOiseaux == 4) {
            printf("Vous termine le niveau 3!\n");
            etatNiveau3 = 1;
            score1 = score(nombreDeCoupsNvx1,nombreDeCoupsNvx2,*nombreDeCoupsNvx3);
            *scor = score1.resultat;
            sauvegardeScore(scor);
        }
    }
}

//////////////
//Sauvegarde//
//////////////
void stockerMatriceDansFichier(char niveau[10][20], char *nomFichier) {
    FILE *fichier = NULL; // On définit la variable fichier comme étant un pointeur sur un fichier
    fichier = fopen(nomFichier, "w"); // Ouverture du fichier en mode écriture

    if (fichier != NULL) { // Si le fichier est ouvert alors :
        for (int i = 0; i < 10; i++) { // Parcours de la matrice
            for (int j = 0; j < 20; j++) {
                fprintf(fichier, "%c ", niveau[i][j]); // Écriture de chaque élément de la matrice dans le fichier
            }
            fprintf(fichier, "\n"); // Saut de ligne après chaque ligne de la matrice
        }
        fclose(fichier); // Fermeture du fichier
        printf("Matrice stockee dans le fichier avec succes.\n");
    } else {
        printf("Impossible d'ouvrir le fichier pour stocker la matrice.\n");
    }
}

void lireMatriceDepuisFichier(char niveau[NB_LIGNES][NB_COLONNES], char *nomFichier) {
    FILE *fichier = NULL; // On définit la variable fichier comme étant un pointeur sur un fichier
    fichier = fopen(nomFichier, "r"); // Ouverture du fichier en mode lecture

    if (fichier != NULL) { // Si le fichier est ouvert alors :
        for (int i = 0; i < NB_LIGNES; i++) { // Parcours de la matrice
            for (int j = 0; j < NB_COLONNES; j++) {
                fscanf(fichier, " %c", &niveau[i][j]); // Lecture de chaque élément du fichier dans la matrice
            }
        }
        fclose(fichier); // Fermeture du fichier
        printf("Matrice lue depuis le fichier avec succes.\n");
    } else {
        printf("Impossible d'ouvrir le fichier pour lire la matrice.\n");
    }
}

void sauvegardeScore(float* scor){
    FILE* fichier = NULL; //On définit la variable fichier comme étant un pointeur sur un fichier
    fichier = fopen("../score.txt","w"); //On ouvre le fichier score.txt en mode écriture
    if(fichier != NULL){ //Si le fichier est ouvert alors :
        fprintf(fichier,"%d",(int)*scor); //On écrit le score dans le fichier
        fclose(fichier); //On ferme le fichier
        fichier = NULL; //On définit le pointeur fichier comme étant NULL
    }
    else{
        printf("Impossible d'ouvrir le fichier\n"); //Sinon on affiche un message d'erreur
    }
}

void lectureScoreSauvegarde() {
    int valeur; //On définit la variable valeur comme étant un entier
    FILE *fichier = NULL; //On définit la variable fichier comme étant un pointeur sur un fichier
    fichier = fopen("../score.txt", "r"); //On ouvre le fichier score.txt en mode lecture
    if (fichier != NULL) { //Si le fichier est ouvert alors :
        fscanf(fichier, "%d", &valeur); //On lit le fichier et on stocke la valeur dans la variable valeur
        printf("Score de la partie precedente : %d\n", valeur); //On affiche le score de la partie précédente
        fclose(fichier); //On ferme le fichier
        fichier = NULL; //On définit le pointeur fichier comme étant NULL
    } else {
        printf("Impossible d'ouvrir le fichier\n"); //Sinon on affiche un message d'erreur
    }
}

//Essai de sauvegarde et de chargement d'une partie en cours
void sauvegardeNiveau(char niveau[10][20], int niveauActuel, int etatBloc1, int etatBloc2, int etatBloc3, int etatBloc4, int etatBloc5, int etatBloc6, int etatBloc7, int etatBloc8, int positionSnoopyX, int positionSnoopyY, int nombreOiseaux, int positionBalleX, int positionBalleY, int directionBalleX, int directionBalleY, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP, int nbVie, float nombreDeCoupsNvx1, float nombreDeCoupsNvx2, float nombreDeCoupsNvx3){
    char nomFichier[50];
    FILE* pf = NULL; //On définit la variable fichier comme étant un pointeur sur un fichier
    stockerMatriceDansFichier(niveau, "../sauvegardeMatrice.txt");
    pf = fopen("../sauvegarde.txt","w"); //On ouvre le fichier score.txt en mode écriture
    fprintf(pf,"%d\n", niveauActuel);
    fprintf(pf, "%d %d\n", positionBalleX, positionBalleY);
    fprintf(pf, "%d %d\n", directionBalleX, directionBalleY);
    fprintf(pf, "%d %d\n", positionSnoopyX, positionSnoopyY);
    fprintf(pf, "%f %f %f\n", nombreDeCoupsNvx1, nombreDeCoupsNvx2, nombreDeCoupsNvx3);
    fprintf(pf, "%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", positionB.positionBlocX1, positionB.positionBlocY1, positionB.positionBlocX2, positionB.positionBlocY2, positionB.positionBlocX3, positionB.positionBlocY3, positionB.positionBlocX4, positionB.positionBlocY4, positionB.positionBlocX5, positionB.positionBlocY5, positionB.positionBlocX6, positionB.positionBlocY6, positionB.positionBlocX7, positionB.positionBlocY7, positionB.positionBlocX8, positionB.positionBlocY8);
    fprintf(pf, "%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", positionBC.X1, positionBC.Y1, positionBC.X2, positionBC.Y2, positionBC.X3, positionBC.Y3, positionBC.X4, positionBC.Y4, positionBC.X5, positionBC.Y5, positionBC.X6, positionBC.Y6, positionBC.X7, positionBC.Y7);
    fprintf(pf, "%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", positionBP.X1, positionBP.Y1, positionBP.X2, positionBP.Y2, positionBP.X3, positionBP.Y3, positionBP.X4, positionBP.Y4, positionBP.X5, positionBP.Y5, positionBP.X6, positionBP.Y6, positionBP.X7, positionBP.Y7);
    fprintf(pf, "%d\n", nbVie);
    fprintf(pf, "%d\n", nombreOiseaux);
    fclose(pf);
    pf = NULL; //On définit le pointeur fichier comme étant NULL
    pf = fopen("../sauvegarde1.txt","w");
    fprintf(pf,"%d %d %d %d %d %d %d %d\n", etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5, etatBloc6, etatBloc7, etatBloc8);
    fclose(pf); //On ferme le fichier
    pf = NULL; //On définit le pointeur fichier comme étant NULL
}

void niveauX(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy1, float* nombreDeCoupsNvx1,float* nombreDeCoupsNvx2,float* nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP, float* scor,int* nombreDeVie){
    Score score1 = {*nombreDeCoupsNvx1,*nombreDeCoupsNvx2,*nombreDeCoupsNvx3,0};
    printf("Vous allez reprendre le niveau.\n"); //On affiche un message pour dire que le joueur va commencer le niveau 1
    int etatBloc1 = 0, etatBloc2 = 0, etatBloc3 = 0, etatBloc4 = 0,etatBloc5 = 0, etatBloc6=0, etatBloc7=0, etatBloc8=0; //On définit les variables etatBloc1, etatBloc2, etatBloc3, etatBloc4 et etatBloc5 comme étant égale à 0 variable indiquant si le bloc n°x a déjà été déplacé
    int positionSnoopyX = positionSnoopy1.X, positionSnoopyY = positionSnoopy1.Y; //On définit les variables positionSnoopyX et positionSnoopyY comme étant égale à la position de Snoopy en X et en Y
    int etat=0; //On définit la variable sauvegarde comme étant égale à 0
    FILE* pf = NULL; //On définit la variable fichier comme étant un pointeur sur un fichier
    pf = fopen("../sauvegarde1.txt","r"); //On ouvre le fichier score.txt en mode écriture
    if(pf != NULL){ //Si le fichier est ouvert alors :
        fscanf(pf,"%d %d %d %d %d %d %d %d", &etatBloc1, &etatBloc2, &etatBloc3, &etatBloc4, &etatBloc5, &etatBloc6, &etatBloc7, &etatBloc8);
        fclose(pf); //On ferme le fichier
        pf = NULL; //On définit le pointeur fichier comme étant NULL
    }
    while (nombreOiseaux < 4 && *nombreDeVie > 0) { //Tant que le nombre d'oiseaux récupérés est inférieur à 4 et que le nombre de vie est supérieur à 0 alors :
        afficherNiveau(niveau); //On affiche le niveau actualisé
        deplacementBalle(niveau, &positionBalleX, &positionBalleY, &directionBalleX, &directionBalleY); //On effectue le déplacement de la balle présente le niveau
        deplacerSnoopy(niveau, nombreDeVie, &positionSnoopyX, &positionSnoopyY, nombreDeCoupsNvx1, &nombreOiseaux, &etatBloc1, &etatBloc2, &etatBloc3, &etatBloc4, &etatBloc5,&etatBloc6,&etatBloc7,&etatBloc8, &positionB, &positionBC, &positionBP, &etat, positionBalleX, positionBalleY); //On effectue le déplacement de Snoopy
        detectionVie(nombreDeVie, positionBalleX, positionBalleY, positionSnoopyX, positionSnoopyY); //On détecte si Snoopy est sur la même case que la balle
        if (etat == 1){
            sauvegardeNiveau(niveau, 1, etatBloc1, etatBloc2, etatBloc3, etatBloc4, etatBloc5, etatBloc6, etatBloc7, etatBloc8, positionSnoopyX, positionSnoopyY,nombreOiseaux,positionBalleX, positionBalleY, directionBalleX, directionBalleY, positionB, positionBC, positionBP,*nombreDeVie, *nombreDeCoupsNvx1, *nombreDeCoupsNvx2, *nombreDeCoupsNvx3);
            etat = 0;
            printf("Vous avez sauvegardé la partie\n");
        }
        if (nombreOiseaux == 4) { //Si tout les oiseaux ont été récupérés alors :
            printf("Vous termine le niveau 1!\n"); //On affiche un message de confirmation
            printf("Nombre de coups : %f\n", *nombreDeCoupsNvx1); //On affiche le nombre de coups effectué par le joueur
            score1 = score(*nombreDeCoupsNvx1,0,0); //On appelle la fonction score afin de calculer le score du joueur
            *scor = score1.resultat; //On stocke le score du joueur dans la variable scor
            sauvegardeScore(scor);//On appelle la fonction sauvegardeScore afin de sauvegarder le score du joueur
        }
    }
}
