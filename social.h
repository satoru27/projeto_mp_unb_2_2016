#pragma once
#include <vector>
#include <string>
#include "transacao.h"
#include "usuario.h"

struct requisitos{
  int idade; // aceita qualquer um com usuario.idade >= idade. -1 para aceitar qualquer idade
  int media; // aceita qualquer um com usuario.media >= media. -1 para aceitar qualquer media
  int escol; // aceita qualquer um com usuario.escolaridade >= escolaridade. -1 qualquer escolaridade
  std::string CEP; // so aceita se usuario.cep == cep. string vazia para aceitar qualquer um
  char gen; // aceita se usuario.genero = gen. 'p' para aceitar qualquer genero
  std::string nome; // mesma coisa do cep
  int grau; // se grau == 0, pecisa ser amigo. se grau == 1 precisa ser no maximo amigo de amigo. -1 para qualquer 1
  int tipo; // so aceita se o usuario ja fez uma transacao do msm tipo. -1 anula esse requisito
};

//interesses = servicos ou criar um enum interesses que lista os interesses possiveis

const int MAX_USUARIOS = 100;

class Social
{
private:
  int contador_transacao;
public:
	std::vector<Transacao*> lista_transacoes[MAX_USUARIOS];
	Usuario * lista_usuarios[MAX_USUARIOS];
	bool amizades[MAX_USUARIOS][MAX_USUARIOS];
	int get_novo_id();

	Social();
	~Social();
	static int num_total_usuarios;

	void cria_amizade(int id1, int id2);
	Usuario * cria_usuario();

	Usuario * get_usuario_by_id(int id);
	void print_lista_usuarios();

	bool sao_amigos(int id1, int id2);
	bool eh_amigo_de_amigo(int id1, int id2);

	//usuario
	void interface_usuario();//
	void interface_geral();//


	void edita_usuario(Usuario* usuario);
		//funcoes auxiliares edita usuario
		int interfaceEdicao();
		void realizaEdicao(Usuario* usuario, int escolha);


	void exclui_usuario(Usuario* usuario);

	Usuario* retornaUsuario();


	//adm transacao
	void cria_transacao();
	void excluiTransacao();

	//user transacao
	float media_avaliacoes(int userID);
	
	void solicita_transacao(int id_criador);//
	bool preenche_requis(Usuario * a, int id_criador, struct requisitos * requis);
	void cria_transacao(int id_criador, int tipo, struct requisitos * requis);

	void print_lista_transacoes(int userID);

	void historico_transacoes(int userID);
	void transacoes_pendentes(int userID);
	void interface_adm();
	void mostraRede();
	void mostraAmizades(Usuario * user);
	void mostraUsuario(Usuario * user);
	void modificaAmizade(int id1, int id2);

	//adm 
	//void visualizaPessoas();
};


//funcoes auxiliares cria usuario
std::string pegaNome();
int pegaIdade();
int pegaEscolaridade();
char pegaGenero();
std::string pegaCEP();
std::vector<int> pegaInteresses();
void cria_transacao(struct requisitos * requis);
struct requisitos * cria_requis();


//funcoes auxiliares solicita_transacao