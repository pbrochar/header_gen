#ifndef TET_H
# define TET_H

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
void		ft_puthex_maj(t_varg *ftpf);
void		ft_putaddr(t_varg *ftpf);
void		ft_putid(t_varg *ftpf);
void		ft_putstring(t_varg *ftpf);
void		ft_putcharac(t_varg *ftpf);
void		ft_putpct(t_varg *ftpf);
void		ft_putunsigned(t_varg *ftpf);
void		init_s_varg(t_varg *ftpf, const char *format, va_list *parameters);
void		init_s_flags(t_flags *flags);
int			pf_istype(char c);
int			pf_isflag(char c);
int			nb_len_addr(void *ptr);
int			nb_len_unsigned(unsigned int nb);
int			nb_len_str(char *str);
void		print_arg(t_varg *ftpf, t_flags *flags);
void		print_flags(t_varg *ftpf, t_flags *flags);
void		pf_print_zero(t_varg *ftpf, t_flags *flags);
void		pf_print_space(t_varg *ftpf, t_flags *flags);
void		pf_print_dash(t_varg *ftpf, t_flags *flags);
void		pf_print_precision(t_varg *ftpf, t_flags *flags);
int			ft_printf(const char *format, ...);
void		ft_putnbr_pf(int n, size_t *i, int indicator);
void		ft_putchar_pf(char c, size_t *i);
void		ft_putstr_pf(char *s, size_t *i);
void		ft_put_param(t_varg *ftpf);
void		print_zero(t_varg *test);
int			nb_len_dec(int n);
int			nb_len_hex(int n);
void		int_precision(t_varg *ftpf, t_flags *flags);
void		unsigned_precision(t_varg *ftpf, t_flags *flags);
int			open_fd_header_exist(t_args args, t_hgen *opt);
void		print_a_opt(t_args args, t_hgen *opt, int fd_h);
int			str_is_fct(char *line);
int			print_line_in_header(char *line, int fd);
void		parse_and_print(int fd_c, int fd_h, t_list **lst, char *file_name);
t_prot		*malloc_struct_proto(char *prototype, char *file_name);
int			check_ext(const char *file_name, const char *ext);
int			check_args(t_args args);
int			check_access_and_create(t_args args);
int			check_access_c(char *argv);
int			create_header_file(char *file_name);
int			print_header_base(int fd, char *name);
void		print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h);
int			add_line_in_list(t_args args, int fd_h, t_list **lst);
void		rem_lst(t_list **lst);
void		init_args_parse(t_hgen *opt, t_args *args, int argc, char **argv);
error_t		parse_opt(int key, char *arg, struct argp_state *state);
int			ft_isspace(char c);
void		sort_ascii_list(t_list **lst);
void		ft_puthex_min(t_varg *ftpf);
void		ft_puthex_maj(t_varg *ftpf);
void		ft_putaddr(t_varg *ftpf);
void		ft_putid(t_varg *ftpf);
void		ft_putstring(t_varg *ftpf);
void		ft_putcharac(t_varg *ftpf);
void		ft_putpct(t_varg *ftpf);
void		ft_putunsigned(t_varg *ftpf);
void		init_s_varg(t_varg *ftpf, const char *format, va_list *parameters);
void		init_s_flags(t_flags *flags);
int			pf_istype(char c);
int			pf_isflag(char c);
int			nb_len_addr(void *ptr);
int			nb_len_unsigned(unsigned int nb);
int			nb_len_str(char *str);
void		print_arg(t_varg *ftpf, t_flags *flags);
void		print_flags(t_varg *ftpf, t_flags *flags);
void		pf_print_zero(t_varg *ftpf, t_flags *flags);
void		pf_print_space(t_varg *ftpf, t_flags *flags);
void		pf_print_dash(t_varg *ftpf, t_flags *flags);
void		pf_print_precision(t_varg *ftpf, t_flags *flags);
int			ft_printf(const char *format, ...);
void		ft_putnbr_pf(int n, size_t *i, int indicator);
void		ft_putchar_pf(char c, size_t *i);
void		ft_putstr_pf(char *s, size_t *i);
void		ft_put_param(t_varg *ftpf);
void		print_zero(t_varg *test);
int			nb_len_dec(int n);
int			nb_len_hex(int n);
void		int_precision(t_varg *ftpf, t_flags *flags);
void		unsigned_precision(t_varg *ftpf, t_flags *flags);

#endif