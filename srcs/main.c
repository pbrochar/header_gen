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
	if (init_args_parse(&opt, &args, argc, argv) == -1)
		return (-1);
	if (check_args(args) == -1)
		return (-1);
	if (check_h_file(args) == -1)
		return (-1);
	if (check_c_files(args) == -1)
		return (-1);
	if (add_line_in_list(args, &lst) == -1)
		return (-1);
	if ((fd_h = check_access_and_create(args)) == -1)
		return (-1);
	if (args.a_opt == 1)
	{
		if (open_fd_header_exist(args, &opt) == -1)
			return (-1);
		execute_a_opt(args, &opt, fd_h);
	}
	if (args.s_opt == 1)
		sort_ascii_list(&lst);
	print_list_in_header(args, &opt, lst, fd_h);
	close(fd_h);
	rem_lst(&lst);
	if (args.c_opt == 1)
		printf("%d\n", opt.count);
	return (0);
}
