#include "fillit.h"

void	ft_tetri_clr(t_tetri *start)
{
	while (start != NULL)
	{
		start->used = FALSE;
		start = start->next;
	}
}

static t_tetri	*ft_tetri_add(t_tetri *begin_tetri)
{
	t_tetri	*tetri;
	int		col;

	col = -1;
	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->tested = FALSE;
	tetri->next = begin_tetri;
	tetri->shape = (char **)malloc(sizeof(char *) * 4);
	while (++col < 4)
		tetri->shape[col] = (char *)malloc(sizeof(char) * 4 + 1);
	return (tetri);
}

t_tetri			*ft_tetri_init(char *tab)
{
	t_tetri	*begin_tetri;
	int		cursor;
	int		col;

	col = -1;
	if (!(begin_tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if (ft_strlen(tab) >= 440)
		cursor = ft_strlen(tab) / 20;
	else
		cursor = ft_strlen(tab) / 20 + 1;
	begin_tetri->next = NULL;
	begin_tetri->tested = FALSE;
	begin_tetri->shape = (char **)malloc(sizeof(char *) * 4);
	while (++col < 4)
		begin_tetri->shape[col] = (char *)malloc(sizeof(char) * 4 + 1);
	while (--cursor)
		begin_tetri = ft_tetri_add(begin_tetri, cursor);
	return (begin_tetri);
}