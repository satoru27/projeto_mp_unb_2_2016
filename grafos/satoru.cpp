

#include "grafo.h"
#include <iostream>


//implementando constutores
Grafo::Grafo() {
	std::cout << "[-]Erro: Sem parametros para o grafo" << std::endl;
}

Grafo::Grafo(std::string nome) : nome_grafo(nome) {
	std::cout << "[+]Criando e preparando o grafo " + nome_grafo << std::endl;
	
	

	for (int i = 0; i < 100; i++) {

		Grafo::validade_vertices[i] = false; //inicia como todos os vertices ao existindo
		Grafo::valor_vertices[i] = 0; // inicia todos os valores dos possiveis vertices com zero

		for (int j = 0; j < 100; j++) {
			Grafo::matriz_adjacencias[i][j] = false; //inicia como nao havendo adjacencias
			Grafo::valores_arestas[i][j] = 0; //arestas iniciam com valor 0
		}
	}

}


//destrutor
Grafo::~Grafo()
{
	std::cout << "[-]Grafo "+ nome_grafo +" destruido" << std::endl;
}

void Grafo::bakuhatsu()
{//aparentemente so funciona se o grafo for alocado dinamicamente
	delete this;
}


//inicio implementacao dos metodos do Grafo

std::string Grafo::retornaNome() {

	return Grafo::nome_grafo;

}

bool Grafo::verificaValidadeVertice(int x)
{
	return validade_vertices[x];
}

bool Grafo::verificaValidadeAresta(int x, int y)
{
	return matriz_adjacencias[x][y];
}

void Grafo::adicionaVertice(int x) {
	Grafo::validade_vertices[x] = true;
}

void Grafo::removeVertice(int x)
{
	Grafo::validade_vertices[x] = false;
}

void Grafo::adicionaAresta(int x, int y)
{
	matriz_adjacencias[x][y] = true;
}

void Grafo::removeAresta(int x, int y)
{
	matriz_adjacencias[x][y] = false;
}

bool Grafo::verificaAdjacencia(int x, int y)
{
	return Grafo::matriz_adjacencias[x][y];
}

void Grafo::identificaVizinhos(int x)
{
	int count = 0;

	for (int i = 0; i < 100; i++) {
		if (Grafo::matriz_adjacencias[x][i]) {
			std::cout << "[+] Adjacencia:" + std::to_string(x) + " - " + std::to_string(i) << std::endl;
			count++;
		}
	}
	if (count == 0) {
		std::cout << "[-] Nenhuma "<< std::endl;
	}
}

float Grafo::retornaValorVertice(int x)
{
	return Grafo::valor_vertices[x];
}


void Grafo::mudaValorVertice(int x, float v)
{
	Grafo::valor_vertices[x] = v;
}

float Grafo::retornaValorAresta(int x, int y)
{
	return valores_arestas[x][y];
}

void Grafo::mudaValorAresta(int x, int y, float v)
{
	Grafo::valores_arestas[x][y] = v;
}


//fim da definicao dos metodos da classe Grafo


//devera ser criada uma referecia para o objeto, exemplo String s = new String("foo"); , s e uma referencia para o objeto entao String t = s; e uma nova referencia para o mesmo objeto



//funcoes implementando os metodos da classe Grafo

/*Grafo cria_grafo(std::string nome) { // retorna estrutura de dados grafo que tem um nome

	return Grafo(nome);

} //testar para ver se o grafo nao e destruido apos o fim da funcao 
*/


Grafo* cria_grafo(std::string nome) { // retorna estrutura de dados grafo que tem um nome
	return new Grafo(nome);
}



//definicao das funcoes do programa

std::string retorna_nome_grafo(Grafo* G) { //: retorna o nome do grafo G
	return G->retornaNome();
}

void destroi_grafo(Grafo* G) { //: destroi grafo g
	//destroi grafo dinamico
	G->bakuhatsu();
} 

bool adjacente(Grafo* G, int x, int y) { //: verifica se x e y sao adjacentes em G
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return false;
	}
	if (y > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(y) << std::endl;
		return false;
	}
	
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return false;
	}
	if (!(G->verificaValidadeVertice(y))) {
		std::cout << "[!]Vertice " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return false;
	}
	
	bool adjacente = G->verificaAdjacencia(x, y);

	if (adjacente) {
		std::cout << "[+]Vertices " + std::to_string(x) + " e " + std::to_string(y) + " sao adjacentes" + " no " + retorna_nome_grafo(G) << std::endl;
	}
	else {
		std::cout << "[+]Vertices " + std::to_string(x) + " e " + std::to_string(y) + " nao sao adjacentes" + " no " + retorna_nome_grafo(G) << std::endl;
	}

	return adjacente;
}

void vizinhos(Grafo* G, int x) { //: retorna lista de todos os vertices que podem ser visitados a partir de x (existe uma aresta que vai de x para este vertice)
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no grafico " + retorna_nome_grafo(G) << std::endl;
		return;
	}

	std::cout << "[+]Os vizinhos de " + std::to_string(x) + " no " + retorna_nome_grafo(G) + " sao: " << std::endl;
	G->identificaVizinhos(x);
}

void adiciona_vertice(Grafo* G, int x) {// : adiciona vertice x no grafo G
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (G->verificaValidadeVertice(x)) {
		std::cout << "[!]Vertice " + std::to_string(x) + " ja existente" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}

	G->adicionaVertice(x);
	std::cout << "[+]Adicionado vertice: " + std::to_string(x) + " no " + retorna_nome_grafo(G) << std::endl;
}

void remove_vertice(Grafo* G, int x) {
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}

	G->removeVertice(x);
	std::cout << "[+]Vertice " + std::to_string(x) + " removido" + " do " + retorna_nome_grafo(G) << std::endl;
}

void adiciona_aresta(Grafo* G, int x, int y){ //: no grafo G adiciona uma aresta de x para y
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (y > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(y) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(y))) {
		std::cout << "[!]Vertice " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}

	if ((G->verificaValidadeAresta(x,y))) {
		std::cout << "[!]Aresta " + std::to_string(x) + " - " +std::to_string(y) + " ja existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}

	G->adicionaAresta(x, y);
	std::cout << "[+]Aresta " + std::to_string(x) + " - " + std::to_string(y) + " adicionada" + " no " + retorna_nome_grafo(G) << std::endl;
}

void remove_aresta(Grafo* G, int x, int y){ //: remove a aresta que vai de x para y
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (y > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(y) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(y))) {
		std::cout << "[!]Vertice " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}
	if (!(G->verificaValidadeAresta(x, y))) {
		std::cout << "[!]Aresta " + std::to_string(x) + " - " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}
	G->removeAresta(x, y);
	std::cout << "[+]Aresta " + std::to_string(x) + " - " + std::to_string(y) + " removida" + " no " + retorna_nome_grafo(G) << std::endl;
}

float retorna_valor_vertice(Grafo* G, int x){ //: retorna o valor associado com o vertice x
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return 0;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return 0;
	}

	float valor = G->retornaValorVertice(x);
	std::cout << "[+]Valor do vertice " + std::to_string(x) + " e " + std::to_string(valor) + " no " + retorna_nome_grafo(G) << std::endl;
	return valor;
}

void muda_valor_vertice(Grafo* G, int x,float v){ //: coloca valor v no vertice x em G
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}


	G->mudaValorVertice(x, v);
	std::cout << "[+]Valor do vertice " + std::to_string(x) + " mudado para " + std::to_string(v) + " no " + retorna_nome_grafo(G) << std::endl;
}

float retorna_valor_aresta(Grafo* G, int x, int y){ //: retorna valor da aresta x, y em G
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return 0;
	}
	if (y > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(y) << std::endl;
		return 0;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return 0;
	}
	if (!(G->verificaValidadeVertice(y))) {
		std::cout << "[!]Vertice " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return 0;
	}
	if (!(G->verificaValidadeAresta(x, y))) {
		std::cout << "[!]Aresta " + std::to_string(x) + " - " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return 0;
	}
	float valor = G->retornaValorAresta(x, y);
	std::cout << "[+]Valor da aresta " + std::to_string(x) + " - " + std::to_string(y) + " e: " + std::to_string(valor) + " no " + retorna_nome_grafo(G) << std::endl;
	return valor;
}

void muda_valor_aresta(Grafo* G, int x, int y, float v) { //: coloca o valor v na aresta x, y em G* /
	if (x > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(x) << std::endl;
		return;
	}
	if (y > 99) {
		std::cout << "[!]Erro: numero de posicoes excedido: " + std::to_string(y) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(x))) {
		std::cout << "[!]Vertice " + std::to_string(x) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}
	if (!(G->verificaValidadeVertice(y))) {
		std::cout << "[!]Vertice " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}
	if (!(G->verificaValidadeAresta(x, y))) {
		std::cout << "[!]Aresta " + std::to_string(x) + " - " + std::to_string(y) + " nao existe" + " no " + retorna_nome_grafo(G) << std::endl;
		return;
	}

	G->mudaValorAresta(x, y, v);
	std::cout << "[+]Valor da aresta " + std::to_string(x) + " - " + std::to_string(y) + " mudado para: " + std::to_string(v) + " no " + retorna_nome_grafo(G) << std::endl;
}



