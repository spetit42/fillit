/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 18:08:05 by spetit            #+#    #+#             */
/*   Updated: 2014/11/23 18:08:07 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void				*new_mem;
	unsigned int		i;
	char				*str;

	i = 0;
	new_mem = (void *)malloc(size);
	str = (char *)new_mem;
	if (new_mem != NULL)
	{
		while (i++ < size)
			*str++ = 0;
	}
	return (new_mem);
}
