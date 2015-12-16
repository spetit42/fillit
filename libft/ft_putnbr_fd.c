/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:43:00 by spetit            #+#    #+#             */
/*   Updated: 2014/12/01 17:43:00 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int nb, int fd)
{
	unsigned int i;

	i = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (nb * -1);
	}
	while (nb / i >= 10)
	{
		i = i * 10;
	}
	while (i > 0)
	{
		ft_putchar_fd(((nb / i) % 10) + 48, fd);
		i = i / 10;
	}
}
