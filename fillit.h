#ifndef FILLIT_H
#define FILLIT_H

#include "./libft/libft.h"
#include <fcntl.h>

struct	s_tetriminos
{
	char	**shape;
	char	letter;
	int		height;
	int		width;
	void	*next;
}		t_tetriminos;

#endif
