#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>







int n,i=0,p=0,nm=1,t=1,n1=0,n2=0,s1=0,s2=0,N=0,s=0,j3=0;
int m[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int mm[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int annuler=0;

char G[13][13]={{'a','_','_','_','_','_','b','_','_','_','_','_','c'},
                {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
                {'|',' ','d','_','_','_','e','_','_','_','f',' ','|'},
                {'|',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ','|'},
                {'|',' ','|',' ','g','_','h','_','i',' ','|',' ','|'},
                {'|',' ','|',' ','|',' ',' ',' ','|',' ','|',' ','|'},
                {'1','_','2','_','3',' ',' ',' ','4','_','5','_','6'},
                {'|',' ','|',' ','|',' ',' ',' ','|',' ','|',' ','|'},
                {'|',' ','|',' ','j','_','k','_','l',' ','|',' ','|'},
                {'|',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ','|'},
                {'|',' ','m','_','_','_','n','_','_','_','o',' ','|'},
                {'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
                {'p','_','_','_','_','_','q','_','_','_','_','_','r'}
                };



char nom1[20];
char nom2[20];
int r;







void placement(int nm){
    int l=1,p=2,f=0;
    N=0;t=1;
    l=nm;
    p=pow(2,(2-nm));
    while(N<9){
    newgrille(G);
    remplire(G,l);
    newgrille(G);
    testmoulin(G,f,l);
   if(t==1) {    /* si le premier joueur choisit de sortir (t=0) le programme sort sans donner la main au 2eme joueur*/
    newgrille(G);
    remplire(G,p);
    newgrille(G);
    testmoulin(G,f,p);
    N++;}}
}
void mouvement(int nm){
    int l=1,p=2,f=0;
    l=nm;
    p=pow(2,(2-nm));
    while(t==1){
    if(s==1&&j3==l)saut(G,l);
    else remplire2(G,l);
    newgrille(G);
    if(t==1)test(G); /*si l utilisatuer tape 0 pour sortir (t=0) le programme ne refait pas le test(modifier le t)*/
    if(t==1){
    testmoulin(G,f,l);
    if(s==1&&j3==p)saut(G,p);
    else remplire2(G,p);
    newgrille(G);
    if(t==1)test(G);
    testmoulin(G,f,p);
    }
    }
    if(annuler!=1){
    if(n1<3||mouvement_exist1(G)==0){color(9,0);printf("***   %s  GAGNE  ***\n",nom2);}
    else{color(12,0); printf("***   %s  GAGNE  ***\n",nom1);}
    congratulation();
    nouvelle_partie();}
    else printf("Au revoir\n");


}
void remplire2(char T[13][13],int p){
    char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";
printf("           \n");
color(15,0);printf(" taper 0 pour retourner au menu\n");
color(9,0);
printf("le schema du jeu\n");
color(14,0);
printf("    a__b__c\n");
printf("    |d_e_f|\n");
printf("    ||ghi||\n");
printf("    123 456\n");
printf("    ||jkl||\n");
printf("    |m_n_o|\n");
printf("    p__q__r\n");
printf("   \n");color(15,0);


    char t[2];
    if(p==1){color(12,0);printf("%s ! deplacerz votre pion selon le schema de: ",nom1);}
    else {color(9,0);printf("%s ! deplacez votre pion selon le schema de: ",nom2);}
    fflush(stdin);
    t[0]=getchar();
    printf("vers:  ");
    fflush(stdin);
    t[1]=getchar();
     int i,j;
     char m;
     if(t[0]=='0'||t[1]=='0')enregistrer();
     else{
            if(mouvement_possible(t)){
     for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(C[i][j]==t[0]){ m=T[i][j];T[i][j]=t[0];}}}

    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(T[i][j]==t[1])T[i][j]=m;}}}
            else printf("mouvement non autorisé");

     }
}
void testmoulin(char T[13][13],int f,int l){
    f=0;
    s2=s1;
    s1=0;
    int i;
    for(i=0;i<16;i++)mm[i]=m[i];
    if(T[0][0]==T[0][6]&&T[0][0]==T[0][12]){
            color(15,0);
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[0]=1;}else m[0]=0;
    if(T[0][0]==T[6][0]&&T[0][0]==T[12][0]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[1]=1;}else m[1]=0;
    if(T[12][0]==T[12][6]&&T[12][0]==T[12][12]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[2]=1;}else m[2]=0;
    if(T[12][12]==T[6][12]&&T[12][12]==T[0][12]){
       printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[3]=1;}else m[3]=0;
    if(T[2][2]==T[2][6]&&T[2][2]==T[2][10]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[4]=1;}else m[4]=0;
    if(T[2][2]==T[6][2]&&T[2][2]==T[10][2]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[5]=1;}else m[5]=0;
    if(T[10][2]==T[10][6]&&T[10][2]==T[10][10]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[6]=1;}else m[6]=0;
    if(T[10][10]==T[6][10]&&T[10][10]==T[2][10]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[7]=1;}else m[7]=0;
    if(T[4][4]==T[4][6]&&T[4][4]==T[4][8]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[8]=1;}else m[8]=0;
    if(T[8][4]==T[8][6]&&T[8][4]==T[8][8]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[9]=1;}else m[9]=0;
    if(T[8][8]==T[6][8]&&T[8][8]==T[4][8]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[10]=1;}else m[10]=0;
    if(T[0][6]==T[2][6]&&T[0][6]==T[4][6]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[11]=1;}else m[11]=0;
    if(T[6][0]==T[6][2]&&T[6][0]==T[6][4]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[12]=1;}else m[12]=0;
    if(T[8][6]==T[10][6]&&T[8][6]==T[12][6]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[13]=1;}else m[13]=0;
    if(T[6][8]==T[6][10]&&T[6][8]==T[6][12]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[14]=1;}else m[14]=0;
    if(T[4][4]==T[6][4]&&T[4][4]==T[8][4]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[15]=1;}else m[15]=0;
        enlever(T,f,l);

}
void enlever(char T[13][13],int f,int l){
    char c;
    char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";
p=0;
for(i=0;i<16;i++){if(mm[i]!=m[i])p=1;}
    if (f==1&&p==1&&s1>=s2){
            if(l==1){
                    printf("           \n");
color(9,0);
printf("le schema du jeu\n");
color(14,0);
printf("    a__b__c\n");
printf("    |d_e_f|\n");
printf("    ||ghi||\n");
printf("    123 456\n");
printf("    ||jkl||\n");
printf("    |m_n_o|\n");
printf("    p__q__r\n");
printf("   \n");color(15,0);printf("%s ! enlever un pion adversaire!",nom1);}
    else {printf("           \n");
color(9,0);
printf("le schema du jeu\n");
color(14,0);
printf("    a__b__c\n");
printf("    |d_e_f|\n");
printf("    ||ghi||\n");
printf("    123 456\n");
printf("    ||jkl||\n");
printf("    |m_n_o|\n");
printf("    p__q__r\n");
printf("   \n");color(15,0);printf("%s ! enlever un pion adversaire!",nom2);}
        fflush(stdin);
        c=getchar();
        int i,j;
         for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(C[i][j]==c) {

            if(l==2&&T[i][j]=='*'&&is_moulin(T,i,j)==0) T[i][j]=C[i][j];
            if(l==1&&T[i][j]=='#'&&faire_moulin(T,i,j)==0) T[i][j]=C[i][j];
            }
            }}
            newgrille(T);
            f=0;
            }
}
void test(char T[13][13]){
    n1=0;
    n2=0;
    t=0;
    int i,j;
     for(i=0;i<13;i++){
        for(j=0;j<13;j++){
                if(T[i][j]=='*')n1++;
                if(T[i][j]=='#')n2++;}}
                color(15,0);
      if(n1==3){s=1;j3=1;printf("   %s !  peut sauter\n",nom1);}
      if(n2==3){s=1;j3=2;printf("   %s !  peut sauter\n",nom2);}
      if(n1>2&&n2>2&&mouvement_exist1(T)==1&&mouvement_exist2(T)==1)t=1;else t=0;
}

void placement_computer(int nm)
{
    N=0;t=1;
    while(N<18){
     if(nm==1){
    joueur_humain_placement();
    nm=2;
    N++;}
    if(nm==2){
    joueur_ordinateur_placement();
    nm=1;
    N++;}
    }
}
void remplire_computer(char T[13][13]){
    int i,j;
    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[i][j]='#';
            i=13;j=13;}
        }
        }
}
void testmoulin_computer(char T[13][13],int f)
{
    f=0;
    s2=s1;
    s1=0;
    int i;
    for(i=0;i<16;i++)mm[i]=m[i];
    if(T[0][0]==T[0][6]&&T[0][0]==T[0][12]){
            color(15,0);
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[0]=1;}else m[0]=0;
        if(T[0][0]==T[6][0]&&T[0][0]==T[12][0]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[1]=1;}else m[1]=0;
        if(T[12][0]==T[12][6]&&T[12][0]==T[12][12]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[2]=1;}else m[2]=0;
        if(T[12][12]==T[6][12]&&T[12][12]==T[0][12]){
       printf("**//Moulin\\**\n");
        f=1;
        s1++;
       m[3]=1;}else m[3]=0;
        if(T[2][2]==T[2][6]&&T[2][2]==T[2][10]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[4]=1;}else m[4]=0;
        if(T[2][2]==T[6][2]&&T[2][2]==T[10][2]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[5]=1;}else m[5]=0;
        if(T[10][2]==T[10][6]&&T[10][2]==T[10][10]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[6]=1;}else m[6]=0;
        if(T[10][10]==T[6][10]&&T[10][10]==T[2][10]){
       printf("**//Moulin\\**\n");
        f=1;
        s1++;
       m[7]=1;}else m[7]=0;
        if(T[4][4]==T[4][6]&&T[4][4]==T[4][8]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
       m[8]=1;}else m[8]=0;
        if(T[8][4]==T[8][6]&&T[8][4]==T[8][8]){
       printf("**//Moulin\\**\n");
        f=1;
        s1++;
       m[9]=1;}else m[9]=0;
        if(T[8][8]==T[6][8]&&T[8][8]==T[4][8]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[10]=1;}else m[10]=0;
        if(T[0][6]==T[2][6]&&T[0][6]==T[4][6]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[11]=1;}else m[11]=0;
        if(T[6][0]==T[6][2]&&T[6][0]==T[6][4]){
        printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[12]=1;}else m[12]=0;
        if(T[8][6]==T[10][6]&&T[8][6]==T[12][6]){
     printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[13]=1;}else m[13]=0;
        if(T[6][8]==T[6][10]&&T[6][8]==T[6][12]){
       printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[14]=1;}else m[14]=0;
        if(T[4][4]==T[6][4]&&T[4][4]==T[8][4]){
       printf("**//Moulin\\**\n");
        f=1;
        s1++;
        m[15]=1;}else m[15]=0;
        enlever_computer(T,f);

}
void enlever_computer(char T[13][13],int f){
    char c;
    char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";
p=0;
for(i=0;i<16;i++){if(mm[i]!=m[i])p=1;}
    if (f==1&&p==1&&s1>=s2){
            color(9,0);
        printf("le computer enleve ton pion!!");color(15,0);
        int i,j;
         for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(T[i][j]=='*'&&is_moulin(T,i,j)==0) {T[i][j]=C[i][j];j=13;i=13;}
            }}
            newgrille(T);
            f=0;
            }
}
void mouvement_computer(int nm){
    while(t==1){
            if(nm==1){
    joueur_humain_mouvement();
    nm=2;}
    if(nm==2&&t==1){
    joueur_ordinateur_mouvement();
    nm=1;
    }
    }
    if(annuler!=1){
    if(n1<3){color(9,0);printf("***   Computer  GAGNE  ***\n");}
    else {color(12,0);printf("***   %s  GAGNE  ***\n",nom1);}
    color(15,0);
    congratulation();
    nouvelle_partie();}
    else printf("Au revoir");
}
void remplire2_computer(char T[13][13]){
     char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";
    int i,j,b=0;
    if(T[0][0]=='#'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][0]=C[0][0];T[i][j]='#';b=1; }
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][0]=C[0][0];T[i][j]='#';b=1; }
    }
    if(T[0][12]=='#'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][12]=C[0][12];T[i][j]='#';b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][12]=C[0][12];T[i][j]='#';b=1; }
    }
    if(T[12][12]=='#'){
            i=12;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][12]=C[12][12];T[i][j]='#';b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][12]=C[12][12];T[i][j]='#';b=1; }
    }
    if(T[12][0]=='#'){
            i=12;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][0]=C[12][0];T[i][j]='#';b=1; }
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][0]=C[12][0];T[i][j]='#';b=1; }
    }
    if(T[2][2]=='#'){
            i=2;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][2]=C[2][2];T[i][j]='#';b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][2]=C[2][2];T[i][j]='#';b=1; }
    }
    if(T[2][10]=='#'){
            i=2;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][10]=C[2][10];T[i][j]='#';b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][10]=C[2][10];T[i][j]='#';b=1; }
    }
    if(T[10][10]=='#'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][10]=C[10][10];T[i][j]='#';b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][10]=C[10][10];T[i][j]='#';b=1; }
    }
    if(T[10][2]=='#'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][2]=C[10][2];T[i][j]='#';b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][2]=C[10][2];T[i][j]='#';b=1; }
    }
    if(T[4][4]=='#'){
            i=4;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][4]=C[4][4];T[i][j]='#';b=1; }
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][4]=C[4][4];T[i][j]='#';b=1; }
    }
    if(T[4][8]=='#'){
            i=4;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][8]=C[4][8];T[i][j]='#';b=1; }
        i=6;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][8]=C[4][8];T[i][j]='#';b=1; }
    }
    if(T[8][8]=='#'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][8]=C[8][8];T[i][j]='#';b=1; }
        i=6;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][8]=C[8][8];T[i][j]='#';b=1; }
    }
    if(T[8][4]=='#'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][4]=C[8][4];T[i][j]='#';b=1; }
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][4]=C[8][4];T[i][j]='#';b=1; }
    }
    if(T[0][6]=='#'){
            i=0;
            j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][6]=C[0][6];T[i][j]='#';b=1; }
        i=0;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][6]=C[0][6];T[i][j]='#';b=1; }
        i=2;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[0][6]=C[0][6];T[i][j]='#';b=1; }
    }
    if(T[6][12]=='#'){
            i=6;
            j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][12]=C[6][12];T[i][j]='#';b=1; }
        i=0;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][12]=C[6][12];T[i][j]='#';b=1; }
        i=12;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][12]=C[6][12];T[i][j]='#';b=1; }
    }
     if(T[12][6]=='#'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][6]=C[12][6];T[i][j]='#';b=1; }
        i=12;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][6]=C[12][6];T[i][j]='#';b=1; }
        i=12;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[12][6]=C[12][6];T[i][j]='#';b=1;}
    }
    if(T[6][0]=='#'){
            i=0;
            j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][0]=C[6][0];T[i][j]='#';b=1; }
        i=12;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][0]=C[6][0];T[i][j]='#';b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][0]=C[6][0];T[i][j]='#';b=1; }
    }
    if(T[4][6]=='#'){
            i=4;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][6]=C[4][6];T[i][j]='#';b=1; }
        i=2;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][6]=C[4][6];T[i][j]='#';b=1; }
        i=4;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[4][6]=C[4][6];T[i][j]='#';b=1; }
    }
    if(T[6][8]=='#'){
            i=4;
            j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][8]=C[6][8];T[i][j]='#';b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][8]=C[6][8];T[i][j]='#';b=1; }
        i=8;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][8]=C[6][8];T[i][j]='#';b=1; }
    }
    if(T[8][6]=='#'){
            i=8;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][6]=C[8][6];T[i][j]='#'; b=1;}
        i=10;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][6]=C[8][6];T[i][j]='#';b=1; }
        i=8;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[8][6]=C[8][6];T[i][j]='#';b=1; }
    }
    if(T[6][4]=='#'){
            i=4;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][4]=C[6][4];T[i][j]='#';b=1; }
        i=8;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][4]=C[6][4];T[i][j]='#';b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][4]=C[6][4];T[i][j]='#'; b=1;}
    }
    if(T[2][6]=='#'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][6]=C[2][6];T[i][j]='#';b=1; }
        i=2;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][6]=C[2][6];T[i][j]='#'; b=1;}
        i=4;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][6]=C[2][6];T[i][j]='#';b=1; }
        i=2;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[2][6]=C[2][6];T[i][j]='#'; b=1;}
    }
    if(T[6][10]=='#'){
            i=6;
            j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][10]=C[6][10];T[i][j]='#'; b=1;}
        i=2;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][10]=C[6][10];T[i][j]='#';b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][10]=C[6][10];T[i][j]='#'; b=1;}
        i=10;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][10]=C[6][10];T[i][j]='#';b=1; }
    }
    if(T[10][6]=='#'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][6]=C[10][6];T[i][j]='#'; b=1;}
        i=10;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][6]=C[10][6];T[i][j]='#'; b=1;}
        i=12;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][6]=C[10][6];T[i][j]='#';b=1; }
        i=10;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[10][6]=C[10][6];T[i][j]='#';b=1; }
    }
     if(T[6][2]=='#'){
            i=2;
            j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][2]=C[6][2];T[i][j]='#'; b=1;}
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][2]=C[6][2];T[i][j]='#'; b=1;}
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][2]=C[6][2];T[i][j]='#';b=1; }
        i=10;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){T[6][2]=C[6][2];T[i][j]='#';b=1; }
    }

}
void joueur_humain_placement(){
    int f=0;
    newgrille(G);
    remplire(G,1);
    newgrille(G);
    testmoulin(G,f,1);

}
void joueur_ordinateur_placement(){
    int f=0;
    newgrille(G);
    remplire_computer(G);
    newgrille(G);
    testmoulin_computer(G,f);

}

void joueur_ordinateur_mouvement(){
    int f=0;
    remplire2_computer(G);
    newgrille(G);
    test(G);
    testmoulin_computer(G,f);

}


void nouvelle_partie(){
    int i,j;
    char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";
    for(i=0;i<13;i++){
        for(j=0;j<13;j++)G[i][j]=C[i][j];
    }
}
void enregistrer(){
    system("cls");
    printf("      \n");
    printf("               voulez vous enregistrer la partie?\n");
      color(9,0);
    printf("                                      ____________ \n");
    color(12,0);
    printf("                                     |   1-OUI    |\n");
     color(9,0);
    printf("                                      _____________ \n");
     color(12,0);
    printf("                                     |   2-NON     |\n");
     color(9,0);
    printf("                                      ______________ \n");
    printf("            \n");
    color(15,0);
    int b=0;
    fflush(stdin);
    scanf("%d",&b);
     switch(b){
case 1:
    t=0;
    N=20;
    annuler=1;
    enregistrer_partie(G);
    break;
case 2:
    nouvelle_partie();
    t=0;
    N=20;
    annuler=1;
    break;

default : printf("entrer un nombre parmis 1 ou 2");
    break;

           };
}
void joueur_humain_mouvement(){
    int f=0;
    if(s==1&&j3==1)saut(G,1);
    else remplire2(G,1);
    newgrille(G);
    test(G);
    testmoulin(G,f,1);

}
void remplire(char T[13][13],int p)
{
    color(15,0);printf("\n\n taper 0 pour retourner au menu\n\n");
    char t;
    char s='+';
    if(p==1){t='*';
        color(12,0);
        printf("%s ! posez votre pion \n",nom1);
        color(15,0);
        fflush(stdin);
        s=getchar();
        }
    else{t='#';
    color(9,0);printf("%s ! posez votre pion \n",nom2);color(15,0);
    fflush(stdin);
    s=getchar();}
    int i,j;
if(s=='0')enregistrer();
else{
    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(T[i][j]==s) T[i][j]=t;
}}}

}
void newgrille(char T1[13][13])
{
    system("cls");
    int i,j;
for(i=0;i<13;i++){
    printf("                      ");
     for(j=0;j<13;j++){
            if(T1[i][j]=='*'){color(12,0);printf("%c ",T1[i][j]);}
            else{
            if(T1[i][j]=='#'){color(9,0);printf("%c ",T1[i][j]);}
            else{color(15,0);printf("%c ",T1[i][j]);}}}

printf("\n");
   }


}
void joueur_joueur()
{
    system("cls");

printf("le nom du joueur 1 est?:");
scanf("%s",nom1);
printf("le nom du joueur 2 est?:");
scanf("%s",nom2);
color(9,0);
printf("                               **%s  VS   %s**\n",nom1,nom2);
printf("       \n");
grille();
color(15,0);
printf(" taper 1 pour commencer");
int k=1;
scanf("%d",&k);
char T[13][13];
nm=(rand()%2)+1;
placement(nm);
mouvement(nm);

}



void tirausort(int nm,char nom[20])
{

    if(nm==1)printf("%s commence le jeu\n",nom1);
else printf("%s commence le jeu\n",nom);

}

void partie_machine(){
     system("cls");

    color(9,0);
    printf("                                      _________________________ \n");
    color(12,0);
    printf("                                     |   1-Nouvelle partie    |\n");
     color(9,0);
    printf("                                      _________________________ \n");
     color(12,0);
    printf("                                     |   2-Partie enregistree  |\n");
     color(9,0);
    printf("                                      _________________________ \n");
    printf("            \n");
    color(15,0);
    printf("Quel est ton choix?            \n");
    int a;
    scanf("%d",&a);
     switch(a){
case 1:
    nouvelle_partie();
    joueurVSmachine();
    break;
case 2:
    charger_partie(G);
    joueurVSmachine();
    break;

default : printf("entrer un nombre parmis 1 ou 2");
    break;

           };
}

void niveau_facile()
{
    system("cls");
printf("le nom du joueur 1 est?:");
scanf("%s",nom1);
color(9,0);
printf("                              **%s  VS  computer**\n",nom1);
printf("       \n");
grille();
char nom[9]="computer";
nm=(rand()%2)+1;
tirausort(nm,nom);
color(15,0);
printf(" taper 1 pour commencer");
int k=1;
scanf("%d",&k);
placement_computer(nm);
mouvement_computer(nm);



}
void congratulation()
{

printf("                   \n");
color(6,0);
    printf("\t\t"); printf(" ________________________________________________________\n");
    color(8,0);
    printf("\t\t"); printf("|                                                        |\n");
    color(9,0);
    printf("\t\t"); printf("|   *       * ******* *    *   *       * * *       *     |\n");
    color(10,0);
    printf("\t\t"); printf("|     *   *   *     * *    *   *       * * * *     *     |\n");
    color(11,0);
    printf("\t\t"); printf("|       *     *     * *    *   *   *   * * *   *   *     |\n");
    color(12,0);
    printf("\t\t"); printf("|       *     *     * *    *   * *   * * * *     * *     |\n");
    color(13,0);
    printf("\t\t"); printf("|       *     ******* ******   *       * * *       *     |\n");
    color(14,0);
    printf("\t\t"); printf("|________________________________________________________|");
    color(15,0);
    printf("\t\t"); printf("\n\n\n\n");
    printf("                   \n");
    printf("                   \n");
    printf("tapez 1 pour retourner ");
    fflush(stdin);
    scanf("%d",&r);
}


int mouvement_possible(char t[2]){
    char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";

int possible=0;
int i,j,k=0,l=0,m=0,n=0;

for(i=0;i<13;i++){
    for(j=0;j<13;j++){
        if(C[i][j]==t[0]){k=i;l=j;}
        if(C[i][j]==t[1]){m=i;n=j;}

                      }
                }
if(k==0 &&l==0 ){if((m==0 &&n==6 )||(m== 6 &&n==0)  )possible=1;}
if(k==0&&l==12){if((m==0&&n==6) ||(m==6&&n==12 ) )possible=1;}
if(k==12 &&l==12 ){if((m==6 &&n==12) ||(m==12 &&n==6 ) )possible=1;}
if(k==12 &&l==0 ){if((m==12 &&n==6) ||(m==6  &&n==0 ) )possible=1;}
if(k==2 &&l==2 ){if((m==2 &&n==6) ||(m==6  &&n==2 ) )possible=1;}
if(k==2 &&l==10 ){if((m==2 &&n==6) ||(m==6  &&n==10 ) )possible=1;}
if(k==10 &&l==10 ){if((m==6 &&n==10) ||(m==10  &&n==6 ) )possible=1;}
if(k==10 &&l==2 ){if((m==10 &&n==6) ||(m==6  &&n==2 ) )possible=1;}
if(k==4 &&l==4 ){if((m==6 &&n==4) ||(m==4  &&n==6 ) )possible=1;}
if(k==4 &&l==8 ){if((m==4 &&n==6) ||(m==6  &&n==8 ) )possible=1;}
if(k==8 &&l==8 ){if((m==6 &&n==8) ||(m==8  &&n==6 ) )possible=1;}
if(k==8 &&l==4 ){if((m==8 &&n==6) ||(m==6  &&n==4 ) )possible=1;}
if(k==0 &&l==6 ){if((m==0 &&n==0)||(m==0  &&n==12 )||(m==2 &&n==6 ) )possible=1;}
if(k==6 &&l==12 ){if((m==0 &&n==12)||(m==12&&n==12 )||(m==6 &&n==10 ) )possible=1;}
if(k==12 &&l==6 ){if((m==12 &&n==12)||(m==12&&n==0 )||(m==10&&n==6 ) )possible=1;}
if(k==6 &&l==0 ){if((m==12 &&n==0)||(m==0&&n==0 )||(m==6 &&n==2 ) )possible=1;}
if(k==4 &&l==6 ){if((m==4 &&n==4)||(m==4&&n==8 )||(m==2 &&n==6 ) )possible=1;}
if(k==6 &&l==8 ){if((m==4 &&n==8)||(m==8&&n==8 )||(m==6 &&n==10 ) )possible=1;}
if(k==8 &&l==6 ){if((m==8 &&n==8)||(m==8&&n==4 )||(m==10 &&n==6 ) )possible=1;}
if(k==6 &&l==4 ){if((m==8 &&n==4)||(m==4&&n==4 )||(m==6 &&n==2 ) )possible=1;}
if(k==2&&l==6 ){if((m==0 &&n==6)||(m==2&&n==10 )||(m==4 &&n==6 )||(m==2&&n==2) )possible=1;}
if(k==6&&l==10 ){if((m==2 &&n==10)||(m==6&&n==12 )||(m==10 &&n==10 )||(m==6&&n==8) )possible=1;}
if(k==10&&l==6 ){if((m==8 &&n==6)||(m==10&&n==10 )||(m==12 &&n==6 )||(m==10&&n==2) )possible=1;}
if(k==6&&l==2 ){if((m==2 &&n==2)||(m==6&&n==4 )||(m==10 &&n==2 )||(m==6&&n==0) )possible=1;}

return possible;
}

void arrete_moulin_adversaire(char T[13][13])
{
    int i,j,k=100,l=100,faire=0;

        for(i=0;i<13;i++){
            for(j=0;j<13;j++){
                if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){k=i;l=j;}
                 if(future_moulin(T,k,l)==1){faire=1;T[k][l]='#';i=13;j=13;}
                 }
        }
      if(faire==0)aleatoire(T);

}
void niveau_moyen()
{
    system("cls");
printf("le nom du joueur 1 est?:");
scanf("%s",nom1);
color(9,0);
printf("                              **%s  VS  computer**\n",nom1);
printf("       \n");
grille();
char nom[9]="computer";
nm=(rand()%2)+1;
tirausort(nm,nom);
color(15,0);
printf(" taper 1 pour commencer");
int k=1;
scanf("%d",&k);
placement_computer_niveau2(nm);
mouvement_computer_niveau2(nm);

}
void placement_computer_niveau2(int nm)
{
    N=0;t=1;
    while(N<18){
     if(nm==1){
    joueur_humain_placement();
    nm=2;
    N++;}
    if(nm==2){
    joueur_ordinateur_placement_niveau2();
    nm=1;
    N++;}
    }
}
void joueur_ordinateur_placement_niveau2(){
    int f=0;
    newgrille(G);
    arrete_moulin_adversaire(G);
    newgrille(G);
    testmoulin_computer(G,f);

}
void joueurVSmachine(){
     system("cls");

       color(9,0);
    printf("                                _____________________________ \n");
    color(12,0);
    printf("                               |   0-Niveau 0 :tres facile   |\n");
    color(9,0);
    printf("                                _____________________________ \n");
    color(12,0);
    printf("                               |   1-Niveau 1 :facile        |\n");
     color(9,0);
    printf("                                _____________________________\n");
     color(12,0);
    printf("                               |   2-Niveau 2 :moyen2        |\n");
     color(9,0);
    printf("                                _____________________________\n");
     color(12,0);
    printf("                               |   3-Niveau 3 :moyen3        |\n");
     color(9,0);
    printf("                                _____________________________\n");
    color(12,0);
    printf("                               |   4-Niveau 4 :difficile     |\n");
     color(9,0);
    printf("                                ______________________________\n");
    printf("            \n");
    color(15,0);
    printf("Quel est ton choix?            \n");
    int a;
    fflush(stdin);
    scanf("%d",&a);
     switch(a){
case 0:
    niveau_0();

    break;
case 1:
    niveau_facile();

    break;
case 2:
    niveau_moyen();

    break;
case 3:
    niveau_moyen3();

    break;

case 4:
    niveau_difficile4();

    break;

default : printf("entrer un nombre parmis0,1,2,3 ou 4");
    break;

           };

}
void partie(){
     system("cls");

    color(9,0);
    printf("                                      _________________________ \n");
    color(12,0);
    printf("                                     |   1-Nouvelle partie    |\n");
     color(9,0);
    printf("                                      _________________________ \n");
     color(12,0);
    printf("                                     |   2-Partie enregistree  |\n");
     color(9,0);
    printf("                                      _________________________ \n");
    printf("            \n");
    color(15,0);
    printf("Quel est ton choix?            \n");
    int a;
    scanf("%d",&a);
     switch(a){
case 1:
    nouvelle_partie();
    joueur_joueur();
    break;
case 2:
    charger_partie(G);
    joueur_joueur();
    break;

default : printf("entrer un nombre parmis 1 ou 2");
    break;

           };
}
void enregistrer_partie( char T[13][13])
{

    FILE* fichier = NULL;

    fichier = fopen("test.txt", "w+");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        int i,j;
        for(i=0;i<13;i++){
            for(j=0;j<13;j++){
                    fputc(T[i][j], fichier); // Écriture du caractère A

            }
        }
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }


}

void charger_partie(char T[13][13])
{
    FILE* fichier = NULL;

    fichier = fopen("test.txt", "r");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        int i,j;
        for(i=0;i<13;i++){
            for(j=0;j<13;j++){
                    T[i][j]=fgetc(fichier); // Écriture du caractère A

            }
        }
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible de lire le fichier test.txt");
    }
}
void creer_moulin(char T[13][13])
{
     int i,j,faire=0;

        for(i=0;i<13;i++){
            for(j=0;j<13;j++){
                if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '&&faire_moulin(T,i,j)==1)
                 {faire=1;T[i][j]='#';i=13;j=13;}}

        }
      if(faire==0)remplire_computer(T);

}
void niveau_moyen3()
{
    system("cls");
printf("le nom du joueur 1 est?:");
scanf("%s",nom1);
color(9,0);
printf("                              **%s  VS  computer**\n",nom1);
printf("       \n");
grille();
char nom[9]="computer";
nm=(rand()%2)+1;
tirausort(nm,nom);
color(15,0);
printf(" taper 1 pour commencer");
int k=1;
scanf("%d",&k);
placement_computer_niveau3(nm);
mouvement_computer_niveau3(nm);

}
void placement_computer_niveau3(int nm)
{
    N=0;t=1;
    while(N<18){
     if(nm==1){
    joueur_humain_placement();
    nm=2;
    N++;}
    if(nm==2){
    joueur_ordinateur_placement_niveau3();
    nm=1;
    N++;}
    }
}
void joueur_ordinateur_placement_niveau3(){
    int f=0;
    newgrille(G);
    creer_moulin(G);
    newgrille(G);
    testmoulin_computer(G,f);

}

void niveau_difficile4()
{
    system("cls");
printf("le nom du joueur 1 est?:");
scanf("%s",nom1);
color(9,0);
printf("                              **%s  VS  computer**\n",nom1);
printf("       \n");
grille();
char nom[9]="computer";
nm=(rand()%2)+1;
tirausort(nm,nom);
color(15,0);
printf(" taper 1 pour commencer");
int k=1;
scanf("%d",&k);
placement_computer_niveau4(nm);
mouvement_computer_niveau4(nm);

}
void placement_computer_niveau4(int nm)
{
    N=0;t=1;
    while(N<18){
     if(nm==1){
    joueur_humain_placement();
    nm=2;
    N++;}
    if(nm==2){
    joueur_ordinateur_placement_niveau4();
    nm=1;
    N++;}
    }
}
void joueur_ordinateur_placement_niveau4(){
    int f=0;
    newgrille(G);
    maxi_moulin(G);
    newgrille(G);
    testmoulin_computer(G,f);

}
void maxi_moulin(char T[13][13])
{
   int i,j,faire=0;

        for(i=0;i<13;i++){
            for(j=0;j<13;j++){
                if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '&&faire_moulin(T,i,j)==1)
                 {faire=1;T[i][j]='#';i=13;j=13;}}

        }
      if(faire==0)arrete_moulin_adversaire(T);

}

void aleatoire(char T[13][13])
{
    int k,l,t=0;
    while(t==0)
        {
            k=(rand()%13);l=(rand()%13);
            if(T[k][l]!='*'&&T[k][l]!='#'&&T[k][l]!='_'&&T[k][l]!='|'&&T[k][l]!=' '){T[k][l]='#';t=1;}

    }


}
void niveau_0()
{
    system("cls");
printf("le nom du joueur 1 est?:");
scanf("%s",nom1);
color(9,0);
printf("                              **%s  VS  computer**\n",nom1);
printf("       \n");
grille();
char nom[9]="computer";
nm=(rand()%2)+1;
tirausort(nm,nom);
color(15,0);
printf(" taper 1 pour commencer");
int k=1;
scanf("%d",&k);
placement_computer_niveau0(nm);
mouvement_computer(nm);

}
void placement_computer_niveau0(int nm)
{
    N=0;t=1;
    while(N<18){
     if(nm==1){
    joueur_humain_placement();
    nm=2;
    N++;}
    if(nm==2){
    joueur_ordinateur_placement_niveau0();
    nm=1;
    N++;}
    }
}
void joueur_ordinateur_placement_niveau0()
{
    int f=0;
    newgrille(G);
    aleatoire(G);
    newgrille(G);
    testmoulin_computer(G,f);

}
void saut(char T[13][13],int p)
{
    char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";
printf("           \n");
color(15,0);printf(" taper 0 pour retourner au menu\n");
color(9,0);
printf("le schema du jeu\n");
color(14,0);
printf("    a__b__c\n");
printf("    |d_e_f|\n");
printf("    ||ghi||\n");
printf("    123 456\n");
printf("    ||jkl||\n");
printf("    |m_n_o|\n");
printf("    p__q__r\n");
printf("   \n");color(15,0);


    char t[2];
    if(p==1){color(12,0);printf("%s ! deplacerz votre pion selon le schema de: ",nom1);}
    else {color(9,0);printf("%s ! deplacez votre pion selon le schema de: ",nom2);}
    fflush(stdin);
    t[0]=getchar();
    printf("vers:  ");
    fflush(stdin);
    t[1]=getchar();
     int i,j;
     char m;
     if(t[0]=='0'||t[1]=='0')enregistrer();
     else{
     for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(C[i][j]==t[0]){ m=T[i][j];T[i][j]=t[0];}}}

    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(T[i][j]==t[1])T[i][j]=m;}}}



}
int future_moulin(char T[13][13],int k,int l)
{
    int moulinadversaire=0;
if(k==0 &&l==0 ){if((T[0][6]=='*'&&T[0][12]=='*' )||(T[6][0]=='*'&&T[12][0]=='*') )moulinadversaire=1;}
if(k==0&&l==12){if((T[0][6]=='*'&&T[0][0]=='*' )||(T[6][12]=='*'&&T[12][12]=='*') )moulinadversaire=1;}
if(k==12 &&l==12 ){if((T[12][6]=='*'&&T[12][0]=='*' )||(T[6][12]=='*'&&T[0][12]=='*') )moulinadversaire=1;}
if(k==12 &&l==0 ){if((T[6][0]=='*'&&T[0][0]=='*' )||(T[12][6]=='*'&&T[12][12]=='*') )moulinadversaire=1;}
if(k==2 &&l==2 ){if((T[2][6]=='*'&&T[2][10]=='*' )||(T[6][2]=='*'&&T[10][2]=='*') )moulinadversaire=1;}
if(k==2 &&l==10 ){if((T[2][2]=='*'&&T[2][6]=='*' )||(T[6][10]=='*'&&T[10][10]=='*') )moulinadversaire=1;}
if(k==10 &&l==10 ){if((T[10][2]=='*'&&T[10][6]=='*' )||(T[6][10]=='*'&&T[10][10]=='*') )moulinadversaire=1;}
if(k==10 &&l==2 ){if((T[10][10]=='*'&&T[10][6]=='*' )||(T[2][2]=='*'&&T[6][2]=='*') )moulinadversaire=1;}
if(k==4 &&l==4 ){if((T[4][6]=='*'&&T[4][8]=='*' )||(T[6][4]=='*'&&T[8][4]=='*') )moulinadversaire=1;}
if(k==4 &&l==8 ){if((T[4][4]=='*'&&T[4][6]=='*' )||(T[6][8]=='*'&&T[8][8]=='*') )moulinadversaire=1;}
if(k==8 &&l==8 ){if((T[4][8]=='*'&&T[6][8]=='*' )||(T[8][6]=='*'&&T[8][4]=='*') )moulinadversaire=1;}
if(k==8 &&l==4 ){if((T[8][6]=='*'&&T[8][8]=='*' )||(T[6][4]=='*'&&T[4][4]=='*') )moulinadversaire=1;}
if(k==0 &&l==6 ){if((T[0][0]=='*'&&T[0][12]=='*' )||(T[2][6]=='*'&&T[4][6]=='*') )moulinadversaire=1;}
if(k==6 &&l==12 ){if((T[0][12]=='*'&&T[12][12]=='*' )||(T[6][10]=='*'&&T[6][8]=='*') )moulinadversaire=1;}
if(k==12 &&l==6 ){if((T[12][0]=='*'&&T[12][12]=='*' )||(T[10][6]=='*'&&T[8][6]=='*') )moulinadversaire=1;}
if(k==6 &&l==0 ){if((T[0][0]=='*'&&T[12][0]=='*' )||(T[6][2]=='*'&&T[6][4]=='*') )moulinadversaire=1;}
if(k==4 &&l==6 ){if((T[0][6]=='*'&&T[2][6]=='*' )||(T[4][4]=='*'&&T[4][8]=='*') )moulinadversaire=1;}
if(k==6 &&l==8 ){if((T[6][10]=='*'&&T[6][12]=='*' )||(T[4][8]=='*'&&T[8][8]=='*') )moulinadversaire=1;}
if(k==8 &&l==6 ){if((T[8][4]=='*'&&T[8][8]=='*' )||(T[10][6]=='*'&&T[12][6]=='*') )moulinadversaire=1;}
if(k==6 &&l==4 ){if((T[6][0]=='*'&&T[6][2]=='*' )||(T[4][4]=='*'&&T[8][4]=='*') )moulinadversaire=1;}
if(k==2&&l==6 ){if((T[2][2]=='*'&&T[2][10]=='*' )||(T[0][6]=='*'&&T[4][6]=='*') )moulinadversaire=1;}
if(k==6&&l==10 ){if((T[6][8]=='*'&&T[6][12]=='*' )||(T[2][10]=='*'&&T[10][10]=='*') )moulinadversaire=1;}
if(k==10&&l==6 ){if((T[10][2]=='*'&&T[10][10]=='*' )||(T[8][6]=='*'&&T[12][6]=='*') )moulinadversaire=1;}
if(k==6&&l==2 ){if((T[6][0]=='*'&&T[6][4]=='*' )||(T[2][2]=='*'&&T[10][2]=='*') )moulinadversaire=1;}

return moulinadversaire;

}

int faire_moulin(char T[13][13],int k,int l)
{
      int moulin=0;
if(k==0 &&l==0 ){if((T[0][6]=='#'&&T[0][12]=='#' )||(T[6][0]=='#'&&T[12][0]=='#') )moulin=1;}
if(k==0&&l==12){if((T[0][6]=='#'&&T[0][0]=='#' )||(T[6][12]=='#'&&T[12][12]=='#') )moulin=1;}
if(k==12 &&l==12 ){if((T[12][6]=='#'&&T[12][0]=='#' )||(T[6][12]=='#'&&T[0][12]=='#') )moulin=1;}
if(k==12 &&l==0 ){if((T[6][0]=='#'&&T[0][0]=='#' )||(T[12][6]=='#'&&T[12][12]=='#') )moulin=1;}
if(k==2 &&l==2 ){if((T[2][6]=='#'&&T[2][10]=='#' )||(T[6][2]=='#'&&T[10][2]=='#') )moulin=1;}
if(k==2 &&l==10 ){if((T[2][2]=='#'&&T[2][6]=='#' )||(T[6][10]=='#'&&T[10][10]=='#') )moulin=1;}
if(k==10 &&l==10 ){if((T[10][2]=='#'&&T[10][6]=='#' )||(T[6][10]=='#'&&T[10][10]=='#') )moulin=1;}
if(k==10 &&l==2 ){if((T[10][10]=='#'&&T[10][6]=='#' )||(T[2][2]=='#'&&T[6][2]=='#') )moulin=1;}
if(k==4 &&l==4 ){if((T[4][6]=='#'&&T[4][8]=='#' )||(T[6][4]=='#'&&T[8][4]=='#') )moulin=1;}
if(k==4 &&l==8 ){if((T[4][4]=='#'&&T[4][6]=='#' )||(T[6][8]=='#'&&T[8][8]=='#') )moulin=1;}
if(k==8 &&l==8 ){if((T[4][8]=='#'&&T[6][8]=='#' )||(T[8][6]=='#'&&T[8][4]=='#') )moulin=1;}
if(k==8 &&l==4 ){if((T[8][6]=='#'&&T[8][8]=='#' )||(T[6][4]=='#'&&T[4][4]=='#') )moulin=1;}
if(k==0 &&l==6 ){if((T[0][0]=='#'&&T[0][12]=='#' )||(T[2][6]=='#'&&T[4][6]=='#') )moulin=1;}
if(k==6 &&l==12 ){if((T[0][12]=='#'&&T[12][12]=='#' )||(T[6][10]=='#'&&T[6][8]=='#') )moulin=1;}
if(k==12 &&l==6 ){if((T[12][0]=='#'&&T[12][12]=='#' )||(T[10][6]=='#'&&T[8][6]=='#') )moulin=1;}
if(k==6 &&l==0 ){if((T[0][0]=='#'&&T[12][0]=='#' )||(T[6][2]=='#'&&T[6][4]=='#') )moulin=1;}
if(k==4 &&l==6 ){if((T[0][6]=='#'&&T[2][6]=='#' )||(T[4][4]=='#'&&T[4][8]=='#') )moulin=1;}
if(k==6 &&l==8 ){if((T[6][10]=='#'&&T[6][12]=='#' )||(T[4][8]=='#'&&T[8][8]=='#') )moulin=1;}
if(k==8 &&l==6 ){if((T[8][4]=='#'&&T[8][8]=='#' )||(T[10][6]=='#'&&T[12][6]=='#') )moulin=1;}
if(k==6 &&l==4 ){if((T[6][0]=='#'&&T[6][2]=='#' )||(T[4][4]=='#'&&T[8][4]=='#') )moulin=1;}
if(k==2&&l==6 ){if((T[2][2]=='#'&&T[2][10]=='#' )||(T[0][6]=='#'&&T[4][6]=='#') )moulin=1;}
if(k==6&&l==10 ){if((T[6][8]=='#'&&T[6][12]=='#' )||(T[2][10]=='#'&&T[10][10]=='#') )moulin=1;}
if(k==10&&l==6 ){if((T[10][2]=='#'&&T[10][10]=='#' )||(T[8][6]=='#'&&T[12][6]=='#') )moulin=1;}
if(k==6&&l==2 ){if((T[6][0]=='#'&&T[6][4]=='#' )||(T[2][2]=='#'&&T[10][2]=='#') )moulin=1;}

return moulin;
}

int mouvement_exist2(char T[13][13])
{

    int i,j,b=0;
    if(T[0][0]=='#'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[0][12]=='#'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[12][12]=='#'){
            i=12;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[12][0]=='#'){
            i=12;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[2][2]=='#'){
            i=2;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[2][10]=='#'){
            i=2;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[10][10]=='#'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[10][2]=='#'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[4][4]=='#'){
            i=4;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[4][8]=='#'){
            i=4;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[8][8]=='#'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[8][4]=='#'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[0][6]=='#'){
            i=0;
            j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=0;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[6][12]=='#'){
            i=6;
            j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=0;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
     if(T[12][6]=='#'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1;}
    }
    if(T[6][0]=='#'){
            i=0;
            j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[4][6]=='#'){
            i=4;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=4;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[6][8]=='#'){
            i=4;
            j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=8;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[8][6]=='#'){
            i=8;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=10;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=8;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[6][4]=='#'){
            i=4;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=8;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
    }
    if(T[2][6]=='#'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=4;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
    }
    if(T[6][10]=='#'){
            i=6;
            j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' ') b=1;
        i=2;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=10;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[10][6]=='#'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=10;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=12;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=10;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
     if(T[6][2]=='#'){
            i=2;
            j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=10;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
 return b;

}

int mouvement_exist1(char T[13][13])
{

    int i,j,b=0;
    if(T[0][0]=='*'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[0][12]=='*'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[12][12]=='*'){
            i=12;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[12][0]=='*'){
            i=12;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[2][2]=='*'){
            i=2;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[2][10]=='*'){
            i=2;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[10][10]=='*'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[10][2]=='*'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[4][4]=='*'){
            i=4;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[4][8]=='*'){
            i=4;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[8][8]=='*'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[8][4]=='*'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[0][6]=='*'){
            i=0;
            j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=0;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[6][12]=='*'){
            i=6;
            j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=0;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
     if(T[12][6]=='*'){
            i=10;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1;}
    }
    if(T[6][0]=='*'){
            i=0;
            j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=12;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[4][6]=='*'){
            i=4;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=4;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[6][8]=='*'){
            i=4;
            j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=8;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[8][6]=='*'){
            i=8;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=10;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=8;
        j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[6][4]=='*'){
            i=4;
            j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=8;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
    }
    if(T[2][6]=='*'){
            i=0;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=4;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=2;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
    }
    if(T[6][10]=='*'){
            i=6;
            j=8;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' ') b=1;
        i=2;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=6;
        j=12;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=10;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
    if(T[10][6]=='*'){
            i=8;
            j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=10;
        j=10;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=12;
        j=6;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=10;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
     if(T[6][2]=='*'){
            i=2;
            j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=6;
        j=4;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){ b=1;}
        i=6;
        j=0;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
        i=10;
        j=2;
        if(b==0&&T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '){b=1; }
    }
 return b;

}
int is_moulin(char T[13][13],int k,int l)
{
    int moulinadversaire=0;
if(k==0 &&l==0 ){if((T[0][6]=='*'&&T[0][12]=='*' )||(T[6][0]=='*'&&T[12][0]=='*') )moulinadversaire=1;}
if(k==0&&l==12){if((T[0][6]=='*'&&T[0][0]=='*' )||(T[6][12]=='*'&&T[12][12]=='*') )moulinadversaire=1;}
if(k==12 &&l==12 ){if((T[12][6]=='*'&&T[12][0]=='*' )||(T[6][12]=='*'&&T[0][12]=='*') )moulinadversaire=1;}
if(k==12 &&l==0 ){if((T[6][0]=='*'&&T[0][0]=='*' )||(T[12][6]=='*'&&T[12][12]=='*') )moulinadversaire=1;}
if(k==2 &&l==2 ){if((T[2][6]=='*'&&T[2][10]=='*' )||(T[6][2]=='*'&&T[10][2]=='*') )moulinadversaire=1;}
if(k==2 &&l==10 ){if((T[2][2]=='*'&&T[2][6]=='*' )||(T[6][10]=='*'&&T[10][10]=='*') )moulinadversaire=1;}
if(k==10 &&l==10 ){if((T[10][2]=='*'&&T[10][6]=='*' )||(T[6][10]=='*'&&T[10][10]=='*') )moulinadversaire=1;}
if(k==10 &&l==2 ){if((T[10][10]=='*'&&T[10][6]=='*' )||(T[2][2]=='*'&&T[6][2]=='*') )moulinadversaire=1;}
if(k==4 &&l==4 ){if((T[4][6]=='*'&&T[4][8]=='*' )||(T[6][4]=='*'&&T[8][4]=='*') )moulinadversaire=1;}
if(k==4 &&l==8 ){if((T[4][4]=='*'&&T[4][6]=='*' )||(T[6][8]=='*'&&T[8][8]=='*') )moulinadversaire=1;}
if(k==8 &&l==8 ){if((T[4][8]=='*'&&T[6][8]=='*' )||(T[8][6]=='*'&&T[8][4]=='*') )moulinadversaire=1;}
if(k==8 &&l==4 ){if((T[8][6]=='*'&&T[8][8]=='*' )||(T[6][4]=='*'&&T[4][4]=='*') )moulinadversaire=1;}
if(k==0 &&l==6 ){if((T[0][0]=='*'&&T[0][12]=='*' )||(T[2][6]=='*'&&T[4][6]=='*') )moulinadversaire=1;}
if(k==6 &&l==12 ){if((T[0][12]=='*'&&T[12][12]=='*' )||(T[6][10]=='*'&&T[6][8]=='*') )moulinadversaire=1;}
if(k==12 &&l==6 ){if((T[12][0]=='*'&&T[12][12]=='*' )||(T[10][6]=='*'&&T[8][6]=='*') )moulinadversaire=1;}
if(k==6 &&l==0 ){if((T[0][0]=='*'&&T[12][0]=='*' )||(T[6][2]=='*'&&T[6][4]=='*') )moulinadversaire=1;}
if(k==4 &&l==6 ){if((T[0][6]=='*'&&T[2][6]=='*' )||(T[4][4]=='*'&&T[4][8]=='*') )moulinadversaire=1;}
if(k==6 &&l==8 ){if((T[6][10]=='*'&&T[6][12]=='*' )||(T[4][8]=='*'&&T[8][8]=='*') )moulinadversaire=1;}
if(k==8 &&l==6 ){if((T[8][4]=='*'&&T[8][8]=='*' )||(T[10][6]=='*'&&T[12][6]=='*') )moulinadversaire=1;}
if(k==6 &&l==4 ){if((T[6][0]=='*'&&T[6][2]=='*' )||(T[4][4]=='*'&&T[8][4]=='*') )moulinadversaire=1;}
if(k==2&&l==6 ){if((T[2][2]=='*'&&T[2][10]=='*' )||(T[0][6]=='*'&&T[4][6]=='*') )moulinadversaire=1;}
if(k==6&&l==10 ){if((T[6][8]=='*'&&T[6][12]=='*' )||(T[2][10]=='*'&&T[10][10]=='*') )moulinadversaire=1;}
if(k==10&&l==6 ){if((T[10][2]=='*'&&T[10][10]=='*' )||(T[8][6]=='*'&&T[12][6]=='*') )moulinadversaire=1;}
if(k==6&&l==2 ){if((T[6][0]=='*'&&T[6][4]=='*' )||(T[2][2]=='*'&&T[10][2]=='*') )moulinadversaire=1;}

return moulinadversaire;

}

void remplire_creer_moulin(char T[13][13])
{
    char t[2];
    int i,j,k,l,faire=0;
     char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";

for(i=0;i<13;i++){
    for(j=0;j<13;j++){
        if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '&&faire_moulin(T,i,j)==1){
            t[1]=C[i][j];
            for(k=0;k<13;k++){
                for(l=0;l<13;l++){
                        if(T[k][l]=='#'){t[0]=C[k][l];
                        if(mouvement_possible(t)==1){
                            T[k][l]=C[k][l];
                            T[i][j]='#';
                            k=13;l=13;i=13;j=13;faire=1;
                        }}
        }
    }
}
    }}
    if(faire==0)remplire2_computer(T);

}
void mouvement_computer_niveau3(int nm){
    while(t==1){
            if(nm==1){
    joueur_humain_mouvement();
    nm=2;}
    if(nm==2&&t==1){
    joueur_ordinateur_mouvement_niveau3();
    nm=1;
    }
    }
    if(annuler!=1){
    if(n1<3){color(9,0);printf("***   Computer  GAGNE  ***\n");}
    else {color(12,0);printf("***   %s  GAGNE  ***\n",nom1);}
    color(15,0);
    congratulation();
    nouvelle_partie();}
    else printf("Au revoir");
}
void joueur_ordinateur_mouvement_niveau3()
{
    int f=0;
    remplire_creer_moulin(G);
    newgrille(G);
    test(G);
    testmoulin_computer(G,f);

}

void remplire_arrete_moulin(char T[13][13])
{
    char t[2];
    int i,j,k,l,faire=0;
     char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";

for(i=0;i<13;i++){
    for(j=0;j<13;j++){
        if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '&&future_moulin(T,i,j)==1){
            t[1]=C[i][j];
            for(k=0;k<13;k++){
                for(l=0;l<13;l++){
                        if(T[k][l]=='#'){t[0]=C[k][l];
                        if(mouvement_possible(t)==1){
                            T[k][l]=C[k][l];
                            T[i][j]='#';
                            k=13;l=13;i=13;j=13;faire=1;
                        }}
        }
    }
}
    }}
    if(faire==0)remplire2_computer(T);

}
void mouvement_computer_niveau2(int nm){
    while(t==1){
            if(nm==1){
    joueur_humain_mouvement();
    nm=2;}
    if(nm==2&&t==1){
    joueur_ordinateur_mouvement_niveau2();
    nm=1;
    }
    }
    if(annuler!=1){
    if(n1<3){color(9,0);printf("***   Computer  GAGNE  ***\n");}
    else {color(12,0);printf("***   %s  GAGNE  ***\n",nom1);}
    color(15,0);
    congratulation();
    nouvelle_partie();}
    else printf("Au revoir");
}
void joueur_ordinateur_mouvement_niveau2()
{
    int f=0;
    remplire_arrete_moulin(G);
    newgrille(G);
    test(G);
    testmoulin_computer(G,f);

}
void mouvement_computer_niveau4(int nm)
{
    while(t==1){
            if(nm==1){
    joueur_humain_mouvement();
    nm=2;}
    if(nm==2&&t==1){
    joueur_ordinateur_mouvement_niveau4();
    nm=1;
    }
    }
    if(annuler!=1){
    if(n1<3){color(9,0);printf("***   Computer  GAGNE  ***\n");}
    else {color(12,0);printf("***   %s  GAGNE  ***\n",nom1);}
    color(15,0);
    congratulation();
    nouvelle_partie();}
    else printf("Au revoir");
}
void joueur_ordinateur_mouvement_niveau4()
{
    int f=0;
    remplire_maxi_moulin(G);
    newgrille(G);
    test(G);
    testmoulin_computer(G,f);

}
void remplire_maxi_moulin(char T[13][13])
{
    char t[2];
    int i,j,k,l,faire=0;
     char* C[13];
C[0]="a_____b_____c";
C[1]="|     |     |";
C[2]="| d___e___f |";
C[3]="| |   |   | |";
C[4]="| | g_h_i | |";
C[5]="| | |   | | |";
C[6]="1_2_3   4_5_6";
C[7]="| | |   | | |";
C[8]="| | j_k_l | |";
C[9]="| |   |   | |";
C[10]="| m___n___o |";
C[11]="|     |     |";
C[12]="p_____q_____r";

for(i=0;i<13;i++){
    for(j=0;j<13;j++){
        if(T[i][j]!='*'&&T[i][j]!='#'&&T[i][j]!='_'&&T[i][j]!='|'&&T[i][j]!=' '&&faire_moulin(T,i,j)==1){
            t[1]=C[i][j];
            for(k=0;k<13;k++){
                for(l=0;l<13;l++){
                        if(T[k][l]=='#'){t[0]=C[k][l];
                        if(mouvement_possible(t)==1){
                            T[k][l]=C[k][l];
                            T[i][j]='#';
                            k=13;l=13;i=13;j=13;faire=1;
                        }}
        }
    }
}
    }}
    if(faire==0)remplire_arrete_moulin(T);

}

