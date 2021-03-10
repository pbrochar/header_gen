#include "header_gen.h"

int     f_opt_compare(char *file_name, t_list *lst)
{
    if (ft_strncmp(file_name, ((t_prot *)(lst->content))->file_name, ft_strlen(file_name)) != 0)
        return (1);
    return (0);
}

char *execute_f_opt(t_list *lst, int fd_h)
{
    char *file_name;

    file_name = ((t_prot *)(lst->content))->file_name;
    print_file_name(file_name, fd_h);
    return (file_name);
}