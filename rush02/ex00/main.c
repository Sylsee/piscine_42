/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:14:22 by ssar              #+#    #+#             */
/*   Updated: 2020/09/27 21:11:24 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_all(t_dict *list)
{
	int i;

	i = 0;
	while (!(ft_strcmp(list[i].value, "-1")))
	{
		free(list[i].key);
		free(list[i].value);
		i++;
	}
	free(list[i].key);
	free(list[i].value);
	free(list);
}

int		parse_and_print(char *file, char *to_print)
{
	t_dict	*list;
	int		size;

	size = dict_size(file);
	if (dict_to_struct(&list, file, size) < 0)
		return (-1);
	if (!(ft_print_first_numbers(to_print, list)))
		return (-1);
	free_all(list);
	return (1);
}

int		main(int argc, char **argv)
{
	char *to_print;
	char *file;

	if (!(ft_check_conditions(argc, argv)))
	{
		ft_error();
		return (0);
	}
	if (argc == 2)
	{
		to_print = argv[1];
		file = "numbers.dict";
	}
	else if (argc == 3)
	{
		file = argv[1];
		to_print = argv[2];
	}
	else
		return (0);
	parse_and_print(file, to_print);
	ft_putstr("\n");
	return (0);
}
