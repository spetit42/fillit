#include "libft.h"

int		ft_size(int i)
{
	int		c;

	c = 0;
	if (i < 0)
		c++;
	while (i)
	{
		c++;
		i /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	nbc;
	size_t	sign;
	size_t	v_absolu;
	size_t	i;

	nbc = ft_size(n);
	i = nbc - 1;
	nb = (char*)malloc(sizeof(char) * (nbc + 1));
	sign = ((n < 0) ? 1 : 0);
	v_absolu = (unsigned)((n < 0) ? -n : n);
	if (!v_absolu)
	{
		nb[0] = '0';
		return (nb);
	}
	if (sign == 1)
		nb[0] = '-';
	while (v_absolu)
	{
		nb[i--] = '0' + (v_absolu % 10);
		v_absolu /= 10;
	}
	nb[nbc] = '\0';
	return (nb);
}