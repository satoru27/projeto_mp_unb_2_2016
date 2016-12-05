#include "social.h"

int main()
{
	Social a = Social();
	for(int i = 0; i < 3;i++)
	{
		a.cria_usuario();
	}
	a.print_lista_usuarios();
	return 0;
}