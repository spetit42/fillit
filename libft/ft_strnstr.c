/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 19:01:26 by spetit            #+#    #+#             */
/*   Updated: 2014/11/14 19:01:27 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	size_t		i;
	char		*str1;

	if (s1 && s1)
	{
		s2_len = ft_strlen(s2);
		str1 = (char *)s1;
		if (ft_strlen(str1) < s2_len)
			return (NULL);
		if (!s2_len)
			return (str1);
		if (s2_len > n)
			return (NULL);
		i = n - s2_len + 1;
		while (i)
		{
			if (!ft_memcmp(str1, s2, s2_len))
				return (str1);
			str1++;
			i--;
		}
	}
	return (NULL);
}
