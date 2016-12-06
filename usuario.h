#pragma once
#include <vector>
#include <string>
#include "social.h"

const int MAX_USUARIOS = 100;

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

	// Setters
	void set_idade(int nova_idade);
	void set_genero(char novo_genero);
	void set_escolaridade(int nova_escolaridade);
	void set_nome(std::string novo_nome);
	void set_cep(std::string novo_cep);

	void novos_interesses(std::vector<int> nInteresses);
	void add_interesse(int nInteresse);
	void delete_interesse(int nInterese);

	void bakuhatsu();

};


