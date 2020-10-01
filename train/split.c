#include <libc.h>

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i] || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		total_length(char *str, char *charset)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (!is_charset(str[0], charset))
		j = 1;
	while (str[i])
	{
		if (is_charset(str[i - 1], charset) && !is_charset(str[i], charset))
			j++;
		i++;
	}
	return (j);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	split(char *tab, char *str, char *charset, int word)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (!is_charset(str[0], charset))
		j = 1;
	while (str[i])
	{
		if ((is_charset(str[i - 1], charset) && !is_charset(str[i], charset)) && i > 0)
			j++;
		if (j == word + 1 && !is_charset(str[i], charset) && str[i])
		{
			tab[k] = str[i];
			k++;
		}
		i++;
	}
	tab[k] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int i;
	int nb_words;
	char **tab;

	i = 0;
	tab = NULL;
	if (!str)
	{
		if (!(tab = malloc(sizeof(char *))))
			return (NULL);
		if (!(tab[0] = malloc(sizeof(char))))
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	nb_words = total_length(str, charset);
	if (!(tab = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0);
		split(tab[i], str, charset, i);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int i;
	char **tab;

	i = 0;
	tab = ft_split(argv[1], argv[2]);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
*/
