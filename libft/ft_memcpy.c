/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:09:46 by spetit            #+#    #+#             */
/*   Updated: 2014/11/12 22:09:46 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (unsigned char *)dst;
	str2 = (const unsigned char *)src;
	if (n == 0)
		return (dst);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
