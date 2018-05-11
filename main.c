/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/07 17:21:28 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 20:30:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "rendu/inc/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>



int main (int argc, char **argv)
{
/*	if (argc != 2)
	{
		printf("Usage : %s format", argv[0]);
	}
	
*/	setlocale(LC_ALL, "");
	(void)argc;
	(void)argv;
		
	int a = printf("   printf = %C\n", 0xabc) - 13;
	int b = ft_printf("ft_printf = %C\n", 0xabc) - 13;
	if (a == b)
		printf("OK\n");
	else
	{
		printf("printf = %d, ft_printf = %d\n", a, b);
		printf("ERROR\n");
	}
	return (0);
}
