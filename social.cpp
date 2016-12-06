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

	// matriz de transacoes ja inicializada pelo construtor do vector
	
}

Social::~Social(){}

int Social::get_novo_id()
{
	for (int i = 0; i < MAX_USUARIOS; i++)
	{
		if (lista_usuarios[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

void Social::cria_amizade(int id1, int id2)
{
	amizades[id1][id2] = true;
	amizades[id2][id1] = true;
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

void Social::cria_usuario()
{	//Usuario(int nIdade, char nGenero, std::string nNome,
	//std::vector<int> nInteresses, std::string nCEP);
	std::cout << "# Bem vindo a criacao de um novo usuario da rede" << std::endl;

	std::cout << "# Digite seu nome" << std::endl;
	std::string nNome = pegaNome();

	std::cout << "# Digite sua idade" << std::endl;
	int nIdade = pegaIdade();

	std::cout << "# Escolha seu nivel de escolariade" << std::endl;
	int nEscolaridade = pegaEscolaridade();

	std::cout << "# Escolha seu genero" << std::endl;
	char nGenero = pegaGenero();

	std::cout << "# Digite seu CEP" << std::endl;
	std::string nCEP = pegaCEP();

	std::cout << "# Escolha seus interesses" << std::endl;
	std::vector<int> nInteresses = pegaInteresses();

	int nId = get_novo_id();
	Usuario *novoUsuario = new Usuario(nIdade, nId, nGenero, nNome, nInteresses, nCEP, nEscolaridade);
	lista_usuarios[nId] = novoUsuario;

}

//AUXILIARES CRIA_USUARIO
std::string pegaNome()
{
	std::string nome;
	std::cout << ">> ";
	std::cin >> nome;
	return nome;
}

int pegaIdade()
{
	int idade = 0;
	std::cout << ">> ";
	std::cin >> idade;
	return idade;
}

int pegaEscolaridade()
{
	int escolaridade = 0;
	std::cout << "[1] Superior incompleto" << std::endl;
	std::cout << "[2] Superior completo" << std::endl;
	std::cout << ">> ";
	std::cin >> escolaridade;
	return escolaridade;
}

char pegaGenero()
{
	char genero = 'O';
	std::cout << "[M] Masculino" << std::endl;
	std::cout << "[F] Feminino" << std::endl;
	std::cout << "[O] Outro" << std::endl;
	std::cout << ">> ";
	std::cin >> genero;

	if (genero == 'm') {
		genero = 'M';
	}
	else if (genero == 'f') {
		genero = 'F';
	}
	else if (genero != 'M' || genero != 'F') {
		genero = 'O';
	}
	return genero;
}

std::string pegaCEP()
{
	std::string CEP;
	std::cout << ">> ";
	std::cin >> CEP;
	return CEP;
}

std::vector<int> pegaInteresses()
{
	std::vector<int> interesses;
	int i = 0;
	int temp = 0;
	char mais = 'n';
	std::cout << "# Escolha os seus interesses (ate 20):" << std::endl;
	std::cout << "[1] Carona" << std::endl;
	std::cout << "[2] Imoveis" << std::endl;
	std::cout << "[3] Servicos" << std::endl;

	while ((i < 20) && (mais == 's' || mais == 'S')) {
		std::cout << ">> ";
		std::cin >> temp;
		//if temp nao esta entre as escolhas manda mensagem e i--
		interesses.push_back(temp);
		temp = 0;
		i++;
		std::cout << "# Adicionar mais interesses ? (S - sim, N - nao) ";
		std::cout << ">> ";
		std::cin >> mais;
	}
	return interesses;
}

