/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:57:17 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/16 18:12:17 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (++i <= nb)
		result *= i;
	return (result);
}
