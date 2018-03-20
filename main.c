/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 11:25:44 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 13:56:48 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rendu/inc/ft_printf.h"

#include <stdio.h>

int main (int argc, char **argv)
{
/*	if (argc != 2)
	{
		printf("Usage : %s format", argv[0]);
	}
	
*/	
	(void)argc;
	(void)argv;
	ft_printf("'%#8x'\n", 101);
	printf("'%#8x'\n", 101);
	return (0);
}
