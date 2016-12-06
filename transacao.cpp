#include <iostream>
#include "transacao.h"

enum servicos_disp {carona = 1, venda = 2, limpeza = 3, construcao = 4, pintura = 5};

Transacao::Transacao(int idc, int idv, int nota, int tipo, int id): id1(idc), id2(idv),avaliacao(nota), tipo_transacao(tipo), id_transacao(id)
{
	std::cout << "Transacao adicionada"<< std::endl;
	trans_aceita = false;
	trans_rejeitada = false;
}

Transacao::~Transacao()
{
	std::cout << "Transacao apagada" << std::endl;
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

int Transacao::get_id_transacao()
{
	return id_transacao;
}

int Transacao::get_tipo_transacao()
{
	return tipo_transacao;
}

// Se foi aceita (vai pro historico)
bool Transacao::finalizada()
{
	return trans_aceita && !trans_rejeitada; 
}

// Ainda nao foi aceita por ninguem
bool Transacao::disponivel()
{
	return !trans_aceita && !trans_rejeitada;
}

// Foi rejeitada ou finalizada por outra pessoa
bool Transacao::rejeitada()
{
	return trans_rejeitada;
}

void Transacao::aceitar()
{
	trans_aceita = true;
}

void Transacao::rejeitar()
{
	trans_rejeitada = true;
}

void Transacao::finalizar_transacao()
{
	int avaliacao = 0;
	std::cout << "Transacao finalizada" << std::endl;
	std::cout << "Avalie a sua transacao (0 a 10): " << std::endl;
	std::cout << ">> ";
	std::cin >> avaliacao;
	this->avaliacao = avaliacao;
	this->trans_aceita = true;
	this->trans_rejeitada = false;
}
