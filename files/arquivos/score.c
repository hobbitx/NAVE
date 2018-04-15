#include "score.h"

void score(void){
	FILE *pont_arq;
	float val[11];
	float pontos_exibir;
	int i=0,j=0,aux;
	pont_arq = fopen("score.txt","r");
	if (pont_arq==NULL){
		printf(" Erro na abertura");
	}
	while( i<10){
		fscanf(pont_arq,"%f\n",&pontos_exibir);
		
		val[i]=pontos_exibir;
		i++;
	}
	fclose(pont_arq);
	fflush(stdin);
	for (i = 0; i < 10; i++){
		for ( j = 0; j <= 10; j++){		
			if (val[i]>val[j]){
				aux=val[j];
				val[j]=val[i];
				val[i]=aux;
			}
		}
		j=0;
	}
	if (pontuacao>val[9]){
		val[9]=pontuacao;
	}

	pont_arq = fopen("score.txt","w");
	for (i = 0; i <10; i++){
			
			fprintf(pont_arq, "%.2f\n",val[i]);
	}	
		
	
	
	fflush(stdin);
	fclose(pont_arq);

}
void recuperar_scores(){
	FILE *pont_arq;
	float aux;
	char ponts[10];
	float val[10];
	float pontos_exibir;
	int i=0,j=0;
	pont_arq = fopen("score.txt","r");
	if (pont_arq==NULL){
		printf(" Erro na abertura");
	}
	while( i<=10 ){
		fscanf(pont_arq,"%f\n",&pontos_exibir);
	
		val[i]=pontos_exibir;
		i++;
	}
	for (i = 0; i < 10; i++){
		for ( j = 0; j < 10; j++){		
			if (val[i]>val[j]){
				aux=val[j];
				val[j]=val[i];
				val[i]=aux;
			}
		}
		j=0;
	}
	for (int i = 0; i < 10; ++i){

			sprintf(ponts,"\n%iª Lugar %.2f",i+1,val[i]);
			strcat(s_lugar,ponts);
	}

	//printf("%s",s_lugar);
	fclose(pont_arq);
}