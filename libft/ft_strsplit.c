#include "libft.h"

size_t			count_words(char const *s, char c)
{
	size_t		word;

	word = 0;
	while (s && *s)
	{
		if (*s == c)
			word++;
		while (*s == c)
			s++;
		s++;
	}
	return (word);
}

static int		letters(char const *s, char c, int count)
{
	int	letters;

	letters = 0;
	while (s[count] != c && s[count] != '\0')
	{
		letters++;
		count++;
	}
	return (letters);
}

static int		skip_char(char const *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

static void		ft_tab(char **tab, char c, char const *s)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (s[count] != '\0' && (skip_char(s, c, count) != -1))
	{
		j = 0;
		count = skip_char(s, c, count);
		tab[i] = (char *)malloc((letters(s, c, count) + 1) * sizeof(char));
		if (tab[i] != NULL)
		{
			while (s[count] != c && s[count] != '\0')
			{
				tab[i][j] = s[count];
				j++;
				count++;
			}
			tab[i][j] = '\0';
			i++;
		}
	}
	tab[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	tab = NULL;
	if (s)
	{
		words = count_words(s, c);
		tab = (char **)malloc((words + 1) * sizeof(char *));
		if (tab)
			ft_tab(&(*tab), c, s);
	}
	return (tab);
}