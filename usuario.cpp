#include "usuario.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
static int nextId = 0;


///////////////USUARIO

Usuario::Usuario(int nIdade, int nId, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP, int nEscolariadade)
	:idade(nIdade), id(nId), genero(nGenero), nome(nNome), interesses(nInteresses), CEP(nCEP), escolaridade(nEscolariadade)
{
	id = nId;
	std::cout << "Usuario [" + std::to_string(id) + "] criado" << std::endl;
}

Usuario::~Usuario() {
	std::cout << "Usuario apagado" << std::endl;
}

void Usuario::novos_interesses(std::vector<int> nInteresses)
{
	this->interesses = nInteresses;
}

void Usuario::add_interesse(int nInteresse)
{
	if (this->interesses.size() < 20)
		interesses.push_back(nInteresse);
}

void Usuario::delete_interesse(int nInteresse)
{
	std::vector<int>::iterator iter = this->interesses.begin();

	while (iter != this->interesses.end())
	{
		if (*iter == nInteresse)
			iter = this->interesses.erase(iter);
		else
			iter++;
	}
}

void Usuario::bakuhatsu()
{
	delete this;
}

// Getters
int Usuario::get_idade()
{
	return this->idade;
}

int Usuario::get_id()
{
	return this->id;
}

char Usuario::get_genero()
{
	return this->genero;
}

int Usuario::get_escolaridade()
{
	return this->escolaridade;
}

std::string Usuario::get_nome()
{
	return this->nome;
}

std::vector<int> Usuario::get_interesses()
{
	return this->interesses;
}

std::string Usuario::get_CEP()
{
	return this->CEP;
}


// Setters
void Usuario::set_idade(int nova_idade)
{
	this->idade = nova_idade;
}

void Usuario::set_genero(char novo_genero)
{
	this->genero = novo_genero;
}

void Usuario::set_escolaridade(int nova_escolaridade)
{
	this->escolaridade = nova_escolaridade;
}

void Usuario::set_nome(std::string novo_nome)
{
	this->nome = novo_nome;
}

void Usuario::set_cep(std::string novo_cep)
{
	this->CEP = novo_cep;
}

void Usuario::print_dados()
{
	std::cout << "Usuario: " << this->nome << " id[" << this->id << "]" << std::endl;
}

