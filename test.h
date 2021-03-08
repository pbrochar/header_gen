#ifndef TEST_H
# define TEST_H

# include <stdarg.h>
# include <stdio.h>

typedef struct	s_varg
{
	const char	*str;
	int			pos;
	va_list		*lst;
	size_t		nb_print;
	int			indicator;
}				t_varg;

typedef struct	s_flags
{
	int		nb_zero;
	int		nb_dash;
	int		nb_space;
	int		precision;
	int		len;
	int		eq_type;
	char	type;

}				t_flags;






/*
**	from inc/ft_printf.h
*/
void		ft_puthex_min(t_varg *ftpf);
