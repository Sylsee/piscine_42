#include "R02.h"

void	add_useless(t_dict **dict, int d, int end)
{
	if (end)
	{
		(*dict)[d].nb = -2;
		(*dict)[d].pow = -2;
	}
	else
	{
		(*dict)[d].nb = -1;
		(*dict)[d].pow = -1;
	}
}

int		add_til_hund(t_dict **dict, char *str, char *wrd, int par[2])
{
	(*dict)[par[0]].nb = ft_atoi(str);
	if (!((*dict)[par[0]].wrd = malloc((par[1] + 1) * sizeof(char))))
		return (-1);
	str_cpy((*dict)[par[0]].wrd, wrd);
	(*dict)[par[0]].pow = 0;
	(*dict)[par[0]].ten = (str_len(str) == 2);
	return (1);
}

int		add_ten_pow(t_dict **dict, char *str, char *wrd, int par[2])
{
	int		i;

	if (str[0] == '1' && (str_len(str) % 3 == 1))
	{
		i = 1;
		while (str[i] == '0')
			i++;
		if (!str[i])
		{
			(*dict)[par[0]].nb = -1;
			(*dict)[par[0]].pow = (1 - ((i - 1) % 3)) * ((i - 1) / 3);
			(*dict)[par[0]].ten = 0;
			if (!((*dict)[par[0]].wrd = malloc((par[1] + 1) * sizeof(char))))
				return (-1);
			str_cpy((*dict)[par[0]].wrd, wrd);
		}
		else
			add_useless(dict, par[0], 0);
	}
	return (1);
}

int		add_dict(t_dict **dict, char *str, char *wrd, int par[2])
{
	if (str_len(str) <= 3 && str_len(str) > 0)
		return (add_til_hund(dict, str, wrd, par));
	else
		return (add_ten_pow(dict, str, wrd, par));
}
