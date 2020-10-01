/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gest_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 09:10:33 by ssar              #+#    #+#             */
/*   Updated: 2020/09/27 21:10:00 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		ft_check_conditions(int argc, char *argv[])
{
	if (argc == 1 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) > 37 || ft_strlen(argv[1]) < 1
				|| !(ft_check_nbr(argv[1]))
				|| !(ft_check_nbr(argv[1]))
				|| !(ft_check_nbr(argv[1]))
				|| !(ft_check_nbr(argv[1])))
			return (0);
	}
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) > 37 || ft_strlen(argv[2]) < 1
				|| ft_strlen(argv[1]) < 1
				|| !(ft_check_nbr(argv[2])))
			return (0);
	}
	return (1);
}

int		ft_check_nbr(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
