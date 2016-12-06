#pragma once
#include <vector>
#include <string>
#include "social.h"

const int MAX_USUARIOS = 100;

/*************************************************************************** 
* Classe: Usuario
* Descrição
* Contem toda a estrutura basica de um usuario da rede
***************************************************************************/
class Usuario
{
private:
	int id;
	int idade;
	char genero;
	int escolaridade;
	std::string nome;
	std::vector<int> interesses;
	std::string CEP;
	static int nextId;



public:
	/*************************************************************************** 
	* Metodo: Construtor da classe Usuario
	* Descrição
	* Usada para criar uma instancia da classe Usuario
	* Parametros
	* nIdade - Idade do usuario, deve ser um numero maior que 0
	* nGenero - Genero do usuario, deve ser m (homem), f (mulher), o (outro)
	* nId - Id do novo usuario
	* nNome - Nome do usuario, deve ser uma string nao vazia e que nao contenha numeros
	* nInteresses - vetor de inteiros contendo os interesses do usuario
	* nCEP - CEP do usuario
	* nEscolaridade - Contem um inteiro representando a escolaridade do usuario
	* Asseriva de entrada 
	*		nIdade > 0
	*		nGenero == 'm' || nGenero == 'f' || nGenero == 'o'
	*		nNome.size() > 0
	***************************************************************************/
	Usuario(int nIdade, int nId, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP, int nEscolaridade);
	~Usuario();

	// Getters
	int get_idade();
	int get_id();
	char get_genero();
	int get_escolaridade();
	std::string get_nome();
	std::vector<int> get_interesses();
	std::string get_CEP();

	void print_dados();
	void print_lista_usuarios();

	// Setters
	void set_idade(int nova_idade);
	void set_genero(char novo_genero);
	void set_escolaridade(int nova_escolaridade);
	void set_nome(std::string novo_nome);
	void set_cep(std::string novo_cep);
	void novos_interesses(std::vector<int> nInteresses);
	
	/*************************************************************************** 
	* Metodo: Construtor da classe Usuario
	* Descrição
	* 	Adiciona um novo interesse no vetor de enderecos
	* Assertivas de entrada
	* 	nInteresse deve ser equivalente a um interesse valido e nao existir na lista
	***************************************************************************/
	void add_interesse(int nInteresse);
	void delete_interesse(int nInterese);

	void bakuhatsu();

};

// Guarda todos os usuarios da rede
static Usuario *lista_usuarios[MAX_USUARIOS];
// Matriz de amizades. Para uma amizade ser valida, é necessario que 
// seja bidirecional.
static bool amizades[MAX_USUARIOS][MAX_USUARIOS];

//inicializadores
void inicializa_usuarios();
void inicializa_amizades();

/*************************************************************************** 
* Funcao: retorna usuario
* Descrição
* 	Pede o nome de um usuario como input e retorna um ponteiro para este usuario
* Assertivas de saida
*	Se o usuario existir, retorna um ponteiro para o usuario, caso contrario
*	imprime [!] Usuario nao encontrado.
***************************************************************************/
Usuario* retornaUsuario();

/*************************************************************************** 
* Funcao: Sao amigos
* Descrição
* 	Funcao usada para verificar se dois usuarios sao amigos. Uma amizade so e 
*	valida se for bidirecional
* Parametros
*	id1 e id2 sao os ids dos usuarios que a amizade sera verificada
* Assertiva de entrada
*	id1 e id2 devem ser ids de usuarios existentes.
* Assertivas de saida
*	retorna verdadeiro se a amizade existir e falso caso contrario
***************************************************************************/
bool sao_amigos(int id1, int id2);

/*************************************************************************** 
* Funcao: retorna usuario
* Descrição
* 	Verifica se dois usuarios possuem pelo menos um amigo em comum
* Parametros
*	id1 e id2 sao os ids dos usuarios que sera checado se existe uma amizade em comum
* Assertivas de saida
*	Verdadeiro se existir pelo menos um amigo em comum entre os dois usuarios
***************************************************************************/
bool eh_amigo_de_amigo(int id1, int id2);


//INTERFACE USUARIO
/* 
Usuario* cria_usuario();
//funcoes auxiliares cria usuario
std::string pegaNome();
int pegaIdade();
int pegaEscolaridade();
char pegaGenero();
std::string pegaCEP();
std::vector<int> pegaInteresses();
*/

/*************************************************************************** 
* Funcao: Edita Usuario
* Descrição
* 	Edita as informacoes de um usuario especifico
* Parametros
*	Recebe um ponteiro para o objeto do usuario que sera editado
* Assertivas de entrada
*	usuario nao pode ser um ponteiro nulo
***************************************************************************/
void edita_usuario(Usuario* usuario);
//funcoes auxiliares edita usuario
int interfaceEdicao();
void realizaEdicao(Usuario* usuario, int escolha);

/*************************************************************************** 
* Funcao: Exclui Usuario
* Descrição
* 	Exclui um usuario
* Parametros
*	Recebe um ponteiro para o objeto do usuario que sera excluido
* Assertivas de entrada
*	usuario nao pode ser um ponteiro nulo
***************************************************************************/
void exclui_usuario(Usuario* usuario);


//administrador
void visualizaPessoas();
