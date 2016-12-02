
#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct arestas{
	int valor; 
	int vertice; // Qual vertice esta sendo ligado por essa aresta
	struct arestas * next; // Faremos uma lista encadeada de arestas
} Aresta;

typedef struct vertice{
	int index;
	int valor;
	int num_arestas;
	Aresta * arestas; // Array de arestas
	Aresta * ultima_aresta;
	struct vertice * next; // Proximo vertice
} Vertice;

typedef struct grafo{
	char * nome; // Nome do grafo
	Vertice * inicio; // Inicio da lista encadeada de vertices
	Vertice * ultimo_vertice; // Ultimo elemento da lista encadeada de vertices
} Grafo;


/*************************************************************************** 
* Função: Cria grafo
* Descrição
*	Cria a cabeça do grafo
*	o grafo retornado pela função tera o nome especificado pelo parametro de entrada da função
*	e estara vazio (sem nenhum vertice)
* Parâmetros
*	nome - String contendo o nome do grafo
* Retorno
*	Ponteiro que aponta para a cabeça do grafo, 
*	caso a função falhe por algum motivo, sera retornado NULL
* Assertiva de entrada
*	nome != NULL
* Assertiva de saida
*	ExisteGrafo( grafo )
***************************************************************************/
Grafo * cria_grafo (char* nome);


/*************************************************************************** 
* Função: Retorna nome do grafo
* Descrição
*	Retorna o nome do grafo que for passado como parametro
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
* Retorno
*	Retorna um ponteiro para char contendo o nome do grafo
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*	grafo->nome != NULL
***************************************************************************/
char * retorna_nome_grafo(Grafo * grafo);


/*************************************************************************** 
* Função: Detroi grafo
* Descrição
*	Libera espaco da memoria usado pelo grafo passado 
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
* Assertiva de entrada
*	grafo != NULL
***************************************************************************/
void destroi_grafo(Grafo * grafo);


/*************************************************************************** 
* Função: Adjacente
* Descrição
*	Função usada para avaliar se dois vertices são adjacentes.
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
*	y - identificador de um vertice
* Retorno
*	Retorna 1 caso os dois vertices sejam adjacentes, 0 caso contrario.
*	Se um dos vertices nao existirem, a funçao também retorna 0
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*   adjacente() = 1 || adjacente() = 0
***************************************************************************/
int adjacente(Grafo * grafo, int x, int y);


/*************************************************************************** 
* Função: Vizinhos
* Descrição
*	Função usada para se obter uma lista de vertices vizinhos do vertice x
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
* Retorno
*	Retorna um array em que o primeiro elemento possui o numero de vizinhos
* 	e os elementos seguintes sao ponteiros para os vertices vizinhos
*   Caso o vertice x nao exista, retorna NULL
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*	vizinhos[0] = numero_de_vizinhos
*   if i < vizinhos[0]  existe(vizinhos[i])
***************************************************************************/
int * vizinhos(Grafo * grafo, int x);


/*************************************************************************** 
* Função: Adiciona vertice
* Descrição
*	Adiciona um vertice com identificador ao grafo
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador do vertice a ser adicionado
* Retorno
*	Retorna verdadeiro (1) caso o vertice seja adicionado com sucesso,
*	falso (0) caso contrario
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*	adiciona_vertice() = 1 || adiciona_vertice() = 0
***************************************************************************/
int adiciona_vertice(Grafo * grafo, int x);


/*************************************************************************** 
* Função: Remove vertice
* Descrição
*	Remove um vertice do grafo
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
* Assertiva de entrada
*	grafo != NULL
***************************************************************************/
void remove_vertice(Grafo * grafo, int x);


/*************************************************************************** 
* Função: Adiciona Aresta
* Descrição
*	Função usada para adicionar aresta no grafo entre dois vertices
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
*	y - identificador de um vertice
* Retorno
*	Retorna verdadeiro (1) caso a aresta seja adicionada com sucesso, Falso (0) caso contrario
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*	adiciona_aresta() = 1 || adiciona_aresta() = 0
***************************************************************************/
int adiciona_aresta(Grafo * grafo, int x, int y);


/*************************************************************************** 
* Função: Remove Aresta
* Descrição
*	Função usada para remover arestas entre dois vertices
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
*	y - identificador de um vertice
* Assertiva de entrada
*	grafo != NULL
***************************************************************************/
void remove_aresta(Grafo * grafo, int x, int y);


/*************************************************************************** 
* Função: Retorna Valor Vertice
* Descrição
*	Função usada para se obter o valor de um vertice x
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
* Retorno
*	Retorna o valor guardado no vertice x, se o vertice nao existir, ira retornar -1
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*	retorna_valor_vertice = int
***************************************************************************/
int retorna_valor_vertice(Grafo * grafo, int x);


/*************************************************************************** 
* Função: Muda Valor Vertice
* Descrição
*	Função usada para mudar o valor de um vertice
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
*	v - novo valor do vertice x
* Assertiva de entrada
*	grafo != NULL
***************************************************************************/
void muda_valor_vertice(Grafo * grafo, int x, int v);


/*************************************************************************** 
* Função: Retorna Valor Aresta
* Descrição
*	Função que retorna o valor contido em uma aresta do grafo
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
*	y - identificador de um vertice
* Retorno
*	Retorna o valor contido na aresta entre os vertices x e y. Se tal aresta nao existir
*	o valor -1 sera retornado.
* Assertiva de entrada
*	grafo != NULL
* Assertiva de saida
*	retorna_valor_aresta() = int
***************************************************************************/
int retorna_valor_aresta(Grafo * grafo, int x, int y);


/*************************************************************************** 
* Função: Muda Valor Aresta
* Descrição
*	Muda o valor da aresta entre os vertices x e y
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
*	x - identificador de um vertice
*	y - identificador de um vertice
*	v - novo valor da aresta x->y
* Assertiva de entrada
*	grafo != NULL
***************************************************************************/
void muda_valor_aresta(Grafo * grafo, int x, int y, int v);


/*************************************************************************** 
* Função: Imprime Vertices
* Descrição
*	Imprime todos os vertices do grafo 
* Parâmetros
*	grafo - Ponteiro que aponta para a cabeça do grafo
* Assertiva de entrada
*	grafo != NULL
***************************************************************************/
void imprime_vertices(Grafo * grafo);

#endif // GRAFOS_H