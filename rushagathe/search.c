#include "R02.h"

int		search_unit(t_dict *dict, char u)
{
	int i;

	i = 0;
	while (dict[i].nb != -2 && dict[i].ten == 0)
	{
		if (dict[i].nb == u - '0')
			return (i);
		i++;
	}
	return (-1);
}

int		search_ten_ten(t_dict *dict, char u)
{
	int i;
	int	nbr;

	i = 0;
	nbr = 10 + (u - '0');
	while (dict[i].nb != -2)
	{
		if (dict[i].nb == nbr)
			return (i);
		i++;
	}
	return (-1);
}

int		search_ten(t_dict *dict, char d)
{
	int i;

	i = 0;
	while (dict[i].nb != -2)
	{
		if (dict[i].nb == 10 * (d - '0'))
			return (i);
		i++;
	}
	return (-1);
}

int		search_nbr(t_dict *dict, int nbr)
{
	int	i;

	i = 0;
	while (dict[i].nb != -2 && dict[i].nb >= 0)
	{
		if (dict[i].nb == nbr)
			return (i);
		i++;
	}
	return (-1);
}
