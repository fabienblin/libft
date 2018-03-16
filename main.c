/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 11:25:44 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 11:35:30 by fablin      ###    #+. /#+    ###.fr     */
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
	ft_printf("%#o %.-1s", 1, "abc");
	printf("%#o %.-1s", 1, "abc");
	return (0);
}
