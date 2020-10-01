/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:42:06 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/27 20:39:36 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		new_entry(char *key, char *value, t_dict **list, int par[2])
{
	if (!((*list)[par[0]].key = malloc(sizeof(char *) * (ft_strlen(key) + 1))))
		return (-1);
	if (!((*list)[par[0]].value = malloc(sizeof(char *) * (ft_strlen(value)
			+ 1))))
		return (-1);
	ft_str_cpy((*list)[par[0]].key, key);
	ft_str_cpy((*list)[par[0]].value, value);
	return (1);
}
