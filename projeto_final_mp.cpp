// projeto_final_mp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "social.h"
#include <gtest/gtest.h>


/**
*	Testando se a criacao de novos usuarios funciona
*	Testa constructor e getters
*/
TEST(Usuario_test, criar)
{
	std::vector<int> coisas = { 1,3,5,6,4 };
	Usuario a(22, 'm', "Felipe", coisas, "71929000");
	Usuario b(10, 'f', "bla", coisas, "812712828");
	Usuario c(30, 'f', "dsdsd", coisas, "71782909");
	EXPECT_EQ(22, a.get_idade());
	EXPECT_EQ('m', a.get_genero());
	EXPECT_EQ("Felipe", a.get_nome());
	EXPECT_EQ("71929000", a.get_CEP());
	EXPECT_EQ(0, a.get_id());
	EXPECT_EQ(1, b.get_id());
	EXPECT_EQ(2, c.get_id());
}

/**
*	Testando se as funcoes setters funcionam
*/
TEST(Usuario_test, setters)
{
	std::vector<int> coisas = { 1,3,5,6,4 };
	Usuario a(22, 'm', "Felipe", coisas, "71929000");
	a.set_idade(50);
	a.set_genero('f');
	a.set_nome("Filipe");
	a.set_cep("77777777");
	EXPECT_EQ(50, a.get_idade());
	EXPECT_EQ('f', a.get_genero());
	EXPECT_EQ("Filipe", a.get_nome());
	EXPECT_EQ("77777777", a.get_CEP());
}


/**
*	Testando se os interesses estao funcionando corretamente
*/
TEST(Usuario_test, interesses)
{
	std::vector<int> coisas = { 1,3,5,6,4 };
	Usuario a(22, 'm', "Felipe", coisas, "71929000");
	EXPECT_EQ(0, a.get_interesses().size());
	a.add_interesse(7);
	a.add_interesse(9);
	EXPECT_EQ(2, a.get_interesses().size());
	EXPECT_EQ(7, a.get_interesses()[5]);
	EXPECT_EQ(9, a.get_interesses()[6]);
	// Testando se o limite de 20 interesses funciona
	for (int i = 0; i < 25; i++)
	{
		a.add_interesse(1);
	}
	EXPECT_EQ(20, a.get_interesses().size());
	a.delete_interesse(9);
	EXPECT_EQ(19, a.get_interesses().size());
	a.delete_interesse(1);
	EXPECT_EQ(5, a.get_interesses().size());
}


int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

