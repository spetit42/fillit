
// #include "fillit.h"

// int main(int ac, char **av)
// {
// 	int fd;
// 	char *line;

// 	line = NULL;
// 	fd = open(av[1], O_RDONLY);
// 	if (ac == 1)
// 	{
// 		return(0);
// 	}
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		ft_putstr(line);
// 	}
// 	ft_putstr(line);

// 	return(0);
// }