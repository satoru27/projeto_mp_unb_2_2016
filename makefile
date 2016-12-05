social:
	g++ social.cpp -c

socialt: social
	g++ social_test.cpp social.o -o test -I../gtest/include -L.. -lgtest -lgtest_main -ftest-coverage -std=c++11

usuario:
	g++ usuario.cpp -c

usuariot:
	g++ usuario_test.cpp usuario.o -o test -I../gtest/include -L.. -lgtest -lgtest_main -ftest-coverage -std=c++11

transacao:
	g++ transacao.cpp -c

transacaot:
	g++ transacao_test.cpp transacao.o -o test -I../gtest/include -L.. -lgtest -lgtest_main -ftest-coverage -std=c++11

social:
	g++ social.cpp -c

clean:
	rm -f *.o
	rm -f *.gcno
	rm -f test