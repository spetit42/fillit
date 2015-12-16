/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:15:58 by spetit            #+#    #+#             */
/*   Updated: 2014/11/05 19:16:00 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	if_signe(int *i, int *j, int *k, const char *str)
{
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '+')
			(*k)++;
		if (str[*i] == '-')
			(*j)++;
		(*i)++;
	}
}

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int k;
	int nbr;

	i = 0;
	j = 0;
	k = 0;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
	|| str[i] == '\f' || str[i] == ' ')
		i++;
	if_signe(&i, &j, &k, str);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (10 * nbr);
		i++;
	}
	if (j == 1)
	{
		nbr = nbr * -1;
	}
	if ((j > 1 || k > 1) || (j == 1 && k == 1))
		nbr = 0;
	return (nbr);
}
