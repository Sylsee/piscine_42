/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_others.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:29:30 by ssar              #+#    #+#             */
/*   Updated: 2020/09/27 21:49:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_clear_temp(char *temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		temp[i] = '\0';
		i++;
	}
	temp[i] = '\0';
}

void	ft_zero(char *argv, char *temp, t_dict *list)
{
	int i;
	int is_zero;

	i = 0;
	is_zero = 1;
	while (argv[i])
	{
		if (argv[i] != '0')
			is_zero = 0;
		i++;
	}
	if (is_zero == 1)
	{
		temp[0] = '0';
		ft_write(list, temp);
	}
}

void	ft_print_millier(char *temp, int len, t_dict *list)
{
	int i;

	temp[0] = '1';
	i = 1;
	while (i < len)
	{
		temp[i] = '0';
		i++;
	}
	temp[i] = '\0';
	ft_write(list, temp);
}

int		ft_print_cent(int u, char *argv, char *temp, t_dict *list)
{
	temp[0] = argv[u];
	ft_write(list, temp);
	ft_write(list, "100");
	u++;
	return (u);
}

int		ft_if_diz_is_zero(int u, char *temp, char *argv, t_dict *list)
{
	u++;
	if (argv[u] != '0')
	{
		temp[0] = argv[u];
		ft_write(list, temp);
	}
	u++;
	return (u);
}
