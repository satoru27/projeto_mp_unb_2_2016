#include <iostream>
#include "transacao.h"

enum servicos_disp {carona = 1, venda = 2, limpeza = 3, construcao = 4, pintura = 5};

Transacao::Transacao(int idc, int idv, int nota, int tipo): id1(idc), id2(idv),avaliacao(nota), tipo_transacao(tipo)
{
	std::cout << "Transacao adicionada"<< std::endl;
	this->proxima = nullptr;
}

Transacao::~Transacao()
{
	std::cout << "Transacao apagada" << std::endl;
}

void Transacao::prox_transacao(Transacao *prox) {
	proxima = prox;
}

void Transacao::dados_transacao(){
	std::cout << std::endl <<"Transacao realizada entre usuario " << "[" << this->id2 << "] ";
	std::cout << "e usuario " << "[" << this->id1 << "]." << std::endl;
	std::cout << "Tipo de transacao: ";
	switch(this->tipo_transacao)
	{
		case 1:
			std :: cout << "carona.";
			break;
		case 2:
			std::cout << "venda.";
			break;
		case 3:
			std::cout << "limpeza.";
			break;
		case 4:
			std::cout << "construcao.";
			break;
		case 5:
			std::cout << "pintura.";
			break;
	}
	std::cout << std::endl;
	std::cout << "Avaliacao: " << this->avaliacao << std::endl;
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
	return tipo_transacao;
}

//FUNCOES TRANSACAO
void adiciona_transacao(Transacao *tran) {
	int id1 = tran->get_id1;
	int id2 = tran->get_id2;
	lista_transacoes[id1].push_back(*tran);
	lista_transacoes[id2].push_back(*tran);
}

void cria_transacao(int id1, int id2, int tran, int avaliacao) {
	Transacao *nTransacao = new Transacao(id1, id2, tran, avaliacao);
	adiciona_transacao(nTransacao);
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

	cria_transacao(id1, id2, tran, avaliacao);
}

void excluiTransacao()
{
	std::cout << "# Bem vindo a exclusao de transacao" << std::endl;
	std::cout << "# Informe o iD do usuario" << std::endl;
	std::cout << ">> ";
	int id = 0;
	std::cin >> id;
	for (int i = lista_transacoes[id].size; i > -1; i--) {
		mostraTransacao(id, i);

		std::cout << "# Deseja excluir essa transacao ?" << std::endl;

		int escolha = 0;
		std::cout << "[1] Sim" << std::endl;
		std::cout << "[2] Nao" << std::endl;
		std::cout << ">> ";
		std::cin >> escolha;

		if (escolha == 1) {
			lista_transacoes[id].erase(lista_transacoes[id].begin() + (i - 1));
		}
	}

}

void mostraTransacao(int id, int posicao)
{
	std::cout << "Transacao entre " + std::to_string(lista_transacoes[id][posicao].get_id1()) + " e " + std::to_string(lista_transacoes[id][posicao].get_id2()) << std::endl;
	std::cout << "Do tipo " + std::to_string(lista_transacoes[id][posicao].get_tipo()) + "com avaliacao " + std::to_string(lista_transacoes[id][posicao].get_avaliacao()) << std::endl;
}