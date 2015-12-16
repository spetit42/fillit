/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:46:32 by spetit            #+#    #+#             */
/*   Updated: 2014/11/05 18:46:34 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = ft_strlen(src);
	str = (char *)malloc(sizeof(char *) * (i + 1));
	if (str == NULL || src == NULL)
		return (NULL);
	else
		ft_strcpy(str, src);
	return (str);
}
