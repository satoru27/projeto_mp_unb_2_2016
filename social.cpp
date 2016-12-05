#include "social.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

///////////////USUARIO
int novo_id() {
	int nId = 0;
	if (lista_usuarios[0] == nullptr) {
		nId = 0;
	}
	else {
		for (int i = 0; i < MAX_USUARIOS - 1; i++) {

			if (lista_usuarios[i] != nullptr && lista_usuarios[i + 1] == nullptr) {
				nId = i + 1;
				break;
			}
		}
	}
	return nId;
}

Usuario::Usuario(int nIdade, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP)
	:idade(nIdade), genero(nGenero), nome(nNome),interesses(nInteresses), CEP(nCEP)
{
	id = novo_id();
	std::cout << "Usuario [" + std::to_string(id) + "] criado" << std::endl;
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





//////////////FIM_USUARIO


//////////////INICIO_TRANSACOES
Transacao::Transacao(int idc, int idv,int nTipo ,int nota): id1(idc), id2(idv),tipo(nTipo),avaliacao(nota)
{
	std::cout << "Transacao criada"<< std::endl;
}

Transacao::~Transacao()
{
	std::cout << "Transacao apagada" << std::endl;
}

void Transacao::prox_transacao(Transacao *prox) {
	proxima = prox;
}

int  Transacao::get_avaliacao() {
	return avaliacao;
}

int  Transacao::get_id1() {
	return id1;
}

int  Transacao::get_id2() {
	return id2;
}

int Transacao::get_tipo()
{
	return tipo;
}


//FUNCOES TRANSACAO
void adiciona_transacao(Transacao *tran) {
	int id1 = tran->get_id1;
	int id2 = tran->get_id2;
	lista_transacoes[id1].push_back(*tran);
	lista_transacoes[id2].push_back(*tran);
}

void cria_transacao(int id1, int id2,int tran,int avaliacao){
	Transacao *nTransacao = new Transacao(id1, id2, tran, avaliacao);
	adiciona_transacao(nTransacao);
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


float media_avaliacoes(int userId)
{
	float resultado = 0;
	for (int i = 0; i < lista_transacoes[userId].size(); i++) {
		resultado = lista_transacoes[userId][i].get_avaliacao();
	}
	if (lista_transacoes[userId].size() > 0) {
		resultado = resultado / lista_transacoes[userId].size();
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

	Usuario *novoUsuario = new Usuario(nIdade,nGenero,nNome, nInteresses,nCEP);
}

void edita_usuario(Usuario* usuario)
{
	bool editar_mais = false;

	int escolha = interfaceEdicao();

	realizaEdicao(usuario,escolha);

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

void solicita_transacao()
{
}

void cadastraTransacao()
{
	std::cout << "# Informe o iD do comprador" << std::endl;
	int id1 = 0;
	std::cout << ">> ";
	std::cin >> id1;

	std::cout << "# Informe o iD do vendedor ou prestador do servico" << std::endl;
	int id2 = 0;
	std::cout << ">> ";
	std::cin >> id2;

	std::cout << "# Infrome qual foi o tipo da transacao" << std::endl;
	int tran = 0;
	std::cout << ">> ";
	std::cin >> tran;

	std::cout << "# Infrome qual foi a avaliacao da transacao" << std::endl;
	int avaliacao = 0;
	std::cout << ">> ";
	std::cin >> avaliacao;

	cria_transacao(id1,id2,tran,avaliacao);
}

void excluiTransacao()
{
	std::cout << "# Bem vindo a exclusao de transacao" << std::endl;
	std::cout << "# Informe o iD do usuario" << std::endl;
	std::cout << ">> ";
	int id = 0;
	std::cin >> id;
	for (int i = lista_transacoes[id].size; i > -1; i--) {
		mostraTransacao(id,i);
		
		std::cout << "# Deseja excluir essa transacao ?" << std::endl;

		int escolha = 0;
		std::cout << "[1] Sim" << std::endl;
		std::cout << "[2] Nao" << std::endl;
		std::cout << ">> ";
		std::cin >> escolha;

		if (escolha == 1) {
			lista_transacoes[id].erase(lista_transacoes[id].begin() + (i-1));
		}
	}
	
}

void mostraTransacao(int id, int posicao)
{
	std::cout << "Transacao entre " + std::to_string(lista_transacoes[id][posicao]->get_id1()) + " e " + std::to_string(lista_transacoes[id][posicao]->get_id2()) << std::endl;
	std::cout << "Do tipo " + std::to_string(lista_transacoes[id][posicao]->get_tipo()) + "com avaliacao " + std::to_string(lista_transacoes[id][posicao]->get_avaliacao()) + << std::endl
}
