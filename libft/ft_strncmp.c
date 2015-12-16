/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 06:55:24 by spetit            #+#    #+#             */
/*   Updated: 2014/11/05 19:38:53 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	str1;
	unsigned int	str2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	if (n > str1)
		n = str1 + 1;
	if (n > str2)
		n = str2 + 1;
	return (ft_memcmp(s1, s2, n));
}
