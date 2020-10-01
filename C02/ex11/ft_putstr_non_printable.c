/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:13:27 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/12 18:50:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_conv(unsigned char non_printable)
{
	static char *hex = "0123456789abcdef";

	write(1, &hex[non_printable / 16], 1);
	write(1, &hex[non_printable % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			ft_conv(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
