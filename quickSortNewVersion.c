#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

typedef struct{
	char nome[MAX];
	long int matricula; //matricula pode ser um inteiro com muitos bytes
	int idade;
}t_aluno;

int lerArquivo(FILE *arq , t_aluno alunos[], char url[]);
void quickSort(t_aluno alunos[], int inicio, int fim);
void organizarArquivo(FILE *arq, t_aluno alunos[], int tamanhoArq,char url[]);
void imprimirAlunos(t_aluno alunos[], int qntAlunos);


int main(void)
{
	int i = 0;
	int qntAlunosCadastrados;
	FILE *arq = NULL;
	char nome[15];
	char url[15];
	t_aluno alunos[MAX];
	
	printf("\t\t\t OBS: todo conteudo do arquivo esta sendo organizado pela matricula! \n\n\n");
	
	printf("informe apenas o nome do arquivo, exemplo: alunos: ");
	scanf("%s", &url);
	printf("\n\n\n\n");
	strcat(url, ".txt");
	
	
	qntAlunosCadastrados = lerArquivo(arq, alunos, url);
	
	if(qntAlunosCadastrados <= 0){
		printf("Impossivel organizar uma lista vazia! ");
	}
	
	else{
		quickSort(alunos, 0, qntAlunosCadastrados-1);
		organizarArquivo(arq, alunos, qntAlunosCadastrados, url);
		imprimirAlunos(alunos, qntAlunosCadastrados);
	}
	
	
	

	
	return 0;
}


int lerArquivo(FILE *arq , t_aluno alunos[],char url[]) {
	int i = 0;
	char vet_aux[MAX];
	arq = fopen(url, "r");
	if(!arq) return -1; // erro
	
	else{
		while(!feof(arq)){
			fgets(vet_aux, MAX, arq);
			alunos[i].matricula =  atoi(strtok(vet_aux, ","));
			strcpy(alunos[i].nome, strtok(NULL, ","));	
			alunos[i].idade = atoi(strtok(NULL, ","));
			
			
			i++;
			
		}
		
	}
	return i; //ocorreu tudo bem e me retorna a quantidade de alunos cadastrados no arquivo
	
}

void quickSort(t_aluno alunos[], int inicio, int fim){
	int i = inicio;
	int j = fim;
	t_aluno pivo = alunos[(i + j) / 2];
	t_aluno aluno_aux;

	while(i < j){
		
		while(alunos[i].matricula < pivo.matricula) i++;
		while(alunos[j].matricula > pivo.matricula) j--;

		if(i <= j){
			aluno_aux = alunos[i];
			alunos[i] = alunos[j];
			alunos[j] = aluno_aux;
			i++;
			j--;
		}

	}

	if(inicio < j) quickSort(alunos, inicio, j);
	if (i < fim) quickSort(alunos, i, fim);

}


void organizarArquivo(FILE *arq, t_aluno alunos[], int tamanhoArq, char url[]){
	
	strcat(url, " organizado.txt");
	arq = fopen(url, "w");
	
	int i;
	
	if(!arq) printf("Erro na escrita do arquivo"); // erro
	
	else{
		for(i = 0; i <= tamanhoArq; i++){
			fprintf(arq, "Matricula:  %d\nNome:  %s\nidade: %d\n\n\n",alunos[i].matricula, alunos[i].nome, alunos[i].idade );
			
		}
	
	
	}
	
}


void imprimirAlunos(t_aluno alunos[], int qntAlunos){
		int i;
		
		for(i = 0; i < qntAlunos; i++){
	 		printf("Matricula: %d \n", alunos[i].matricula);
	 		printf("Aluno: %s \n", alunos[i].nome);
	 		printf("Idade: %d \n", alunos[i].idade);
	 		printf("\n\n\n");
		
	}
	
}
