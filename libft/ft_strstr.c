/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 00:22:24 by spetit            #+#    #+#             */
/*   Updated: 2014/09/03 08:47:48 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_analist(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*str;

	str = (char*)s1;
	if (!*s2)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == s2[0])
			if (ft_analist(&str[i], s2))
				return (&str[i]);
		i++;
	}
	return (NULL);
}