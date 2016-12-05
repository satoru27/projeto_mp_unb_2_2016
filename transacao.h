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

};