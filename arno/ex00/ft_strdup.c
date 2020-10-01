/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:35:52 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/29 01:33:38 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str_cpy;

	i = 0;
	while (src[i] != '\0')
		i++;
	str_cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_cpy)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str_cpy[i] = src[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
