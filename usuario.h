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
	void set_nome(std::string novo_nome);
	void set_cep(std::string novo_cep);

	void add_interesse(int nInteresse);
	void delete_interesse(int nInterese);

};