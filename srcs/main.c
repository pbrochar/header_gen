#include "header_gen.h"

int main(int argc, char **argv)
{
	int		fd_h;
	int		fd_c;
	int		i;
	t_list	*lst;
	t_args	args;
	t_hgen	opt;

	i = 1;
	lst = NULL;
	init_args_parse(&opt, &args, argc, argv);
	if (check_args(args) == -1)
		return (1);
	fd_h = check_access_and_create(args);
	if (args.a_opt == 1)
		open_fd_header_exist(args, &opt);
	if (fd_h == -1)
		return (1);
	add_line_in_list(args, fd_h, &lst);
	if (args.s_opt == 1)
		sort_ascii_list(&lst);
	print_list_in_header(args, &opt, lst, fd_h);
	ft_putstr_fd("\n#endif", fd_h);
	close(fd_h);
	rem_lst(&lst);
	if (args.c_opt == 1)
		printf("%d\n", opt.count);
	return (0);
}
