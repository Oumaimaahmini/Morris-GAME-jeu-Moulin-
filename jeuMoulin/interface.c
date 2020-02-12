#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <math.h>
#include <windows.h>

void bienvenue(){
    system("cls");
    color(9,0);
 printf("                            ***Bienvenue au Moulin!***\n");
    printf("                   \n");
    color(12,0);
    printf("\t\t"); printf(" __________________________________________________\n");
    printf("\t\t"); printf("|                                                  |\n");
    printf("\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t"); printf("|__________________________________________________|");
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
     system("cls");
    color(9,0);
 printf("                            ***Bienvenue au Moulin!***\n");
    printf("                   \n");
    color(12,0);
    printf("\t\t");color(15,0); printf("____________________________________________________\n");color(12,0);
    printf("\t\t");color(6,15); printf("|                                                  |\n");color(12,0);
    printf("\t\t");color(13,7); printf("|   *       *");color(11,7); printf(" *******");color(12,7); printf(" *    *");color(14,7); printf(" *     ");color(9,7); printf("*");color(10,7); printf(" *       *     |\n");color(12,0);
    printf("\t\t");color(13,15); printf("|   * *   * *");color(11,15); printf(" *     *");color(12,15); printf(" *    *");color(14,15); printf(" *     ");color(9,15); printf("*");color(10,15); printf(" * *     *     |\n");color(12,0);
    printf("\t\t");color(13,7); printf("|   *   *   *");color(11,7); printf(" *     *");color(12,7); printf(" *    *");color(14,7); printf(" *     ");color(9,7); printf("*");color(10,7); printf(" *   *   *     |\n");color(12,0);
    printf("\t\t");color(13,15); printf("|   *       *");color(11,15); printf(" *     * ");color(12,15); printf("*    *");color(14,15); printf(" *     ");color(9,15); printf("*");color(10,15); printf(" *     * *     |\n");color(12,0);
    printf("\t\t");color(13,7); printf("|   *       * ");color(11,7); printf("******* ");color(12,7); printf("******");color(14,7); printf(" ***** ");color(9,7); printf("*");color(10,7); printf(" *       *     |\n");color(12,0);
    printf("\t\t");color(0,15); printf("|__________________________________________________|");color(12,0);
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
     system("cls");
    color(9,0);
 printf("                            ***Bienvenue au Moulin!***\n");
    printf("                   \n");
    color(11,0);
    printf("\t\t"); printf(" __________________________________________________\n");
    printf("\t\t"); printf("|                                                  |\n");
    printf("\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t"); printf("|__________________________________________________|");
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
     system("cls");
    color(9,0);
 printf("                            ***Bienvenue au Moulin!***\n");
    printf("                   \n");
    color(12,0);
    printf("\t\t"); printf(" __________________________________________________\n");
    printf("\t\t"); printf("|                                                  |\n");
    printf("\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t"); printf("|__________________________________________________|");
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
    printf("tapez 1 pour commencer ou 0 pour quitter");
    }



void affichermenue(){
            system("cls");

    color(9,0);
    printf("                                      _________________________ \n");
    color(12,0);
    printf("                                     |   1-Joueur vs Joueur    |\n");
     color(9,0);
    printf("                                      _________________________ \n");
     color(12,0);
    printf("                                     |   2-Joueur vs computer  |\n");
     color(9,0);
    printf("                                      _________________________ \n");
     color(12,0);
    printf("                                     |   3-R%cgles du jeu       |\n",138);
     color(9,0);
    printf("                                      _________________________\n");
     color(12,0);
    printf("                                     |   4-A propos            |\n");
     color(9,0);
    printf("                                      _________________________ \n");
     color(12,0);
    printf("                                     |   5-Quitter             |\n");
     color(9,0);
    printf("                                      _________________________       \n");
    printf("            \n");
    color(15,0);
    printf("Quel est ton choix?            \n");

    }





void Rules(){
system("cls");
color(9,0); printf("                                ***R%cgles du jeu***\n",138);
color(14,0);printf(" _______________________________________________________________________\n");
printf("| -Pour gagner,il vous faut laisser l'adversaire avec seulement 2 pions |\n");
printf("| -Ou le priver de tout autre mouvement regulier                        |\n");
printf("| -Vous jouez sur les point d intersection d'un plateau                 |\n");
printf("| -le jeu se deroule en 3 phases:                                       |\n");
printf("|   1-Placement des pions sur le plateau                                |\n");
printf("|   2-Deplaceement des pions                                            |\n");
printf("|   3-Envol:lorsque le joueur a seulement 3 pions                       |\n");
printf("| -Formation d'un moulin:vous pouvez enlever un pion adversaire         |\n");
printf(" _______________________________________________________________________");
printf("\n\n\n");color(15,0);

            printf("                                  ***1-retour***\n");
}





void Apropos(){
   system("cls");
   color(9,0);
           printf("                                  ***A propos***\n\n");
 color(14,0);printf(" __________________________________________________________________________\n");
           printf("| C est l un des jeux les plus anciens du monde,                             |\n");
           printf("| on a retrouve des traces qui datent de 1 400 av. J.C.                      |\n");
           printf("| en Egypte sur une des dalles du plafond du temple de Kurna.                |\n");
           printf("| Un autre dessin fut trouve dans les fouilles de la premiere ville de Troie.| \n");
           printf(" _____________________________________________________________________________");
               printf("   \n");
            printf("   \n");
            printf("   \n");
color(15,0);
            printf("                                  ***1-retour***\n");
}





void Quitter(){ system("cls");
printf(" \n");
   color(9,0);
    printf("                                ***Au revoir***");
           printf(" \n");
           color(12,0);
    printf("\t\t"); printf(" __________________________________________________\n");
    printf("\t\t"); printf("|                                                  |\n");
    printf("\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t"); printf("|__________________________________________________|\n");
    printf("\t\t"); printf("\n\n\n\n");color(15,0);
    printf("                   \n");

     system("cls");
    color(14,0);
 printf("                                ***Au revoir***\n");
    printf("                   \n");
    color(14,0);
    printf("\t\t"); printf(" __________________________________________________\n");
    printf("\t\t"); printf("|                                                  |\n");
    printf("\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t"); printf("|__________________________________________________|");
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
     system("cls");
    color(9,0);
 printf("                                ***Au revoir***\n");
    printf("                   \n");
    color(11,0);
    printf("\t\t"); printf(" __________________________________________________\n");
    printf("\t\t"); printf("|                                                  |\n");
    printf("\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t"); printf("|__________________________________________________|");
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
     system("cls");
    color(9,0);
 printf("                                ***Au revoir***\n");
    printf("                   \n");
    color(12,0);
    printf("\t\t");color(15,0); printf("____________________________________________________\n");color(12,0);
    printf("\t\t");color(6,15); printf("|                                                  |\n");color(12,0);
    printf("\t\t");color(13,7); printf("|   *       *");color(11,7); printf(" *******");color(12,7); printf(" *    *");color(14,7); printf(" *     ");color(9,7); printf("*");color(10,7); printf(" *       *     |\n");color(12,0);
    printf("\t\t");color(13,15); printf("|   * *   * *");color(11,15); printf(" *     *");color(12,15); printf(" *    *");color(14,15); printf(" *     ");color(9,15); printf("*");color(10,15); printf(" * *     *     |\n");color(12,0);
    printf("\t\t");color(13,7); printf("|   *   *   *");color(11,7); printf(" *     *");color(12,7); printf(" *    *");color(14,7); printf(" *     ");color(9,7); printf("*");color(10,7); printf(" *   *   *     |\n");color(12,0);
    printf("\t\t");color(13,15); printf("|   *       *");color(11,15); printf(" *     * ");color(12,15); printf("*    *");color(14,15); printf(" *     ");color(9,15); printf("*");color(10,15); printf(" *     * *     |\n");color(12,0);
    printf("\t\t");color(13,7); printf("|   *       * ");color(11,7); printf("******* ");color(12,7); printf("******");color(14,7); printf(" ***** ");color(9,7); printf("*");color(10,7); printf(" *       *     |\n");color(12,0);
    printf("\t\t");color(0,15); printf("|__________________________________________________|");color(12,0);
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    color(15,0);
}






int i;
void grille(){for(i=0;i<13;i++){

char* G[13];
G[0]="a_____b_____c";
G[1]="|     |     |";
G[2]="| d___e___f |";
G[3]="| |   |   | |";
G[4]="| | g_h_i | |";
G[5]="| | |   | | |";
G[6]="1_2_3   4_5_6";
G[7]="| | |   | | |";
G[8]="| | j_k_l | |";
G[9]="| |   |   | |";
G[10]="| m___n___o |";
G[11]="|     |     |";
G[12]="p_____q_____r";
color(12,0);
printf("                                %s\n",G[i]);color(15,0);};
}




void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}







