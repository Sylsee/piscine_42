/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:03:09 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/27 22:54:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_cmp(t_dict list, char *nb)
{
	int i;

	i = 0;
	while (list.key[i] == nb[i] && list.key[i] && nb[i])
		i++;
	return (list.key[i] - nb[i]);
}

int		ft_write(t_dict *list, char *nb)
{
	int			i;
	static	int n = 0;

	i = 0;
	while ((ft_cmp(list[i], nb) != 0) && list[i].key)
		i++;
	if (ft_cmp(list[i], nb))
		ft_putstr("Dict Error\n");
	else
	{
		if (n == 1)
			ft_putstr(" ");
		n = 1;
		ft_putstr(list[i].value);
	}
	return (0);
}
