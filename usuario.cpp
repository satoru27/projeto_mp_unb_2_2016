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

void Usuario::mostraInteresses()
{
	std::vector<int> interesses = this->get_interesses();


	if (interesses.size() > 0) {
		std::cout << "[+] Interesses: ";
		for (int i = 0; i < interesses.size(); i++) {
			switch (interesses[i])
			{
			case 1:
				std::cout << "carona ";
				break;
			case 2:
				std::cout << "venda ";
				break;
			case 3:
				std::cout << "limpeza ";
				break;
			case 4:
				std::cout << "construcao ";
				break;
			case 5:
				std::cout << "pintura ";
			default: //nao cadastrado
				break;
			}
			std::cout << "." << std::endl;

		}
	}
	else {
		std::cout << "[+] Interesses: Nenhum interesse cadastrado";
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

int Usuario::get_escolaridade()
{
	return this->escolaridade;
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


void exclui_usuario(Usuario* usuario)
{
	std::cout << "# Usuario sera excluido, deseja continuar ?" << std::endl;
	int escolha = 0;
	std::cout << "[1] Sim" << std::endl;
	std::cout << "[2] Nao" << std::endl;
	std::cout << ">> ";
	std::cin >> escolha;

	if (escolha == 1) {
		usuario->bakuhatsu();
		std::cout << "Sucesso, retornando" << std::endl;
	}
	else
		std::cout << "Retornando" << std::endl;
}

void Usuario::print_dados()
{
	std::cout << "Usuario: " << this->nome << " id[" << this->id << "]" << std::endl;
}


void Usuario::mostraEscolaridade()
{
	int esc = this->get_escolaridade();

	switch (esc)
	{
	case 1: std::cout << "[+] Escolaridade: Superior incompleto" << std::endl;
	case 2: std::cout << "[+] Escolaridade: Superior completo" << std::endl;
	default: std::cout << "[+] Escolaridade nao cadastrada" << std::endl;
		break;
	}
}



