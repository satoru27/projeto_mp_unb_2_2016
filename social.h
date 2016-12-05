#pragma once
#include <vector>
#include <string>
#include "transacao.h"
#include "usuario.h"

//interesses = servicos ou criar um enum interesses que lista os interesses possiveis

const int MAX_USUARIOS = 100;

class Social
{
private:
	Transacao * matriz_transacoes[MAX_USUARIOS][MAX_USUARIOS];
	Usuario * lista_usuarios[MAX_USUARIOS];
	bool amizades[MAX_USUARIOS][MAX_USUARIOS];
	int get_novo_id();
public:
	Social();
	~Social();
	static int num_total_usuarios;
	void cria_amizade(int id1, int id2);
	void cria_usuario();
	Usuario * get_usuario_by_id(int id);
	void print_lista_usuarios();

};


