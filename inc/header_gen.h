#ifndef HEADER_GEN_H
# define HEADER_GEN_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

int check_ext(const char *file_name, const char *ext);
int check_args(int argc, char **argv);
int check_access_and_create(int argc, char **argv);
int create_header_file(char *file_name);
int print_header_base(int fd, char *name);
void parse_and_print(int fd_c, int fd_h, t_list **lst);
int check_access_c(char *argv);
int ft_isspace(char c);
int print_line_in_header(char *line, int fd);
void sort_ascii_list(t_list **lst);
void print_list_in_header(t_list *lst, int fd_h);
int add_line_in_list(char **argv, int argc, int fd_h, t_list **lst);
void rem_lst(t_list **lst);

#endif
