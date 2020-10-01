/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:16:16 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/28 21:14:34 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int		increment_or_strlen(int *k, int *j, int flag, char *str)
{
	int i;

	i = 0;
	if (flag)
	{
		*k = *k + 1;
		*j = *j + 1;
		return (1);
	}
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_allow(int *k, int *j, char *str, char *strs)
{
	*str = *strs;
	*j = *j + 1;
	*k = *k + 1;
}

char	*ft_return(int flag)
{
	char *str;

	if (flag)
		str = NULL;
	else
	{
		if (!(str = malloc(sizeof(char))))
			return (0);
		str[0] = '\0';
	}
	return (str);
}

char	*assign(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len = len + increment_or_strlen(&i, &len, 0, strs[i]);
		i++;
	}
	len = len + (size - 1) * increment_or_strlen(&i, &len, 0, sep) + 1;
	if (size <= 0)
		len = 1;
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = assign(size, strs, sep);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			ft_allow(&k, &j, &str[k], &strs[i][j]);
		j = 0;
		while (sep[j] != '\0' && (i != size - 1))
		{
			str[k] = sep[j];
			increment_or_strlen(&k, &j, 1, "");
		}
	}
	str[k] = '\0';
	return (str);
}
