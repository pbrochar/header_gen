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

static void put_in_list_and_print(t_args args, t_hgen *opt, int fd_h)
{
    char    *line;
    char    before;
    
    line = NULL;
    get_next_line(opt->fd_header, &line);
    while (ft_strncmp(line, "# define", 8) != 0)
    {
        free(line);
        get_next_line(opt->fd_header, &line);
    }
    before = line[0];
    free(line);
    get_next_line(opt->fd_header, &line);
    while (ft_strncmp(line, "#endif", 6) != 0)
    {
        if (str_is_fct(line) == 0)
            ft_lstadd_back(&(opt->lst_a_opt), ft_lstnew(malloc_struct_proto(line, args.argvalue[args.argcount - 2])));
        else
        {
            ft_putstr_fd(line, fd_h);
            ft_putchar_fd('\n', fd_h);
        }
        before = line[0];
        free(line);
        get_next_line(opt->fd_header, &line);
    }
    free(line);
    close(opt->fd_header);
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
    put_in_list_and_print(args, opt, fd_h);
    if (args.s_opt == 1)
        sort_ascii_list(&(opt->lst_a_opt));
    if (args.f_opt == 1)
        print_file_name(args.argvalue[args.argcount - 2], fd_h);
    print_list_a_opt(opt, fd_h);
    rem_lst(&(opt->lst_a_opt));
}