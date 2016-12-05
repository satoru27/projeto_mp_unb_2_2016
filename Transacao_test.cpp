#include "transacao.h"
#include <gtest/gtest.h>


TEST(Transacao_test, criar_transacao)
{
	Transacao a(1,2,5,1);
	EXPECT_EQ(1, a.get_id1());
	EXPECT_EQ(2, a.get_id2());
	EXPECT_EQ(5, a.get_avaliacao());
}


int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}