class Usuario
{
private:
	int id;
	int idade;
	char genero;
	std::string nome;
	std::vector<int> interesses;
	std::string CEP;
	static int nextId;



public:
	Usuario(int nIdade, int nId, char nGenero, std::string nNome, std::vector<int> nInteresses, std::string nCEP);
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
	void set_escolaridade(int nova_escolaridade);
	void set_nome(std::string novo_nome);
	void set_cep(std::string novo_cep);

	void add_interesse(int nInteresse);
	void delete_interesse(int nInterese);
	void novos_interesses(std::vector<int> nInteresses);

	void bakuhatsu();

	void print_dados();

};

//funcoes
Usuario* retornaUsuario();
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


//administrador
void visualizaPessoas();