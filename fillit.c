#include "fillit.h"
#include <stdio.h>

static int check_diese(char **str, int i, int j)
{
	if (str[i][j] == '#')
	{
		if(str[i + 1][j] == '#' || str[i][j + 1] == '#' || str[i - 1][j]
			== '#' || str[i][j - 1] == '#')
			return(1);
		else
			return(-1);
	}
	return (0);
}

static int check_line(char **str, int j, int i)
{

	if (str[i][j] != '.' && str[i][j] != '#')
		return (-1);
	if (str[i][j] == '.')
		return(0);
	if (str[i][j] == '#')
	{
		if (check_diese(str, i, j) == 1)
			return(1);
		else
			return(-1);
	}
	return(2);
}


static int check_file(char **str)
{
	int i;
	int j;
	int p;
	int d;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strlen(str[i]) != 4 && ft_strlen(str[i]) != 0)
			return (-1);
		p = 0;
		d = 0;
		while (str[i][0] != '\0')
		{
			j = 0;
			while (str[i][j] != '\0')
			{
				if (check_line(str, j, i) == 0)
					p++;
				else if (check_line(str, j, i) == 1)
					d++;
				else
					return(-1);
				j++;
			}
			i++;
		}
		if (p != 12 || d != 4)
			return(-1);
		i++;
	}
	return(0);
}

static char **get_file(int fd)
{
	char *buff;
	char **stock;
	int ret;
	int i;

	i = 0;
	stock = malloc(sizeof(char *) * 132);
	while ((ret = get_next_line(fd, &buff)) == 1)
	{
			stock[i] = ft_strdup(buff);
			i++;
	}
	stock[i] = ft_strdup(buff);
	return(stock);
}

int main(int argc, char **argv)
{
	int fd;
	char **buff;
	int i;

	i = 0;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments the program will exit now.\n");
		return(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("invalid argument\n");
		return(0);
	}
	buff = get_file(fd);
 	if (check_file(buff) == -1)
	 {
	 	ft_putstr("error\n");
	 	exit(0);
	 }
	 while (buff[i] != '\0')
	 {
		ft_putstr(buff[i]);
		ft_putchar('\n');
		i++;
	 } 
	return(0);	
}