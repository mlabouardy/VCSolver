#include "vc.h"
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0



int func(int i,int j,int k){ 
	 return j+(i-1)*k;
}

void genSAT_Formule(int k,bool test){
	int i,j,t,p,N;
	FILE *f;
	if(test==TRUE){
		f=fopen("resultat.txt","a");	
		fprintf(f,"Cas k=%d\n",k);
	}else{
		f=fopen("resultat.txt","w");
	}	
	N=nb_sommet();
	bool** tab=(bool**)malloc(sizeof(bool**)*N);
	for(i=0;i<N;i++)
		tab[i]=(bool*)malloc(sizeof(bool*)*N);
	for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(!(tab[i-1][j-1] && tab[j-1][i-1])){			
					if(i!=j){		
						for(p=1;p<=k;p++){
							fprintf(f,"-%d -%d 0\n",func(i,p,k),func(j,p,k));
						}
						tab[i-1][j-1]=TRUE;
						tab[j-1][i-1]=TRUE;
					}
				}
			}
		}	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				tab[i][j]=FALSE;
		}
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(!(tab[i-1][j-1] && tab[j-1][i-1])){			
					if(i!=j && est_adjacent(i,j)){		
						for(t=1;t<=k;t++)
							fprintf(f,"%d %d ",func(i,t,k),func(j,t,k));
						tab[i-1][j-1]=TRUE;
						tab[j-1][i-1]=TRUE;
						fprintf(f,"0\n");
					}
				}
			}
		}
		if(test==TRUE)
			fprintf(f,"\n\n");
		fclose(f);
}

void min_k(int k){
	int i;
	FILE *f=fopen("resultat.txt","w");
	fprintf(f,"la valeur exacte de K\n\n");
	for(i=1;i<=k;i++)
		genSAT_Formule(i,TRUE);
}

