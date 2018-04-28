/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 11:25:44 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 15:11:16 by fablin      ###    #+. /#+    ###.fr     */
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
// a faire :
// %010p

	int a = printf("   printf = %10R\n");
	int b = ft_printf("ft_printf = %10R\n");
	if (a == b)
		printf("OK\n");
	else
	{
		printf("printf = %d, ft_printf = %d\n", a, b);
		printf("ERROR\n");
	}
	return (0);
}
