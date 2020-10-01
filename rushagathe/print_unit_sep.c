#include "R02.h"

int		print_str(char *str, int sep, int bloc)
{
	if (sep == 1 && bloc != -1)
		write(1, "and ", 4);
	else if (sep == 2)
		write(1, "-", 1);
	write_str(str);
	if ((sep == 0 || sep == 2) && (bloc != 0))
		write(1, " ", 1);
	return (1);
}

int		print_c(t_dict *dict, char nb[3], int bloc)
{
	int		c;
	int		bol;

	c = search_unit(dict, nb[0]);
	if (c < 0)
		return (-1);
	print_str(dict[c].wrd, 0, 1);
	c = search_nbr(dict, 100);
	if (c < 0)
		return (-1);
	bol = (-1) * (bloc == 0) * (nb[2] == '0' && nb[1] == '0');
	print_str(dict[c].wrd, bol, 1);
	return (1);
}

int		print_d(t_dict *dict, char nb[3], int bloc)
{
	int		d;
	int		p;

	if (nb[1] > '1')
	{
		d = search_ten(dict, nb[1]);
		p = search_unit(dict, nb[2]);
		if (d < 0 || p < 0)
			return (-1);
		print_str(dict[d].wrd, !(nb[2] == '0'), bloc);
		if (nb[2] != '0')
			print_str(dict[p].wrd, 2, bloc);
	}
	else if (nb[1] == '1')
	{
		d = search_ten_ten(dict, nb[2]);
		if (d < 0)
			return (-1);
		print_str(dict[d].wrd, 1 * (nb[0] != '0'), bloc);
	}
	return (1);
}
