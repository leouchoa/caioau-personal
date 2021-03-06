/*

Objetivo: implementar em czao um "lib" para grafos



*/

#include <stdio.h>
#include <stdlib.h>


struct cel{
	int dest;
	double peso;
	struct cel *prox;
};

typedef struct cel cel;

struct grafo{
	int nn; // numero de nos
	//int na; // numero de arcos (estamos usando apenas arestas por enquanto)
	cel **eds; // lista de adjacencias , representando os arcos
};

typedef struct grafo grafo;

/* Prototipos de funcoes*/

void inicia_grafo(grafo *G,int nn);
void adiciona_aresta(grafo *G,int orig,int dest,double peso);
void imprime_grafo(grafo *G);
void destroi_grafo(grafo *G);

int main(){ // fazer o maic num main.c separado
	grafo G;
	inicia_grafo(&G,4);
	adiciona_aresta(&G,0,1,1.0);
	adiciona_aresta(&G,0,2,2.0);
	adiciona_aresta(&G,0,3,3.0);
	adiciona_aresta(&G,1,3,4.0);
	adiciona_aresta(&G,2,3,5.0);
	imprime_grafo(&G);
	destroi_grafo(&G);
	return 0;
}

void inicia_grafo(grafo *G,int nn){
	int i;
	G->nn = nn;
	G->eds = malloc(nn*sizeof(cel*));
	if (G->eds == NULL){
		printf("erro! sem memoria!\n");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<nn;i++){
		G->eds[i] = NULL;
	}
}

void destroi_grafo(grafo *G){
	int i;
	cel *atual,*proximo;
	for(i=0;i<G->nn;i++){
		proximo = G->eds[i];
		while(proximo != NULL){
			atual = proximo;
			proximo = atual->prox;
			free(atual);
		}
	}
	free(G->eds);
}

void adiciona_aresta(grafo *G,int orig,int dest,double peso){ 
// TODO: como eh um grafo simples, ou seja nao direcionado, colocar alem da aresta (u,v) colocar (v,u)
	cel *novo;
	novo = malloc(sizeof(cel));
	if (novo == NULL){
		printf("erro! sem memoria!\n");
		exit(EXIT_FAILURE);
	}
	novo->peso = peso;
	novo->dest = dest;
	novo->prox = G->eds[orig];
	G->eds[orig] = novo;
}

void imprime_grafo(grafo *G){
	int i;
	cel *atual;
	for(i=0;i<G->nn;i++){
		atual = G->eds[i];
		printf("%d:",i);
		while(atual != NULL){
			printf("%d(%.1lf),",atual->dest,atual->peso);
			atual = atual->prox;
		}
		printf("\n");
	}
}
