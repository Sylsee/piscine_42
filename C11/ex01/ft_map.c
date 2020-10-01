/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:37:28 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/30 15:15:42 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *result;

	i = -1;
	result = malloc(sizeof(int *) * length);
	while (++i < length)
		result[i] = f(tab[i]);
	return (result);
}
