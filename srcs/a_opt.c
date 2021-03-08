#include "header_gen.h"

int open_fd_header_exist(t_args args, t_hgen *opt)
{
    if ((opt->fd_header = open(args.argvalue[args.argcount - 2], O_RDONLY)) == -1)
    {
        ft_printf("Can't open %s\n", args.argvalue[args.argcount - 2]);
        return (-1);
    }
    return (0);
}