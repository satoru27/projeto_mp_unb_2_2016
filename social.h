#pragma once
#include <vector>
#include <string>
#include "transacao.h"
#include "usuario.h"

//interesses = servicos ou criar um enum interesses que lista os interesses possiveis

// Numero maximo de usuarios suportados pela rede
const int MAX_USUARIOS = 100;

/*************************************************************************** 
* Classe: Social
* Descrição
* Controla todas as relacoes entre usuarios
***************************************************************************/
class Social
{
public:
	// Contem todas as transacoes realizadas entre usuarios
	std::vector<Transacao> lista_transacoes[MAX_USUARIOS];
	// Contem todos os usuarios criados pelo programa
	Usuario * lista_usuarios[MAX_USUARIOS];
	// Matriz que guarda todas as amizades
	bool amizades[MAX_USUARIOS][MAX_USUARIOS];
	
	/*************************************************************************** 
	* Metodo: Pega novo id
	* Descrição
	* 	Acha o primeiro id valido na lista de usuarios
	* Assertivas de saida
	*	Retorna um inteiro que sera o novo id do proximo usuario criado
	*	se nao existirem mais vagas para um novo usuario, retorna -1
	***************************************************************************/
	int get_novo_id();

	/*************************************************************************** 
	* Metodo: Construtor da classe Social
	* Descrição
	* 	A classe social controla todas as interacoes do usuario com a rede social
	***************************************************************************/
	Social();
	~Social();
	// Guarda o total de usuarios cadastrados na rede
	static int num_total_usuarios;
	
	/*************************************************************************** 
	* Metodo: Cria amizade
	* Descrição
	* 	Cria uma amizade entre o usuario do id1 e id2. A amizade deve ser
	*	bidirecional na matriz de amizades
	* Assertivas de entrada
	* 	id1 e id2 devem ser ids validos.
	***************************************************************************/
	void cria_amizade(int id1, int id2);
	
	/*************************************************************************** 
	* Metodo: Cria Usuario
	* Descrição
	* 	Cria um usuario com um id novo e valido. Essa funcao utiliza o construtor
	*	da classe usuario (fornece um id valido) e coloca o novo usuario criado 
	*	na lista de usuarios.
	***************************************************************************/
	void cria_usuario();
	
	/*************************************************************************** 
	* Metodo: Pega usuario pelo id
	* Descrição
	* 	Retorna um ponteiro para o objeto de usuario que possui o id passado como
	*	parametro.
	* Assertivas de entrada
	* 	id deve ser um inteiro
	* Assertiva de saida
	*	Caso o usuario exista, retorna um ponteiro para o objeto, caso contrario
	*	retorna nullptr
	***************************************************************************/
	Usuario * get_usuario_by_id(int id);
	
	/*************************************************************************** 
	* Metodo: Imprime lista de usuarios
	* Descrição
	* 	Imprime os dados (Nome e Id) de todos os usuarios registrados.
	***************************************************************************/
	void print_lista_usuarios();

};


/*************************************************************************** 
* Funcoes: Pega [valor]
* Descrição
* 	As funcoes abaixo realizam o input dos dados, ja realizando a valiacao das 
*	assertivas de entrada (Baseado nas assertivas de entrada do construtor da classe Usuario)
* Assertivas de saida
*	Retornam um valor valido referente a um atributo da classe
***************************************************************************/
std::string pegaNome();
int pegaIdade();
int pegaEscolaridade();
char pegaGenero();
std::string pegaCEP();
std::vector<int> pegaInteresses();
