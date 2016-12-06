// projeto_final_mp.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include "social.h"
#include "usuario.h"
#include "transacao.h"

/**
*	Testando se a criacao de novos usuarios funciona
*	Testa constructor e getters
*/
TEST(Social_test,)
{
	std::vector<int> coisas = { 1,3,5,6,4 };
	Usuario a(22, 0, 'm', "Felipe", coisas, "71929000", 1);
	Usuario b(10, 1, 'f', "bla", coisas, "812712828", 2);
	Usuario* c = new Usuario(30, 2, 'f', "dsdsd", coisas, "71782909", 1);
	
	//teste cria amizade
	cria_amizade(0, 1)
	EXPECT_EQ(true, amizades[0][1]);
	EXPECT_EQ(true, amizades[1][0]);

	//cria_usuario()

	//teste get usuario by id
	Usuario* d = get_usuario_by_id(2);
	EXPECT_EQ(c, d);

	Usuario* not_user = get_usuario_by_id(98);
	EXPECT_EQ(nullptr, not_user);
	
	//print_lista_de_usuario()

	//teste sao amigos
	//foi criada amizade acima entre 0 e 1
	bool amigos = sao_amigos(0, 1);
	EXPECT_EQ(true, amigos);

	//teste eh amigo de amigo
	cria_amizade(1, 2);
	bool amigosDeAmigos = eh_amigo_de_amigo(0, 2);
	EXPECT_EQ(true, amigosDeAmigos);

	//interface_usuario()

	//interface_adm()

	//interface_geral()

	//edita_usuario(Usuario* usuario)

	//interfaceEdicao()

	//realizaEdicao(Usuario* usuario, int escolha)

	//exclui_usuario(Usuario* usuario)

	//retornaUsuario()

	//print_lista_usuarios()
	
	//modificaAmizade(int id1, int id2)

	//cria_transacao()

	//excluiTransacao()

	/*media_avaliacoes(int userID)
	!!! essa da pra testar mas tem que criar a transacao antes
	*/

	//mostraRede()

	//mostraUsuario(Usuario * user)

	//mostraAmizades()

	//historicoGeral()

	/*
	std::string pegaNome();
	int pegaIdade();
	int pegaEscolaridade();
	char pegaGenero();
	std::string pegaCEP();
	std::vector<int> pegaInteresses();
	*/
}




int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

