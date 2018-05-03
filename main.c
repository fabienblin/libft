/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:25:44 by fablin            #+#    #+#             */
/*   Updated: 2018/05/02 18:17:28 by fablin           ###   ########.fr       */
/*                                                                            */
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

	int a = printf("   printf = %S\n", L"����");
	int b = ft_printf("ft_printf = %S\n", L"����");
	if (a == b)
		printf("OK\n");
	else
	{
		printf("printf = %d, ft_printf = %d\n", a, b);
		printf("ERROR\n");
	}
	return (0);
}
