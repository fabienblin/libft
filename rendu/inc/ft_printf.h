/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:17:06 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 15:48:25 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>

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
	char				*tostring;	//	chaine de sortie
	void				*arg;		//	ap
	char				*form;		// "% ls"
	int					err;		//err is true if ft_tostring == -1
}				t_format;

// misc
t_format	*ft_new_format(char *substr);
t_format	*ft_parse(char *format);
int			ft_printf(const char *format, ...);
char		*ft_uintmax_itoa_type(uintmax_t n, char t);
char		*ft_intmax_itoa_type(intmax_t n, char t);
char		*ft_ptoa(void *p);
char		*ft_strgen(int c, int len);
void		ft_del_format_lst(t_format *f);
int			ft_puttostring_fd(t_format *f, int fd);
int			ft_convert_wstr_to_str(char **dst, wchar_t *wstr, int limit);

// ft_format_setters.c
char		*ft_set_flags(char *c, t_format *f);
char		*ft_set_width(char *c, t_format *f);
char		*ft_set_preci(char *c, t_format *f);
char		*ft_set_size(char *c, t_format *f);
char		*ft_set_type(char *c, t_format *f);
void		ft_set_tostring(t_format *f, va_list ap);

// ft_tostring.c
void		ft_preci_tostring(t_format *f);
int			ft_type_tostring(t_format *f, va_list ap);
void		ft_width_tostring(t_format *f);
void		ft_flags_tostring(t_format *f);
// asupprimer.c
void		puttformat(t_format *f);

#endif
