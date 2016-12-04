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
Transacao::Transacao(int idc, int idv, int nota): id1(idc), id2(idv),avaliacao(nota)
{
	std::cout << "Transacao criada"<< std::endl;
	adiciona_transacao(this);
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


//FUNCOES TRANSACAO
void adiciona_transacao(Transacao *tran) {
	int id1 = tran->get_id1;
	int id2 = tran->get_id2;
	lista_transacoes[id1].push_back(*tran);
	lista_transacoes[id2].push_back(*tran);
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


