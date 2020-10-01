#include "R02.h"

int		size_file(char *file)
{
	char	buf[4096];
	int		size;
	int		fd;
	int		tot;

	errno = 0;
	fd = open(file, O_RDONLY);
	if (!errno)
	{
		size = read(fd, buf, 4096);
		tot = size;
		while (size)
		{
			size = read(fd, buf, 4096);
			tot += size;
		}
		close(fd);
		return (tot);
	}
	return (-1);
}

void	nbr_entries(char *buf, int entries[2])
{
	int		i;
	int		j;
	int		nb;

	nb = 0;
	i = 0;
	j = 0;
	entries[1] = 0;
	while (buf[i])
	{
		while (buf[i] && buf[i] == '\n')
			i++;
		if (buf[i])
			nb++;
		while (buf[i] && buf[i] != '\n')
		{
			i++;
			j++;
		}
		entries[1] = (entries[1] < j) ? j : entries[1];
	}
	entries[0] = nb;
}
