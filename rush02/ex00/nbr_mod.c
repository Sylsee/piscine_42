/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:58:11 by ssar              #+#    #+#             */
/*   Updated: 2020/09/27 21:48:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_mod_is_one(int u, char *argv, char *temp, t_dict *list)
{
	int len;

	len = ft_strlen(argv);
	if (argv[0] == '0')
		u = 1;
	else
	{
		temp[0] = argv[0];
		ft_write(list, temp);
		if (u < len)
			ft_print_millier(temp, len, list);
	}
	return (u);
}

int		ft_mod_is_two(int u, char *argv, char *temp, t_dict *list)
{
	int len;

	len = ft_strlen(argv);
	if (argv[0] == '0' && argv[1] == '0')
		u = 2;
	else if (argv[0] == '0' && argv[1] != '0')
	{
		temp[0] = argv[1];
		ft_write(list, temp);
	}
	else
		u = ft_print_diz(0, temp, argv, list);
	u = 2;
	if (u < len && !(argv[0] == '0' && argv[1] == '0'))
		ft_print_millier(temp, len - 1, list);
	return (u);
}

int		ft_mod_is_three(int u, char *argv, char *temp, t_dict *list)
{
	int len;

	len = ft_strlen(argv);
	if (argv[0] != '0')
		ft_print_cent(0, argv, temp, list);
	if (argv[0] == '0' && argv[1] == '0' && argv[2] == '0')
		u = 3;
	else
	{
		if (argv[1] == '0')
		{
			if (argv[2] != '0')
			{
				temp[0] = argv[2];
				ft_write(list, temp);
			}
		}
		else
			ft_print_diz(1, temp, argv, list);
		if (u < len)
			ft_print_millier(temp, len - 2, list);
	}
	return (u);
}
