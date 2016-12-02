#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"

Grafo * cria_grafo (char* nome)
{
	if(nome != NULL){
		/* nome nao aponta para NULL */
		Grafo * novo_grafo = (Grafo *) malloc(sizeof(Grafo));
		// Testando se a memoria foi alocada
		if(novo_grafo == NULL)
		{
			fprintf(stderr, "Nao ha memoria o suficiente para criar um novo grafo");
			return NULL;
		}
		/* novo_grafo aponta posicao de memoria em que o novo grafo esta */
		novo_grafo->nome = nome;
		novo_grafo->inicio = NULL;
		novo_grafo->ultimo_vertice = NULL;
		return novo_grafo;
	}
	return NULL;
}

char * retorna_nome_grafo(Grafo * grafo)
{
	if(grafo != NULL)
	{
	/* Grafo n aponta para NULL */
		return grafo->nome;
	}
	return NULL;
}

static void destroi_arestas(Aresta * lista_arestas)
{
	if(lista_arestas != NULL)
	{
		/* lista_arestas existe */
		Aresta * temp; // Vai apontar para a proxima aresta depois que cur for destruido
		for(Aresta * cur = lista_arestas; cur != NULL; cur = temp)
		{
			temp = cur->next;
			free(cur);
		}
	}
}

void destroi_grafo(Grafo * grafo)
{
	// Testando se o grafico realmente existe
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * temp;
		for(Vertice * cur = grafo->inicio; cur != NULL; cur = temp)
		{
			temp = cur->next;
			destroi_arestas(cur->arestas);
			free(cur);
		}	
		free(grafo);
	}
}

/*
* Retorna endereco do vertice que tem indice x
*/
static Vertice * retorna_vertice(Grafo * grafo, int x)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice;
		for(vertice = grafo->inicio; vertice != NULL; vertice = vertice->next)
		{
			if(vertice->index == x)
			{
				return vertice;
			}
		}
	}
	return NULL;
}

int adjacente(Grafo * grafo, int x, int y)
{
	if(grafo != NULL){
		/* Grafo n aponta para NULL */
		// Testando se x e y existem
		Vertice * vertice_x = retorna_vertice(grafo, x);
		for(Aresta * cur = vertice_x->arestas; cur != NULL; cur = cur->next)
		{
			if(cur->vertice == y)
			{
				return 1;
			}
		}
	}
	return 0;
}


/******************************************
Se vertice x existe:
	Se a lista_vizinhos for alocada:
		lista_vizinhos[0] = tamanho da lista
		para cada aresta do grafo:
 			lista_vizinho[i] = aresta
 		retorna lista_vizinhos
*******************************************/
int * vizinhos(Grafo * grafo, int x)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice_x = retorna_vertice(grafo, x);
		if(vertice_x != NULL)
		{
			/* Vertice x existe */
			// Um espaco inicial pois o primeiro elemento sera o numero total de elementos na lista
			int * lista_vizinhos = (int*) malloc((sizeof(int) * vertice_x->num_arestas) + sizeof(int));
			if(lista_vizinhos != NULL)
			{
				lista_vizinhos[0] = vertice_x->num_arestas + 1; // tamanho da lista
				int i = 1;
				for(Aresta * cur = vertice_x->arestas; cur != NULL; cur = cur->next, i++)
				{
					lista_vizinhos[i] = cur->vertice;
				}
				return lista_vizinhos;
			}
			else
			{
				fprintf(stderr, "Nao ha memoria suficiente para criar lista de vizinhos\n");
			}
		}
	}
	return NULL;
}


/******************************************
Cria o vertice
Seta as variaveis do vertice para o valor default
Se o grafo nao tiver vertices:
	primeiro_vertice = vertice_criado
Se ja tiver vertices:
	iterar ate chegar no ultimo vertice:
		Se vertice novo ja existe:
			fim da funcao
		Se chegar no fim da lista de vertices:
			coloca vertice novo na ultima posicao
*******************************************/
int adiciona_vertice(Grafo * grafo, int x)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * novo_vertice = (Vertice *) malloc(sizeof(Vertice));
		if(novo_vertice == NULL)
		{
			fprintf(stderr, "Nao ha memoria suficiente para criar um novo vertice\n");
			return 0;
		}
		/* novo_vertice aponta para o vertice criado */
		novo_vertice->index = x;
		novo_vertice->arestas = NULL;
		novo_vertice->next = NULL;
		novo_vertice->ultima_aresta = NULL;
		novo_vertice->num_arestas = 0;

		// Variavel usada para procurar o ultimo elemento da lista
		Vertice * ultimo = grafo->inicio;
		if(ultimo == NULL) // novo_vertice sera o primeiro vertice do grafo
		{
			grafo->inicio = novo_vertice;
		}
		else
		{
			for(;ultimo != NULL; ultimo = ultimo->next)
			{
				// Enquanto procuramos o ultimo elemento, checamos se o vertice x ja existe.
				if(ultimo->index == x)
				{
					fprintf(stderr, "Vertice %d ja existe\n", x);
					return 0;
				}
				if(ultimo->next == NULL)
				{
					ultimo->next = novo_vertice;
					return 1;
				}
			}
		}
	}
	return 0;
}

void remove_vertice(Grafo * grafo, int x)
{
	if(grafo != NULL && grafo->inicio != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * last = NULL;
		for(Vertice * cur = grafo->inicio; cur != NULL; last = cur, cur = cur->next)
		{
			if(cur->index == x)
			{
				/*
				* Os ifs/elses estao organizados de forma que eles lidam com o caso do vertice
				* a ser deletado seja o primeiro o ultimo ou algum vertice no meio.
				*/			
				if(cur == grafo->inicio) // Se for o primeiro vertice
				{
					grafo->inicio = cur->next;
				}
				// Caso o grafo tenha apenas um vertice, as duas condicoes a cima sao verdadeiras

				else // Se nao for o primeiro podemos usar o last pois ele ja nao sera NULL
				{
					last->next = cur->next;
				}
				free(cur);		
			}
			// Precisamos deletar as arestas dos outros vertices que apontam para x
			else
			{
				remove_aresta(grafo, cur->index, x);
			}
		}
	}
}

/******************************************
Cria o aresta
Seta as variaveis do aresta para o valor default
Se o grafo nao tiver aresta:
	primeiro_vertice = vertice_criado
Se ja tiver aresta:
	iterar ate chegar no ultimo vertice:
		Se vertice novo ja existe:
			fim da funcao
		Se chegar no fim da lista de aresta:
			coloca vertice novo na ultima posicao
*******************************************/
int adiciona_aresta(Grafo * grafo, int x, int y)
{
	if(grafo == NULL || retorna_vertice(grafo, y) == NULL)
	{
		fprintf(stderr, "O vertice %d nao existe\n", y);
		return 0;
	}
	/* Grafo n aponta para NULL */
	Aresta * nova_aresta = (Aresta *) malloc(sizeof(Aresta));
	if(nova_aresta == NULL)
	{
		fprintf(stderr, "Nao ha memoria suficiente para adicionar uma nova aresta\n");
		return 0;
	}
	/* nova_aresta aponta para posicao de memoria da aresta criada */
	nova_aresta->vertice = y;
	nova_aresta->next = NULL;
	Vertice * vertice_x = retorna_vertice(grafo, x);
	Aresta * ultima = vertice_x->arestas;
	if(ultima == NULL)
	{
		vertice_x->arestas = nova_aresta;
		vertice_x->num_arestas++;
	}
	else
	{
		for(;ultima != NULL; ultima = ultima->next)
		{
			if(ultima->vertice == y)
			{
				fprintf(stderr , "Aresta de %d para %d ja existe\n", x, y);
				return 0;
			}
			if(ultima->next == NULL)
			{
				ultima->next = nova_aresta;
				vertice_x->num_arestas++;
				return 1;
			}
		}
	}
	return 0;
}

void remove_aresta(Grafo * grafo, int x, int y)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice_x = retorna_vertice(grafo, x);
		if(vertice_x != NULL)
		{
			/* vertice_x existe */
			Aresta* last = NULL; 
			for(Aresta * cur = vertice_x->arestas; cur != NULL; last = cur, cur = cur->next)
			{
				if(cur->vertice == y) // Aresta encontrada
				{
					if(cur == vertice_x->arestas) // Se a aresta for a primeira, mudamos o inicio da lista de arestas
					{
						vertice_x->arestas = cur->next;
					}
					else // Se nao for, mudamos para onde a anterior aponta
					{
						last->next = cur->next; 
					}
					free(cur);
					vertice_x->num_arestas--;
					return;
				}
			}
		}
	}
}

int retorna_valor_vertice(Grafo * grafo, int x)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice_x = retorna_vertice(grafo, x);
		if(vertice_x != NULL)
			return vertice_x->valor;
	}
	return -1;
}

void muda_valor_vertice(Grafo * grafo, int x, int v)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice_x = retorna_vertice(grafo, x);
		if(vertice_x != NULL)
			vertice_x->valor = v;
	}
}

int retorna_valor_aresta(Grafo * grafo, int x, int y)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice_x = retorna_vertice(grafo, x);
		if(vertice_x != NULL)
		{
			/* vertice_x existe */
			for(Aresta * cur = vertice_x->arestas; cur != NULL; cur = cur->next)
			{
				if(cur->vertice == y)
				{
					return cur->valor;
				}
			}
		}
	}
	return -1;
}

void muda_valor_aresta(Grafo * grafo, int x, int y, int v)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		Vertice * vertice_x = retorna_vertice(grafo, x);
		if(vertice_x != NULL)
		{
			/* vertice_x existe */
			for(Aresta * cur = vertice_x->arestas; cur != NULL; cur = cur->next)
			{
				if(cur->vertice == y)
				{
					cur->valor = v;
				}
			}
		}
	}
}

void imprime_vertices(Grafo * grafo)
{
	if(grafo != NULL)
	{
		/* Grafo n aponta para NULL */
		printf("Vertices -> ");
		for(Vertice * cur = grafo->inicio; cur != NULL; cur = cur->next)
		{
			printf("%d / ", cur->index);
		}
		printf("\n");
	}
}




