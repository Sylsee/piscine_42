/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:00:11 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/28 12:14:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_doop(char *ac, char *op, char *bc)
{
	int a;
	int b;

	a = ft_atoi(ac);
	b = ft_atoi(bc);
	if (op[0] == '/' && b == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (op[0] == '%' && b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else if (str_len(op) == 1 && (op[0] == '-' || op[0] == '+' || op[0] == '*'
		|| op[0] == '/' || op[0] == '%'))
	{
		ft_putnbr(ft_operations(a, b, op[0]));
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
}
