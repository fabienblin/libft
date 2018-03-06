/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:17:06 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 14:17:48 by fablin      ###    #+. /#+    ###.fr     */
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
	HH = 1,
	H = 2,
	LL = 3,
	L = 4,
	J = 5,
	Z = 6
}				e_size;

typedef struct	s_format
{
	struct	s_format	*next;
	char				flags[6];	//	+ - 0 # ' '
	unsigned int		width;		//	nombre mini de chars pour afficher
	int					preci;		// .x
	int					size;		//	hh h l ll j z
	char				type;		//	s S p d D i o O u U x X c C
	char				*tostring;	//	resultat de la chaine
	int					len;		//	ft_strlen()
	int					capital;	//	bool used to know if type is a capital letter

}				t_format;

t_format	*ft_new_format(char *substr, va_list ap);
t_format	*ft_parse(char *format, va_list ap);
int			ft_printf(const char *format, ...);

// ft_format_setters.c
char		*ft_set_flags(char *c, t_format *f);
char		*ft_set_width(char *c, t_format *f);
char		*ft_set_preci(char *c, t_format *f);
char		*ft_set_size(char *c, t_format *f);
char		*ft_set_type(char *c, t_format *f);
void		ft_set_len(t_format *f);
void		ft_set_tostring(t_format *f, va_list ap);
void		ft_set_capital(t_format *f);

// ft_tostring.c
void		ft_preci_tostring(t_format *format_lst);
void		ft_type_tostring(t_format *f, va_list ap);

// asupprimer.c
void	puttformat(t_format *f);

#endif
