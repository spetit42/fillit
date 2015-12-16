#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	unsigned int i;

	i = 0;
	str = ft_strnew(ft_strlen(s));
	while(s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}