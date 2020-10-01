/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:16:09 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/30 17:38:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return ;
	list->data = data;
	list->next = *begin_list;
	*begin_list = list;
}
