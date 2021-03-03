#include "header_gen.h"

int main(int argc, char **argv)
{
	int fd_h;
	int fd_c;
	int i;
	t_list *lst;

	i = 1;
	if (check_args(argc, argv) == -1)
		return (1);
	fd_h = check_access_and_create(argc, argv);
	if (fd_h == -1)
		return (1);
	add_line_in_list(argv, argc, fd_h, &lst);
	sort_ascii_list(&lst);
	print_list_in_header(lst, fd_h);
	ft_putstr_fd("\n#endif", fd_h);
	close(fd_h);
	rem_lst(&lst);
	return (0);
}
