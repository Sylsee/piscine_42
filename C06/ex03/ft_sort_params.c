/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:55:20 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/16 19:14:16 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *arg1, char *arg2)
{
	int i;

	i = 0;
	while (arg1[i] == arg2[i] && arg1[i] && arg2[i])
		i++;
	return (arg1[i] - arg2[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 2;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], argv[i - 1]) < 0)
		{
			tmp = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = tmp;
			i = 2;
		}
		else
			i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
