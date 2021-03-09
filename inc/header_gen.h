#ifndef HEADER_GEN_H
# define HEADER_GEN_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <argp.h>

# define VERSION "hgen 0.0.2"
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

int check_ext(const char *file_name, const char *ext);
int check_args(t_args args);
int check_access_and_create(t_args args);
int create_header_file(char *file_name);
int print_header_base(int fd, char *name);
void parse_and_print(int fd_c, int fd_h, t_list **lst, char *name);
int check_access_c(char *argv);
int ft_isspace(char c);
int print_line_in_header(char *line, int fd);
void sort_ascii_list(t_list **lst);
void print_list_in_header(t_args args,t_hgen *opt, t_list *lst, int fd_h);
int add_line_in_list(t_args args, int fd_h, t_list **lst);
void rem_lst(t_list **lst);
error_t parse_opt(int key, char *arg, struct argp_state *state);
void init_args_parse(t_hgen *opt, t_args *args, int argc, char **argv);
int open_fd_header_exist(t_args args, t_hgen *opt);
void print_a_opt(t_args args, t_hgen *opt, int fd_h);
int str_is_fct(char *line);
t_prot *malloc_struct_proto(char *prototype, char *file_name);

#endif
