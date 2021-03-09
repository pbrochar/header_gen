#ifndef TEST_H
# define TEST_H

/*
**	from srcs/opt_parse.c
*/
error_t		parse_opt(int key, char *arg, struct argp_state *state);

/*
**	from srcs/opt_parse.c
*/
int			add_line_in_list(t_args args, int fd_h, t_list **lst);

/*
**	from srcs/list_utils.c
*/
int			check_access_and_create(t_args args);
int			check_access_c(char *argv);
int			check_args(t_args args);
int			check_ext(const char *file_name, const char *ext);

/*
**	from srcs/check.c
*/
int			create_header_file(char *file_name);

/*
**	from srcs/create_header.c
*/
int			ft_isspace(char c);

/*
**	from srcs/utils.c
*/
int			open_fd_header_exist(t_args args, t_hgen *opt);

/*
**	from srcs/a_opt.c
*/
int			print_header_base(int fd, char *name);

/*
**	from srcs/create_header.c
*/
int			print_line_in_header(char *line, int fd);
int			str_is_fct(char *line);
t_prot		*malloc_struct_proto(char *prototype, char *file_name);

/*
**	from srcs/c_file_parser.c
*/
void		rem_lst(t_list **lst);

/*
**	from srcs/list_utils.c
*/
void		init_args_parse(t_hgen *opt, t_args *args, int argc, char **argv);

/*
**	from srcs/opt_parse.c
*/
void		parse_and_print(int fd_c, int fd_h, t_list **lst, char *file_name);

/*
**	from srcs/c_file_parser.c
*/
void		print_a_opt(t_args args, t_hgen *opt, int fd_h);

/*
**	from srcs/a_opt.c
*/
void		print_file_name(char *name, int fd);
void		print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h);

/*
**	from srcs/list_utils.c
*/
void		sort_ascii_list(t_list **lst);

#endif