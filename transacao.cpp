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
	std::cout << std::endl <<"Transacao realizada entre usuario " << "[" << this->idv << "] ";
	std::cout << "e usuario " << "[" << this->idc << "]." << std::endl;
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

