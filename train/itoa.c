/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:51:15 by spoliart          #+#    #+#             */
/*   Updated: 2020/10/01 22:24:06 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

long	len_nb(long nb)
{
	int size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	size++;
	return (size);
}

void	str_rev(char *tab)
{
	int i;
	int j;
	char tmp;

	i = 0;
	j = 0;
	if (tab[0] == '-')
		j++;
	while (tab[i])
		i++;
	if (i > 1)
		i--;
	while (i > j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i--;
		j++;
	}
}

char	*itoa(int nb)
{
	int i;
	long tmp;
	char *tab;

	i = 0;
	tmp = nb;
	if (!(tab = malloc(sizeof(char *) * (len_nb(tmp) + 1))))
		return (0);
	if (tmp < 0)
	{
		tab[i] = '-';
		tmp *= -1;
		i++;
	}
	while (tmp > 9)
	{
		tab[i] = tmp % 10 + '0';
		tmp /= 10;
		i++;
	}
	tab[i] = tmp % 10 + '0';
	tab[++i] = '\0';
	if (tab[1] != '\0')
		str_rev(tab);
	return (tab);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", itoa(atoi(argv[1])));
	return (0);
}
