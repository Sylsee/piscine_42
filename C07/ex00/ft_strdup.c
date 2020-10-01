/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:15:06 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/24 20:57:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*src_dup;

	i = 0;
	while (src[i])
		i++;
	i++;
	src_dup = (char *)malloc(sizeof(*src_dup) * (i));
	i = -1;
	while (src[++i])
		src_dup[i] = src[i];
	src_dup[i] = '\0';
	return (src_dup);
}
