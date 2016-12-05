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

	void bakuhatsu();

};



class Transacao
{
private:
	int id1;
	int id2;
	int avaliacao;
	int tipo;
	Transacao *proxima = nullptr;
public:
	Transacao(int idc, int idv, int tipo, int nota);
	~Transacao();

	void prox_transacao(Transacao *prox);
	int get_avaliacao();
	int get_id1();
	int get_id2();
	int get_tipo();

};

void adiciona_transacao(Transacao *tran);
void cria_transacao(int id1,int id2,int tran,int avaliacao);

static std::vector<Transacao> lista_transacoes[MAX_USUARIOS];
static Usuario *lista_usuarios[MAX_USUARIOS];
static bool amizades[MAX_USUARIOS][MAX_USUARIOS];


//////////////FUNCOES

void inicializa_usuarios();
void inicializa_amizades();

Usuario* retornaUsuario();

float media_avaliacoes(int userId);

bool sao_amigos(int id1, int id2);
bool eh_amigo_de_amigo(int id1, int id2);


//INTERFACE USUARIO
Usuario* cria_usuario();
//funcoes auxiliares cria usuario
	std::string pegaNome();
	int pegaIdade();
	int pegaEscolaridade();
	char pegaGenero();
	std::string pegaCEP();
	std::vector<int> pegaInteresses();



void edita_usuario(Usuario* usuario);
//funcoes auxiliares edita usuario
	int interfaceEdicao();
	void realizaEdicao(Usuario* usuario, int escolha);


void exclui_usuario(Usuario* usuario);

void solicita_transacao();
//funcoes auxiliares solicita transacao


//ADMINISTRADOR
void visualizaPessoas();

void cadastraTransacao();

void excluiTransacao();
	void mostraTransacao(int id, int posicao);
void admMostraTransacoes();
