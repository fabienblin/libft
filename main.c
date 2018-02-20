#include <stdio.h>
#include "rendu/libft/inc/libft.h"
#include "rendu/inc/ft_printf.h"
int main (int argc, char **argv)
{
//	printf("You typed : %s\n", argv[1]);
//	ft_printf("You typed : %s\n", argv[1]);
	if (argc != 2)
	{
		printf("Usage : %s string\n", argv[0]);
		exit(1);
	}
	ft_printf(argv[1]);
	return 0;
}