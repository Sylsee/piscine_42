#include "R02.h"

void	isolate_word(char str[38], char *buf, int *i, char **wrd)
{
	int		j;

	j = 0;
	while (buf[*i] == '\n')
		(*i)++;
	while (buf[*i] && (buf[*i] <= '9' && buf[*i] >= '0'))
		str[j++] = buf[(*i)++];
	str[j] = '\0';
	while (buf[*i] && buf[*i] == ' ')
		(*i)++;
	if (buf[*i] && buf[*i] == ':')
	{
		(*i)++;
		j = 0;
		while (buf[*i] && buf[*i] == ' ')
			(*i)++;
		while (buf[*i] && buf[*i] != '\n')
			(*wrd)[j++] = buf[(*i)++];
		(*wrd)[j] = '\0';
	}
}

int		fill(t_dict **dict, char *buf, int maxlen)
{
	int		i;
	int		par[2];
	char	*wrd;
	char	str[38];

	i = 0;
	par[0] = 0;
	par[1] = maxlen;
	if (!(wrd = malloc((maxlen + 1) * sizeof(char))))
		return (-1);
	while (buf[i])
	{
		isolate_word(str, buf, &i, &wrd);
		if (add_dict(dict, str, wrd, par) < 0)
			return (-1);
		par[0]++;
		add_useless(dict, par[0], 1);
	}
	free(wrd);
	return (1);
}

int		parse(t_dict **dict, char *file, int size)
{
	char	*buf;
	int		fd;
	int		entries[2];

	if (!(buf = malloc((size + 1) * sizeof(char))))
		return (-1);
	fd = open(file, O_RDONLY);
	read(fd, buf, size);
	close(fd);
	buf[size] = '\0';
	nbr_entries(buf, entries);
	if (!(*dict = malloc((entries[0] + 1) * sizeof(t_dict))))
		return (-1);
	if (fill(dict, buf, entries[1]) < 0)
		return (-1);
	free(buf);
	return (1);
}
