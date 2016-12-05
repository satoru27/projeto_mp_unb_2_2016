#pragma once
#include <vector>
#include "usuario.h"
#include <string>
class Transacao
{
private:
	int id1;
	int id2;
	int avaliacao;
	int tipo_transacao;
	Transacao *proxima;
public:
	Transacao(int idc, int idv, int nota, int tipo_transacao);
	~Transacao();

	void prox_transacao(Transacao *prox);
	int get_avaliacao();
	int get_id1();
	int get_id2();
	void dados_transacao();
	int get_tipo();

};

static std::vector<Transacao> lista_transacoes[MAX_USUARIOS];

void adiciona_transacao(Transacao *tran);
void cria_transacao(int id1, int id2, int tran, int avaliacao);

float media_avaliacoes(int userId);


void solicita_transacao();


//ADMINISTRADOR
void cadastraTransacao();

void excluiTransacao();
void mostraTransacao(int id, int posicao);
void admMostraTransacoes();
