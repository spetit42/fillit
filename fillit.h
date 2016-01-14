#ifndef FILLIT_H
#define FILLIT_H

#include "./libft/libft.h"
#include <fcntl.h>
# define BUFFER 600
# define TRUE 1
# define FALSE 0



typedef int			t_bool;

typedef struct		s_tetri
{
	char	**shape;
	t_bool	tested;
	void	*next;
}					t_tetri;

typedef struct		s_id
{
	int				type;
	char			letter;
	int				rotation;
	void			*next;
}					t_id;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_bool				ft_ismaj(char c);
char				**ft_backtrack(t_tetri *tetri, char **map, int len, t_point p);
void				ft_tetri_clr(t_tetri *start);
t_tetri				*ft_tetri_init(char *tab);

#endif
