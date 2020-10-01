/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:52:01 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/22 22:36:36 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*src_dup;

	i = 0;
	while (src[i])
		i++;
	i++;
	if (!(src_dup = (char *)malloc(sizeof(*src_dup) * (i + 1))))
		return (0);
	i = -1;
	while (src[++i])
		src_dup[i] = src[i];
	src_dup[i] = '\0';
	return (src_dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*list;

	if (!(list = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	i = -1;
	while (av[++i] && i < ac)
	{
		list[i].size = ft_strlen(av[i]);
		list[i].str = av[i];
		list[i].copy = ft_strdup(av[i]);
	}
	list[i].size = 0;
	list[i].str = 0;
	list[i].copy = 0;
	return (list);
}
