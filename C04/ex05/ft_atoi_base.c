/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:37:51 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/16 22:36:11 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_checkbase(char *base, int *size_base)
{
	int j;

	*size_base = 0;
	while (base[*size_base])
	{
		j = *size_base;
		if (base[*size_base] == '+' || base[*size_base] == '-')
			return (0);
		while (base[++j])
			if (base[*size_base] == base[j])
				return (0);
		*size_base += 1;
	}
	if (*size_base == 0 || *size_base == 1)
		return (0);
	return (1);
}

int		ft_checkbefore_nb(char *str, int *sign)
{
	int j;

	j = 0;
	while (str[j] && (str[j] == ' ' || (str[j] >= 8 && str[j] <= 13)))
		j++;
	while (str[j] && (str[j] == '+' || str[j] == '-'))
	{
		if (str[j] == '-')
			*sign *= -1;
		j++;
	}
	return (j);
}

int		ft_checknb_limit(char *str, char *base, int j)
{
	int k;

	k = j;
	while (str[k])
	{
		j = 0;
		while (base[j])
		{
			if (str[k] == base[j])
				break ;
			j++;
		}
		if (str[k] != base[j])
			return (k - 1);
		k++;
	}
	if (k > 0)
		k--;
	return (k);
}

int		ft_contains(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int j;
	int k;
	int sign;
	int result;
	int size_base;

	sign = 1;
	result = 0;
	if (!ft_checkbase(base, &size_base))
		return (0);
	j = ft_checkbefore_nb(str, &sign);
	k = ft_checknb_limit(str, base, j);
	while (j <= k)
	{
		result = result * size_base + ft_contains(base, str[j]);
		j++;
	}
	return (result *= sign);
}
