#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "interface.h"
#include <time.h>


int main()
{
srand(time(NULL));
bienvenue();
scanf("%d",&c);
while(c==1){
    affichermenue();
    scanf("%d",&n);
    switch(n){
case 1:
    partie();
    break;
case 2:partie_machine();
    break;
case 3:Rules();scanf("%d",&r);
    break;
case 4:Apropos();scanf("%d",&r);
    break;
case 5:Quitter();c=0;
    break;
default : printf("entrer un nombre parmis 1,2,3,4ou5");
    break;

           };
           };
           if (c==0)Quitter();

 return 0;
}
