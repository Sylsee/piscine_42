/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:42:08 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/13 20:11:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	first_line(int x);

void	inter_line(int x);

void	last_line(int x);

int		rush01(int x, int y)
{
	int i;

	if ((x == 0 || y == 0) || (x == 0 && y == 0))
		return (0);
	if (y == 1)
		first_line(x);
	else if (y == 2)
	{
		first_line(x);
		last_line(x);
	}
	else
	{
		i = 0;
		while (++i <= y)
		{
			if (i == 1)
				first_line(x);
			else if (i > 1 && i < y)
				inter_line(x);
			else
				last_line(x);
		}
	}
	return (0);
}

void	first_line(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('/');
		ft_putchar('\n');
	}
	if (x > 1)
	{
		ft_putchar('/');
		i = 1;
		while (++i < x)
			ft_putchar('*');
		if (x == i)
		{
			ft_putchar('\\');
			ft_putchar('\n');
		}
	}
}

void	inter_line(int x)
{
	int i;

	if (x == 1)
		write(1, "*\n", 2);
	else if (x == 2)
		write(1, "**\n", 3);
	else if (x > 2)
	{
		i = 1;
		ft_putchar('*');
		while (++i < x)
			ft_putchar(' ');
		write(1, "*\n", 2);
	}
}

void	last_line(int x)
{
	int i;

	if (x == 1)
		write(1, "/\n", 2);
	else if (x == 2)
		write(1, "/\\\n", 3);
	else if (x > 2)
	{
		i = 1;
		ft_putchar('/');
		while (++i < x)
			ft_putchar('*');
		write(1, "\\\n", 2);
	}
}
