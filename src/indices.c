#include <stdio.h>
#include <string.h>
#include "indices.h"

void criaIndicesPrimarios()
{
	int n_linhas1 = 0, n_linhas2 = 0, cont_char = 0;

	FILE *lista1; 
	FILE *lista2;
	int i, j;
	char ch;

	lista1 = fopen("listas/lista1.txt", "r");
	if(!lista1) printf("lista1 nao foi aberta\n");

	lista2 = fopen("listas/lista2.txt", "r");
	if(!lista2) printf("lista2 nao foi aberta\n");

	//FAZER LISTA ENCADEADA PRA NAO TER QUE SOFRER ESSA MERDA
	
	while(!feof(lista1))
	{
  		ch = fgetc(lista1);
  		if(ch == '\n') n_linhas1++;
  	}

  	while(!feof(lista2))
	{
  		ch = fgetc(lista2);
  		if(ch == '\n') n_linhas2++;
  	}

  	rewind(lista1); //Função que eu achei pra voltar o ponteiro pro começo do arquivo
  	rewind(lista2);

	char ** lista_indices1 = (char**)malloc(sizeof(char*)*n_linhas1);

	for(i = 0; i < n_linhas1; i++){
		lista_indices1[i] = (char*)malloc(sizeof(char)*30);
	}

	char ** lista_indices2 = (char**)malloc(sizeof(char*)*n_linhas2);

	for(i = 0; i < n_linhas2; i++){
		lista_indices2[i] = (char*)malloc(sizeof(char)*30);
	}

	i = 0; //Vai contar as linhas
	j = 0; //Vai contar a quantidade de char ja ocupados na string
	cont_char = 0; //Vai contar a quantidade de char q ja foram lidos da linha do arquivo, ou seja, n passa de 48

	while(i < n_linhas1){

		fscanf(lista1,"%c",&ch);
		cont_char++; //Incrementa sempre q se le um char do arquivo

		if(j < 30 && cont_char < 48){ //Condição pra adicionar o char na string
			if(ch != ' ' && ch != '\n'){ //Não vai adicionar espaço nem pula linha na string
				lista_indices1[i][j] = ch;
				j++;
			}
		}
		if(ch == '\n'){ //Passa para a proxima linha quando chega no \n
			i++;
			j = 0; //Variáveis zeradas para a proxima linha
			cont_char = 0;
		}
	}

	i = 0;
	j = 0;
	cont_char = 0;

	while(i < n_linhas2){
		fscanf(lista2,"%c",&ch);
		cont_char++;
		if(j < 30 && cont_char < 48){
			if(ch != ' ' && ch != '\n'){
				lista_indices2[i][j] = ch;
				j++;
			}
		}
		if(ch == '\n'){
			i++;
			j = 0;
			cont_char = 0;
		}
	}

	FILE* arq_saida1 = fopen("indicelista1.ind","w");
	FILE* arq_saida2 = fopen("indicelista2.ind","w");

	for(i = 0; i < n_linhas1; i++){
		fprintf(arq_saida1,"%s %d\n",lista_indices1[i],i);
	}

	for(i = 0; i < n_linhas1; i++){
		fprintf(arq_saida2,"%s %d\n",lista_indices2[i],i);
	}

	fclose(arq_saida1);
	fclose(arq_saida2);

	for(int i = 0; i < n_linhas1; i++){
		free(lista_indices1[i]);
	}
	free(lista_indices1);

	for(int i = 0; i < n_linhas2; i++){
		free(lista_indices2[i]);
	}
	free(lista_indices2);

	fclose(lista1);
	fclose(lista2);
}