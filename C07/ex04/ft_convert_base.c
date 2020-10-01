/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:33:36 by arguilla          #+#    #+#             */
/*   Updated: 2020/10/01 00:41:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *base);

int		ft_exist_base(char *base);

void	ft_putnbr_base(int nbr, char *base, char *str, int *count);

int		contains(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int size_base;
	int r;
	int sign;
	int id;

	r = 0;
	sign = 1;
	if (ft_exist_base(base) == 0)
		return (0);
	size_base = ft_exist_base(base);
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while ((id = contains(base, *str)) > -1)
	{
		r = r * size_base + id;
		str++;
	}
	return (r * sign);
}

int		get_length(int nbr, char *base)
{
	int	l;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	l = 0;
	while (nbr >= base_len)
	{
		l++;
		nbr /= base_len;
	}
	return (l++);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		result_base_from;
	int		len;
	char	*result_base_to;
	int		i;
	int		count;

	if (!ft_exist_base(base_from) || !ft_exist_base(base_to))
		return (0);
	if (!nbr || !base_from || !base_to)
		return (0);
	i = 0;
	len = 0;
	result_base_from = ft_atoi_base(nbr, base_from);
	len = get_length(result_base_from, base_to);
	if (result_base_from < 0)
		len += 1;
	if (!(result_base_to = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	count = 0;
	ft_putnbr_base(result_base_from, base_to, result_base_to, &count);
	result_base_to[count] = '\0';
	return (result_base_to);
}
