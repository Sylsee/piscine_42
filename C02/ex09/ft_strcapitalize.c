/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:24:28 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/12 21:24:33 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if ((i == 0 || str[i - 1] <= 47 || str[i - 1] >= 123
			|| (str[i - 1] <= 96 && str[i - 1] >= 91)
			|| (str[i - 1] <= 64 && str[i - 1] >= 58))
			&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		i++;
	}
	return (str);
}
