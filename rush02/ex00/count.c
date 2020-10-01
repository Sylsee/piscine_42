/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:42:54 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/27 21:09:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		dict_size(char *file)
{
	int		fd;
	int		size;
	int		tot;
	char	buff[4096];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	size = read(fd, buff, 4096);
	tot = size;
	while (size)
	{
		size = read(fd, buff, 4096);
		tot += size;
	}
	close(fd);
	return (tot);
}

void	size_entry(char *buff, int entry[2])
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	entry[1] = 0;
	while (buff[i])
	{
		while (buff[i] && buff[i] == '\n')
			i++;
		if (buff[i])
			nb++;
		while (buff[i] && buff[i] != '\n')
		{
			i++;
			j++;
		}
		entry[1] = (entry[1] < j) ? j : entry[1];
	}
	entry[0] = nb;
}
