#ifndef HEADER_GEN_H
# define HEADER_GEN_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <argp.h>

# define VERSION "hgen 0.1.0"
# define MAIL "<pbrochar@student.42.fr>"
# define DOC "hgen -- a program to generate header files"

typedef struct  s_args
{
	char    **argvalue;
    char    *c_file_current;
	int     argcount;
	int     c_opt;
    int     v_opt;
    int     a_opt;
    int     s_opt;
    int     f_opt;
}               t_args;

typedef struct  s_hgen
{
    int     count;
    int     fd_header;
    t_list  *lst_a_opt;
}               t_hgen;

typedef struct  s_prot
{
    char    *prototype;
    char    *file_name;
}               t_prot;

/*
** from srcs/a_opt.c
*/
int			open_fd_header_exist(t_args args, t_hgen *opt);
void		execute_a_opt(t_args args, t_hgen *opt, int fd_h);

/*
** from srcs/basics_fct.c
*/
int			add_line_in_list(t_args args, int fd_h, t_list **lst);
void		print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h);

/*
** from srcs/c_file_parser.c
*/
int			print_line_in_header(char *line, int fd);
void		parse_and_put_list(int fd_c, int fd_h, t_list **lst, char *file_name);

/*
** from srcs/check.c
*/
int			check_access_and_create(t_args args);
int			check_access_c(char *argv);
int			check_args(t_args args);
int			check_ext(const char *file_name, const char *ext);

/*
** from srcs/create_header.c
*/
int			create_header_file(char *file_name);
int			print_header_base(int fd, char *name);

/*
** from srcs/list_utils.c
*/
t_prot		*malloc_struct_proto(char *prototype, char *file_name);
void		rem_lst(t_list **lst);
void		sort_ascii_list(t_list **lst);

/*
** from srcs/opt_parse.c
*/
error_t		parse_opt(int key, char *arg, struct argp_state *state);
void		init_args_parse(t_hgen *opt, t_args *args, int argc, char **argv);

/*
** from srcs/utils.c
*/
int			ft_compare(char *str1, char *str2);
int			ft_isspace(char c);
int			str_is_fct(char *line);
void		print_file_name(char *name, int fd);

#endif
