/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strgen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 16:28:10 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 17:43:01 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strgen(int c, int len)
{
	char	*gen;
	
	if (!(gen = ft_strnew(len)))
		return (NULL);
	gen = ft_memset(gen, c, len);
	return (gen);
}