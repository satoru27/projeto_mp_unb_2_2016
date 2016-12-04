#pragma once
#include <vector>
//interesses = servicos ou criar um enum interesses que lista os interesses possiveis
enum servicos_disp {carona = 1, venda = 2 };
const int MAX_USUARIOS = 100;

// Guarda o numero total de usuarios. Tambem vai ser utilizada para fornecer o ID
// de um novo usuario
static int num_total_usuarios = 0;


class Usuario
{
private:
	int id;
	int idade;
	char genero;
	std::string nome;
	std::vector<int> interesses;
	std::string CEP;



public:
	Usuario(int nIdade, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP);
	~Usuario();

	// Getters
	int get_idade();
	int get_id();
	char get_genero();
	std::string get_nome();
	std::vector<int> get_interesses();
	std::string get_CEP();

	// Setters
	void set_idade(int nova_idade);
	void set_genero(char novo_genero);
	void set_nome(std::string novo_nome);
	void set_cep(std::string novo_cep);

	void add_interesse(int nInteresse);
	void delete_interesse(int nInterese);

};



class Transacao
{
private:
	int id1;
	int id2;
	int avaliacao;
	Transacao *proxima = nullptr;
public:
	Transacao(int idc, int idv, int nota);
	~Transacao();

	void prox_transacao(Transacao *prox);
	int get_avaliacao();
	int get_id1();
	int get_id2();

};

static Transacao *matriz_transacoes[MAX_USUARIOS][MAX_USUARIOS];
static Usuario *lista_usuarios[MAX_USUARIOS];
static bool amizades[MAX_USUARIOS][MAX_USUARIOS];


//////////////FUNCOES
