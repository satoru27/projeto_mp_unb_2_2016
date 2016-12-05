#include <vector>
#include <string>
#include <iostream>
#include "usuario.h"

static int nextId = 0;


Usuario::Usuario(int nIdade, int nId, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP)
	:idade(nIdade), id(nId),genero(nGenero), nome(nNome),interesses(nInteresses), CEP(nCEP)
{
	std::cout << "Usuario [" + std::to_string(this->id) + "] criado" << std::endl;
}

Usuario::~Usuario() {
	std::cout << "Usuario apagado" << std::endl;
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

void Usuario::print_dados()
{
	std::cout << "Usuario: " << this->nome << " id[" << this->id << "]" << std::endl;
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

void Usuario::set_nome(std::string novo_nome)
{
	this->nome = novo_nome;
}

void Usuario::set_cep(std::string novo_cep)
{
	this->CEP = novo_cep;
}
