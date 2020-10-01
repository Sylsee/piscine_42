/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:05:45 by ssar              #+#    #+#             */
/*   Updated: 2020/09/27 21:12:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_dict
{
	char *key;
	char *value;
}				t_dict;

int				ft_write(t_dict *list, char *nb);
int				dict_to_struct(t_dict **list, char *file, int size);
int				new_entry(char *key, char *value, t_dict **list, int par[2]);
int				dict_size(char *file);
void			size_entry(char *buff, int entry[2]);
int				ft_check_nbr(char *argv);
int				ft_check_conditions(int argc, char *argv[]);
int				ft_error(void);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_str_cpy(char *cpy, char *str);
int				ft_strcmp(char *s1, char *s2);
void			ft_clear_temp(char *temp);
void			ft_zero(char *argv, char *temp, t_dict *list);
void			ft_print_millier(char *temp, int len, t_dict *list);
int				ft_print_cent(int u, char *argv, char *temp, t_dict *list);
int				ft_if_diz_is_zero(int u, char *temp, char *argv, t_dict *list);
int				ft_mod_is_one(int u, char *argv, char *temp, t_dict *list);
int				ft_mod_is_two(int u, char *argv, char *temp, t_dict *list);
int				ft_mod_is_three(int u, char *argv, char *temp, t_dict *list);
int				ft_print_first_numbers(char *argv, t_dict *list);
int				ft_print_diz(int u, char *temp, char *argv, t_dict *list);

#endif
