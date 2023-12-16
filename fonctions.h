#ifndef PROJET_FONCTIONS_H
#define PROJET_FONCTIONS_H
////////////////
//Bibliothèque//
////////////////
#include "string.h"
#include "stdio.h"

//////////
//Macros//
//////////
#define SNOOPY 'S'
#define BALLE 'O'
#define OISEAU 'P'
#define VIDE '.'
#define BLOC 'X'
#define NB_LIGNES 10
#define NB_COLONNES 20

/////////////
//STRUCTURE//
/////////////
typedef struct {
    float nbCoupsNiveau1, nbCoupsNiveau2, nbCoupsNiveau3,resultat;
}Score;

typedef struct {
    int positionBlocX1, positionBlocY1;
    int positionBlocX2, positionBlocY2;
    int positionBlocX3, positionBlocY3;
    int positionBlocX4, positionBlocY4;
    int positionBlocX5, positionBlocY5;
    int positionBlocX6, positionBlocY6;
    int positionBlocX7, positionBlocY7;
    int positionBlocX8, positionBlocY8;
}positionBloc;

typedef struct {
    int X1, Y1;
    int X2, Y2;
    int X3, Y3;
    int X4, Y4;
    int X5, Y5;
    int X6, Y6;
    int X7, Y7;
}positionBlocCassable;

typedef struct {
    int X1, Y1;
    int X2, Y2;
    int X3, Y3;
    int X4, Y4;
    int X5, Y5;
    int X6, Y6;
    int X7, Y7;
}positionBlocPiege;

typedef struct {
    int X,Y;
}positionSnoopy;

////////////
//Fonction//
////////////
positionBloc positionBlock(int niveauActuel);
Score score(float nbCoupsNiveau1, float nbCoupsNiveau2, float nbCoupsNiveau3);
positionBlocCassable positionBlocC(int niveauActuel);
positionBlocPiege positionBlocP(int niveauActuel);
positionSnoopy positionS(int niveauActuel);
int menu();
int motDePasse();
int blocDeplacable(char niveau[10][20], int* pEtatBloc1, int* pEtatBloc2, int* pEtatBloc3, int* pEtatBloc4, int* etatBloc5, int* pEtatBloc6, int* pEtatBloc7, int* pEtatBloc8, int* positionSnoopyX, int* positionSnoopyY, char direction, positionBloc* positionB);
int blocCassable(char niveau[10][20],positionBlocCassable* positionBC,int positionSnoopyX,int positionSnoopyY,char direction);
int blocPiege(char niveau[10][20],positionBlocPiege* positionBP,int positionSnoopyX,int positionSnoopyY,char direction, int* nbVie);
char initialisationMatrice(char niveau[NB_LIGNES][NB_COLONNES], int niveauActuel);

/////////////
//Procédure//
/////////////
void afficherNiveau(char niveau[NB_LIGNES][NB_COLONNES]);
void deplacementBalle(char niveau[NB_LIGNES][NB_COLONNES], int* pPositionBalleX, int* pPositionBalleY, int* pDirectionBalleX, int* pDirectionBalleY);
void deplacerSnoopy(char niveau[10][20],int* nbVie, int* pPositionSnoopyX, int* pPositionSnoopyY,float* pNombreDeCoups,int* pNombreOiseaux,int* etatBloc1, int* etatBloc2, int* etatBloc3, int* etatBloc4, int* etatBloc5, int* etatBloc6, int* etatBloc7, int* etatBloc8, positionBloc* positionBl, positionBlocCassable* positionBC, positionBlocPiege* positionBP, int* etat, int positionBalleX, int positionBalleY);
void niveau1(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy, float* nombreDeCoupsNvx1,float nombreDeCoupsNvx2,float nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP,int etatNiveau1, float* score, int* nbVie);
void niveau2(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy, float nombreDeCoupsNvx1,float* nombreDeCoupsNvx2,float nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP,int etatNiveau2, float* score,int* nbVie);
void niveau3(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy, float nombreDeCoupsNvx1,float nombreDeCoupsNvx2,float* nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP,int etatNiveau3, float* score,int* nbVie);
void lectureScoreSauvegarde();
void sauvegardeScore(float* scor);
void detectionVie(int* nbVie, int positionBalleX,int positionBalleY,int positionSnoopyX,int positionSnoopyY);
void stockerMatriceDansFichier(char niveau[10][20], char *nomFichier);
void lireMatriceDepuisFichier(char niveau[NB_LIGNES][NB_COLONNES], char *nomFichier);
void sauvegardeNiveau(char niveau[10][20], int niveauActuel, int etatBloc1, int etatBloc2, int etatBloc3, int etatBloc4, int etatBloc5, int etatBloc6, int etatBloc7, int etatBloc8, int positionSnoopyX, int positionSnoopyY, int nombreOiseaux, int positionBalleX, int positionBalleY, int directionBalleX, int directionBalleY, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP, int nbVie, float nombreDeCoupsNvx1, float nombreDeCoupsNvx2, float nombreDeCoupsNvx3);
void niveauX(char niveau[10][20],int nombreOiseaux, int positionBalleX,int positionBalleY, int directionBalleX, int directionBalleY, positionSnoopy positionSnoopy, float* nombreDeCoupsNvx1,float* nombreDeCoupsNvx2,float* nombreDeCoupsNvx3, positionBloc positionB, positionBlocCassable positionBC, positionBlocPiege positionBP, float* score, int* nbVie);

#endif //PROJET_FONCTIONS_H


