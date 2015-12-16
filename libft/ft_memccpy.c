/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 19:16:20 by spetit            #+#    #+#             */
/*   Updated: 2014/11/14 22:27:14 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*str1;
	const char	*str2;

	str2 = src;
	str1 = dst;
	while (n--)
	{
		if (*str2 == c)
		{
			*str1++ = *str2++;
			return (str1);
		}
		*str1++ = *str2++;
	}
	return (NULL);
}
