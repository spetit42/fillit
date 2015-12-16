/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:31:52 by spetit            #+#    #+#             */
/*   Updated: 2015/03/14 17:31:57 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_realloc(char *dest, const char *src, size_t len)
{
	char	*cpy;

	cpy = ft_strnew(ft_strlen(dest) + len);
	cpy = ft_strcpy(cpy, dest);
	cpy = ft_strncat(cpy, src, len);
	if (cpy == NULL)
		return (NULL);
	free(dest);
	return (cpy);
}

static int		get_line(char **line, char **buff, char *ptr, size_t len)
{
	char	*cpy;

	*line = ft_realloc(*line, *buff, len);
	cpy = ft_strnew(BUFF_SIZE);
	cpy = ft_strcpy(cpy, ptr + 1);
	free(*buff);
	*buff = cpy;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	static char	*buff = NULL;
	char		*ptr;

	if (fd < 0 || line == NULL)
		return (-1);
	if (buff)
	{
		*line = ft_strnew(0);
		if ((ptr = ft_strchr(buff, '\n')))
			return (get_line(line, &buff, ptr, ptr - buff));
		*line = ft_realloc(*line, buff, ft_strlen(buff));
	}
	else
	{
		buff = ft_strnew(BUFF_SIZE);
		*line = ft_strnew(0);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
			return (get_line(line, &buff, ptr, ptr - buff));
		*line = ft_realloc(*line, buff, ret);
	}
	if (ret <= 0)
	{
		free(*line);
		free(buff);
		buff = NULL;
		return (ret);
	}
	return (ret);
}
