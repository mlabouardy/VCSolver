#include<stdio.h>
#include<stdlib.h>
#include "sat.h"
#include "vc.h"
/*

Input : G=(V,E) and k<=|V|

X={[v,i] v∈V , 1<=i<=K}

donc la formule est :

F=ET at_most_one{[v,i] | v∈V,1<=i<=k} ET at_least_one{[u,i],[v,i],{u,v}∈E,1<=i<=K}

avec:
 
at_most_one(l1,l2...lx)=ET(-li v -lj) avec 1<=i<j<=x

at_least_one(l1,l2,lx)=(l1 v l2 v ... lx)

la premiére partie du formule implique que au plus K sommets sont choisis ( [v,i]=VRAI)
la deuxiéme partie verifier que l'ensemble des sommet choisis présente une couverture par sommet

*/
int main(){
	int k,choix;
	char c;
	printf("\t\t\tVertex Cover Solver\n\n");
	do{
		printf("\t1-Tester k\n");
		printf("\t2-Calculer la taille exacte de la couverture minimum\n\n");
		printf("Choix=");
		scanf("%d",&choix);
		switch(choix){
			case 1:
				printf("Entrer k=");
				scanf("%d",&k);
				genSAT_Formule(k,0);
				printf("resultat est stocke dans le fichier 'resultat.txt'\n");
			   break;
			case 2:
				printf("Entrer k=");
				scanf("%d",&k);
			   min_k(k);
				printf("resultat est stocke dans le fichier 'resultat.txt'\n");
				break;
			default:printf("Erreur !! 1/2 svp !!\n");	
      }
		getchar();
		printf("\nVous voulez reessayer ? (o/n):");
		scanf("%c",&c);
	}while(c!='n');	
}
