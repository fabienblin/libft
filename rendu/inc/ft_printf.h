/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:17:06 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:07:58 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>

# include "libft.h"

typedef enum	e_size
{
	HH,
	H,
	LL,
	L,
	J,
	Z,
}

typedef struct	s_format
{
	char				flags[6];	//	# 0 - + ' '
	unsigned int		width;		//	nombre mini de chars pour afficher
	unsigned int		preci;		// .x
	int					size;		//	hh h l ll j z
	char				type;		//	s S p d D i o O u U x X c C
	char				*tostring	//	resultat de la chaine
	struct	s_format	*next;		//suivant
}				t_format;

// ft_format_getters.c
char		*ft_set_flags(char *c, t_format *f)
char		*ft_set_width(char *c, t_format *f)
char		*ft_set_preci(char *c, t_format *f)
char		*ft_set_size(char *c, t_format *f)
char		*ft_set_type(char *c, t_format *f)

void			ft_parse(const char *format, int *last);
t_str			*ft_new_str(char *str);
void			ft_del_str(t_str **str);
int				ft_printf(const char *format, ...);

#endif
