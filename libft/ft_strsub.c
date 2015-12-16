#include "libft.h"

char *ft_strcpysub(char *dst, const char *src, unsigned int start, size_t len)
{
	int i;

	i = 0;
	while (len != 0)
	{
		dst[i] = src[start];
		start++;
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}


char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = ft_strnew(len);
	if (!str || (int)len < 0)
		return (NULL);
	ft_strcpysub(str, s, start, len);
	return (str);
}