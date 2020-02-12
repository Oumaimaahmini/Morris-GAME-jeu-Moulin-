#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED


char po='a';
int r,i,j,n,nm,c=1;
char nom1[20];
char nom2[20];


void placement(int nm);
void remplire2(char T[13][13],int p);
void mouvement(int nm);
void testmoulin(char T[13][13],int f,int l);
void enlever(char T[13][13],int f,int l);
void test(char T[13][13]);
void remplire_computer(char T[13][13]);
void placement_computer(int nm);
void testmoulin_computer(char T[13][13],int f);
void enlever_computer(char T[13][13],int f);
void mouvement_computer(int nm);
void remplire2_computer(char T[13][13]);
void joueur_ordinateur_placement();
void joueur_ordinateur_mouvement();
void joueur_humain_mouvement();
void partie();
void enregistrer_partie( char T[13][13]);
void charger_partie(char T[13][13]);
void joueur_humain_placement();



void nouvelle_partie();
void enregistrer();


void remplire(char T[13][13],int p);
void newgrille(char T1[13][13]);
void joueur_joueur();
void tirausort(int nm,char nom[]);
void partie_machine();

void niveau_facile();
void congratulation();
int mouvement_possible(char t[2]);
void arrete_moulin_adversaire(char T[13][13]);
void joueur_ordinateur_placement_niveau2();
void placement_computer_niveau2(int nm);
void niveau_moyen();
void joueurVSmachine();

void creer_moulin(char T[13][13]);
void joueur_ordinateur_placement_niveau3();
void placement_computer_niveau3(int nm);
void niveau_moyen3();

void maxi_moulin(char T[13][13]);
void joueur_ordinateur_placement_niveau4();
void placement_computer_niveau4(int nm);
void niveau_difficile4();

void aleatoire(char T[13][13]);
void niveau_0();
void placement_computer_niveau0(int nm);
void joueur_ordinateur_placement_niveau0();
void saut(char T[13][13],int p);
int future_moulin(char T[13][13],int k,int l);
int faire_moulin(char T[13][13],int k,int l);
int mouvement_exist2(char T[13][13]);
int mouvement_exist1(char T[13][13]);
int is_moulin(char T[13][13],int k,int l);

void mouvement_computer_niveau3(int nm);
void remplire_creer_moulin(char T[13][13]);
void joueur_ordinateur_mouvement_niveau3();

void joueur_ordinateur_mouvement_niveau2();
void mouvement_computer_niveau2(int nm);
void remplire_arrete_moulin(char T[13][13]);

void remplire_maxi_moulin(char T[13][13]);
void joueur_ordinateur_mouvement_niveau4();
void mouvement_computer_niveau4(int nm);


#endif // FONCTION_H_INCLUDED
