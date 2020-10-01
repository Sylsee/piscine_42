/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:30:35 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/28 19:37:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

void	isolate(char **key, char **value, char *buff, int *i)
{
	int j;

	j = 0;
	while (buff[*i] == '\n')
		(*i)++;
	while (buff[*i] && buff[*i] >= '0' && buff[*i] <= '9')
		(*key)[j++] = buff[(*i)++];
	(*key)[j] = '\0';
	while (buff[*i] && buff[*i] == ' ')
		(*i)++;
	if (buff[*i] && buff[*i] == ':')
	{
		(*i)++;
		j = 0;
		while (buff[*i] == ' ')
			(*i)++;
		while (buff[*i] > 31 && buff[*i] < 127)
		{
			(*value)[j++] = buff[(*i)++];
		}
		(*value)[j] = '\0';
	}
}

int		fill_dict(char *buff, t_dict **list, int sizemax)
{
	int		i;
	int		par[2];
	char	*key;
	char	*value;

	i = 0;
	par[0] = 0;
	par[1] = sizemax;
	if (!(value = malloc(sizeof(char) * (sizemax + 1))))
		return (-1);
	if (!(key = malloc(sizeof(char) * (sizemax + 1))))
		return (-1);
	while (buff[i])
	{
		isolate(&key, &value, buff, &i);
		if (new_entry(key, value, list, par) < 0)
			return (-1);
		par[0]++;
	}
	new_entry("-1", "-1", list, par);
	free(value);
	free(key);
	return (1);
}

int		dict_to_struct(t_dict **list, char *file, int size)
{
	int		fd;
	int		entry[2];
	char	*buff;

	if (!(buff = malloc(sizeof(char) * (size + 1))))
		return (-1);
	fd = open(file, O_RDONLY);
	read(fd, buff, size);
	close(fd);
	buff[size] = '\0';
	size_entry(buff, entry);
	if (!(*list = malloc(sizeof(t_dict) * (entry[0] + 1))))
		return (-1);
	if (fill_dict(buff, list, entry[1]) < 0)
		return (-1);
	free(buff);
	return (1);
}
