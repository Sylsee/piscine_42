#ifndef R02_H
# define R02_H

# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct
{
	int		nb;
	char	*wrd;
	int		pow;
	int		ten;
}			t_dict;

int			print_letters(t_dict *dict, char *nb);
int			str_len(char *str);
int			search_nbr(t_dict *dict, int nbr);
int			print_str(char *str, int sep, int first);
int			search_unit(t_dict *dict, char u);
int			search_ten_ten(t_dict *dict, char u);
int			search_ten(t_dict *dict, char d);
int			search_nbr(t_dict *dict, int nbr);
int			str_len(char *str);
void		write_str(char *str);
int			ft_atoi(char *str);
void		str_cpy(char *dest, char *src);
int			is_valid(char *nbr);
int			print_first_bloc(int n, t_dict *dict, char *nb, int bloc);
int			print_bloc(t_dict *dict, char *nb, int bloc);
int			print_bloc_name(t_dict *dict, int bloc);
int			print_str(char *str, int sep, int bloc);
int			print_c(t_dict *dict, char nb[3], int bloc);
int			print_d(t_dict *dict, char nb[3], int bloc);
void		add_useless(t_dict **dict, int d, int end);
int			add_til_hund(t_dict **dict, char *str, char *wrd, int par[2]);
int			add_ten_pow(t_dict **dict, char *str, char *wrd, int par[2]);
int			add_dict(t_dict **dict, char *str, char *wrd, int par[2]);
void		isolate_word(char str[38], char *buf, int *i, char **wrd);
int			fill(t_dict **dict, char *buf, int maxlen);
int			parse(t_dict **dict, char *file, int size);
int			size_file(char *file);
void		nbr_entries(char *buf, int entries[2]);

#include <stdio.h>

#endif
