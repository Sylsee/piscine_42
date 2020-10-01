#include "R02.h"

int		print_bloc_name(t_dict *dict, int bloc)
{
	int		j;

	j = 0;
	if (bloc == 0)
		return (1);
	while (dict[j].nb != -2)
	{
		if (dict[j].pow == bloc)
			return (print_str(dict[j].wrd, 0, bloc));
		j++;
	}
	return (-1);
}

int		print_bloc(t_dict *dict, char *nb, int bloc)
{
	int		u;

	if (nb[0] == '0' && nb[1] == '0' && nb[2] == '0')
		return (0);
	if (nb[0] != '0' && (print_c(dict, nb, bloc) < 0))
		return (-1);
	if (nb[1] != '0' && (print_d(dict, nb, bloc) < 0))
		return (-1);
	else if (nb[1] == '0' && nb[2] != '0')
	{
		u = search_unit(dict, nb[2]);
		if (u < 0)
			return (-1);
		print_str(dict[u].wrd, nb[0] != '0', bloc);
	}
	return (1);
}

int		print_first_bloc(int n, t_dict *dict, char *nb, int bloc)
{
	char	fill[3];

	if (n == 3 && print_bloc(dict, nb, bloc) < 0)
		return (-1);
	else if (n == 2)
	{
		fill[0] = '0';
		fill[1] = nb[0];
		fill[2] = nb[1];
		if (print_d(dict, fill, (-1) * (bloc > 0)) < 0)
			return (-1);
	}
	else if (n == 1)
	{
		fill[0] = '0';
		fill[1] = '0';
		fill[2] = nb[0];
		if (print_bloc(dict, fill, (-1) * (bloc > 0)) < 0)
			return (-1);
	}
	return (1);
}

int		print_letters(t_dict *dict, char *nb)
{
	int		len;
	int		bloc;
	int		n;
	int		ok;

	len = str_len(nb);
	bloc = (len - 1) / 3;
	n = (len - 1) % 3 + 1;
	if (print_first_bloc(n, dict, nb, bloc) < 0)
		return (-1);
	if (print_bloc_name(dict, bloc) < 0)
		return (-1);
	nb += n;
	bloc--;
	while (bloc >= 0)
	{
		ok = print_bloc(dict, nb, bloc);
		if (ok < 0 || (ok && print_bloc_name(dict, bloc) < 0))
			return (-1);
		nb += 3;
		bloc--;
	}
	write(1, "\n", 1);
	return (1);
}
