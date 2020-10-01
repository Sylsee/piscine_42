/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:16:17 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/30 23:50:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_string(char **s1, char **s2)
{
	char *tmp_str;

	tmp_str = *s1;
	*s1 = *s2;
	*s2 = tmp_str;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int i;
	int j;
	int size;

	size = 0;
	i = 0;
	j = 0;
	while (tab[size])
		size++;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) < 0)
			{
				ft_swap_string(&tab[i], &tab[j]);
				j = 0;
			}
			j++;
		}
		i++;
	}
}
