#include "social.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static int num_total_usuarios = 0;

Social::Social()
{
	// Inicializa lista de usuarios
	for (int i = 0; i < MAX_USUARIOS; i++) {
		lista_usuarios[i] = nullptr;
	}

	// Inicializa matriz de amizades
	for (int i = 0; i < MAX_USUARIOS; i++) {
		for (int j = 0; j < MAX_USUARIOS; j++) {
			amizades[i][j] = false;
		}
	}

	// matriz de transacoes ja inicializada pelo construtor do vector
	
}

Social::~Social(){}

int Social::get_novo_id()
{
	for (int i = 0; i < MAX_USUARIOS; i++)
	{
		if (lista_usuarios[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

void Social::cria_amizade(int id1, int id2)
{
	amizades[id1][id2] = true;
	amizades[id2][id1] = true;
}

void Social::print_lista_usuarios()
{
	for (int i = 0; i < MAX_USUARIOS; i++)
	{
		if (lista_usuarios[i] != nullptr)
		{
			lista_usuarios[i]->print_dados();
		}
	}
}

bool Social::sao_amigos(int id1, int id2)
{
	if (amizades[id1][id2] == true && amizades[id2][id1] == true) {
		return true;
	}
	else {
		return false;
	}
}

bool Social::eh_amigo_de_amigo(int id1, int id2)
{
	for (int i = 0; i < MAX_USUARIOS; i++) {
		if (sao_amigos(id1, i) && sao_amigos(id2, i)) {
			return true;
		}
	}
	return false;
}

/////mudancas 06/12 01:29
void Social::interface_usuario()
{
	int escolha = 0;
	do {

		std::cout << "# Escolha o que deseja fazer: " << std::endl;
		std::cout << "[1] Criar um usuario" << std::endl;
		std::cout << "[2] Editar um usuario ja existente" << std::endl;
		std::cout << "[3] Editar amizades" << std::endl;
		std::cout << "[4] Excluir um usuario ja existente" << std::endl;
		std::cout << "[5] Solicitar uma nova transacao" << std::endl;
		std::cout << "[6] Aceitar ou rejeitar transacoes" << std::endl;
		std::cout << "[7] Ver historico de transacoes" << std::endl;
		std::cout << "[0] Sair" << std::endl;

		std::cout << ">> ";
		std::cin >> escolha;

		Usuario * user = nullptr;
		Usuario * user2 = nullptr;
		int id1 = -1;
		int id2 = -1;

		if (escolha == 2 || escolha == 4 || escolha == 5 || escolha == 6 || escolha == 7) {
			user = retornaUsuario();
		}
		if (escolha == 3) {
			user = retornaUsuario();
			std::cout << "# Usuario com que deseja editar amizade: " << std::endl;
			user2 = retornaUsuario();
			id1 = user->get_id();
			id2 = user2->get_id();
		}
		
		if (user == nullptr || ((user2 == nullptr) && (escolha == 3))) {
			std::cout << "# Usuario nao cadastrado. Saindo. " << std::endl;
			escolha = 0;
		}

		switch (escolha) {
		case 1: interface_usuario();
			break;
		case 2: edita_usuario(user);
			break;
		case 3: //modifica_amizade(id1,id2)
			break;
		case 4: exclui_usuario(user);
			break;
		case 5: //solicita_transacao(user)
			break;
		case 6: //aceita_solicitacao(user)
			break;
		case 7: //historico_transacoes(user)
			break;
		default:
			break;
		}

	} while (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5 || escolha == 6 || escolha == 7);
}

void Social::interface_adm()
{
	int escolha = 0;
	do {

		std::cout << "# Escolha o que deseja fazer: " << std::endl;
		std::cout << "[1] Mostrar a rede social" << std::endl;
		std::cout << "[2] Cadastrar transacao" << std::endl;
		std::cout << "[3] Decadastrar transacao" << std::endl;
		std::cout << "[4] Olhar historico de transacoes" << std::endl;
		std::cout << "[0] Sair" << std::endl;

		std::cout << ">> ";
		std::cin >> escolha;

		switch (escolha) {
		case 1: //mostrar_rede()
			break;
		case 2: cria_transacao();
			break;
		case 3: excluiTransacao();
			break;
		case 4: //historico geral
		default:
			break;
		}

	} while (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4);
}

void Social::interface_geral()
{
	int escolha = 0;
	do {

		std::cout << "# Escolha a interface desejada " << std::endl;
		std::cout << "[1] Usuario" << std::endl;
		std::cout << "[2] Administrador" << std::endl;
		std::cout << "[0] Sair" << std::endl;

		std::cout << ">> ";
		std::cin >> escolha;

		switch (escolha) {
		case 1: interface_usuario();
			break;
		case 2: interface_adm();
			break;

		default:
			break;
		}

	} while (escolha == 1 || escolha == 2);
}
/////fim mudancas 06/12 01:29
void Social::edita_usuario(Usuario * usuario)
{
	char mais = 'n';

	while (mais == 's' || mais == 'S') {

		int escolha = interfaceEdicao();

		if (escolha == 0) {
			break;
		}

		realizaEdicao(usuario, escolha);

		std::cout << "# Realizar mais edicoes ? (S - sim, N - nao) ";
		std::cout << ">> ";
		std::cin >> mais;
	}

	return;

}

int Social::interfaceEdicao()
{
	int escolha = 0;
	std::cout << "# Escolha a edicao a ser realizada:" << std::endl;
	std::cout << "[1] Nome" << std::endl;
	std::cout << "[2] Idade" << std::endl;
	std::cout << "[3] Escolaridade" << std::endl;
	std::cout << "[4] Genero" << std::endl;
	std::cout << "[5] CEP" << std::endl;
	std::cout << "[6] Interesses" << std::endl;
	std::cout << "[0] Cancela" << std::endl;

	std::cout << ">> ";
	std::cin >> escolha;

	return escolha;
}

void Social::realizaEdicao(Usuario * usuario, int escolha)
{
	std::string nNome;
	int nIdade;
	int nEscolaridade;
	char nGenero;
	std::string nCEP;
	std::vector<int> nInteresse;

	switch (escolha) {
	case 1:
		nNome = pegaNome();
		usuario->set_nome(nNome);
		break;

	case 2:
		nIdade = pegaIdade();
		usuario->set_idade(nIdade);
		break;

	case 3:
		nEscolaridade = pegaEscolaridade();
		usuario->set_escolaridade(nEscolaridade);
		break;

	case 4:
		nGenero = pegaGenero();
		usuario->set_genero(nGenero);
		break;

	case 5:
		nCEP = pegaCEP();
		usuario->set_cep(nCEP);
		break;

	case 6:
		nInteresse = pegaInteresses();
		usuario->novos_interesses(nInteresse);
		break;

	default: break;
	}
}

void Social::exclui_usuario(Usuario * usuario)
{
	std::cout << "# Usuario sera excluido, deseja continuar ?" << std::endl;
	int escolha = 0;
	std::cout << "[1] Sim" << std::endl;
	std::cout << "[2] Nao" << std::endl;
	std::cout << ">> ";
	std::cin >> escolha;

	if (escolha == 1) {
		usuario->bakuhatsu();
		std::cout << "Sucesso, retornando" << std::endl;
	}
	else
		std::cout << "Retornando" << std::endl;
}

Usuario * Social::retornaUsuario()
{
		Usuario * resultado = nullptr;
		std::string nome;
		std::cout << "# Digite o nome do usuario" << std::endl;
		std::cout << ">> ";
		std::cin >> nome;

		for (int i = 0; i < MAX_USUARIOS; i++) {
			std::string nome_rec = lista_usuarios[i]->get_nome();
			if (nome.compare(nome_rec) == 0) {
				resultado = lista_usuarios[i];
			}
		}
		if (resultado == nullptr) {
			std::cout << "[!] Usuario nao encontrado" << std::endl;
		}
		return resultado;
	}

void Social::cria_transacao()
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
	int tipo = 0;
	std::cout << ">> ";
	std::cin >> tipo;

	std::cout << "# Infrome qual foi a avaliacao da transacao" << std::endl;
	int avaliacao = 0;
	std::cout << ">> ";
	std::cin >> avaliacao;

	Transacao* tran = new Transacao(id1, id2, avaliacao, tipo);
	lista_transacoes[id1].push_back(tran);
	lista_transacoes[id2].push_back(tran);
}

void Social::excluiTransacao()
{
	std::cout << "# Bem vindo a exclusao de transacao" << std::endl;
	std::cout << "# Informe o iD do usuario" << std::endl;
	std::cout << ">> ";
	int id = 0;
	std::cin >> id;
	for (int i = lista_transacoes[id].size; i > -1; i--) {
		lista_transacoes[id][i]->dados_transacao();

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

float Social::media_avaliacoes(int userId)
{
	float resultado = 0;
	for (int i = 0; i < lista_transacoes[userId].size(); i++) {
		resultado += lista_transacoes[userId][i]->get_avaliacao();
	}
	if (lista_transacoes[userId].size() > 0) {
		resultado = resultado / lista_transacoes[userId].size();
	}
	return resultado;
}

Usuario * Social::get_usuario_by_id(int id)
{
	return lista_usuarios[id];
}

void Social::cria_usuario()
{	//Usuario(int nIdade, char nGenero, std::string nNome,
	//std::vector<int> nInteresses, std::string nCEP);
	std::cout << "# Bem vindo a criacao de um novo usuario da rede" << std::endl;

	std::cout << "# Digite seu nome" << std::endl;
	std::string nNome = pegaNome();

	std::cout << "# Digite sua idade" << std::endl;
	int nIdade = pegaIdade();

	std::cout << "# Escolha seu nivel de escolariade" << std::endl;
	int nEscolaridade = pegaEscolaridade();

	std::cout << "# Escolha seu genero" << std::endl;
	char nGenero = pegaGenero();

	std::cout << "# Digite seu CEP" << std::endl;
	std::string nCEP = pegaCEP();

	std::cout << "# Escolha seus interesses" << std::endl;
	std::vector<int> nInteresses = pegaInteresses();

	int nId = get_novo_id();
	Usuario *novoUsuario = new Usuario(nIdade, nId, nGenero, nNome, nInteresses, nCEP, nEscolaridade);
	lista_usuarios[nId] = novoUsuario;

}

//AUXILIARES CRIA_USUARIO
std::string pegaNome()
{
	std::string nome;
	std::cout << ">> ";
	std::cin >> nome;
	return nome;
}

int pegaIdade()
{
	int idade = 0;
	std::cout << ">> ";
	std::cin >> idade;
	return idade;
}

int pegaEscolaridade()
{
	int escolaridade = 0;
	std::cout << "[1] Superior incompleto" << std::endl;
	std::cout << "[2] Superior completo" << std::endl;
	std::cout << ">> ";
	std::cin >> escolaridade;
	return escolaridade;
}

char pegaGenero()
{
	char genero = 'O';
	std::cout << "[M] Masculino" << std::endl;
	std::cout << "[F] Feminino" << std::endl;
	std::cout << "[O] Outro" << std::endl;
	std::cout << ">> ";
	std::cin >> genero;

	if (genero == 'm') {
		genero = 'M';
	}
	else if (genero == 'f') {
		genero = 'F';
	}
	else if (genero != 'M' || genero != 'F') {
		genero = 'O';
	}
	return genero;
}

std::string pegaCEP()
{
	std::string CEP;
	std::cout << ">> ";
	std::cin >> CEP;
	return CEP;
}

std::vector<int> pegaInteresses()
{
	std::vector<int> interesses;
	int i = 0;
	int temp = 0;
	char mais = 'n';
	std::cout << "# Escolha os seus interesses (ate 20):" << std::endl;
	std::cout << "[1] Carona" << std::endl;
	std::cout << "[2] Imoveis" << std::endl;
	std::cout << "[3] Servicos" << std::endl;

	while ((i < 20) && (mais == 's' || mais == 'S')) {
		std::cout << ">> ";
		std::cin >> temp;
		//if temp nao esta entre as escolhas manda mensagem e i--
		interesses.push_back(temp);
		temp = 0;
		i++;
		std::cout << "# Adicionar mais interesses ? (S - sim, N - nao) ";
		std::cout << ">> ";
		std::cin >> mais;
	}
	return interesses;
}

