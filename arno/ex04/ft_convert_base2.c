/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:41:36 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/28 22:55:39 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		is_space(char c)
{
	return ((c == 32 || (c >= 9 && c <= 13)));
}

int		ft_exist_base(char *base)
{
	int i;
	int j;
	int size_base;

	j = 0;
	i = 0;
	size_base = 0;
	if (ft_strlen(base) < 2 || !base)
		return (0);
	size_base = ft_strlen(base);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126
				|| is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (size_base);
}

void	ft_putnbr_base(int nbr, char *base, char *str, int *count)
{
	long	nbr_long;
	int		i;

	if (base == NULL || ft_exist_base(base) == 0)
		return ;
	i = ft_strlen(base);
	nbr_long = nbr;
	if (nbr_long < 0)
	{
		str[*count] = '-';
		(*count)++;
		nbr_long *= -1;
	}
	if (nbr_long > i - 1)
	{
		ft_putnbr_base(nbr_long / i, base, str, count);
		nbr_long = nbr_long % i;
	}
	str[*count] = base[nbr_long % i];
	*count = *count + 1;
}
