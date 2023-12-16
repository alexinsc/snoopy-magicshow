#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "string.h"
#include "time.h"

int main() {
    /////////////////////
    //Variable initiale//
    /////////////////////
    char niveau[10][20],direction,mdp[100];
    int rMenu=0, etatNiveau1=0, etatNiveau2=0, etatNiveau3=0, niveauMdp=0;
    int positionBalleX = 6, positionBalleY = 5, directionBalleX = 1, directionBalleY = 1;
    int nombreOiseaux = 0, nbVie=3, m=0;
    positionSnoopy positionSnoopy1 = positionS(1), positionSnoopy2 = positionS(2), positionSnoopy3 = positionS(3);
    float nombreDeCoupsNvx1 = 0,nombreDeCoupsNvx2=0,nombreDeCoupsNvx3=0, score=0;
    ///////////////////////
    //Variable Sauvegarde//
    ///////////////////////
    int niveauActuel = 0;
    int positionBalleX2 = 6, positionBalleY2 = 5, directionBalleX2 = 1, directionBalleY2 = 1;
    int nombreOiseaux2 = 0, nbVie2=3;
    float nombreDeCoupsNvx1_2 = 0,nombreDeCoupsNvx2_2=0,nombreDeCoupsNvx3_2=0, score_2=0;
    int X=0,Y=0,temp=0;
    positionBloc posB;
    positionBlocCassable posBC;
    positionBlocPiege posBP;
    ////////////////////////////
    //Affichage menu séléction//
    ////////////////////////////
    while (m==0) {
        rMenu = menu();
        switch (rMenu) {
            case 1:
                printf("Voici les regles du jeu :\n");
                printf("Snoopy's Magic Show est un jeu video cree en 1990 qui met en scene le personnage de Snoopy. C'est un jeu de reflexion de type puzzle game ou le but est de recuperer 4 oiseaux pour passer au niveau suivant... mais le chemin le long des niveaux est seme d'embuches..\n");
                printf("Vous devez deplacer Snoopy a l'aide des touches directionnelles de votre clavier pour recuperer les quatres oiseaux qui sont presents sur la carte.\n");
                printf("\n \n");
                break;
            case 2:
                niveau1(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                        positionSnoopy1,
                        &nombreDeCoupsNvx1, nombreDeCoupsNvx2, nombreDeCoupsNvx3,
                        positionBlock(1), positionBlocC(1), positionBlocP(1), etatNiveau1, &score, &nbVie);
                if (nbVie != 0) {
                    niveau2(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                            positionSnoopy2, nombreDeCoupsNvx1, &nombreDeCoupsNvx2, nombreDeCoupsNvx3, positionBlock(2),
                            positionBlocC(2), positionBlocP(2), etatNiveau2, &score, &nbVie);
                }
                if (nbVie != 0) {
                    niveau3(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                            positionSnoopy3, nombreDeCoupsNvx1, nombreDeCoupsNvx2, &nombreDeCoupsNvx3, positionBlock(3),
                            positionBlocC(3), positionBlocP(3), etatNiveau3, &score, &nbVie);
                }
                break;

            case 3:
                lireMatriceDepuisFichier(niveau, "../sauvegardeMatrice.txt");
                FILE* pf = NULL; //On définit la variable fichier comme étant un pointeur sur un fichier
                pf = fopen("../sauvegarde.txt","r"); //On ouvre le fichier score.txt en mode écriture
                fscanf(pf,"%d\n", &niveauActuel);
                fscanf(pf, "%d %d\n", &positionBalleX2, &positionBalleY2);
                fscanf(pf, "%d %d\n", &directionBalleX2, &directionBalleY2);
                fscanf(pf, "%d %d\n", &X, &Y);
                positionSnoopy posS = {X,Y};
                fscanf(pf, "%f %f %f\n", &nombreDeCoupsNvx1_2, &nombreDeCoupsNvx2_2, &nombreDeCoupsNvx3_2);
                fscanf(pf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &posB.positionBlocX1, &posB.positionBlocY1, &posB.positionBlocX2, &posB.positionBlocY2, &posB.positionBlocX3, &posB.positionBlocY3, &posB.positionBlocX4, posB.positionBlocY4, posB.positionBlocX5, posB.positionBlocY5, posB.positionBlocX6, posB.positionBlocY6, posB.positionBlocX7, posB.positionBlocY7, posB.positionBlocX8, posB.positionBlocY8);
                fscanf(pf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &posBC.X1, &posBC.Y1, &posBC.X2, &posBC.Y2, &posBC.X3, &posBC.Y3, &posBC.X4, &posBC.Y4, &posBC.X5, &posBC.Y5, &posBC.X6, &posBC.Y6, &posBC.X7, &posBC.Y7);
                fscanf(pf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &posBP.X1, &posBP.Y1, &posBP.X2, &posBP.Y2, &posBP.X3, &posBP.Y3, &posBP.X4, &posBP.Y4, &posBP.X5, &posBP.Y5, &posBP.X6, &posBP.Y6, &posBP.X7, &posBP.Y7);
                fscanf(pf, "%d\n", &nbVie2);
                fscanf(pf, "%d\n", &nombreOiseaux2);
                fclose(pf);
                niveauX(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                            posS, &nombreDeCoupsNvx1, &nombreDeCoupsNvx2, &nombreDeCoupsNvx3, posB, posBC,
                            posBP, &score, &nbVie);
                break;
            case 4:
                niveauMdp = motDePasse();
                if (niveauMdp == 1) {
                    niveau1(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                            positionSnoopy1, &nombreDeCoupsNvx1, nombreDeCoupsNvx2, nombreDeCoupsNvx3, positionBlock(1),
                            positionBlocC(1), positionBlocP(1), etatNiveau1, &score, &nbVie);
                } else if (niveauMdp == 2) {
                    niveau2(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                            positionSnoopy2, nombreDeCoupsNvx1, &nombreDeCoupsNvx2, nombreDeCoupsNvx3, positionBlock(2),
                            positionBlocC(2), positionBlocP(2), etatNiveau2, &score, &nbVie);
                } else if (niveauMdp == 3) {
                    niveau3(niveau, nombreOiseaux, positionBalleX, positionBalleY, directionBalleX, directionBalleY,
                            positionSnoopy3, nombreDeCoupsNvx1, nombreDeCoupsNvx2, &nombreDeCoupsNvx3, positionBlock(3),
                            positionBlocC(3), positionBlocP(3), etatNiveau3, &score, &nbVie);
                }
                break;
            case 5:
                lectureScoreSauvegarde();
                printf("\n \n");

                break;
            case 6:
                printf("Quitter\n");
                m=1;
                break;
            default:
                break;
        }
    }
    return 0;
}