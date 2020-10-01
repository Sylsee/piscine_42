#include "R02.h"

void	free_all(t_dict *dict)
{
	int		i;

	i = 0;
	while (dict[i].nb != -2)
	{
		free(dict[i].wrd);
		i++;
	}
	free(dict[i].wrd);
	free(dict);
}

int		parse_then_print(char *file, char *to_print)
{
	t_dict	*dict;
	int		size;
	int		u;

	if (is_valid(to_print))
	{
		size = size_file(file);
		if (parse(&dict, file, size) < 0)
			return (write(1, "Dict Error\n", 11));
		while (*to_print == '0')
			to_print++;
		if (*to_print == '\0')
		{
			u = search_nbr(dict, 0);
			if (print_str(dict[u].wrd, 0, 0) < 0)
				write(1, "Dict Error\n", 11);
		}
		else if (print_letters(dict, to_print) < 0)
			write(1, "Dict Error\n", 11);
		free_all(dict);
	}
	else
		write(1, "Error\n", 6);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*file;
	char	*to_print;

	if (argc == 2)
	{
		to_print = argv[1];
		file = "numbers.dict";
	}
	else if (argc == 3)
	{
		file = argv[1];
		to_print = argv[2];
	}
	else
		return (0);
	parse_then_print(file, to_print);
	return (0);
}
