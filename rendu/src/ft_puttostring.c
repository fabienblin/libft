/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttostring.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 21:01:32 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 16:18:05 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putwchar_fd(wchar_t c, int fd)
{
    if (c <= 0x7F)
        ft_putchar_fd(c, fd);
    else if (c <= 0x7FF)
    {
        ft_putchar_fd((c >> 6) + 0xC0, fd);
        ft_putchar_fd((c & 0x3F) + 0x80, fd);
    }
    else if (c <= 0xFFFF)
    {
        ft_putchar_fd((c >> 12) + 0xE0, fd);
        ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
        ft_putchar_fd((c & 0x3F) + 0x80, fd);
    }
    else if (c <= 0x10FFFF)
    {
        ft_putchar_fd((c >> 18) + 0xF0, fd);
        ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
        ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
        ft_putchar_fd((c & 0x3F) + 0x80, fd);
    }
}

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	while (*str)
	{
		ft_putwchar_fd(*str, fd);
		str++;
	}
	
}
