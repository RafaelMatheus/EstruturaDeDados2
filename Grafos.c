#include <stdio.h>
#include <stdlib.h>
#define tamanhoMatriz 26
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void inicializaMatriz(int matriz[][tamanhoMatriz]);
void percorreMatriz(int matriz[][tamanhoMatriz], char alfabeto[]);
void iniciarLizaMatrizComMenosUm(int matriz[][tamanhoMatriz]);
void pegarOrigemEDestino(char *origem, char*destino, int *peso);
void adicionarMatriz(int matriz[][tamanhoMatriz], char origem, char destino, int peso, char alfabeto[]);

int main(int argc, char *argv[]) {
	char alfabeto[26]={'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int matrizAdjacente[tamanhoMatriz][tamanhoMatriz];
	char origem;
	char destino;
	int peso;
	inicializaMatriz(matrizAdjacente);
	while(1){
		
		percorreMatriz(matrizAdjacente, alfabeto);
		printf("Pressione enter...");
		getchar();
		fflush(stdin);
		
		
		system("cls");
		printf("Informe a origem e o destino. Exemplo: A enter B, caso deseja sair pressione '.':  ");
		scanf("%c", &origem);	
		fflush(stdin);
		if(origem == '.' ) break;
	
		scanf("%c", &destino);
		fflush(stdin);
		system("cls");
		if(destino == '.') break;;
	
		printf("Informe o peso da aresta que liga os vertices %c e %c : ", origem, destino);
		scanf("%d", &peso);
		fflush(stdin);
		
	

	adicionarMatriz(matrizAdjacente, origem, destino, peso, alfabeto);


	
	
	}
	
	return 0;
}

void iniciarLizaMatrizComMenosUm(int matriz[][tamanhoMatriz]){
	int  i = 0;
	int j = 0;
	
	for(i = 0; i < tamanhoMatriz; i ++){
		for(j = 0; j < tamanhoMatriz; j++)	
			matriz[i][j] = -1;		
	}
}

void inicializaMatriz(int matriz[][tamanhoMatriz]){
	int i = 0;
	int j = 0;
	
	 iniciarLizaMatrizComMenosUm(matriz); // a principio na há nenhuma conexão por isso com menos 1
	 
	 
}


void percorreMatriz(int matriz[][tamanhoMatriz], char alfabeto[]){
	int i = 0;
	int j = 0;
	int x = 0;
	system("cls");
	printf("    ");
	for(x ;x<26;x++){
 		printf("%3c ", alfabeto[x]);
	}
	printf("\n");
	
	for(i = 0; i < tamanhoMatriz; i ++){
		printf("%3c " , alfabeto[i]);
		for(j = 0; j < tamanhoMatriz; j++){
			printf("%3d ", matriz[i][j]);
		}
			printf("\n");
		}
}




void adicionarMatriz(int matriz[][tamanhoMatriz], char origem, char destino, int peso, char alfabeto[]){
	int i = 0; // posicao de origem 
	int j = 0; // posicao de destino
	int posOrigem = 0;
	int posDestino = 0;
	for(i = 0; i < 26; i++){
		if(alfabeto[i] == origem)
		break;
	}
	for(j = 0; j < 26; j++){
		if(alfabeto[j] == destino)
		break;
	}
	if(matriz[i][j] != -1 ){
		system("cls");
		printf("Invalido, ja existe uma aresta conectando %c -> %c \n ", origem, destino);
		getchar();
		return;
	}
	
	if(peso <0){
		system("cls");
		printf("Peso invalido! ");
		getchar();
		return;
	}	
		
	matriz[i][j] = peso;
	
	
}
