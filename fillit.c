#include "fillit.h"


static char **get_file(int fd)
{
	char *map;
	char **stock;
	int ret;
	int i;

	i = 0;
	stock = malloc(sizeof(char *) * 132);
	while ((ret = get_next_line(fd, &map)) == 1)
	{
			stock[i] = ft_strdup(map);
			i++;
	}
	stock[i] = ft_strdup(map);
	return(stock);
}

char	*ft_read(char **av, int index)
{
	int					fd;
	unsigned long long	rd;
	char				*tab;

	if (!(tab = (char *)malloc(sizeof(char) * BUFFER)))
		return (NULL);
	if (!(fd = open(av[index], O_RDONLY)))
		return (NULL);
	if (!(rd = read(fd, tab, BUFFER)))
		return (NULL);
	close(fd);
	return (tab);
}

void		ft_print_map(char **map)
{
	int		col;

	col = -1;
	while (map[++col] != NULL)
	{
		ft_putstr(map[col]);
		ft_putchar('\n');
	}
}

char		**ft_get_map(int len)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (++i < len)
	{
		if (!(ret[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		j = -1;
		while (++j < len)
			ret[i][j] = '.';
		ret[i][j] = '\0';
	}
	ret[len] = NULL;
	return (ret);
}

void	ft_fillit2(char **map, t_tetri **begin_tetri, t_id **begin_dct, int len)
{
	t_point		p;

	p.x = 0;
	p.y = 0;
	while ((map = ft_backtrack(*begin_tetri, map, len, p)) == NULL)
	{
		ft_tetri_clr(*begin_tetri);
		while (map)
		{
			free(*map);
			map++;
		}
		free(map);
		map = ft_get_map(++len);
	}
	if (map)
		ft_print_map(map);
}

void ft_fillit(int ac, char **av, int len)
{
	int fd;
	char **map;
	char *buf;
	t_id		*begin_dct;
	t_tetri		*begin_tetri;

	if ((buf = ft_read(av, 1)) == NULL)
	{
		ft_putstr("error\n");
		return ;
	}
	begin_tetri = ft_tetri_init(buf);
	fd = 0;
	if (ac != 2)
	{
		ft_putstr("wrong number of arguments the program will exit now.\n");
		return;
	}
	map = get_file(fd);
	 ft_fillit2(map, &begin_tetri, &begin_dct, len);	
}

int		main(int ac, char **av)
{
	ft_fillit(ac, av, 2);
	return (0);
}