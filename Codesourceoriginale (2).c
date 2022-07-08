#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
char code[30];
char date_fab[30];
char etat[30];
int jour;
int mois;
int annee;
int age;
int cap;
int nb_voy;
}avion;

typedef struct{
    avion AV;
    struct structnoeud  *suivant;
    struct structnoeud *precedent;
}structnoeud;
typedef structnoeud *NOEUD;

typedef struct{
    int lg;
    NOEUD tete;
    NOEUD queue;
}structliste;
typedef structliste *LISTE;


/*
void tri(LISTE l){
int k,i,o,min;
int m=0;
NOEUD n;
LISTE LR=creer_liste();

for(k=1;k<=l->lg;k++){
    if(m>1){
        for(o=0;o<i;o++){
            n=n->suivant;
                        }
            }
    min=n->AV.age;
for(i=1;i<=l->lg-k+1;i++ ){
if(n->AV.age<min){min=n->AV.age;}
}
AjoutDebut (LR,n->AV.age,n->AV.nb_voy,n->AV.cap,n->AV.jour,n->AV.mois,n->AV.annee,n->AV.etat,n->AV.code);
n=n->suivant;
}
NOEUD q=LR->tete;
printf("\n la liste apres le tri   ");
for(i=1;i<=LR->lg;i++){
    printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %i/%i/%i | son etat : %s | son nombre de voyage : %i ||",q->AV.code,q->AV.cap,2020-q->AV.annee,q->AV.jour,q->AV.mois,q->AV.annee,q->AV.etat,q->AV.nb_voy);
}
}
*/


int menu(){
 printf("");
    printf("\n");
    printf("\n");
    printf("\n \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\____MENU Principale____//////////////////////////////////////////////////////////////////////////////");
 printf("\n");
    printf("\n");
printf("\n 1- Verifier la presence d'un avion  ");
printf("\n 2- supprimer les avions ages de plus de 20 ans et qui sont en maintenace technique ");
printf("\n 3- Trier les avions par ordre croissant selon l'age ");
printf("\n 4- Afficher les avions qui ont assure le nombre maximale et ages de moins de 10 ans ");
printf("\n 5- Afficher les avions qui ont assure le nombre minimale et ages de moins de 10 ans ");
printf("\n 6- Scinder la liste principale en ses trois formes ");
printf("\n 7- Afficher les avions atterits ,decolles et en maintenance technique  ");
printf("\n 8- Affiche les avions atterits par un traitement recursif  ");
int rep;
scanf("%i",&rep);
while(rep<1 || rep>8){
        printf("");
    printf("\n");
    printf("\n");
    printf("\n \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\____MENU Principale____//////////////////////////////////////////////////////////////////////////////");
 printf("\n");
    printf("\n");
    printf("\n 1- Verifier la presence d'un avion  ");
printf("\n 2- supprimer les avions ages de plus de 20 ans et qui sont en maintenace technique ");
printf("\n 3- Trier les avions par ordre croissant selon l'age ");
printf("\n 4- Afficher les avions qui ont assure le nombre maximale et ages de moins de 10 ans ");
printf("\n 5- Afficher les avions qui ont assure le nombre minimale et ages de moins de 10 ans ");
printf("\n 6- Scinder la liste principale en ses trois formes ");
printf("\n 7- Afficher les avions atterits ,decolles et en maintenance technique  ");
printf("\n 8- Affiche les avions atterits par un traitement recursif  ");
scanf("%i",&rep);
}
}







void  afficher_avion_atterit (LISTE l,int i,NOEUD n){

 printf("\n les avions atterits sont");
if((i<=l->lg)&&(strcmp(n->AV.etat,"a")==0)){

    printf("\n   %s ",n->AV.code);

    afficher_avion_atterit(l,i+1,n=n->suivant);
}
}







LISTE creer_liste (){
LISTE L;

L=(LISTE)malloc (sizeof(structliste));
if(!L){printf("\n Un probl�me de m�moire ");}
else{
    L->tete=NULL;
    L->queue=NULL;
    L->lg=0;
}
return L;
}

NOEUD creer_noeud(int age,int nb_voy,int cap,int jour,int mois,int annee ,char etat[10],char code[30]){

NOEUD n;
n=(NOEUD)malloc(sizeof( structliste));
if(!n){printf("\n Pobl�me de m�moire ");}
else{
    n->AV.age=age;
    n->AV.cap=cap;
    n->AV.nb_voy=nb_voy;
    n->AV.jour=jour;
    n->AV.mois=mois;
    n->AV.annee=annee;
    strcpy(n->AV.etat,etat);
    strcpy(n->AV.code,code);
}
return n;
}

void afficher(LISTE l){

NOEUD q;
int i;
q=l->tete;
for (i=1;i<=l->lg;i++){
    printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %i/%i/%i | son etat : %s | son nombre de voyage : %i ||",q->AV.code,q->AV.cap,2020-q->AV.annee,q->AV.jour,q->AV.mois,q->AV.annee,q->AV.etat,q->AV.nb_voy);
q=q->suivant;
}
}


int verif_code(char code [30]){
int test=1;
if(strlen(code)<3){test=0;printf("\n                   !!!ERREUR!!! \n il faut que le code soit de taille minumum 4");}
return test;
}
int verif_cap(int cap){
int test=1;
if ((cap<0) || (cap>850)){test=0;printf("\n                  !!!ERREUR!!! \n la capacite minimale est 1 et la capacite maximale est 850 ");}
return test;
}
int verif_nb_voy(int nb_voy){
int test=1;
if ((nb_voy<0) || (nb_voy>450)){test=0;printf("\n                 !!!ERREUR!!! \n nombre illogique     \ (le nombre de voyages d'un avion ne peut pas d�passer 450)  ");}
return test;
}
int verif_etat(char etat[2]){
int test=0;
if (strcmp(etat,"m")==0){test=1;}
if (strcmp(etat,"a")==0){test=1;}
if (strcmp(etat,"d")==0){test=1;}
if (test==0){printf("\n         !!!!!ERREUR !!!!!! \n tapez / m (maintenance technique) / a (avion atteit) / d (avion decolle) ");}
return test;
}
int verif_age(int age){
int test=1;
if ((age<0) || (age>100)){test=0;printf("\n                 !!!ERREUR!!! \n nombre illogique ");}
return test;
}
int verif_date_jour(int jour){
int test=1;
if ( (jour<1) || (jour>31)){test=0;printf("\n          !!!!!!! ERREUR !!!!!!!!   \n le nombre de jours doit etre compris entre 1 et 31 ");}
return test;
}
int verif_date_mois(int mois){
int test=1;
if ( (mois<1) || (mois>12)){test=0;printf("\n          !!!!!!! ERREUR !!!!!!!!   \n le nombre de mois doit etre compris entre 1 et 12 ");}
return test;
}
int verif_date_annees(int annee){
int test=1;
if ( (annee<1910) || (annee>2020)){test=0;printf("\n          !!!!!!! ERREUR !!!!!!!!   \n le nombre d'annees doit etre compris entre 1910 et 2020 ");}
return test;
}


void AjoutDebut(LISTE L, int age,int nb_voy,int cap,int jour,int mois,int annee,char etat[10],char code[30])
{
    NOEUD p = creer_noeud(age, nb_voy,cap,jour,mois,annee, etat,code);
    p->suivant=L->tete;
    L->tete=p;
    L->lg++;
}

void afficher_av_max(LISTE l){
NOEUD p=l->tete;
LISTE lr =creer_liste();
int i;
printf("\n Donner le nombre maximal ");
int nb_donne;
scanf("%i",&nb_donne);
int o=0;
for(i=1;i<=l->lg;i++){
    if ((p->AV.age<10) && (p->AV.nb_voy>=nb_donne)){
        AjoutDebut(lr,p->AV.age,p->AV.nb_voy,p->AV.cap,p->AV.jour,p->AV.mois,p->AV.annee,p->AV.etat,p->AV.code);
        o++;
        }
p=p->suivant;
}

if(o>0){
printf("\n Voici les avions qui ont assure le nombre maximal et sont ages de moins de 10 ans  ");
NOEUD q=lr->tete;
for (i=1;i<=o;i++){
    printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %i/%i/%i | son etat : %s | son nombre de voyage : %i ||",q->AV.code,q->AV.cap,q->AV.age,q->AV.jour,q->AV.mois,q->AV.annee,q->AV.etat,q->AV.nb_voy);
q=q->suivant;
}

}
else {printf("\n Pas d'avions ages moins de 10 ans et qui ont assure le nombre maximal de voyage  que vous avez donne");}
}


void afficher_av_min(LISTE l){
NOEUD p=l->tete;
LISTE lr =creer_liste();
int i;
printf("\n Donner le nombre minimal ");
int nb_donne;
scanf("%i",&nb_donne);
int o=0;
for(i=1;i<=l->lg;i++){
    if ((p->AV.age<10) && (p->AV.nb_voy<=nb_donne)){
        AjoutDebut(lr,p->AV.age,p->AV.nb_voy,p->AV.cap,p->AV.jour,p->AV.mois,p->AV.annee,p->AV.etat,p->AV.code);
        o++;
        }
p=p->suivant;
}
if(o>0){
printf("\n Voici les avions qui ont assure le nombre minimal et sont ages de moins de 10 ans  ");
NOEUD q=lr->tete;
for (i=1;i<=o;i++){
    printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %i/%i/%i | son etat : %s | son nombre de voyage : %i ||",q->AV.code,q->AV.cap,q->AV.age,q->AV.jour,q->AV.mois,q->AV.annee,q->AV.etat,q->AV.nb_voy);
q=q->suivant;
}
}
else {printf("\n Pas d'avions ages moins de 10 ans et qui ont assure le nombre minimal de voyage  que vous avez donne");}
}










void scinder (LISTE l){
LISTE la=creer_liste();
LISTE ld=creer_liste();
LISTE lm=creer_liste();
NOEUD p=l->tete;
int i;
for (i=1;i<=l->lg;i++){
    if   (strcmp(p->AV.etat,"a")==0){ AjoutDebut(la,p->AV.age,p->AV.nb_voy,p->AV.cap,p->AV.jour,p->AV.mois,p->AV.annee,p->AV.etat,p->AV.code);}
    if   (strcmp(p->AV.etat,"m")==0){ AjoutDebut(lm,p->AV.age,p->AV.nb_voy,p->AV.cap,p->AV.jour,p->AV.mois,p->AV.annee,p->AV.etat,p->AV.code);}
    if   (strcmp(p->AV.etat,"d")==0){ AjoutDebut(ld,p->AV.age,p->AV.nb_voy,p->AV.cap,p->AV.jour,p->AV.mois,p->AV.annee,p->AV.etat,p->AV.code);}
}
printf("\n Voici les 3 listes ");
int a ;
NOEUD q=la->tete;
for (a=1;a<=la->lg;i++){
  printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %s | son etat : %s | son nombre de voyage : %i ||",q->AV.code,q->AV.cap,q->AV.age,q->AV.date_fab,q->AV.etat,q->AV.nb_voy);
  q=q->suivant;
}
int d;
NOEUD dd=ld->tete;
for(d=1;d<=ld->lg;d++){
 printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %s | son etat : %s | son nombre de voyage : %i ||",dd->AV.code,dd->AV.cap,dd->AV.age,dd->AV.date_fab,dd->AV.etat,dd->AV.nb_voy);
    dd=dd->suivant;
}
int m;
NOEUD mm=lm->tete;
for(m=1;m<=lm->lg;m++){
  printf("\n l'avion de code %s sa capacit� : %i | son age : %i | sa date de fabrication : %s | son etat : %s | son nombre de voyage : %i ||",q->AV.code,q->AV.cap,q->AV.age,q->AV.date_fab,q->AV.etat,q->AV.nb_voy);
mm=mm->suivant;
}
}


void remplir(LISTE l){

    NOEUD n;

    printf("\n \n \n Donner le nombre d'element ");
    int nb_elem;
    scanf("%i",&nb_elem);

    int i;
    int age;
    int nb_voy;
    int cap;
    char date[30];
    char etat[30];
    char code[30];



printf("\n Rempir la case num 1 ");
printf("");
printf("");


printf("\n Age ");
scanf("%i",&age);
while(verif_age(age)!=1){
    printf("\n Age ");
    scanf("%i",&age);
}

printf("\n Nombre de voyages ");
scanf("%i",&nb_voy);
while(verif_nb_voy(nb_voy)!=1){
    printf("\n Nombre de voyages ");
    scanf("%i",&nb_voy);
}

printf("\n Capacit� ");
scanf("%i",&cap);
while(verif_cap(cap)!=1){
    printf("\n Capacit� ");
scanf("%i",&cap);
}



printf("\n Date de fabrication : jj/mm/aaaa ");
printf("\n Jour: ");
int jour;
scanf("%i",&jour);
while(verif_date_jour(jour)!=1){
    printf("\n Jour: ");
scanf("%i",&jour);
}
int mois;
printf("\n Mois: ");
scanf("%i",&mois);
while(verif_date_mois(mois)!=1){
    printf("\n Mois: ");
    scanf("%i",&mois);
}
int annee;
printf("\n Annee: ");
scanf("%i",&annee);
while(verif_date_annees(annee)!=1){
    printf("\n Annee: ");
    scanf("%i",&annee);
}



printf("\n Etat: m:(maintenance technique)    a:(avion atterit)       d:(avion decolle) ");
scanf("%s",etat);
while(verif_etat(etat)!=1){
    printf("\n etat avion ");
    scanf("%s",etat);
}

printf("\n Code avion ");
scanf("%s",code);
while (verif_code(code)!=1){
    printf("\n Code avion ");
scanf("%s",code);
}



n=creer_noeud(age, nb_voy,cap,jour,mois,annee, etat,code);
  l->tete=n;
l->lg=1;


NOEUD q;
for (i=2;i<=nb_elem;i++){
        q=n;
                printf("\n \n \n ");

        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        printf("\n \n  \n");
   printf("\n Rempir la case num %i ",i);
printf("\n");
printf("\n");


printf("\n Age ");
scanf("%i",&age);
while(verif_age(age)!=1){
    printf("\n Age ");
    scanf("%i",&age);
}


printf("\n Nombre de voyages ");
scanf("%i",&nb_voy);
while(verif_nb_voy(nb_voy)!=1){
    printf("\n Nombre de voyages ");
    scanf("%i",&nb_voy);
}

printf("\n Capacit� ");
scanf("%i",&cap);
while(verif_cap(cap)!=1){
    printf("\n Capacit� ");
scanf("%i",&cap);
}



printf("\n Date de fabrication : jj/mm/aaaa ");
printf("\n Jour: ");
int jour;
scanf("%i",&jour);
while(verif_date_jour(jour)!=1){
    printf("\n Jour: ");
scanf("%i",&jour);
}
int mois;
printf("\n Mois: ");
scanf("%i",&mois);
while(verif_date_mois(mois)!=1){
    printf("\n Mois: ");
    scanf("%i",&mois);
}
int annee;
printf("\n Annee: ");
scanf("%i",&annee);
while(verif_date_annees(annee)!=1){
    printf("\n Annee: ");
    scanf("%i",&annee);
}

printf("\n Etat: m:(maintenance technique)    a:(avion atterit)       d:(avion decolle) ");
scanf("%s",etat);
while(verif_etat(etat)!=1){
    printf("\n etat avion ");
    scanf("%s",etat);
}

printf("\n Code avion ");
scanf("%s",code);
while (verif_code(code)!=1){
    printf("\n Code avion ");
scanf("%s",code);
}





n=creer_noeud(age, nb_voy,cap,jour,mois,annee, etat,code);
q->suivant=n;
n->precedent=q;
q=q->suivant;
(l->lg)++;
}
}


int verifier(LISTE l){
NOEUD n;
int test=0;
int i;
n=l->tete;
char code[30];
printf("\n Donner le code de l'avion que vous voulez verifier son existence ");
scanf("%s",code);

for(i=1;i<=l->lg;i++){
    if(strcmp(n->AV.code,code)==0){test=1;break;}
    n=n->suivant;
}
return test;
// ca on l'ajoute dans le menu principal
/* if(verifier(l)==1){printf("l'avion est trouv�");};
if(verifier(l)!=1){printf("avion introuvable");} */


}


/*comment on fait pour faire plusieurs valeurs en sorties */
int avion_decolle (LISTE l){
NOEUD n;
int i ;
int somme=0;
n=l->tete;
for (i=1;i<=l->lg;i++){

    if   (  ( strcmp(n->AV.etat,"D")==0 ) ){somme++;}
n=n->suivant;
}
return somme ;
//printf("\n le nombre d'avion att�rits est %i",avion_decolle(l));
}

int avion_atterit (LISTE l){
NOEUD n;
int i ;
int somme=0;
n=l->tete;
for (i=1;i<=l->lg;i++){

    if   (  ( strcmp(n->AV.etat,"a")==0 ) ){somme++;}
n=n->suivant;
}
return somme ;
//printf("\n le nombre d'avion att�rits est %i",avion_decolle(l));
}


int avion_en_maintenance (LISTE l){
NOEUD n;
int i ;
int somme=0;
n=l->tete;
for (i=1;i<=l->lg;i++){

    if   (  ( strcmp(n->AV.etat,"m")==0 ) ){somme++;}
n=n->suivant;
}
return somme ;
//printf("\n le nombre d'avion att�rits est %i",avion_en_maintenance(l));
}

void detruir_noeud (NOEUD n){
free(n);
}

int supprimer(LISTE l){
NOEUD n,p,q,z;
n=l->tete;
int test=0;
while(n!=NULL){
    if((strcmp(n->AV.etat,"m")==0)&& (n->AV.age>20)){
    q=n;
    p=n->precedent;
    z=n->suivant;
    p->suivant=z;
    z->precedent=p;
    free(q);
    (l->lg)--;
    test=1;
    }
    n=n->suivant;
}
return test;
    }




int main(){
    int rep;
LISTE l=creer_liste();
printf("\n");
printf("\n");
printf("\n \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
printf("\n");
printf("\n");
printf("\n                Remplissons la liste   ");
printf("\n");
printf("\n");
printf("\n \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

remplir(l);
afficher(l);



do{
switch(menu()){

case 1: printf("\n Vous avez choisi de verifier la presence de l'avion ");
        if(verifier(l)==1){printf("l'avion est trouv�");}
        else {printf("avion introuvable");}
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}
break;







case 2: printf("\n Vous avez choisi de supprimer les avions ages de plus de 20 ans et qui sont en maintenace technique ");
        printf("resultat test supprimer %i",supprimer(l));
        afficher(l);
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}
break;









case 3: printf("\n Vous avez choisi de Trier les avions par ordre croissant selon l'age   ");
       // tri(l);
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}
break;








case 4: printf("\n Vous avez choisi d'afficher les avions qui ont assure le nombre maximale et ages de moins de 10 ans  ");
        afficher_av_max(l);
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}
break;









case 5: printf("\n Vous avez choisi d'afficher les avions qui ont assure le nombre minimale et ages de moins de 10 ans ");
        afficher_av_min(l);
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}
break;









case 6: printf("\n Vous avez choisi de scinder la liste en ses 3 principales etats  ");
        scinder(l);
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}
break;










case 7: printf("\n Vous avez choisi d'afficher les avions atterits ,decolles et en maintenance technique       ");
printf("\n ");

printf("\n le nombre d'avion decolles est %i",avion_decolle(l));
printf("\n le nombre d'avion en maintenance technique est %i",avion_en_maintenance(l));
printf("\n le nombre d'avion att�rits est %i",avion_atterit(l));
printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
scanf("%i",&rep);
if(rep==0){exit(1);}

break;






case 8 :printf("\n Vous avez choisi d'afficher les avions atterits par un traitement recurssif  ");
        afficher_avion_atterit(l,1,l->tete);
        printf("\n Retourner au menu princpal ???  1(oui) ou 0 (quitter) ");
        scanf("%i",&rep);
        if(rep==0){exit(1);}

break;


}
}while (rep==1);


return 0;
}


