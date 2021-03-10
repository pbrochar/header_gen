#include "header_gen.h"

/*
** Try to open file.h
** If success, put the file descriptor in opt struct
*/
int open_fd_header_exist(t_args args, t_hgen *opt)
{
    if ((opt->fd_header = open(args.argvalue[args.argcount - 2], O_RDONLY)) == -1)
    {
        ft_printf("Can't open %s\n", args.argvalue[args.argcount - 2]);
        return (-1);
    }
    return (0);
}

static int put_in_list_and_print(t_args args, t_hgen *opt, int fd_h)
{
    char    *line;
    int     ret;
    
    line = NULL;
    if ((ret = get_next_line(opt->fd_header, &line)) < 1)
        return (-1);
    while (ft_strncmp(line, "# define", 8) != 0)
    {
        free(line);
        if ((ret = get_next_line(opt->fd_header, &line)) < 1)
            return (-1);
    }
    free(line);
    if ((ret = get_next_line(opt->fd_header, &line)) == 0)
        return (-2);
    while (ft_strncmp(line, "#endif", 6) != 0 && ret == 1)
    {
        if (str_is_fct(line) == 0)
            ft_lstadd_back(&(opt->lst_a_opt), ft_lstnew(malloc_struct_proto(line, args.argvalue[args.argcount - 2])));
        else
        {
            ft_putstr_fd(line, fd_h);
            ft_putchar_fd('\n', fd_h);
        }
        free(line);
        ret = get_next_line(opt->fd_header, &line);
    }
    free(line);
    close(opt->fd_header);
    return (0);
}

static void print_list_a_opt(t_hgen *opt, int fd_h)
{
    while (opt->lst_a_opt)
    {
        print_line_in_header(((t_prot *)(opt->lst_a_opt->content))->prototype, fd_h);
        opt->lst_a_opt = opt->lst_a_opt->next;
    }
}

void execute_a_opt(t_args args, t_hgen *opt, int fd_h)
{
    int ret;

    ret = put_in_list_and_print(args, opt, fd_h);
    if (ret == -1)
        ft_printf("Bad file, please check %s. Generate .h file from sources.\n", args.argvalue[args.argcount - 2]);
    else if (ret == -2)
        ft_printf("Nothing found in %s, please check. Generate .h file from sources.\n", args.argvalue[args.argcount - 2]);
    if (args.s_opt == 1 && opt->lst_a_opt)
        sort_ascii_list(&(opt->lst_a_opt));
    if (args.f_opt == 1)
        print_file_name(args.argvalue[args.argcount - 2], fd_h);
    print_list_a_opt(opt, fd_h);
    rem_lst(&(opt->lst_a_opt));
}