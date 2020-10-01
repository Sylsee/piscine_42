/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:51:18 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/28 23:02:30 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *str;
	int i;
	int len;

	if (min >= max)
		return (NULL);
	i = -1;
	len = max - min;
	if (!(str = (int *)malloc(sizeof(min) * len)))
		return (0);
	while (++i < len)
		str[i] = min + i;
	return (str);
}
