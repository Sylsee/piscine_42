/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:22:22 by spoliart          #+#    #+#             */
/*   Updated: 2020/10/01 18:39:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	ft_print_sol(int *tab)
{
	int		i;
	char	c;

	i = -1;
	while (++i < 10)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int		ft_check_place(int *tab, int x)
{
	int ok;
	int index;

	ok = 1;
	index = -1;
	while (++index < x && ok)
	{
		if (tab[x] == tab[index])
			ok = 0;
		if (ft_abs(index - x) == ft_abs(tab[index] - tab[x]))
			ok = 0;
	}
	return (ok);
}

void	ft_check_queen(int x, int *count)
{
	int			y;
	static int	tab[10] = {0};

	y = -1;
	while (++y < 10)
	{
		tab[x] = y;
		if (ft_check_place(tab, x))
		{
			if (x < 9)
				ft_check_queen(x + 1, count);
			else
			{
				++(*count);
				ft_print_sol(tab);
			}
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int count;

	ft_check_queen(0, &count);
	return (count);
}
