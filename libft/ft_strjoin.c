/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:09:27 by spetit            #+#    #+#             */
/*   Updated: 2015/01/06 20:09:34 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(char *) * (i + 1));
	if (str == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	else
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	return (str);
}
