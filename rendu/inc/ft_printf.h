/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:17:06 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 20:12:19 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <locale.h>

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
	int					width;		//	nombre mini de chars pour afficher
	int					preci;		// .x
	int					size;		//	hh h l ll j z
	char				type;		//	s S p d D i o O u U x X c C
	void				*tostring;	//	chaine basique
	int					len;		//	ft_strlen()

}				t_format;

// misc
t_format	*ft_new_format(char *substr);
t_format	*ft_parse(char *format);
int			ft_printf(const char *format, ...);
char		*ft_uintmax_itoa_type(uintmax_t n, char t);
char		*ft_intmax_itoa_type(intmax_t n, char t);
char		*ft_ptoa(void *p);
wchar_t		*ft_strgen(int c, int len);
void		ft_del_format_lst(t_format *f);
void		ft_puttostring(t_format *f);

// ft_format_setters.c
char		*ft_set_flags(char *c, t_format *f);
char		*ft_set_width(char *c, t_format *f);
char		*ft_set_preci(char *c, t_format *f);
char		*ft_set_size(char *c, t_format *f);
char		*ft_set_type(char *c, t_format *f);
void		ft_set_len(t_format *f);
void		ft_set_tostring(t_format *f, va_list ap);

// ft_tostring.c
void		ft_preci_tostring(t_format *f);
void		ft_type_tostring(t_format *f, va_list ap);
void		ft_width_tostring(t_format *f);
// asupprimer.c
void	puttformat(t_format *f);

#endif
