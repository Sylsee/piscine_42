/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/17 17:32:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_checkbase(char *base, int *i)
{
	int j;

	*i = 0;
	while (base[*i])
	{
		j = *i;
		if (base[*i] == '+' || base[*i] == '-')
			return (0);
		while (base[++j])
			if (base[*i] == base[j])
				return (0);
		*i += 1;
	}
	if (*i == 0 || *i == 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	tmp;
	int		i;

	tmp = nb;
	if (!ft_checkbase(base, &i))
		return ;
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp = tmp * -1;
	}
	if (tmp > i - 1)
	{
		ft_putnbr_base(tmp / i, base);
		tmp = tmp % i;
	}
	ft_putchar(base[tmp % i]);
}
