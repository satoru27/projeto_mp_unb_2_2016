#pragma once
#include <vector>
#include <string>
#include "transacao.h"
#include "usuario.h"

//interesses = servicos ou criar um enum interesses que lista os interesses possiveis

const int MAX_USUARIOS = 100;

class Social
{
public:
	std::vector<Transacao> lista_transacoes[MAX_USUARIOS];
	Usuario * lista_usuarios[MAX_USUARIOS];
	bool amizades[MAX_USUARIOS][MAX_USUARIOS];
	int get_novo_id();

	Social();
	~Social();
	static int num_total_usuarios;
	void cria_amizade(int id1, int id2);
	void cria_usuario();
	Usuario * get_usuario_by_id(int id);
	void print_lista_usuarios();

};


//funcoes auxiliares cria usuario
std::string pegaNome();
int pegaIdade();
int pegaEscolaridade();
char pegaGenero();
std::string pegaCEP();
std::vector<int> pegaInteresses();
