#include "social.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static int num_total_usuarios = 0;

Social::Social()
{
	// Inicializa lista de usuarios
	for (int i = 0; i < MAX_USUARIOS; i++) {
		lista_usuarios[i] = nullptr;
	}

	// Inicializa matriz de amizades
	for (int i = 0; i < MAX_USUARIOS; i++) {
		for (int j = 0; j < MAX_USUARIOS; j++) {
			amizades[i][j] = false;
		}
	}

	// Inicializa matriz de transacoes
	for (int i = 0; i < MAX_USUARIOS; i++) {
		for (int j = 0; j < MAX_USUARIOS; j++) {
			matriz_transacoes[i][j] = nullptr;
		}
	}
}

Social::~Social(){}

int Social::get_novo_id()
{
	for(int i = 0; i < MAX_USUARIOS;i++)
	{
		if(lista_usuarios[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

void Social::cria_amizade(int id1, int id2)
{
	amizades[id1][id2] = true;
}

void Social::cria_usuario()
{

	std::string nome;
	int idade;
	char genero;
	std::string cep;
	std::vector<int> interesses;
	std::cout << "Para criar um usuario responda as perguntas abaixo" << std::endl;
	std::cout << ">> Qual nome do novo usuario? ";
	std::getline(std::cin, nome);
	std::cout << ">> Qual a idade? ";
	std::cin >> idade;
	std::cout << ">> Qual o genero [m/f]? ";
	std::cin >> genero;
	std::cout << ">> Qual o CEP? ";
	std::cin >> cep;
	std::cin.ignore(1000,'\n'); // Limpa buffer
	int novo_id = get_novo_id();
	Usuario *a = new Usuario(idade, novo_id, genero, nome, interesses ,cep);
	lista_usuarios[novo_id] = a;
}

void Social::print_lista_usuarios()
{
	for(int i = 0; i < MAX_USUARIOS; i++)
	{
		if(lista_usuarios[i] != nullptr)
		{
			lista_usuarios[i]->print_dados();
		}
	}
}

Usuario * Social::get_usuario_by_id(int id)
{
	return lista_usuarios[id];
}
