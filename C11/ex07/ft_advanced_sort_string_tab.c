/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:00:24 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/30 23:50:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_string(char **s1, char **s2)
{
	char *tmp_str;

	tmp_str = *s1;
	*s1 = *s2;
	*s2 = tmp_str;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		j = 0;
		while (tab[j + 1])
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap_string(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
