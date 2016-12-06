#pragma once
#include <vector>
#include <string>
#include "social.h"

/*************************************************************************** 
* Classe: Usuario
* Descrição
* Contem toda a estrutura basica de um usuario do programa
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

	/***************************************************************************
	* Métodos: get_[valor]
	* Descrição
	* 	As seguintes métodos devolvem as respectivas informações dos atributos
	*	do objeto
	* Assertivas de saida
	*	Retornam um valor valido do Usuario
	***************************************************************************/

	// Getters
	int get_idade();
	int get_id();
	char get_genero();
	int get_escolaridade();
	std::string get_nome();
	std::vector<int> get_interesses();
	std::string get_CEP();

	/***************************************************************************
	* Métodos: get_[valor]
	* Descrição
	* 	Os seguintes métodos devolvem as respectivas informações dos atributos
	*	do objeto
	* Assertivas de saida
	*	Retornam um valor valido do Usuario
	***************************************************************************/
	void print_dados();

	/***************************************************************************
	* Métodos: set_[valor]
	* Descrição
	* 	As seguintes métodos definem os atributos do objeto com um respectivo valor
	* Assertivas de entrada
	*	As entradas são válidas para os respectivos atributos do objeto
	***************************************************************************/
	// Setters
	void set_idade(int nova_idade);
	void set_genero(char novo_genero);
	void set_escolaridade(int nova_escolaridade);
	void set_nome(std::string novo_nome);
	void set_cep(std::string novo_cep);
	void novos_interesses(std::vector<int> nInteresses);
	
	/*************************************************************************** 
	* Metodo: Adiciona interesse
	* Descrição
	* 	Adiciona um novo interesse no vetor de enderecos
	* Assertivas de entrada
	* 	nInteresse deve ser equivalente a um interesse valido e nao existir na lista
	***************************************************************************/
	void add_interesse(int nInteresse);
	
	/*************************************************************************** 
	* Metodo: Deleta interesse
	* Descrição
	* 	Deleta um interesse da lista de interesses
	* Assertivas de entrada
	* 	nInteresse deve ser equivalente a um interesse valido e nao existir na lista
	***************************************************************************/
	void delete_interesse(int nInterese);

	/***************************************************************************
	* Metodo: Apaga objeto
	* Descrição
	* 	Utilizado para deletar manualmente o prório objeto
	***************************************************************************/
	void bakuhatsu();

	//adicionado 15h
	/***************************************************************************
	* Metodo: Mostra escolaridade do Usuario
	* Descrição
	* 	Imprime na tela a escolaridade do Usuario, a partir do atributo
	*	escolaridade do usuario é mostrado na tela a descrição correspondente
	***************************************************************************/
	void mostraEscolaridade();
	/***************************************************************************
	* Metodo: Mostra interesses do Usuario
	* Descrição
	* 	Imprime na tela os interesses do Usuario, a partir do atributo interesses
	*	do usuario é mostrado na tela a descrição correspondente desses interesses.
	***************************************************************************/
	void mostraInteresses();

};


