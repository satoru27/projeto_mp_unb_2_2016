
#include <string>
#include <iostream>

class Grafo
{
private:
	std::string nome_grafo;

	float valor_vertices[100]; /*cria 100 referencias de possiveis vertices do tipo float, onde x e o identificador dele e e possivel colocar o seu valor*/
	bool validade_vertices[100]; /*verifica se o vertice existe e foi criado de fato*/

	bool matriz_adjacencias[100][100]; //matriz de adjacencias indica caminhos entre os vertices x e y

									   /* ------------------------------------
									   0 1 2 3 4 5     arestas: 0-1 0-5 1-0 1-5 2-4 3-1 5-3

									   0  0 1 0 0 0 1
									   1  1 0 0 0 0 1
									   2  0 0 0 0 1 0
									   3  0 1 0 0 0 0
									   4  0 0 0 0 0 0
									   5  0 0 0 1 0 0
									   ----------------------------------------
									   */
	float valores_arestas[100][100];

public:
	Grafo();//Construtor vazio
	Grafo(std::string nome);//Construtor recebendo nome

	~Grafo(); //Destructor

	void bakuhatsu(); //destroi objeto dinamico

	std::string retornaNome();

	bool verificaValidadeVertice(int x);
	bool verificaValidadeAresta(int x, int y);

	void adicionaVertice(int x); /**/

	void removeVertice(int x);							 /*remove vertice*/

	void adicionaAresta(int x, int y); /*recebera vertice x e y e colocara true no caminho deles na */

	void removeAresta(int x, int y); /*colocar como falso a aresta entre x e y*/

	bool verificaAdjacencia(int x, int y);

	void identificaVizinhos(int x); /*verificar na linha de x*/

	float retornaValorVertice(int x); /*retorna o valor associado com o vertice x*/

	void mudaValorVertice(int x, float v); /*coloca valor v no vertice x em G*/

	float retornaValorAresta(int x, int y); /*retorna valor da aresta x,y em G*/

	void mudaValorAresta(int x, int y, float v); /*coloca o valor v na aresta x,y em G*/


};
//fim classe Grafo

//inicio funcoes principais

Grafo* cria_grafo(std::string nome);

std::string retorna_nome_grafo(Grafo* G);

void destroi_grafo(Grafo* G);

bool adjacente(Grafo* G, int x, int y);

void vizinhos(Grafo* G, int x);

void adiciona_vertice(Grafo* G, int x);

void remove_vertice(Grafo* G, int x);

void adiciona_aresta(Grafo* G, int x, int y);

void remove_aresta(Grafo* G, int x, int y);

float retorna_valor_vertice(Grafo* G, int x);

void muda_valor_vertice(Grafo* G, int x, float v);

float retorna_valor_aresta(Grafo* G, int x, int y);

void muda_valor_aresta(Grafo* G, int x, int y, float v);

//fim funcoes principais






/*#cria_grafo (nome): retorna estrutura de dados grafo que tem um nome
#retorna_nome_grafo(G): retorna o nome do grafo G
#destroi_grafo(G): destroi grafo g
#adjacente(G, x, y): verifica se x e y sao adjacentes em G
#vizinhos(G, x): retorna lista de todos os vertices que podem ser visitados a partir de x
(existe uma aresta que vai de x para este vertice)
#adiciona_vertice(G, x): adiciona vertice x no grafo G
#remove_vertice(G, x): remove vertice x do grafo G
#adiciona_aresta(G, x, y): no grafo G adiciona uma aresta de x para y
#remove_aresta(G, x, y): remove a aresta que vai de x para y
retorna_valor_vertice(G, x): retorna o valor associado com o vertice x
muda_valor_vertice(G, x, v): coloca valor v no vertice x em G
retorna_valor_aresta(G, x, y): retorna valor da aresta x,y em G
muda_valor_aresta(G, x, y, v): coloca o valor v na aresta x,y em G*/