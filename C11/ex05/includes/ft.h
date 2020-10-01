/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:26:49 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/28 12:18:46 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
int		ft_operations(int a, int b, char op);
int		main(int argc, char **argv);
void	ft_doop(char *ac, char *op, char *bc);
int		str_len(char *str);
void	ft_putnbr(int nbr);
int		minus(int a, int b);
int		mult(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

#endif
