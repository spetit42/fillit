/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 20:45:44 by spetit            #+#    #+#             */
/*   Updated: 2014/11/13 20:45:44 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size > (len1 + 1))
	{
		while (i < (size - len1 - 1))
		{
			dst[len1 + i] = src[i];
			i++;
		}
		dst[len1 + i] = '\0';
	}
	if (size >= len1)
		return (len1 + len2);
	return ((len1 + len2) - (len1 - size));
}
