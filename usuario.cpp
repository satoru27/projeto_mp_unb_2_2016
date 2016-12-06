#include "usuario.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
static int nextId = 0;


///////////////USUARIO
int novo_id() {
	for(int i = 0; i < MAX_USUARIOS;i++)
	{
		if(lista_usuarios[i] == nullptr)
		{
			return i;
		}
	}
	return -1; // Nao existem mais posicoes vazias
}

Usuario::Usuario(int nIdade, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP, int nEscolariadade)
	:idade(nIdade), genero(nGenero), nome(nNome), interesses(nInteresses), CEP(nCEP), escolaridade(nEscolariadade)
{
	id = novo_id();
	lista_usuarios[id] = a;
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


//INICIALIZACOES
void inicializa_usuarios() {
	for (int i = 0; i < MAX_USUARIOS; i++) {
		lista_usuarios[i] = nullptr;
	}
}

void inicializa_amizades() {
	for (int i = 0; i < MAX_USUARIOS; i++) {
		for (int j = 0; j < MAX_USUARIOS; j++) {
			amizades[i][j] = false;
		}
	}
}



Usuario * retornaUsuario()
{
	Usuario * resultado = nullptr;
	std::string nome;
	std::cout << "# Digite o nome do usuario" << std::endl;
	std::cout << ">> ";
	std::cin >> nome;

	for (int i = 0; i < MAX_USUARIOS; i++) {
		std::string nome_rec = lista_usuarios[i]->get_nome();
		if (nome.compare(nome_rec) == 0) {
			resultado = lista_usuarios[i];
		}
	}
	if (resultado == nullptr) {
		std::cout << "[!] Usuario nao encontrado" << std::endl;
	}
	return resultado;
}


bool sao_amigos(int id1, int id2)
{
	if (amizades[id1][id2] == true && amizades[id2][id1] == true) {
		return true;
	}
	else {
		return false;
	}
}

bool eh_amigo_de_amigo(int id1, int id2)
{
	for (int i = 0; i < MAX_USUARIOS; i++) {
		if (sao_amigos(id1, i) && sao_amigos(id2, i)) {
			return true;
		}
	}
	return false;

}

Usuario * cria_usuario()
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

	Usuario *novoUsuario = new Usuario(nIdade, nGenero, nNome, nInteresses, nCEP, nEscolaridade);
	return novoUsuario;
}

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

void edita_usuario(Usuario* usuario)
{
	char mais = 'n';

	while (mais == 's' || mais == 'S') {

		int escolha = interfaceEdicao();

		if (escolha == 0) {
			break;
		}

		realizaEdicao(usuario, escolha);

		std::cout << "# Realizar mais edicoes ? (S - sim, N - nao) ";
		std::cout << ">> ";
		std::cin >> mais;
	}

	return;

}

int interfaceEdicao()
{
	int escolha = 0;
	std::cout << "# Escolha a edicao a ser realizada:" << std::endl;
	std::cout << "[1] Nome" << std::endl;
	std::cout << "[2] Idade" << std::endl;
	std::cout << "[3] Escolaridade" << std::endl;
	std::cout << "[4] Genero" << std::endl;
	std::cout << "[5] CEP" << std::endl;
	std::cout << "[6] Interesses" << std::endl;
	std::cout << "[0] Cancela" << std::endl;

	std::cout << ">> ";
	std::cin >> escolha;

	return escolha;
}

void realizaEdicao(Usuario * usuario, int escolha)
{
	std::string nNome;
	int nIdade;
	int nEscolaridade;
	char nGenero;
	std::string nCEP;
	std::vector<int> nInteresse;

	switch (escolha) {
	case 1:
		nNome = pegaNome();
		usuario->set_nome(nNome);
		break;

	case 2:
		nIdade = pegaIdade();
		usuario->set_idade(nIdade);
		break;

	case 3:
		nEscolaridade = pegaEscolaridade();
		usuario->set_escolaridade(nEscolaridade);
		break;

	case 4:
		nGenero = pegaGenero();
		usuario->set_genero(nGenero);
		break;

	case 5:
		nCEP = pegaCEP();
		usuario->set_cep(nCEP);
		break;

	case 6:
		nInteresse = pegaInteresses();
		usuario->novos_interesses(nInteresse);
		break;

	default: break;
	}
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

void Usuario::print_lista_usuarios()
{
	for(int i = 0; i < MAX_USUARIOS; i++)
	{
		if(lista_usuarios[i] != nullptr)
		{
			lista_usuarios[i]->print_dados();
		}
	}
}
