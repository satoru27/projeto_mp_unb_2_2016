#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "social.h"

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
	contador_transacao = 0;
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


void Social::edita_usuario(Usuario * usuario)
{
	char mais = 'n';

	do{
		int escolha = interfaceEdicao();

		if (escolha == 0) {
			break;
		}

		realizaEdicao(usuario, escolha);

		std::cout << "# Realizar mais edicoes ? (S - sim, N - nao) ";
		std::cout << ">> ";
		std::cin >> mais;

	} while (mais == 's' || mais == 'S');

	return;

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
		if (nome == lista_usuarios[i]->get_nome()) {
			return lista_usuarios[i];
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

	contador_transacao++;
	Transacao* tran = new Transacao(id1, id2, avaliacao, tipo, contador_transacao);
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
	for (int i = lista_transacoes[id].size(); i > -1; i--) {
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

Usuario * Social::cria_usuario()
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
	std::cin.ignore(1000, '\n');

	std::cout << "# Escolha seus interesses" << std::endl;
	std::vector<int> nInteresses = pegaInteresses();

	int nId = get_novo_id();
	Usuario *novoUsuario = new Usuario(nIdade, nId, nGenero, nNome, nInteresses, nCEP, nEscolaridade);
	lista_usuarios[nId] = novoUsuario;
	return novoUsuario;
}

void Social::solicita_transacao(int id_criador)
{
	int tipo;
	char requis;
	struct requisitos * requisitos = nullptr;
	std::cout << "Bem vindo a criacao de transacao " << std::endl;
	std::cout << "Escolha o tipo de transacao " << std::endl;
	std::cout << "[1] Carona " << std::endl;
	std::cout << "[2] Limpeza " << std::endl;
	std::cout << "[3] Venda " << std::endl;
	std::cout << "[4] Construcao " << std::endl;
	std::cout << "[5] Pintura " << std::endl;
	std::cout << ">> ";
	std::cin >> tipo;
	std::cout << "Deseja especificar algum tipo de prerequisito? [y/n]" << std::endl;
	std::cout << ">> ";
	std::cin >> requis;
	if(requis == 'y')
		requisitos = cria_requis();
	cria_transacao(id_criador, tipo, requisitos);
}

struct requisitos * cria_requis()
{
	struct requisitos * new_requis = new struct requisitos;
	if(new_requis == nullptr)
	{
		std::cout <<" ERRO CRIANDO A PORRA DA STRUCT ";
	}
	char resp;
	std::cout << "Deseja especificar idade minima? [y/n]" << std::endl;
	std::cout << ">> ";
	std::cin >> resp;
	if(resp == 'y')
	{
		std::cout << "Qual a idade minima?" << std::endl;
		std::cout << ">> ";
		std::cin >> new_requis->idade;
	}
	else
	{
		new_requis->idade = -1;
	}

	std::cout << "Deseja especificar algum nivel de escolaridade? [y/n]" << std::endl;
	std::cout << ">> ";
	std::cin >> resp;
	if(resp == 'y')
	{
		std::cout << "Qual nivel minimo de escolaridade?" << std::endl;
		std::cout << "[0 - Ensino superior incompleto, 1 - Superior completo]" << std::endl;
		std::cout << ">> ";
		std::cin >> new_requis->escol;
	}
	else
	{
		new_requis->escol = -1;
	}

	std::cout << "Deseja especificar algum genero? [y/n]" << std::endl;
	std::cout << ">> ";
	std::cin >> resp;
	if(resp == 'y')
	{
		std::cout << "Qual genero?" << std::endl;
		std::cout << "[M - homem, F - mulher, O - outro]" << std::endl;
		std::cout << ">> ";
		char genero;
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
		new_requis->gen = genero;
	}
	else
	{
		new_requis->gen = 'p';
	}

	std::cout << "Deseja que o usuario tenha uma media de avaliacoes minima? [y/n]" << std::endl;
	std::cout << ">> ";
	std::cin >> resp;
	if(resp == 'y')
	{
		std::cout << "Qual a media minima?" << std::endl;
		std::cout << ">> ";
		std::cin >> new_requis->media;
	}
	else
	{
		new_requis->media = -1;
	}

	std::cout << "Deseja que o usuario seja seu amigo ou amigo de amigo?" << std::endl;
	std::cout << ">> ";
	std::cin >> resp;
	if(resp == 'y')
	{
		std::cout << "[0 - amigo]/[1 - amigo de amigo]" << std::endl;
		std::cout << ">> ";
		std::cin >> new_requis->grau;
	}
	else
	{
		new_requis->grau = -1;
	}

	new_requis->CEP = "";
	new_requis->nome = "";

	std::cout << "Deseja que o usuario ja tenha feito um trabalho desse tipo?" << std::endl;
	std::cout << ">> ";
	std::cin >> resp;
	if(resp == 'y')
	{
		new_requis->tipo = 1;
	}
	else
	{
		new_requis->tipo = -1;
	}
	return new_requis;
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

bool requis_idade(int idade, int threshold)
{
	if (threshold == -1) // -1 vai ser o valor padrao (sem requisito)
		return true;
	return idade >= threshold;
}

bool requis_cep(std::string CEP, std::string requis)
{
	if (requis.empty())
		return true;
	return CEP == requis;
}

bool requis_genero(char gen, char requis)
{
	if(requis == 'p')
		return true;
	return gen == requis;
}

bool requis_escolaridade(int escol, int requis)
{
	if(requis == -1)
		return true;
	return escol >= requis;
}

bool requis_nome(std::string nome, std::string requis)
{
	if(requis.empty())
		return true;
	return nome == requis;
}

bool requis_avaliacoes(int media, int threshold)
{
	if(threshold == -1)
		return true;
	return media >= threshold;
}

bool requis_tipo(int tipo, std::vector<Transacao*> transacoes)
{
	if(tipo == -1)
		return true;
	for(int i = 0; i < transacoes.size(); i++)
	{
		if(transacoes[i]->get_tipo_transacao() == tipo)
			return true;
	}
	return false;
}

bool Social::preenche_requis(Usuario * a, int id_criador, struct requisitos * requis)
{
	if(a == nullptr)
		return false;
	if(requis == nullptr)
	{
		return true;
	}
	bool atributos = (requis_idade(a->get_idade(), requis->idade) && requis_cep(a->get_CEP(), requis->CEP)) && 
						(requis_genero(a->get_genero(), requis->gen) && requis_escolaridade(a->get_escolaridade(), requis->escol)) && 
							(requis_nome(a->get_nome(), requis->nome) && requis_avaliacoes(media_avaliacoes(a->get_id()), requis->media)) ;
	switch(requis->grau)
	{
		case 0:
			atributos = atributos && sao_amigos(a->get_id(), id_criador);
			break;
		case 1:
			atributos = atributos && eh_amigo_de_amigo(a->get_id(), id_criador);
			break;
	}
	atributos = atributos && requis_tipo(requis->tipo, lista_transacoes[a->get_id()]);
	return atributos;
}

void Social::cria_transacao(int id_criador, int tipo, struct requisitos * requis) // id do criador e struct com requisitos
{
	int novo_id = contador_transacao;
	contador_transacao++;
	for(int i = 0; i < MAX_USUARIOS;i++)
	{
		if(i != id_criador && preenche_requis(lista_usuarios[i],id_criador ,requis))
		{
			Transacao *a = new Transacao(id_criador, i, -1, tipo,novo_id);
			lista_transacoes[i].push_back(a);
		}
	}
}

void Social::print_lista_transacoes(int userID)
{
	if(userID == -1)
	{
		for(int i = 0; i < MAX_USUARIOS;i++)
		{
			for(int j = 0; j < lista_transacoes[i].size();j++)
			{
				lista_transacoes[i][j]->dados_transacao();
			}
		}
	}
	else{
		std::vector<Transacao*> lista_trans = lista_transacoes[userID];
		for(int i = 0; i < lista_trans.size();i++)
		{
			lista_trans[i]->dados_transacao();
		}
	}
}

void Social::historico_transacoes(int userID)
{
	std::vector<Transacao*> lista_trans = lista_transacoes[userID];
	for(int i = 0; i < lista_trans.size(); i++)
	{
		if(lista_trans[i]->finalizada())
		{
			lista_trans[i]->dados_transacao();
		}
	}	
}

bool fazer_transacao()
{	
	char resp;	
	std::cout << "Deseja realizar essa transacao? [y/n]" << std::endl;
	std::cin >> resp;
	if(resp == 'y')
		return true;
	return false;
}

void Social::transacoes_pendentes(int userID)
{
	std::vector<Transacao*> lista_trans = lista_transacoes[userID];
	int num_transacao = 0;
	for(int i = 0; i < lista_trans.size(); i++)
	{
		if(lista_trans[i]->disponivel())
		{
			std::cout << "Transacao numero " << num_transacao << std::endl;
			num_transacao++;
			lista_trans[i]->dados_transacao();
			if(fazer_transacao())
			{
				lista_trans[i]->finalizar_transacao();
			}
		}
	}
}








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
		std::cout << "[6] Ver historico de transacoes" << std::endl;
		std::cout << "[7] Transacoes Pendentes" << std::endl;
		std::cout << "[0] Sair" << std::endl;

		std::cout << ">> ";
		std::cin >> escolha;

		Usuario * user = nullptr;
		Usuario * user2 = nullptr;
		int id1 = -1;
		int id2 = -1;

		if(escolha == 1)
		{
			user = cria_usuario();
		}

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
		
		if ((escolha != 1) && (user == nullptr || ((user2 == nullptr) && (escolha == 3)))){
			std::cout << "# Usuario nao cadastrado. Saindo. " << std::endl;
			escolha = 0;
		}

		switch (escolha) {
		case 1: interface_usuario();
			break;
		case 2: edita_usuario(user);
			break;
		case 3: modificaAmizade(id1, id2);
			break;
		case 4: exclui_usuario(user);
			break;
		case 5: solicita_transacao(user->get_id());
			break;
		case 6: historico_transacoes(user->get_id());
			break;
		case 7: transacoes_pendentes(user->get_id());
			break;
		default:
			break;
		}

	} while (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5 || escolha == 6 || escolha == 7);
}

void Social::mostraRede()
{
	int escolha = 0;
	do {

		std::cout << "# Digite o id de usuario a ser verificado" << std::endl;
		std::cout << ">> ";
		int id=-1;
		std::cin >> id;

		Usuario * user = get_usuario_by_id(id);

		if (id < 0 || id > MAX_USUARIOS || user == nullptr) {
			std::cout << "# ID invalido ou usuario inexistente" << std::endl;
		}	

		//mostra usuario
		mostraUsuario(user);
		mostraAmizades(user);


		std::cout << "[0] Sair" << std::endl;

	} while (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4);
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
		case 1: mostraRede();
			break;
		case 2: cria_transacao();
			break;
		case 3: excluiTransacao();
			break;
		case 4: print_lista_transacoes(-1);
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


void Social::mostraUsuario(Usuario * user)
{

	std::cout << "[+] Nome : " + user->get_nome() << std::endl;
	std::cout << "[+] Idade : " + std::to_string(user->get_idade()) << std::endl;
	std::cout << "[+] Genero : " << user->get_genero() << std::endl;
	user->mostraEscolaridade();
	user->mostraInteresses();
	std::cout << "[+] CEP : " + user->get_CEP() << std::endl;
}




void Social::mostraAmizades(Usuario * user)
{
	std::cout << "# Amizades do usuario : "<< std::endl;
	int id = user->get_id();
	for (int i = 0; i < MAX_USUARIOS; i++) {
		if (amizades[id][i] && amizades[i][id]) {
			std::cout << "[*] O usuario e amigo de : iD = " + std::to_string(i) << std::endl;
		}
		else {
			if (amizades[id][i]) {
				std::cout << "[*] Enviou solicitacao de amizade para : iD = " + std::to_string(i) << std::endl;
			}
			if (amizades[i][id]) {
				std::cout << "[*] Recebeu solicitacao de amizade de : iD = " + std::to_string(i) << std::endl;
			}
		}

	}
}


void Social::modificaAmizade(int id1, int id2)
{
	int escolha = 0;
	do {

		std::cout << "# Escolha o que deseja fazer: " << std::endl;
		std::cout << "[1] Adicionar amizade" << std::endl;
		std::cout << "[2] Remover amizade" << std::endl;
		std::cout << "[0] Sair" << std::endl;

		std::cout << ">> ";
		std::cin >> escolha;

		switch (escolha) {
		case 1: amizades[id1][id2] = true;
			std::cout << "# Adicionado" << std::endl;
			break;
		case 2: amizades[id1][id2] = false;
			std::cout << "# Removido" << std::endl;
			break;
		default:std::cout << "# Saindo" << std::endl;
			break;
		}

	} while (escolha == 1 || escolha == 2);
}

