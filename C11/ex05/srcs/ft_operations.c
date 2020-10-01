/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:57:01 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/25 16:36:04 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		add(int a, int b)
{
	return (a + b);
}

int		ft_operations(int a, int b, char op)
{
	int	(*ptr[5])(int, int);

	ptr[0] = &add;
	ptr[1] = &minus;
	ptr[2] = &mult;
	ptr[3] = &div;
	ptr[4] = &mod;
	if (op == '+')
		return (ptr[0](a, b));
	else if (op == '-')
		return (ptr[1](a, b));
	else if (op == '*')
		return (ptr[2](a, b));
	else if (op == '/')
		return (ptr[3](a, b));
	else if (op == '%')
		return (ptr[4](a, b));
	return (a);
}
