/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:47:41 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/28 23:06:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i] != '\0')
		if (c == charset[i] || c == '\0')
			return (1);
	return (0);
}

int		ft_tab_len(char *str, char *charset)
{
	int i;
	int j;

	j = 0;
	if (!is_in_charset(str[0], charset))
		j = 1;
	i = 0;
	while (str[++i])
		if (is_in_charset(str[i - 1], charset) &&
			!is_in_charset(str[i], charset))
			j++;
	return (j);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_assign(char *tab, char *str, int index, char *charset)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	if (!is_in_charset(str[0], charset))
		j = 1;
	i = -1;
	while (str[++i])
	{
		if (i > 0)
			if (is_in_charset(str[i - 1], charset) &&
				!is_in_charset(str[i], charset))
				j++;
		if (j == index + 1 && !is_in_charset(str[i], charset) && str[i] != '\0')
		{
			tab[k] = str[i];
			k++;
		}
	}
	tab[k] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;
	int		tab_len;

	tab_len = ft_tab_len(str, charset);
	if (tab_len == 0)
	{
		tab = malloc(sizeof(char *) * 1);
		tab[0] = malloc(sizeof(char **) * 1);
		tab[0] = NULL;
		return (tab);
	}
	if (!(tab = (char **)malloc(sizeof(char *) * tab_len + 2)))
		return (0);
	i = -1;
	while (++i < tab_len)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
			return (0);
		ft_assign(tab[i], str, i, charset);
	}
	tab[i] = NULL;
	return (tab);
}
