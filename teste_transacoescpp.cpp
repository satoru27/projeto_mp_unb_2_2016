#include "stdafx.h"

#include "social.h"
#include <gtest/gtest.h>

TEST(Teste_transacoes, criar)
{	
	Transacao a(10, 11, 7);
	Transacao b(10, 32, 8);
	Transacao c(22, 21, 9);
	

}








int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}