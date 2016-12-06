#pragma once
#include <vector>
#include <string>
#include "transacao.h"
#include "usuario.h"

//interesses = servicos ou criar um enum interesses que lista os interesses possiveis

// Numero maximo de usuarios suportados pela rede
const int MAX_USUARIOS = 100;

/*************************************************************************** 
* Classe: Social
* Descrição
* Controla todas as relacoes entre usuarios
***************************************************************************/
class Social
{
public:
	// Contem todas as transacoes realizadas entre usuarios
	std::vector<Transacao*> lista_transacoes[MAX_USUARIOS];
	// Contem todos os usuarios criados pelo programa
	Usuario * lista_usuarios[MAX_USUARIOS];
	// Matriz que guarda todas as amizades
	bool amizades[MAX_USUARIOS][MAX_USUARIOS];
	
	/*************************************************************************** 
	* Metodo: Pega novo id
	* Descrição
	* 	Acha o primeiro id valido na lista de usuarios
	* Assertivas de saida
	*	Retorna um inteiro que sera o novo id do proximo usuario criado
	*	se nao existirem mais vagas para um novo usuario, retorna -1
	***************************************************************************/
	int get_novo_id();
	
	/*************************************************************************** 
	* Metodo: Construtor da classe Social
	* Descrição
	* 	A classe social controla todas as interacoes do usuario com a rede social
	***************************************************************************/
	Social();
	~Social();
	
	// Guarda o total de usuarios cadastrados na rede
	static int num_total_usuarios;

		
	/*************************************************************************** 
	* Metodo: Cria amizade
	* Descrição
	* 	Cria uma amizade entre o usuario do id1 e id2. A amizade deve ser
	*	bidirecional na matriz de amizades
	* Assertivas de entrada
	* 	id1 e id2 devem ser ids validos.
	***************************************************************************/
	void cria_amizade(int id1, int id2);
	
	/*************************************************************************** 
	* Metodo: Cria Usuario
	* Descrição
	* 	Cria um usuario com um id novo e valido. Essa funcao utiliza o construtor
	*	da classe usuario (fornece um id valido) e coloca o novo usuario criado 
	*	na lista de usuarios.
	***************************************************************************/
	void cria_usuario();

	/*************************************************************************** 
	* Metodo: Pega usuario pelo id
	* Descrição
	* 	Retorna um ponteiro para o objeto de usuario que possui o id passado como
	*	parametro.
	* Assertivas de entrada
	* 	id deve ser um inteiro
	* Assertiva de saida
	*	Caso o usuario exista, retorna um ponteiro para o objeto, caso contrario
	*	retorna nullptr
	***************************************************************************/
	Usuario * get_usuario_by_id(int id);
	
	/*************************************************************************** 
	* Metodo: Imprime lista de usuarios
	* Descrição
	* 	Imprime os dados (Nome e Id) de todos os usuarios registrados.
	***************************************************************************/
	void print_lista_usuarios();


	/***************************************************************************
	* Metodo: Verifica se os usuarios sao amigos
	* Descrição
	* 	Verifica se os usuarios correspondentes ao iD1 e iD2 são amigos, eles só
	*	serão amigos se houver uma aresta de amizade de id1 até id2 e uma aresta
	*	de amizade de id2 até id1.
	* Assertivas de entrada
	* 	Os id's sao de usuarios que existem, id's são inteiros.
	* Assertiva de saida
	*	Caso sejam de fato amigos, retorna true, caso contrário retorna false
	*
	***************************************************************************/
	bool sao_amigos(int id1, int id2);

	/***************************************************************************
	* Metodo: Verifica se os usuarios sao amigos de amigos
	* Descrição
	* 	Verifica se os usuarios correspondentes ao iD1 e iD2 tem amigos em comum
	*	, se houver amigos em comum, significa que id1 e id2 sao amigos de amigos
	* Assertivas de entrada
	* 	Os id's sao de usuarios que existem, id's são inteiros.
	* Assertiva de saida
	*	Se houver pelo menos um amigos em comum, retorna true, caso contrario
	*	retorna false;
	*
	***************************************************************************/
	bool eh_amigo_de_amigo(int id1, int id2);

	/***************************************************************************
	* Metodo: Interface do usuario
	* Descrição
	* 	Inicia a interface do usuario, a interface o guia quanto as opções de
	*	operacoes disponiveis para ele.
	***************************************************************************/
	void interface_usuario();

	/***************************************************************************
	* Metodo: Interface do administrador
	* Descrição
	* 	Inicia a interface do administrador, a interface o guia quanto as opções de
	*	operacoes disponiveis para ele.
	***************************************************************************/
	void interface_adm();

	/*************************************************************************** 
	* Metodo: Interface inicial
	* Descrição
	* 	É a interface inicial do programa, nela existem as opçoes de operar como
	*	um usuário ou administrador, chamando as funções correspondentes.
	***************************************************************************/
	void interface_geral();

	/***************************************************************************
	* Metodo: Edita os atributos de um determinado usuario
	* Descrição
	* 	Recebe um usuario e lança a interface de edição para selecionar qual edição
	*	será feita, com a operação a ser feita em mãos, aciona a função que realiza
	*	a edição, no fim, pergunta se mais edições serão realizadas
	* Assertivas de entrada
	* 	O usuário existe.
	***************************************************************************/
	void edita_usuario(Usuario* usuario);
		//funcoes auxiliares edita usuario

	/***************************************************************************
	* Metodo: Interface de seleção da edição
	* Descrição
	* 	Guia o usuário para ele selecionar qual edição será feita no usuário
	* Assertiva de saida
	*	Será retornado um inteiro que corresponde a operação a ser feita,
	*	esse inteiro está dentro dos parametros a serem utilizados pelo
	*	realizaEdicao
	*
	***************************************************************************/
		int interfaceEdicao();

	/***************************************************************************
	* Metodo: Realiza a edicao do usuário
	* Descrição
	* 	Realiza a edição escolhida no usuário
	* Assertivas de entrada
	* 	O usuário existe e a escolha é válida
	***************************************************************************/
		void realizaEdicao(Usuario* usuario, int escolha);

	/***************************************************************************
	* Metodo: Exclui o usuário
	* Descrição
	* 	Primeiramente a função confirma se deseja prosseguir com a exclusao do usuario
	*	se nao, sai da funcao, se sim, prossegue com a exclusao, primeiramente ele remove 
	*	todas as arestas de amizade que saem dele ou que vao para ele, em seguida o objeto
	*	é desconstruido.
	* Assertivas de entrada
	* 	O usuário existe
	***************************************************************************/
	void exclui_usuario(Usuario* usuario);

	/***************************************************************************
	* Metodo: Retorna o ponteiro para um usuario 
	* Descrição
	* 	A função pede o nome de um usuário e em seguida realiza uma busca na
	*	lista de usuarios e retorna um ponteiro para usuario.
	* Assertiva de saida
	*	Se o usuario existir, um ponteiro para o usuario especificado é retornado,
	*	caso contrario, ele retorna nullptr
	***************************************************************************/
	Usuario* retornaUsuario();

	/***************************************************************************
	* Metodo: Mostra na tela a lista de usuarios
	* Descrição
	*	Mostra na tela todos os usuarios percorrendo a lista de 
	*	usuarios e caso exista seus dados sao mostrados na tela chamando o metodo
	*	de Usuario print_dados.
	***************************************************************************/
	void print_lista_usuarios();

	/***************************************************************************
	* Metodo: Modifica relacao de amizade
	* Descrição
	*	Método utilizado pelo usuario para modificar as suas amizades
	*	A partir dos id1 e id2 adquiridos na interface de Usuario, é possivel
	*	escolher entre remover ou adicionar uma aresta de amizade de id1 até id2
	* Assertivas de entrada
	*	id1 e id2 são de usuários que existem (garantido pela interface de usuario)
	***************************************************************************/
	void modificaAmizade(int id1, int id2);

	/***************************************************************************
	* Metodo: Cria uma nova transacao
	* Descrição
	*	Método utilizado pelo administrador para adicionar uma nova transcação
	*	na lista de transação. É solicitado ao usuário informações necessárias
	*	para a criação da transação e então elas são utilizadas para criar um 
	*	novo objeto Transações que são associados aos vetores de Transação
	*	de cada um dos participantes
	* Assertivas de entrada
	*	As entradas passadas para a criação são válidas
	* Assertiva de saida
	*	O objeto criado é válido se as entradas são válidas
	***************************************************************************/
	void cria_transacao();

	/***************************************************************************
	* Metodo: Exclui uma transacão
	* Descrição
	*	Método utilizado pelo administrador para excluir uma transação.
	*	É solicitado um iD de usuario e em seguida é mostrados as transações 
	*	desse usuário, em cada transacão que é mostrada pergunta-se se deseja
	*	que essa transação seja apagada, se sim, ela é apagada, se não, verifica-se
	*	a próxima
	* Assertivas de entrada
	*	O id do usuário contém transações
	* Assertiva de saida
	*	O vetor de transações do usuário mantém a sua estrutura.
	***************************************************************************/
	void excluiTransacao();

	/***************************************************************************
	* Metodo: Devolve a média das avaliações do usuário
	* Descrição
	*	O método recebe o id do usuário do qual deseja-se saber a média das
	*	avaliações. A função percorre a lista de transações do usuário,
	*	soma a avaliação a um acumulador daquelas que já foram concretizadas
	*	e incrementa um contador para saber quantas transações existem,
	*	ao final, faz a média dividindo o total de avaliações pelo numero de
	*	avaliações, retornando esse resultado.
	* Assertivas de entrada
	*	O id pertence a um usuário já realizou alguma transacao
	* Assertiva de saida
	*	Resultado retornado é um float igual ou entre a 0 e 10
	***************************************************************************/
	float media_avaliacoes(int userID);
	

	//void solicita_transacao();//

	/***************************************************************************
	* Metodo: Mostra os usuarios e amizades da rede
	* Descrição
	* 	Solicita o id de um usuario e prossegue para chamar as funcoes
	*	mostra usuario e mostraUsuario e mostraAmizades 
	* Assertivas de entrada
	* 	O id passado é de um usuário válido
	***************************************************************************/
	void mostraRede();

		//auxiliares mostra REDE
	/***************************************************************************
	* Metodo: Mostra as informacoes do usuario
	* Descrição
	* 	A função recebe um ponteiro para um determinado usuário e mostra na tela
	*	todas as informações do perfil desse usuário.
	* Assertivas de entrada
	* 	O usuário recebido pela função existe
	***************************************************************************/
		void mostraUsuario(Usuario * user);

	/***************************************************************************
	* Metodo: Mostra as amizades do usuário
	* Descrição
	* 	A função recebe um ponteiro para usuário e mostra na tela todas as 
	*	relações de amizade esse usuário (amizades feitas e pendentes)
	* Assertivas de entrada
	* 	O usuário recebido pela função existe
	***************************************************************************/
		void mostraAmizades(Usuario * user);


	/***************************************************************************
	* Metodo: Mostra o historico de transações
	* Descrição
	*	A função percorre a lista de transações imprimindo na tela todas as
	*	transações existentes e suas respectivas informações.
	***************************************************************************/
	void historicoGeral();
};


/*************************************************************************** 
* Funcoes: Pega [valor]
* Descrição
* 	As funcoes abaixo realizam o input dos dados, ja realizando a valiacao das 
*	assertivas de entrada (Baseado nas assertivas de entrada do construtor da classe Usuario)
* Assertivas de saida
*	Retornam um valor valido referente a um atributo da classe
***************************************************************************/
std::string pegaNome();
int pegaIdade();
int pegaEscolaridade();
char pegaGenero();
std::string pegaCEP();
std::vector<int> pegaInteresses();
