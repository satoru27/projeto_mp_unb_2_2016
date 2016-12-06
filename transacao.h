enum tipos_trasacoes {CARONA, LIMPEZA, };

/*************************************************************************** 
* Classe: Transacao
* Descrição
* Objeto basico da transacao guardando toda a informacao necessaria
***************************************************************************/
class Transacao
{
private:
	int id1; // Id do criador da transacao
	int id2; // Id da pessoa que aceitar a transacao
	int id_transacao; // Id da propria transacao
	int avaliacao; // Avaliacao do criador da transacao ao fornecedor do servico
	int tipo_transacao; // O tipo da transacao
	bool trans_aceita;
	bool trans_rejeitada; 

public:
	/*************************************************************************** 
	* Metodo: Construtor da classe Usuario
	* Descrição
	* Usada para criar uma instancia da classe Usuario
	* Parametros
	* nIdade - Idade do usuario, deve ser um numero maior que 0
	* nGenero - Genero do usuario, deve ser m (homem), f (mulher), o (outro)
	* nId - Id do novo usuario
	* nNome - Nome do usuario, deve ser uma string nao vazia e que nao contenha numeros
	* nInteresses - vetor de inteiros contendo os interesses do usuario
	* nCEP - CEP do usuario
	* nEscolaridade - Contem um inteiro representando a escolaridade do usuario
	* Asseriva de entrada 
	*		nIdade > 0
	*		nGenero == 'm' || nGenero == 'f' || nGenero == 'o'
	*		nNome.size() > 0
	***************************************************************************/
	Transacao(int idc, int idv, int nota, int tipo_transacao, int id);
	~Transacao();


	int get_avaliacao();
	int get_id1();
	int get_id2();
	int get_id_transacao();
	int get_tipo_transacao();

	/*************************************************************************** 
	* Metodo: Finalizada
	* Descrição
	* 	Retorna true se a transacao tiver sido finalizada (aceita e nao rejeitada)
	***************************************************************************/
	bool finalizada();

	/*************************************************************************** 
	* Metodo: Disponivel
	* Descrição
	* 	Retorna true se a transacao estiver disponivel (nao aceita e nao rejeitada)
	***************************************************************************/
	bool disponivel();

	/*************************************************************************** 
	* Metodo: Rejeitada
	* Descrição
	* 	Retorna true se a transacao tiver sida rejeitada (rejeitada = true)
	***************************************************************************/
	bool rejeitada();
	void aceitar();
	void rejeitar();
	void dados_transacao();
	void finalizar_transacao();
};