#include <stdio.h>
//#include "rendu/ft_printf.h"
#include "rendu/libft/inc/libft.h"
int main (int argc, char **argv)
{
//	printf("You typed : %s\n", argv[1]);
//	ft_printf("You typed : %s\n", argv[1]);
	printf("ft_itoa = %s", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return 0;
}