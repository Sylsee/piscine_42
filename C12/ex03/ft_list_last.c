/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:47:21 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/30 17:50:24 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	int i;

	i = -1;
	while (begin_list[++i].next != NULL)
		begin_list->next = begin_list->next->next;
	return (begin_list);
}
