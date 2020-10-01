/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_principal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:31:52 by ssar              #+#    #+#             */
/*   Updated: 2020/09/27 22:25:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_print_diz(int u, char *temp, char *argv, t_dict *list)
{
	if (argv[u] == '1')
	{
		temp[0] = argv[u];
		u++;
		temp[1] = argv[u];
		u++;
		ft_write(list, temp);
	}
	else
	{
		temp[0] = argv[u];
		u++;
		temp[1] = '0';
		ft_write(list, temp);
		ft_clear_temp(temp);
		if (argv[u] == '0')
			u++;
		else
		{
			temp[0] = argv[u];
			ft_write(list, temp);
			u++;
		}
	}
	return (u);
}

int		ft_get_end_nbr(char *argv, int u, int len, t_dict *list)
{
	int		fix_len;
	char	*temp;

	fix_len = ft_strlen(argv);
	if (!(temp = malloc(sizeof(char *) * ((fix_len * 2)))))
		return (0);
	ft_clear_temp(temp);
	if (argv[u] == '0')
		u++;
	else
		u = ft_print_cent(u, argv, temp, list);
	if (argv[u] == '0')
		u = ft_if_diz_is_zero(u, temp, argv, list);
	else
		u = ft_print_diz(u, temp, argv, list);
	if (!(argv[u - 3] == '0' && argv[u - 2] == '0' && argv[u - 1] == '0'))
		if (u < fix_len)
			ft_print_millier(temp, len - 2, list);
	free(temp);
	if (len - 3 > 0)
		ft_get_end_nbr(argv, u, len - 3, list);
	return (1);
}

int		ft_print_first_numbers(char *argv, t_dict *list)
{
	char	*temp;
	int		len;
	int		u;

	len = ft_strlen(argv);
	if (!(temp = malloc(sizeof(char *) * ((len * 2)))))
		return (0);
	ft_clear_temp(temp);
	if (len % 3 == 1)
		u = ft_mod_is_one(1, argv, temp, list);
	if (len % 3 == 2)
		u = ft_mod_is_two(2, argv, temp, list);
	if (len % 3 == 0)
		u = ft_mod_is_three(3, argv, temp, list);
	ft_clear_temp(temp);
	if (u < len)
		ft_get_end_nbr(argv, u, len - u, list);
	ft_zero(argv, temp, list);
	free(temp);
	return (1);
}
